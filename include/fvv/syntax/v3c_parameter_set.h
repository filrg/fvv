#ifndef FVV_SYNTAX_V3C_PARAMETER_SET_H
#define FVV_SYNTAX_V3C_PARAMETER_SET_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.4.1 General V3C parameter set syntax
struct fvv_v3c_parameter_set_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_v3c_parameter_set_t *self);
  fvv_ret_t (*copy_from)(fvv_v3c_parameter_set_t *self,
                         fvv_v3c_parameter_set_t *other);

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_v3c_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_reserved_zero_8bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_atlas_count_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_extension_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_extension_8bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_extension_length_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_extension_data_byte);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_atlas_id, (0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_frame_width, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_frame_height, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_map_count_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_multiple_map_streams_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_auxiliary_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_occupancy_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_geometry_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_attribute_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_map_absolute_coding_enabled_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_v3c_parameter_set_t, vps_map_predictor_index_diff, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_parameter_set_t, ptl, fvv_profile_tier_level_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_parameter_set_t, oi, fvv_occupancy_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_parameter_set_t, gi, fvv_geometry_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_parameter_set_t, ai, fvv_attribute_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_parameter_set_t, ba, fvv_byte_alignment_t);
};

fvv_ret_t fvv_v3c_parameter_set_init(fvv_v3c_parameter_set_t *self,
                                     fvv_v3c_unit_t          *vu,
                                     fvv_bitstream_t         *data);
fvv_ret_t
          fvv_v3c_parameter_set_destroy(fvv_v3c_parameter_set_t *self);

fvv_ret_t fvv_v3c_parameter_set_pack(fvv_v3c_parameter_set_t *self);
fvv_ret_t
fvv_v3c_parameter_set_copy_from(fvv_v3c_parameter_set_t *self,
                                fvv_v3c_parameter_set_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_v3c_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_reserved_zero_8bits);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_atlas_count_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_extension_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_extension_8bits);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_extension_length_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_parameter_set_t, vps_extension_data_byte);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_atlas_id, (0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_frame_width, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_frame_height, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_map_count_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_multiple_map_streams_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_auxiliary_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_occupancy_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_geometry_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_attribute_video_present_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_map_absolute_coding_enabled_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_v3c_parameter_set_t, vps_map_predictor_index_diff, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_parameter_set_t, ptl, fvv_profile_tier_level_t);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_parameter_set_t, oi, fvv_occupancy_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_parameter_set_t, gi, fvv_geometry_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_parameter_set_t, ai, fvv_attribute_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_parameter_set_t, ba, fvv_byte_alignment_t);

#endif // FVV_SYNTAX_V3C_PARAMETER_SET_H