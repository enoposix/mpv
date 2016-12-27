enum mChannelLayoutTag {
	/* Use the array of AudioChannelDescription structures to define the layout. */
	kAudioChannelLayoutTag_UseChannelDescriptions,
	/* Use the bitmap to define the layout. */
	kAudioChannelLayoutTag_UseChannelBitmap,
	/* A standard monophonic stream. */
	kAudioChannelLayoutTag_Mono,
	/* A standard stereophonic stream; playback implied. */
	kAudioChannelLayoutTag_Stereo,
	/* A standard stereo stream; headphone playback implied. */
	kAudioChannelLayoutTag_StereoHeadphones,
	/* A matrix-encoded stereo stream. */
	kAudioChannelLayoutTag_MatrixStereo,
	/* Mid/side recording. */
	kAudioChannelLayoutTag_MidSide,
	/* Coincident, angled microphone pair. */
	kAudioChannelLayoutTag_XY,
	/* Binaural stereo. */
	kAudioChannelLayoutTag_Binaural,
	/* Ambisonic B-format. */
	kAudioChannelLayoutTag_Ambisonic_B_Format,
	/* Quadraphonic, with 90° loudspeaker separation. */
	kAudioChannelLayoutTag_Quadraphonic,
	/* Pentagonal, with 72° loudspeaker separation. */
	kAudioChannelLayoutTag_Pentagonal,
	/* Hexagonal, with 60° loudspeaker separation. */
	kAudioChannelLayoutTag_Hexagonal,
	/* Octagonal, with 45° loudspeaker separation. */
	kAudioChannelLayoutTag_Octagonal,
	/* Cubic. */
	kAudioChannelLayoutTag_Cube,
	/* MPEG 1-channel. */
	kAudioChannelLayoutTag_MPEG_1_0,
	/* MPEG 2-channel. */
	kAudioChannelLayoutTag_MPEG_2_0,
	/* MPEG 3-channel layout A. */
	kAudioChannelLayoutTag_MPEG_3_0_A,
	/* MPEG 3-channel layout B. */
	kAudioChannelLayoutTag_MPEG_3_0_B,
	/* MPEG 4- channel layout A. */
	kAudioChannelLayoutTag_MPEG_4_0_A,
	/* MPEG 4-channel layout B. */
	kAudioChannelLayoutTag_MPEG_4_0_B,
	/* MPEG 5-channel layout A. */
	kAudioChannelLayoutTag_MPEG_5_0_A,
	/* MPEG 5-channel layout B. */
	kAudioChannelLayoutTag_MPEG_5_0_B,
	/* MPEG 5-channel layout C. */
	kAudioChannelLayoutTag_MPEG_5_0_C,
	/* MPEG 5-channel layout D. */
	kAudioChannelLayoutTag_MPEG_5_0_D,
	/* MPEG 5.1-channel layout A. */
	kAudioChannelLayoutTag_MPEG_5_1_A,
	/* MPEG 5.1-channel layout B. */
	kAudioChannelLayoutTag_MPEG_5_1_B,
	/* MPEG 5.1-channel layout C. */
	kAudioChannelLayoutTag_MPEG_5_1_C,
	/* MPEG 5.1-channel layout D. */
	kAudioChannelLayoutTag_MPEG_5_1_D,
	/* MPEG 6.1-channel layout A. */
	kAudioChannelLayoutTag_MPEG_6_1_A,
	/* MPEG 7.1-channel layout A. */
	kAudioChannelLayoutTag_MPEG_7_1_A,
	/* MPEG 7.1-channel layout A (see ISO/IEC 13818-7 MPEG2-AAC, Table 3.1). */
	kAudioChannelLayoutTag_MPEG_7_1_B,
	/* MPEG 7.1-channel layout C. */
	kAudioChannelLayoutTag_MPEG_7_1_C,
	/* Emagic 7.1-channel default layout. */
	kAudioChannelLayoutTag_Emagic_Default_7_1,
	/* SMPTE DTV layout; equivalent to the kAudioChannelLayoutTag_ITU_5_1 layout plus a matrix encoded stereo mix. */
	kAudioChannelLayoutTag_SMPTE_DTV,
	/* ITU 1-channel layout. */
	kAudioChannelLayoutTag_ITU_1_0,
	/* ITU 2-channel layout. */
	kAudioChannelLayoutTag_ITU_2_0,
	/* ITU 2.1-channel layout. */
	kAudioChannelLayoutTag_ITU_2_1,
	/* ITU 2.2-channel layout. */
	kAudioChannelLayoutTag_ITU_2_2,
	/* ITU 3-channel layout. */
	kAudioChannelLayoutTag_ITU_3_0,
	/* ITU 3.1-channel layout. */
	kAudioChannelLayoutTag_ITU_3_1,
	/* ITU 3.2-channel layout. */
	kAudioChannelLayoutTag_ITU_3_2,
	/* ITU 3.2.1-channel layout. */
	kAudioChannelLayoutTag_ITU_3_2_1,
	/* ITU 3.4.1-channel layout. */
	kAudioChannelLayoutTag_ITU_3_4_1,
	/* DVD monaural layout. */
	kAudioChannelLayoutTag_DVD_0,
	/* DVD stereo layout. */
	kAudioChannelLayoutTag_DVD_1,
	/* DVD 3-channel layout. */
	kAudioChannelLayoutTag_DVD_2,
	/* DVD 4-channel layout. */
	kAudioChannelLayoutTag_DVD_3,
	/* DVD 2.1-channel layout. */
	kAudioChannelLayoutTag_DVD_4,
	/* DVD 3.1-channel layout. */
	kAudioChannelLayoutTag_DVD_5,
	/* DVD 4.1-channel layout. */
	kAudioChannelLayoutTag_DVD_6,
	/* DVD 3-channel layout. */
	kAudioChannelLayoutTag_DVD_7,
	/* DVD 4-channel layout. */
	kAudioChannelLayoutTag_DVD_8,
	/* DVD 5-channel layout. */
	kAudioChannelLayoutTag_DVD_9,
	/* DVD 3.1-channel layout. */
	kAudioChannelLayoutTag_DVD_10,
	/* DVD 4.1-channel layout. */
	kAudioChannelLayoutTag_DVD_11,
	/* DVD 5.1-channel layout. */
	kAudioChannelLayoutTag_DVD_12,
	/* DVD 4-channel layout; equivalent to kAudioChannelLayoutTag_DVD_8. */
	kAudioChannelLayoutTag_DVD_13,
	/* DVD 5-channel layout; equivalent to kAudioChannelLayoutTag_DVD_9. */
	kAudioChannelLayoutTag_DVD_14,
	/* DVD 3.1-channel layout; equivalent to kAudioChannelLayoutTag_DVD_10. */
	kAudioChannelLayoutTag_DVD_15,
	/* DVD 4.1-channel layout; equivalent to kAudioChannelLayoutTag_DVD_11. */
	kAudioChannelLayoutTag_DVD_16,
	/* DVD 5.1-channel layout; equivalent to kAudioChannelLayoutTag_DVD_12. */
	kAudioChannelLayoutTag_DVD_17,
	/* DVD 4.1-channel layout. */
	kAudioChannelLayoutTag_DVD_18,
	/* DVD 5-channel layout. */
	kAudioChannelLayoutTag_DVD_19,
	/* DVD 5.1-channel layout. */
	kAudioChannelLayoutTag_DVD_20,
	/* Quadraphonic symmetrical layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_4,
	/* Pentagonal symmetrical layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_5,
	/* Hexagonal symmetrical layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_6,
	/* Octagonal symmetrical layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_8,
	/* 5-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_5_0,
	/* 6-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_6_0,
	/* 7-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_7_0,
	/* Alternate 7-channel surround-based layout, for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_7_0_Front,
	/* 5.1-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_5_1,
	/* 6.1-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_6_1,
	/* 7.1-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_7_1,
	/* 7.1-channel surround-based layout, recommended for use by audio units. */
	kAudioChannelLayoutTag_AudioUnit_7_1_Front,
	/* AAC 3-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_3_0,
	/* AAC quadraphonic surround-based layout. */
	kAudioChannelLayoutTag_AAC_Quadraphonic,
	/* AAC 4-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_4_0,
	/* AAC 5-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_5_0,
	/* AAC 5.1-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_5_1,
	/* AAC 6-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_6_0,
	/* AAC 6.1-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_6_1,
	/* AAC 7-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_7_0,
	/* AAC 7.1-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_7_1,
	/* AAC 8-channel surround-based layout. */
	kAudioChannelLayoutTag_AAC_Octagonal,
	/* TMH 10.2, a multiple-channel surround-based layout . */
	kAudioChannelLayoutTag_TMH_10_2_std,
	/* TMH 10.2 (kAudioChannelLayoutTag_TMH_10_2_std) plus additional channels; recommended for use by audio units. */
	kAudioChannelLayoutTag_TMH_10_2_full,
	/* An AC-3 layout. */
	kAudioChannelLayoutTag_AC3_1_0_1,
	/* An AC-3 layout. */
	kAudioChannelLayoutTag_AC3_3_0,
	/* An AC-3 layout. */
	kAudioChannelLayoutTag_AC3_3_1,
	/* An AC-3 layout. */
	kAudioChannelLayoutTag_AC3_3_0_1,
	/* An AC-3 layout. */
	kAudioChannelLayoutTag_AC3_2_1_1,
	/* An AC-3 layout. */
	kAudioChannelLayoutTag_AC3_3_1_1,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC_6_0_A,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC_7_0_A,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_6_1_A,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_6_1_B,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_6_1_C,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_A,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_B,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_C,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_D,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_E,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_F,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_G,
	/* A Blu-ray Disc audio layout for Enhanced AC-3, also known as Dolby Digital Plus. */
	kAudioChannelLayoutTag_EAC3_7_1_H,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_3_1,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_4_1,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_0_A,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_0_B,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_0_C,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_1_A,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_1_B,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_1_C,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_6_1_D,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_7_0,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_7_1,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_8_0_A,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_8_0_B,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_8_1_A,
	/* A Blu-ray Disc audio layout, defined by DTS (Digital Theater Systems Ltd.). */
	kAudioChannelLayoutTag_DTS_8_1_B,
	/* Needs to be ORed with the actual number of channels. */
	kAudioChannelLayoutTag_DiscreteInOrder,
	/* Needs to be ORed with the actual number of channels. */
	kAudioChannelLayoutTag_Unknown,
	kAudioChannelLayoutTag_AAC_7_1_B,
	kAudioChannelLayoutTag_AAC_7_1_C,
};



