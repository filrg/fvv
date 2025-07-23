#ifndef FVV_SYNTAX_H
#define FVV_SYNTAX_H

#include <fvv/bitstream.h>
#include <fvv/defs.h>
#include <fvv/semantic.h>

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
typedef struct fvv_v3c_parameter_set_t  fvv_v3c_parameter_set_t;
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
typedef struct fvv_rbsp_trailing_bits_t fvv_rbsp_trailing_bits_t;
typedef struct fvv_atlas_tile_header_t  fvv_atlas_tile_header_t;
typedef struct fvv_ref_list_struct_t    fvv_ref_list_struct_t;

// 8.3.2 V3C unit syntax
// 8.3.2.1 General V3C unit syntax
struct fvv_v3c_unit_t
{
  fvv_bitstream_t        *data;

  fvv_v3c_unit_header_t  *vuh;
  fvv_v3c_unit_payload_t *vup;

  fvv_ret_t (*pack)(fvv_v3c_unit_t *self,
                    uint64_t        numBytesInV3CUnit);
};

fvv_ret_t fvv_v3c_unit_init(fvv_v3c_unit_t  *self,
                            fvv_bitstream_t *data);
fvv_ret_t fvv_v3c_unit_destroy(fvv_v3c_unit_t *self);

fvv_ret_t fvv_v3c_unit_pack(fvv_v3c_unit_t *self,
                            uint64_t        numBytesInV3CUnit);

// 8.3.2.2 V3C unit header syntax
struct fvv_v3c_unit_header_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  uint32_t         vuh_unit_type;                 // u(5)
  uint32_t         vuh_v3c_parameter_set_id;      // u(4)
  uint32_t         vuh_atlas_id;                  // u(6)
  uint32_t         vuh_attribute_index;           // u(7)
  uint32_t         vuh_attribute_partition_index; // u(5)
  uint32_t         vuh_map_index;                 // u(4)
  uint32_t         vuh_auxiliary_video_flag;      // u(1)
  uint32_t         vuh_reserved_zero_12bits;      // u(12)
  uint32_t         vuh_reserved_zero_17bits;      // u(17)
  uint32_t         vuh_reserved_zero_27bits;      // u(27)

  fvv_ret_t (*pack)(fvv_v3c_unit_header_t *self);
};

fvv_ret_t fvv_v3c_unit_header_init(fvv_v3c_unit_header_t *self,
                                   fvv_v3c_unit_t        *vu,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_v3c_unit_header_destroy(fvv_v3c_unit_header_t *self);

fvv_ret_t fvv_v3c_unit_header_pack(fvv_v3c_unit_header_t *self);

// 8.3.2.3 V3C unit payload syntax
struct fvv_v3c_unit_payload_t
{
  fvv_v3c_unit_t            *vu;
  fvv_bitstream_t           *data;

  fvv_v3c_parameter_set_t   *vps;
  fvv_atlas_sub_bitstream_t *asb;
  fvv_video_sub_bitstream_t *vsb;

  fvv_ret_t (*pack)(fvv_v3c_unit_payload_t *self,
                    uint64_t                numBytesInV3CPayload);
};

fvv_ret_t fvv_v3c_unit_payload_init(fvv_v3c_unit_payload_t *self,
                                    fvv_v3c_unit_t         *vu,
                                    fvv_bitstream_t        *data);
fvv_ret_t fvv_v3c_unit_payload_destroy(fvv_v3c_unit_payload_t *self);

fvv_ret_t fvv_v3c_unit_payload_pack(fvv_v3c_unit_payload_t *self,
                                    uint64_t numBytesInV3CPayload);

// 8.3.2.4 Atlas sub-bitstream syntax
struct fvv_atlas_sub_bitstream_t
{
  fvv_v3c_unit_t                 *vu;
  fvv_bitstream_t                *data;

  fvv_sample_stream_nal_header_t *ssnh;
  fvv_sample_stream_nal_unit_t   *ssnu;

  fvv_ret_t (*pack)(fvv_atlas_sub_bitstream_t *self,
                    uint64_t                   numBytes);
};

fvv_ret_t
fvv_atlas_sub_bitstream_init(fvv_atlas_sub_bitstream_t *self,
                             fvv_v3c_unit_t            *vu,
                             fvv_bitstream_t           *data);
fvv_ret_t
fvv_atlas_sub_bitstream_destroy(fvv_atlas_sub_bitstream_t *self);

fvv_ret_t
fvv_atlas_sub_bitstream_pack(fvv_atlas_sub_bitstream_t *self,
                             uint64_t                   numBytes);

// D.2 Sample stream NAL unit
// D.2.1 Sample stream NAL header syntax
struct fvv_sample_stream_nal_header_t
{
  fvv_bitstream_t *data;
  fvv_v3c_unit_t  *vu;

  uint32_t         ssnh_unit_size_precision_bytes_minus1; // u(3)
  uint32_t         ssnh_reserved_zero_5bits;              // u(5)

  fvv_ret_t (*pack)(fvv_sample_stream_nal_header_t *self);
};
fvv_ret_t fvv_sample_stream_nal_header_init(
    fvv_sample_stream_nal_header_t *self,
    fvv_v3c_unit_t                 *vu,
    fvv_bitstream_t                *data);
fvv_ret_t fvv_sample_stream_nal_header_destroy(
    fvv_sample_stream_nal_header_t *self);

fvv_ret_t fvv_sample_stream_nal_header_pack(
    fvv_sample_stream_nal_header_t *self);

// D.2.2 Sample stream NAL unit syntax
struct fvv_sample_stream_nal_unit_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  uint32_t         ssnu_nal_unit_size; // u(v)

  fvv_nal_unit_t  *nu;

  fvv_ret_t (*pack)(fvv_sample_stream_nal_unit_t *self);
};
fvv_ret_t
fvv_sample_stream_nal_unit_init(fvv_sample_stream_nal_unit_t *self,
                                fvv_v3c_unit_t               *vu,
                                fvv_bitstream_t              *data);
