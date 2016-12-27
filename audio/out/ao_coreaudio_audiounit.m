/*
 * Audio output driver for CoreAudio using AudioUnits
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
#include <AudioUnit/AudioUnit.h>
#include <AudioUnit/AUComponent.h>

#if OS_IOS
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#endif

#include "audio/out/ao_coreaudio.h"
#include "audio/out/ao_coreaudio_utils.h"

struct priv
{
    AudioComponentInstance unit;
    bool paused;
};

static OSStatus audio_callback(void *userdata, AudioUnitRenderActionFlags *ioActionFlags,
                               const AudioTimeStamp *inTimeStamp, uint32_t inBusNumber,
                               uint32_t inNumberFrames, AudioBufferList *ioData)
{
    struct ao *ao = userdata;
    struct priv *priv = ao->priv;
    void *direct[MP_NUM_CHANNELS] = {0};

    for (int i = 0; i < ao->num_planes; i++)
        direct[i] = ioData->mBuffers[i].mData;

    ao_read_data(ao, direct, inNumberFrames, mp_time_us() + 1UL /*needs change*/);
    return noErr;

    return 0;
}

static void uninit(struct ao *ao)
{
    struct priv *priv = ao->priv;
    if (!priv || !priv->unit)
        return;
    AudioComponentInstanceDispose(priv->unit);
}

static int init(struct ao *ao)
{
    struct priv *priv = ao->priv;
    AudioStreamBasicDescription fmt_desc;
    AudioComponent comp;
    int fmt_bytes;

#if OS_IOS
    AVAudioSessionPortDescription *sessionPort = nil;
    AVAudioSession *audioSession = AVAudioSession.sharedInstance;
    NSInteger maxChan = audioSession.maximumOutputNumberOfChannels;
    [audioSession setPreferredOutputNumberOfChannels: (maxChannels > ao->channels.num ? maxChannels : ao->channels.num) error: nil];
    [audioSession setCategory:AVAudioSessionCategoryPlayback error:nil];
    [audioSession setMode:AVAudioSessionModeMoviePlayback error:nil];
    [audioSession setActive:YES error:nil];
#endif

    AudioComponentDescription comp_desc = {
        .componentType          = kAudioUnitType_Output,
#if OS_IOS
        .componentSubType       = kAudioUnitSubType_RemoteIO,
#else
        .componentSubType       = kAudioUnitSubType_HALOutput,
#endif
        .componentManufacturer  = kAudioUnitManufacturer_Apple,
        .componentFlags         = 0,
        .componentFlagsMask     = 0,
    };


    comp = AudioComponentFindNext(NULL, &comp_desc);
    if (!comp) {
        MP_ERR(ao, "Unable to find default audio device.\n");
        return -1;
    }

    if (AudioComponentInstanceNew(comp, &priv->unit)) {
        MP_ERR(ao, "Unable to open default audio device.\n");
        return -1;
    }
    priv->paused = 1;

    if (AudioUnitInitialize(priv->unit)) {
        MP_ERR(ao, "Unable to initialize audio unit instance\n");
        return -1;
    }

    if(ca_absd_from_ao(ao, &fmt_desc)) {
        MP_ERR(ao, "Unable to fill AudioStreamBasicDescription from internal audio format description.\n");
        return -1;
    }

    if (AudioUnitSetProperty(priv->unit, kAudioUnitProperty_StreamFormat,
                             kAudioUnitScope_Input, 0, &fmt_desc, sizeof(fmt_desc))) {
        MP_ERR(ao, "Unable to set audio unit input property.\n");
        return -1;
    }

    //if (AudioUnitSetProperty(priv->unit, kAudioUnitProperty_SetRenderCallback,
    //                         kAudioUnitScope_Input, 0, callback, sizeof(callback))) {
    //    MP_ERR(ao, "Unable to attach an IOProc to the selected audio unit.\n");
    //    return -1;
    //}

    if (AudioOutputUnitStart(priv->unit)) {
        MP_ERR(ao, "Unable to start audio unit.\n");
        return -1;
    }
    return 1;
}

static void reset(struct ao *ao)
{
    struct priv *priv = ao->priv;
    if (!priv || !priv->unit)
        return;
    AudioOutputUnitStop(priv->unit);
    priv->paused = 1;
}

static void resume(struct ao *ao)
{
    struct priv *priv = ao->priv;
    if (!priv || !priv->unit)
        return;
    AudioOutputUnitStart(priv->unit);
    priv->paused = 0;
}

const struct ao_driver audio_out_coreaudio = {
    .description = "CoreAudio",
    .name      = "coreaudio",
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
