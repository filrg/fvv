#ifndef FVV_DEFS_H
#define FVV_DEFS_H

#include <stdint.h>
#include <stdlib.h>

typedef struct fvv_bitstream_t           fvv_bitstream_t;

typedef struct fvv_v3c_unit_t            fvv_v3c_unit_t;
typedef struct fvv_v3c_unit_header_t     fvv_v3c_unit_header_t;
typedef struct fvv_v3c_unit_payload_t    fvv_v3c_unit_payload_t;
typedef struct fvv_v3c_parameter_set_t   fvv_v3c_parameter_set_t;
typedef struct fvv_atlas_sub_bitstream_t fvv_atlas_sub_bitstream_t;
typedef struct fvv_video_sub_bitstream_t fvv_video_sub_bitstream_t;
typedef struct fvv_sample_stream_nal_header_t
    fvv_sample_stream_nal_header_t;
typedef struct fvv_sample_stream_nal_unit_t
                                        fvv_sample_stream_nal_unit_t;
typedef struct fvv_byte_alignment_t     fvv_byte_alignment_t;
typedef struct fvv_profile_tier_level_t fvv_profile_tier_level_t;
typedef struct fvv_occupancy_information_t
    fvv_occupancy_information_t;
typedef struct fvv_geometry_information_t fvv_geometry_information_t;
typedef struct fvv_attribute_information_t
    fvv_attribute_information_t;
typedef struct fvv_profile_toolset_constraints_information_t
    fvv_profile_toolset_constraints_information_t;
typedef struct fvv_nal_unit_t        fvv_nal_unit_t;
typedef struct fvv_nal_unit_header_t fvv_nal_unit_header_t;
typedef struct fvv_atlas_sequence_parameter_set_rbsp_t
    fvv_atlas_sequence_parameter_set_rbsp_t;
typedef struct fvv_asps_plr_information_t fvv_asps_plr_information_t;
typedef struct fvv_atlas_frame_parameter_set_rbsp_t
    fvv_atlas_frame_parameter_set_rbsp_t;
typedef struct fvv_atlas_frame_tile_information_t
    fvv_atlas_frame_tile_information_t;
typedef struct fvv_atlas_adaptation_parameter_set_rbsp_t
    fvv_atlas_adaptation_parameter_set_rbsp_t;
typedef struct fvv_sei_rbsp_t fvv_sei_rbsp_t;
typedef struct fvv_access_unit_delimiter_rbsp_t
    fvv_access_unit_delimiter_rbsp_t;
typedef struct fvv_end_of_sequence_rbsp_t fvv_end_of_sequence_rbsp_t;
typedef struct fvv_end_of_atlas_sub_bitstream_rbsp_t
    fvv_end_of_atlas_sub_bitstream_rbsp_t;
typedef struct fvv_filler_data_rbsp_t fvv_filler_data_rbsp_t;
typedef struct fvv_atlas_tile_layer_rbsp_t
                                         fvv_atlas_tile_layer_rbsp_t;
typedef struct fvv_rbsp_trailing_bits_t  fvv_rbsp_trailing_bits_t;
typedef struct fvv_atlas_tile_header_t   fvv_atlas_tile_header_t;
typedef struct fvv_ref_list_struct_t     fvv_ref_list_struct_t;
typedef struct fvv_vui_parameters_t      fvv_vui_parameters_t;
typedef struct fvv_asps_vpcc_extension_t fvv_asps_vpcc_extension_t;
typedef struct fvv_aaps_vpcc_extension_t fvv_aaps_vpcc_extension_t;
typedef struct fvv_sei_message_t         fvv_sei_message_t;
typedef struct fvv_atlas_tile_data_unit_t fvv_atlas_tile_data_unit_t;
typedef struct fvv_aaps_vpcc_extension_t  fvv_aaps_vpcc_extension_t;
typedef struct fvv_atlas_camera_parameters_t
    fvv_atlas_camera_parameters_t;
typedef struct fvv_patch_information_data_t
                                     fvv_patch_information_data_t;
typedef struct fvv_patch_data_unit_t fvv_patch_data_unit_t;
typedef struct fvv_skip_patch_data_unit_t fvv_skip_patch_data_unit_t;
typedef struct fvv_merge_patch_data_unit_t
    fvv_merge_patch_data_unit_t;
typedef struct fvv_inter_patch_data_unit_t
                                         fvv_inter_patch_data_unit_t;
typedef struct fvv_raw_patch_data_unit_t fvv_raw_patch_data_unit_t;
typedef struct fvv_eom_patch_data_unit_t fvv_eom_patch_data_unit_t;
typedef struct fvv_plr_data_t            fvv_plr_data_t;

typedef uint16_t                         fvv_ret_t;

#define FVV_RET_SUCCESS               0x0000
#define FVV_RET_FAIL                  0x0001
#define FVV_RET_UNINITIALIZED         0x0002
#define FVV_RET_UNSUPPORT             0x0003
#define FVV_RET_ILLEGAL_MEMORY_ACCESS 0x0004

#define FVV_FAILED(x)                 ((x) != FVV_RET_SUCCESS)
#define FVV_SUCCEEDED(x)              ((x) == FVV_RET_SUCCESS)

typedef uint8_t fvv_bool_t;

#define FVV_FALSE         0x00
#define FVV_TRUE          0x01

#define FVV_NULL          ((void *)0)

#define FVV_BITS_PER_BYTE 0x08

#endif