fvv_ret_t fvv_sample_stream_nal_unit_destroy(
    fvv_sample_stream_nal_unit_t *self);

fvv_ret_t
fvv_sample_stream_nal_unit_pack(fvv_sample_stream_nal_unit_t *self);

// 8.3.3 Byte alignment syntax
struct fvv_byte_alignment_t
{
  uint32_t         alignment_bit_equal_to_one;  // f(1)
  uint32_t         alignment_bit_equal_to_zero; // f(1)

  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_byte_alignment_t *self);
};

fvv_ret_t fvv_byte_alignment_init(fvv_byte_alignment_t *self,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_byte_alignment_destroy(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_pack(fvv_byte_alignment_t *self);

// 8.3.4 V3C parameter set syntax
// 8.3.4.1 General V3C parameter set syntax
struct fvv_v3c_parameter_set_t
{
  fvv_bitstream_t *data;

  uint32_t         vps_v3c_parameter_set_id; // u(4)
  uint32_t         vps_reserved_zero_8bits;  // u(8)
  uint32_t         vps_atlas_count_minus1;   // u(6)
  uint32_t vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) +
                        1];                               // u(6)
  uint32_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID];  // ue(v)
  uint32_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]; // ue(v)
  uint32_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(4)
  uint32_t vps_multiple_map_streams_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint32_t vps_map_absolute_coding_enabled_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]; // u(1)
  uint32_t vps_map_predictor_index_diff
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]; // ue(v)
  uint32_t vps_auxiliary_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint32_t vps_occupancy_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint32_t vps_geometry_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint32_t vps_attribute_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID];                        // u(1)
  uint32_t                     vps_extension_present_flag;  // u(1)
  uint32_t                     vps_extension_8bits;         // u(8)
  uint32_t                     vps_extension_length_minus1; // ue(v)
  uint32_t                     vps_extension_data_byte;     // u(8)

  fvv_profile_tier_level_t    *ptl;
  fvv_occupancy_information_t *oi;
  fvv_geometry_information_t  *gi;
  fvv_attribute_information_t *ai;
  fvv_byte_alignment_t        *ba;

  fvv_ret_t (*pack)(fvv_v3c_parameter_set_t *self);
};

fvv_ret_t fvv_v3c_parameter_set_init(fvv_v3c_parameter_set_t *self,
                                     fvv_bitstream_t         *data);
fvv_ret_t
fvv_v3c_parameter_set_destroy(fvv_v3c_parameter_set_t *self);

fvv_ret_t fvv_v3c_parameter_set_pack(fvv_v3c_parameter_set_t *self);

