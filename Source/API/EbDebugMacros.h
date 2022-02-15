/*
* Copyright(c) 2020 Intel Corporation
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
*/


/*
* This file contains only debug macros that are used during the development
* and are supposed to be cleaned up every tag cycle
* all macros must have the following format:
* - adding a new feature should be prefixed by FTR_
* - tuning a feature should be prefixed by TUNE_
* - enabling a feature should be prefixed by EN_
* - disabling a feature should be prefixed by DIS_
* - bug fixes should be prefixed by FIX_
* - code refactors should be prefixed by RFCTR_
* - code cleanups should be prefixed by CLN_
* - all macros must have a coherent comment explaining what the MACRO is doing
* - #if 0 / #if 1 are not to be used
*/


#ifndef EbDebugMacros_h
#define EbDebugMacros_h

// clang-format off

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define OPT_RES_CHECKS          1 // Reduce resolution checks in M7/M8
#define OPT_RES_CHECKS_2        1 // Reduce resolution checks in M9-M13
#define OPT_RES_CHECKS_3        1 // Reduce resolutions checks for M3+
#define OPT_REMOVE_SC_RES_CHECKS 1 // Remove resolution checks for SC content
#define CLN_REMOVE_UNUSED_RES   1 // Remove unused resolution checks

    // For 4k tuning
#define OPT_M12_4K              1 // Tune M12 for 4k
#define OPT_M11_4K              1 // Tune M11 for 4k
#define OPT_M10_4K              1 // Tune M10 for 4k
#define OPT_M9_4K               1 // Tune M9 for 4k
#define OPT_M8_4K               1 // Tune M8 for 4k
#define OPT_M7_4K               1 // Tune M7 for 4k
#define OPT_M12_4K_SPACING      1 // Adjusted M12 spacing for 4k
#define OPT_M13_4K              1 // Tune M13 for 4k
#define OPT_M13_10BIT           1 // Tune M13 for 10bit
#define OPT_M6_4K               1 // Tune M6 for 4k

#define FIX_VBR_DIV0            1 // Fix the VBR div by zero in multipass mode

#define FIX_CHECK_NON_INITIALIZED_VAR       1 // Move around the condition to avoid non-initialized variable
#define FIX_USE_ME_DATA_ISLICE              1 // Properly initialize the ME data when the picture is I-SLICE and used as reference
#define FIX_PALETTE_10BIT                   1 // Remove palette scaling for non-intra candidates
#define FIX_CHROMA_PREDICTION_AVAILABILITY  1 // Align chroma prediction generation and use
#define FIX_SB_TOTAL_COUNT                  1 // Fix the use of sb_total_count by sb_total_count_pix which takes into account the actual SB size


#define TPL_LAD_MG_ZERO         1 // Set tpl_lad_mg to 0 when lookAhead is smalller than mini_gop size
#define TUNE_LP_VBR             1 // Tune lp 16 and above for VBR
#define FIX_UPDATE_COEF         1 // Don't allow bypass_encdec when update_coef is used for non_ISLICE (causes r2r)
#define OPT_DECODER             1 // Decoder speedup optimizations for M5-M10
#define FIX_NIC_BUFF            1 // Fix the way the max NICs are derived

#define TUNE_PRESET_GAP         1 // Correct the preset gap between M6 to M9
//FOR DEBUGGING - Do not remove
#define LOG_ENC_DONE            0 // log encoder job one
#define NO_ENCDEC               0 // bypass encDec to test cmpliance of MD. complained achieved when skip_flag is OFF. Port sample code from VCI-SW_AV1_Candidate1 branch
#define DEBUG_TPL               0 // Prints to debug TPL
#define DETAILED_FRAME_OUTPUT   0 // Prints detailed frame output from the library for debugging
#define TUNE_CHROMA_SSIM        0 // Allows for Chroma and SSIM BDR-based Tuning

#define MIN_PIC_PARALLELIZATION 0 // Use the minimum amount of picture parallelization
#define SRM_REPORT              0 // Report SRM status
#define LAD_MG_PRINT            0 // Report LAD
#define RC_NO_R2R               0 // This is a debugging flag for RC and makes encoder to run with no R2R in RC mode
                                  // Note that the speed might impacted significantly
#if RC_NO_R2R
#define REMOVE_LP1_LPN_DIFF     1 // Disallow single-thread/multi-thread differences
#else
#define REMOVE_LP1_LPN_DIFF     0 // Disallow single-thread/multi-thread differences
#endif
#define FIX_1PVBR               1 // Derive initial qp based on target bitrate
// Super-resolution debugging code
#define DEBUG_SCALING           0
#define DEBUG_TF                0
#define DEBUG_UPSCALING         0
#define DEBUG_SUPERRES_RECODE   0
#define DEBUG_SUPERRES_ENERGY   0
#define DEBUG_RC_CAP_LOG        0 // Prints for RC cap

#ifdef __cplusplus
}
#endif // __cplusplus

// clang-format on

#endif // EbDebugMacros_h
