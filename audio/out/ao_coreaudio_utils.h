/*
 * General CoreAudio utils
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

#ifndef MPLAYER_AUDIO_OUT_AO_COREAUDIO_UTIL
#define MPLAYER_AUDIO_OUT_AO_COREAUDIO_UTIL

#include <CoreAudio/CoreAudioTypes.h>
#include <CoreFoundation/CoreFoundation.h>

const char *osstatus_to_str(OSStatus status);
int ca_fmt_from_af(int format);
int ca_absd_from_ao(struct ao *ao, AudioStreamBasicDescription *asbd);

#endif /* MPLAYER_AUDIO_OUT_AO_COREAUDIO_UTIL */