// 8.3.4.2 Profile, tier, and level syntax
struct fvv_profile_tier_level_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint32_t                 ptl_tier_flag;                  // u(1)
  uint32_t                 ptl_profile_codec_group_idc;    // u(7)
  uint32_t                 ptl_profile_toolset_idc;        // u(8)
  uint32_t                 ptl_profile_reconstruction_idc; // u(8)
  uint32_t                 ptl_reserved_zero_16bits;       // u(16)
  uint32_t                 ptl_reserved_0xffff_16bits;     // u(16)
  uint32_t                 ptl_level_idc;                  // u(8)
  uint32_t                 ptl_num_sub_profiles;           // u(6)
  uint32_t                 ptl_extended_sub_profile_flag;  // u(1)
  uint32_t
           ptl_sub_profile_idc[0x1
                          << FVV_BIT_PTL_NUM_SUB_PROFILES]; // u(v)
  uint32_t ptl_tool_constraints_present_flag; // u(1)

  fvv_profile_toolset_constraints_information_t *ptci;

  fvv_ret_t (*pack)(fvv_profile_tier_level_t *self);
};

fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t *data);
fvv_ret_t
fvv_profile_tier_level_destroy(fvv_profile_tier_level_t *self);

fvv_ret_t
fvv_profile_tier_level_pack(fvv_profile_tier_level_t *self);

// 8.3.4.3 Occupancy information syntax
struct fvv_occupancy_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint32_t
      oi_occupancy_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)
  uint32_t oi_lossy_occupancy_compression_threshold
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)
  uint32_t oi_occupancy_2d_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(5)
  uint32_t
      oi_occupancy_MSB_align_flag[0x1
                                  << FVV_BIT_VPS_ATLAS_ID]; // u(1)

  fvv_ret_t (*pack)(fvv_occupancy_information_t *self,
                    uint64_t                     atlasID);
} fvv_ret_t
fvv_occupancy_information_init(fvv_occupancy_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_occupancy_information_destroy(fvv_occupancy_information_t *self);
fvv_ret_t
fvv_occupancy_information_pack(fvv_occupancy_information_t *self,
                               uint64_t                     atlasID);

// 8.3.4.4 Geometry information syntax
struct fvv_geometry_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint32_t gi_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)
  uint32_t gi_geometry_2d_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(5)
  uint32_t
           gi_geometry_MSB_align_flag[0x1
                                 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint32_t gi_geometry_3d_coordinates_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(5)
  uint32_t gi_auxiliary_geometry_codec_id
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)

  fvv_ret_t (*pack)(fvv_geometry_information_t *self,
                    uint64_t                    atlasID);
};
fvv_ret_t
fvv_geometry_information_init(fvv_geometry_information_t *self,
                              fvv_v3c_parameter_set_t    *vps,
                              fvv_bitstream_t            *data);
fvv_ret_t
fvv_geometry_information_destroy(fvv_geometry_information_t *self);
fvv_ret_t
fvv_geometry_information_pack(fvv_geometry_information_t *self,
                              uint64_t                    atlasID);

