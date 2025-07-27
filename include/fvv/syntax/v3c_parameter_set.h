#ifndef FVV_SYNTAX_V3C_PARAMETER_SET_H
#define FVV_SYNTAX_V3C_PARAMETER_SET_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// typedef struct fvv_v3c_parameter_set_t  fvv_v3c_parameter_set_t;
// typedef struct fvv_profile_tier_level_t fvv_profile_tier_level_t;
// typedef struct fvv_occupancy_information_t
//     fvv_occupancy_information_t;
// typedef struct fvv_geometry_information_t fvv_geometry_information_t;
// typedef struct fvv_attribute_information_t
//                                     fvv_attribute_information_t;
// typedef struct fvv_byte_alignment_t fvv_byte_alignment_t;

// 8.3.4.1 General V3C parameter set syntax
struct fvv_v3c_parameter_set_t
{
  fvv_bitstream_t *data;

  uint64_t         vps_v3c_parameter_set_id; // u(4)
  uint64_t         vps_reserved_zero_8bits;  // u(8)
  uint64_t         vps_atlas_count_minus1;   // u(6)
  uint64_t vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) +
                        1];                               // u(6)
  uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID];  // ue(v)
  uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]; // ue(v)
  uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(4)
  uint64_t vps_multiple_map_streams_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_map_absolute_coding_enabled_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]; // u(1)
  uint64_t vps_map_predictor_index_diff
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]; // ue(v)
  uint64_t vps_auxiliary_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_occupancy_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_geometry_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_attribute_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID];                        // u(1)
  uint64_t                     vps_extension_present_flag;  // u(1)
  uint64_t                     vps_extension_8bits;         // u(8)
  uint64_t                     vps_extension_length_minus1; // ue(v)
  uint64_t                     vps_extension_data_byte;     // u(8)

  fvv_profile_tier_level_t    *ptl;
  fvv_occupancy_information_t *oi;
  fvv_geometry_information_t  *gi;
  fvv_attribute_information_t *ai;
  fvv_byte_alignment_t        *ba;

  fvv_ret_t (*pack)(fvv_v3c_parameter_set_t *self);
  fvv_ret_t (*copy_from)(fvv_v3c_parameter_set_t *self,
                         fvv_v3c_parameter_set_t *other);
  fvv_ret_t (*set_vps_v3c_parameter_set_id)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_v3c_parameter_set_id);
  fvv_ret_t (*set_vps_reserved_zero_8bits)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_reserved_zero_8bits);
  fvv_ret_t (*set_vps_atlas_count_minus1)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_atlas_count_minus1);
  fvv_ret_t (*set_vps_atlas_id)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1]);
  fvv_ret_t (*set_vps_frame_width)(
      fvv_v3c_parameter_set_t *self,
      uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_frame_height)(
      fvv_v3c_parameter_set_t *self,
      uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_map_count_minus1)(
      fvv_v3c_parameter_set_t *self,
      uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_multiple_map_streams_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_multiple_map_streams_present_flag
          [0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_map_absolute_coding_enabled_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_map_absolute_coding_enabled_flag
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
  fvv_ret_t (*set_vps_map_predictor_index_diff)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_map_predictor_index_diff
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
  fvv_ret_t (*set_vps_auxiliary_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_auxiliary_video_present_flag[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_occupancy_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_occupancy_video_present_flag[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_geometry_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_geometry_video_present_flag[0x1
                                          << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_attribute_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_attribute_video_present_flag[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_extension_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_extension_present_flag);
  fvv_ret_t (*set_vps_extension_8bits)(fvv_v3c_parameter_set_t *self,
                                       uint64_t vps_extension_8bits);
  fvv_ret_t (*set_vps_extension_length_minus1)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_extension_length_minus1);
  fvv_ret_t (*set_vps_extension_data_byte)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_extension_data_byte);

  fvv_ret_t (*set_ptl)(fvv_v3c_parameter_set_t  *self,
                       fvv_profile_tier_level_t *ptl);
  fvv_ret_t (*set_oi)(fvv_v3c_parameter_set_t     *self,
                      fvv_occupancy_information_t *oi);
  fvv_ret_t (*set_gi)(fvv_v3c_parameter_set_t    *self,
                      fvv_geometry_information_t *gi);
  fvv_ret_t (*set_ai)(fvv_v3c_parameter_set_t     *self,
                      fvv_attribute_information_t *ai);
  fvv_ret_t (*set_ba)(fvv_v3c_parameter_set_t *self,
                      fvv_byte_alignment_t    *ba);
};

fvv_ret_t fvv_v3c_parameter_set_init(fvv_v3c_parameter_set_t *self,
                                     fvv_bitstream_t         *data);
fvv_ret_t
fvv_v3c_parameter_set_destroy(fvv_v3c_parameter_set_t *self);

fvv_ret_t fvv_v3c_parameter_set_pack(fvv_v3c_parameter_set_t *self);
fvv_ret_t
fvv_v3c_parameter_set_copy_from(fvv_v3c_parameter_set_t *self,
                                fvv_v3c_parameter_set_t *other);

fvv_ret_t fvv_v3c_parameter_set_set_vps_v3c_parameter_set_id(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_v3c_parameter_set_id);
fvv_ret_t fvv_v3c_parameter_set_set_vps_reserved_zero_8bits(
    fvv_v3c_parameter_set_t *self, uint64_t vps_reserved_zero_8bits);
fvv_ret_t fvv_v3c_parameter_set_set_vps_atlas_count_minus1(
    fvv_v3c_parameter_set_t *self, uint64_t vps_atlas_count_minus1);
fvv_ret_t fvv_v3c_parameter_set_set_vps_atlas_id(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_frame_width(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_frame_height(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_map_count_minus1(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_v3c_parameter_set_set_vps_multiple_map_streams_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_multiple_map_streams_present_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_v3c_parameter_set_set_vps_map_absolute_coding_enabled_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_map_absolute_coding_enabled_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_map_predictor_index_diff(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_map_predictor_index_diff
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_auxiliary_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_auxiliary_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_occupancy_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_occupancy_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_geometry_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_geometry_video_present_flag[0x1
                                        << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_attribute_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_attribute_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_extension_present_flag);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_8bits(
    fvv_v3c_parameter_set_t *self, uint64_t vps_extension_8bits);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_length_minus1(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_extension_length_minus1);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_data_byte(
    fvv_v3c_parameter_set_t *self, uint64_t vps_extension_data_byte);
fvv_ret_t
fvv_v3c_parameter_set_set_ptl(fvv_v3c_parameter_set_t  *self,
                              fvv_profile_tier_level_t *ptl);
fvv_ret_t
fvv_v3c_parameter_set_set_oi(fvv_v3c_parameter_set_t     *self,
                             fvv_occupancy_information_t *oi);
fvv_ret_t
fvv_v3c_parameter_set_set_gi(fvv_v3c_parameter_set_t    *self,
                             fvv_geometry_information_t *gi);
fvv_ret_t
          fvv_v3c_parameter_set_set_ai(fvv_v3c_parameter_set_t     *self,
                                       fvv_attribute_information_t *ai);
fvv_ret_t fvv_v3c_parameter_set_set_ba(fvv_v3c_parameter_set_t *self,
                                       fvv_byte_alignment_t    *ba);

#endif // FVV_SYNTAX_V3C_PARAMETER_SET_H