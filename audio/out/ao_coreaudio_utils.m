/*
 * General Util functions for coreaudio
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
#include "internal.h"
#include "ao.h"

#include "audio/out/ao_coreaudio_utils.h"

#include <Foundation/Foundation.h>


int ca_fmt_from_af(int format)
{
    int out = 0;
    if (af_fmt_is_float(format))
        out |= kAudioFormatFlagIsFloat;
    else if (!af_fmt_is_unsigned(format))
        out |= kAudioFormatFlagIsSignedInteger;
    if (!af_fmt_is_planar(format))
        out |= kAudioFormatFlagIsPacked;
    return out;
}

#define FRAMES_PER_PACKET 1
int ca_absd_from_ao(struct ao *ao, AudioStreamBasicDescription *asbd)
{
    int fmt_bytes;
    if (!ao || !asbd)
        return 1;

    fmt_bytes = af_fmt_to_bytes(ao->format);
    asbd->mSampleRate        = ao->samplerate;
    asbd->mFormatID          = kAudioFormatLinearPCM;
    asbd->mFormatFlags       = ca_fmt_from_af(ao->format);
    asbd->mFramesPerPacket   = FRAMES_PER_PACKET;
    asbd->mChannelsPerFrame  = ao->channels.num;
    asbd->mBitsPerChannel    = fmt_bytes * 8;
    asbd->mBytesPerFrame     = ao->channels.num * fmt_bytes;
    asbd->mBytesPerPacket    = ao->channels.num * fmt_bytes * FRAMES_PER_PACKET;

    return 0;
}

const char *osstatus_to_str(OSStatus status)
{
    NSError *error = [NSError errorWithDomain:NSOSStatusErrorDomain code:status userInfo:nil];
    return [[error localizedDescription] cStringUsingEncoding:[NSString defaultCStringEncoding]];
}
