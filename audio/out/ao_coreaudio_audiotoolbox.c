/*
 * Audio output driver for CoreAudio using AudioToolbox
 *
 * Copyright (C) 2016 Josh de Kock <josh@itanimul.li>
 *
 * This file is part of mpv.
 *
 * mpv is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * mpv is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with mpv.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"
#include "audio/format.h"
#include "mpv_talloc.h"
#include "ao.h"
#include "internal.h"
#include "common/common.h"
#include "common/msg.h"
#include "options/m_option.h"
#include "osdep/timer.h"

#include <CoreAudio/CoreAudio.h>
#include <CoreAudio/CoreAudioTypes.h>
#include <AudioToolbox/AudioQueue.h>
#include <AudioToolbox/AudioToolbox.h>

#include "audio/out/ao_coreaudio.h"
#include "audio/out/ao_coreaudio_utils.h"

struct priv
{
    AudioQueueRef queue;
    AudioQueueBufferRef buffers[3];
    bool paused;
};

static void callback(void *userdata, AudioQueueRef queue, AudioQueueBufferRef buffer)
{
    struct ao   *ao      = userdata;
    struct priv *priv    = ao ? ao->priv : NULL;
    int err = 0, samples = 0;

    if (!buffer || !priv || !ao->sstride || !ao->num_planes)
        return;

    int i = 0;
    void *buffers[MP_NUM_CHANNELS];
    for (int i = 0; i < ao->num_planes; i++)
        buffers[i] = buffer->mAudioData + i * buffer->mAudioDataBytesCapacity / ao->num_planes;

    samples = buffer->mAudioDataBytesCapacity / (ao->sstride * ao->num_planes);
    samples = ao_read_data(ao, buffers, samples, mp_time_us() + 1UL);

    if (samples) {
        buffer->mAudioDataByteSize = af_fmt_is_planar(ao->format) ?
                                     samples * ao->num_planes * af_fmt_to_bytes(ao->format) :
                                     samples * ao->sstride;
        if ((err = AudioQueueEnqueueBuffer(queue, buffer, 0, nil))) {
            MP_ERR(ao, "Unable to load audio into AudioToolbox: %s\n", osstatus_to_str(err));
        }
    }
}

static void uninit(struct ao *ao)
{
    struct priv *priv = ao->priv;
    if (!priv)
        return;
}

static int init(struct ao *ao)
{
    struct priv *priv = ao->priv;
    AudioStreamBasicDescription fmt_desc = {0};
    int err = 0;

    /* TODO: support planar */
    switch (ao->format) {
    case AF_FORMAT_U8P:
        ao->format = AF_FORMAT_U8;
        break;
    case AF_FORMAT_S16P:
        ao->format = AF_FORMAT_S16;
        break;
    case AF_FORMAT_S32P:
        ao->format = AF_FORMAT_S32;
        break;
    case AF_FORMAT_FLOATP:
        ao->format = AF_FORMAT_FLOAT;
        break;
    case AF_FORMAT_DOUBLEP:
        ao->format = AF_FORMAT_DOUBLE;
        break;
    }

    ca_absd_from_ao(ao, &fmt_desc);

    if ((err = AudioQueueNewOutput(&fmt_desc, callback, ao, NULL, NULL, 0, &priv->queue))) {
        MP_ERR(ao, "Unable to create new audio output: %s\n", osstatus_to_str(err));
        return -1;

    }

    int bufferByteSize = 4800;//ao->samplerate * af_fmt_to_bytes(ao->format) * ao->channels.num;
    for (int i = 0; i < 3; i++) {
        err = AudioQueueAllocateBuffer(priv->queue, bufferByteSize, &priv->buffers[i]);
        if (err) {
            MP_ERR(ao, "Unable to allocate AudioQueue buffer: %s\n", osstatus_to_str(err));
            return -1;
        }
        //callback((void*)ao, priv->queue, priv->buffers[i]);
        memset(priv->buffers[i]->mAudioData, 0, priv->buffers[i]->mAudioDataBytesCapacity);
        priv->buffers[i]->mAudioDataByteSize = priv->buffers[i]->mAudioDataBytesCapacity;
        err = AudioQueueEnqueueBuffer(priv->queue, priv->buffers[i], 0, NULL);
        if (err) {
            MP_ERR(ao, "Unable to enqueue AudioQueue buffer: %s\n", osstatus_to_str(err));
            return -1;
        }
    }

    if ((err = AudioQueuePrime(priv->queue, 0, NULL))) {
        MP_ERR(ao, "Unable to prime audio output queue: %s\n", osstatus_to_str(err));
        return -1;
    }

    if ((err = AudioQueueStart(priv->queue, NULL))) {
        MP_ERR(ao, "Unable to start audio output queue: %s\n", osstatus_to_str(err));
        return -1;
    }

    return 1;
}

static void reset(struct ao *ao)
{
    struct priv *priv = ao->priv;
    if (!priv)
        return;
    priv->paused = 1;
}

static void resume(struct ao *ao)
{
    struct priv *priv = ao->priv;
    if (!priv)
        return;
    priv->paused = 0;
}

const struct ao_driver audio_out_coreaudio_audiotoolbox = {
    .description = "CoreAudio (using AudioToolbox)",
    .name      = "coreaudio_audiotoolbox",
    .init      = init,
    .uninit    = uninit,
    .reset     = reset,
    .resume    = resume,
    .priv_size = sizeof(struct priv),
    .priv_defaults = &(const struct priv) {
    },
    .options = (const struct m_option[]) {
        {0}
    },
};
