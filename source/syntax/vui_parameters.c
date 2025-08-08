#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/coordinate_system_parameters.h>
#include <fvv/syntax/hrd_parameters.h>
#include <fvv/syntax/max_coded_video_resolution.h>
#include <fvv/syntax/vui_parameters.h>
// G.2.1 VUI parameters syntax
fvv_ret_t
fvv_vui_parameters_init(fvv_vui_parameters_t                    *self,
                        fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                        fvv_bitstream_t                         *data)
{
  *self           = (fvv_vui_parameters_t){0};
  self->data      = data;
  self->asps      = asps;
  self->pack      = fvv_vui_parameters_pack;
  self->copy_from = fvv_vui_parameters_copy_from;

  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_timing_info_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, vui_num_units_in_tick);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, vui_time_scale);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_poc_proportional_to_timing_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_num_ticks_poc_diff_one_minus1);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_hrd_parameters_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_tile_restrictions_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_fixed_atlas_tile_structure_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_fixed_video_tile_structure_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_constrained_tiles_across_v3c_components_idc);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_max_num_tiles_per_atlas_minus1);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_max_coded_video_resolution_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_coordinate_system_parameters_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, vui_unit_in_metres_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_display_box_info_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t,
                     vui_anchor_point_present_flag);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, vui_display_box_origin, 3);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, vui_display_box_size, 3);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, vui_anchor_point, 3);
  FVV_SET_SETTER_PTR(fvv_vui_parameters_t, hp, fvv_hrd_parameters_t);
  FVV_SET_SETTER_PTR(
      fvv_vui_parameters_t, mcvr, fvv_max_coded_video_resolution_t);
  FVV_SET_SETTER_PTR(
      fvv_vui_parameters_t, csp, fvv_coordinate_system_parameters_t);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_vui_parameters_destroy(fvv_vui_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_vui_parameters_t, hp, fvv_hrd_parameters_t);
  FVV_DESTROY_OBJ(
      fvv_vui_parameters_t, mcvr, fvv_max_coded_video_resolution_t);
  FVV_DESTROY_OBJ(
      fvv_vui_parameters_t, csp, fvv_coordinate_system_parameters_t);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_vui_parameters_pack(fvv_vui_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         d    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->vui_timing_info_present_flag,
                   FVV_BIT_VUI_TIMING_INFO_PRESENT_FLAG,
                   FVV_DESCRIPTOR_VUI_TIMING_INFO_PRESENT_FLAG);
  if (self->vui_timing_info_present_flag)
  {
    buff->write_bits(buff,
                     self->vui_num_units_in_tick,
                     FVV_BIT_VUI_NUM_UNITS_IN_TICK,
                     FVV_DESCRIPTOR_VUI_NUM_UNITS_IN_TICK);
    buff->write_bits(buff,
                     self->vui_time_scale,
                     FVV_BIT_VUI_TIME_SCALE,
                     FVV_DESCRIPTOR_VUI_TIME_SCALE);
    buff->write_bits(
        buff,
        self->vui_poc_proportional_to_timing_flag,
        FVV_BIT_VUI_POC_PROPORTIONAL_TO_TIMING_FLAG,
        FVV_DESCRIPTOR_VUI_POC_PROPORTIONAL_TO_TIMING_FLAG);
    if (self->vui_poc_proportional_to_timing_flag)
      buff->write_bits(
          buff,
          self->vui_num_ticks_poc_diff_one_minus1,
          FVV_BIT_VUI_NUM_TICKS_POC_DIFF_ONE_MINUS1,
          FVV_DESCRIPTOR_VUI_NUM_TICKS_POC_DIFF_ONE_MINUS1);
    buff->write_bits(buff,
                     self->vui_hrd_parameters_present_flag,
                     FVV_BIT_VUI_HRD_PARAMETERS_PRESENT_FLAG,
                     FVV_DESCRIPTOR_VUI_HRD_PARAMETERS_PRESENT_FLAG);
    if (self->vui_hrd_parameters_present_flag)
      self->hp->pack(self->hp, 0);
  }
  buff->write_bits(buff,
                   self->vui_tile_restrictions_present_flag,
                   FVV_BIT_VUI_TILE_RESTRICTIONS_PRESENT_FLAG,
                   FVV_DESCRIPTOR_VUI_TILE_RESTRICTIONS_PRESENT_FLAG);
  if (self->vui_tile_restrictions_present_flag)
  {
    buff->write_bits(
        buff,
        self->vui_fixed_atlas_tile_structure_flag,
        FVV_BIT_VUI_FIXED_ATLAS_TILE_STRUCTURE_FLAG,
        FVV_DESCRIPTOR_VUI_FIXED_ATLAS_TILE_STRUCTURE_FLAG);
    buff->write_bits(
        buff,
        self->vui_fixed_video_tile_structure_flag,
        FVV_BIT_VUI_FIXED_VIDEO_TILE_STRUCTURE_FLAG,
        FVV_DESCRIPTOR_VUI_FIXED_VIDEO_TILE_STRUCTURE_FLAG);
    buff->write_bits(
        buff,
        self->vui_constrained_tiles_across_v3c_components_idc,
        FVV_BIT_VUI_CONSTRAINED_TILES_ACROSS_V3C_COMPONENTS_IDC,
        FVV_DESCRIPTOR_VUI_CONSTRAINED_TILES_ACROSS_V3C_COMPONENTS_IDC);
    buff->write_bits(
        buff,
        self->vui_max_num_tiles_per_atlas_minus1,
        FVV_BIT_VUI_MAX_NUM_TILES_PER_ATLAS_MINUS1,
        FVV_DESCRIPTOR_VUI_MAX_NUM_TILES_PER_ATLAS_MINUS1);
  }
  buff->write_bits(
      buff,
      self->vui_max_coded_video_resolution_present_flag,
      FVV_BIT_VUI_MAX_CODED_VIDEO_RESOLUTION_PRESENT_FLAG,
      FVV_DESCRIPTOR_VUI_MAX_CODED_VIDEO_RESOLUTION_PRESENT_FLAG);
  if (self->vui_max_coded_video_resolution_present_flag)
    self->mcvr->pack(self->mcvr);
  buff->write_bits(
      buff,
      self->vui_coordinate_system_parameters_present_flag,
      FVV_BIT_VUI_COORDINATE_SYSTEM_PARAMETERS_PRESENT_FLAG,
      FVV_DESCRIPTOR_VUI_COORDINATE_SYSTEM_PARAMETERS_PRESENT_FLAG);
  if (self->vui_coordinate_system_parameters_present_flag)
    self->csp->pack(self->csp);
  buff->write_bits(buff,
                   self->vui_unit_in_metres_flag,
                   FVV_BIT_VUI_UNIT_IN_METRES_FLAG,
                   FVV_DESCRIPTOR_VUI_UNIT_IN_METRES_FLAG);
  buff->write_bits(buff,
                   self->vui_display_box_info_present_flag,
                   FVV_BIT_VUI_DISPLAY_BOX_INFO_PRESENT_FLAG,
                   FVV_DESCRIPTOR_VUI_DISPLAY_BOX_INFO_PRESENT_FLAG);
  if (self->vui_display_box_info_present_flag)
  {
    for (d = 0; d < 3; d++)
    {
      buff->write_bits(buff,
                       self->vui_display_box_origin[d],
                       self->asps->asps_geometry_3d_bit_depth_minus1 +
                           1,
                       FVV_DESCRIPTOR_VUI_DISPLAY_BOX_ORIGIN);
      buff->write_bits(buff,
                       self->vui_display_box_size[d],
                       self->asps->asps_geometry_3d_bit_depth_minus1 +
                           1,
                       FVV_DESCRIPTOR_VUI_DISPLAY_BOX_SIZE);
    }
  }
  buff->write_bits(buff,
                   self->vui_anchor_point_present_flag,
                   FVV_BIT_VUI_ANCHOR_POINT_PRESENT_FLAG,
                   FVV_DESCRIPTOR_VUI_ANCHOR_POINT_PRESENT_FLAG);
  if (self->vui_anchor_point_present_flag)
    for (d = 0; d < 3; d++)
      buff->write_bits(buff,
                       self->vui_anchor_point[d],
                       self->asps->asps_geometry_3d_bit_depth_minus1 +
                           1,
                       FVV_DESCRIPTOR_VUI_ANCHOR_POINT);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_vui_parameters_copy_from(fvv_vui_parameters_t *self,
                                       fvv_vui_parameters_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_vui_timing_info_present_flag(
      self, other->vui_timing_info_present_flag);
  self->set_vui_num_units_in_tick(self, other->vui_num_units_in_tick);
  self->set_vui_time_scale(self, other->vui_time_scale);
  self->set_vui_poc_proportional_to_timing_flag(
      self, other->vui_poc_proportional_to_timing_flag);
  self->set_vui_num_ticks_poc_diff_one_minus1(
      self, other->vui_num_ticks_poc_diff_one_minus1);
  self->set_vui_hrd_parameters_present_flag(
      self, other->vui_hrd_parameters_present_flag);
  self->set_vui_tile_restrictions_present_flag(
      self, other->vui_tile_restrictions_present_flag);
  self->set_vui_fixed_atlas_tile_structure_flag(
      self, other->vui_fixed_atlas_tile_structure_flag);
  self->set_vui_fixed_video_tile_structure_flag(
      self, other->vui_fixed_video_tile_structure_flag);
  self->set_vui_constrained_tiles_across_v3c_components_idc(
      self, other->vui_constrained_tiles_across_v3c_components_idc);
  self->set_vui_max_num_tiles_per_atlas_minus1(
      self, other->vui_max_num_tiles_per_atlas_minus1);
  self->set_vui_max_coded_video_resolution_present_flag(
      self, other->vui_max_coded_video_resolution_present_flag);
  self->set_vui_coordinate_system_parameters_present_flag(
      self, other->vui_coordinate_system_parameters_present_flag);
  self->set_vui_unit_in_metres_flag(self,
                                    other->vui_unit_in_metres_flag);
  self->set_vui_display_box_info_present_flag(
      self, other->vui_display_box_info_present_flag);
  self->set_vui_anchor_point_present_flag(
      self, other->vui_anchor_point_present_flag);
  self->set_vui_display_box_origin(self,
                                   other->vui_display_box_origin);
  self->set_vui_display_box_size(self, other->vui_display_box_size);
  self->set_vui_anchor_point(self, other->vui_anchor_point);
  self->set_hp(self, other->hp);
  self->set_mcvr(self, other->mcvr);
  self->set_csp(self, other->csp);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_timing_info_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t, vui_num_units_in_tick);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t, vui_time_scale);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_poc_proportional_to_timing_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_num_ticks_poc_diff_one_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_hrd_parameters_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_tile_restrictions_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_fixed_atlas_tile_structure_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_fixed_video_tile_structure_flag);
FVV_DEFINE_SCALAR_SETTER(
    fvv_vui_parameters_t,
    vui_constrained_tiles_across_v3c_components_idc);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_max_num_tiles_per_atlas_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_max_coded_video_resolution_present_flag);
FVV_DEFINE_SCALAR_SETTER(
    fvv_vui_parameters_t,
    vui_coordinate_system_parameters_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_unit_in_metres_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_display_box_info_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_vui_parameters_t,
                         vui_anchor_point_present_flag);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_vui_parameters_t,
                                vui_display_box_origin,
                                3);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_vui_parameters_t,
                                vui_display_box_size,
                                3);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_vui_parameters_t,
                                vui_anchor_point,
                                3);
FVV_DEFINE_OBJ_SETTER(fvv_vui_parameters_t, hp, fvv_hrd_parameters_t);
FVV_DEFINE_OBJ_SETTER(fvv_vui_parameters_t,
                      mcvr,
                      fvv_max_coded_video_resolution_t);
FVV_DEFINE_OBJ_SETTER(fvv_vui_parameters_t,
                      csp,
                      fvv_coordinate_system_parameters_t);