// 8.3.4.5 Attribute information syntax
struct fvv_attribute_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint32_t ai_attribute_count[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(7)
  uint32_t
      ai_attribute_type_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                          [0x1
                           << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(4)
  uint32_t
      ai_attribute_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                           [0x1
                            << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(8)
  uint32_t ai_auxiliary_attribute_codec_id
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(8)
  uint32_t ai_attribute_map_absolute_coding_persistence_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(1)
  uint32_t ai_attribute_dimension_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(6)
  uint32_t ai_attribute_dimension_partitions_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(6)
  uint32_t ai_attribute_partition_channels_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]
      [0x1
       << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1]; // ue(v)
  uint32_t ai_attribute_2d_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(5)
  uint32_t ai_attribute_MSB_align_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(1)

  fvv_ret_t (*pack)(fvv_attribute_information_t *self,
                    uint64_t                     atlasID);
};
fvv_ret_t
fvv_attribute_information_init(fvv_attribute_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_attribute_information_destroy(fvv_attribute_information_t *self);

fvv_ret_t
fvv_attribute_information_pack(fvv_attribute_information_t *self,
                               uint64_t                     atlasID);

// 8.3.4.6 Profile toolset constraints information syntax
struct fvv_profile_toolset_constraints_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint32_t                 ptc_one_v3c_frame_only_flag;      // u(1)
  uint32_t                 ptc_eom_constraint_flag;          // u(1)
  uint32_t                 ptc_max_map_count_minus1;         // u(4)
  uint32_t                 ptc_max_atlas_count_minus1;       // u(4)
  uint32_t ptc_multiple_map_streams_constraint_flag;         // u(1)
  uint32_t ptc_plr_constraint_flag;                          // u(1)
  uint32_t ptc_attribute_max_dimension_minus1;               // u(6)
  uint32_t ptc_attribute_max_dimension_partitions_minus1;    // u(6)
  uint32_t ptc_no_eight_orientations_constraint_flag;        // u(1)
  uint32_t ptc_no_45degree_projection_patch_constraint_flag; // u(1)
  uint32_t ptc_reserved_zero_6bits;                          // u(6)
  uint32_t ptc_num_reserved_constraint_bytes;                // u(8)
  uint32_t ptc_reserved_constraint_byte
      [0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES]; // u(8)

  fvv_ret_t (*pack)(
      fvv_profile_toolset_constraints_information_t *self);
};
fvv_ret_t fvv_profile_toolset_constraints_information_init(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_v3c_parameter_set_t                       *vps,
    fvv_bitstream_t                               *data);
fvv_ret_t fvv_profile_toolset_constraints_information_destroy(
    fvv_profile_toolset_constraints_information_t *self);
fvv_ret_t fvv_profile_toolset_constraints_information_pack(
    fvv_profile_toolset_constraints_information_t *self);

// 8.3.5 NAL unit syntax
// 8.3.5.1 General NAL unit syntax
struct fvv_nal_unit_t
{
  uint32_t              *rbsp_byte;
  uint64_t               rbsp_size;
  fvv_nal_unit_header_t *nuh;

  fvv_bitstream_t       *data;

  fvv_ret_t (*pack)(fvv_nal_unit_t *self,
                    uint64_t        NumBytesInNalUnit);
};

fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t  *self,
                            fvv_bitstream_t *data,
                            uint64_t         rbsp_size);
fvv_ret_t fvv_nal_unit_destroy(fvv_nal_unit_t *self);

fvv_ret_t fvv_nal_unit_pack(fvv_nal_unit_t *self,
                            uint64_t        NumBytesInNalUnit);

// 8.3.5.2 NAL unit header syntax
struct fvv_nal_unit_header_t
{
  uint32_t         nal_forbidden_zero_bit;
  uint32_t         nal_unit_type;
  uint32_t         nal_layer_id;
  uint32_t         nal_temporal_id_plus1;

  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_nal_unit_header_t *self);
}

fvv_ret_t
          fvv_nal_unit_header_init(fvv_nal_unit_header_t *self,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_nal_unit_header_destroy(fvv_nal_unit_header_t *self);
fvv_ret_t fvv_nal_unit_header_pack(fvv_nal_unit_header_t *self);

// 8.3.6 Raw byte sequence payloads, trailing bits, and byte
// alignment syntax 8.3.6.1 Atlas sequence parameter set RBSP syntax
// 8.3.6.1.1 General atlas sequence parameter set RBSP syntax
struct fvv_atlas_sequence_parameter_set_rbsp_t
{
asps_atlas_sequence_parameter_set_id
asps_frame_width
asps_frame_height
asps_geometry_3d_bit_depth_minus1
asps_geometry_2d_bit_depth_minus1
asps_log2_max_atlas_frame_order_cnt_lsb_minus4
asps_max_dec_atlas_frame_buffering_minus1
asps_long_term_ref_atlas_frames_flag
asps_num_ref_atlas_frame_lists_in_asps
asps_use_eight_orientations_flag
asps_extended_projection_enabled_flag
asps_max_number_projections_minus1
asps_normal_axis_limits_quantization_enabled_flag
asps_normal_axis_max_delta_value_enabled_flag
asps_patch_precedence_order_flag
asps_log2_patch_packing_block_size
asps_patch_size_quantizer_present_flag
asps_map_count_minus1
asps_pixel_deinterleaving_enabled_flag
asps_raw_patch_enabled_flag
asps_eom_patch_enabled_flag
asps_eom_fix_bit_count_minus1
asps_auxiliary_video_enabled_flag
asps_plr_enabled_flag
asps_vui_parameters_present_flag
asps_extension_present_flag
asps_vpcc_extension_present_flag
asps_extension_7bits
asps_extension_data_flag
ref_list_struct()
asps_map_pixel_deinterleaving_flag[]
asps_plr_information()
vui_parameters( )
asps_vpcc_extension( ) /* Specified in Annex H*/
rbsp_trailing_bits( )
};
#endif
