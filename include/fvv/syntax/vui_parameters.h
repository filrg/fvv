#ifndef FVV_SYNTAX_VUI_PARAMETERS_H
#define FVV_SYNTAX_VUI_PARAMETERS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// G.2.1 VUI parameters syntax
struct fvv_vui_parameters_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *asps;
  fvv_bitstream_t                         *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_timing_info_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_num_units_in_tick);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t, vui_time_scale);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_poc_proportional_to_timing_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_num_ticks_poc_diff_one_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_hrd_parameters_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_tile_restrictions_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_fixed_atlas_tile_structure_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_fixed_video_tile_structure_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_vui_parameters_t,
      vui_constrained_tiles_across_v3c_components_idc);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_max_num_tiles_per_atlas_minus1);

  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_vui_parameters_t,
      vui_max_coded_video_resolution_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_vui_parameters_t,
      vui_coordinate_system_parameters_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_unit_in_metres_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_display_box_info_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_vui_parameters_t,
                                vui_anchor_point_present_flag);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_vui_parameters_t,
                                       vui_display_box_origin,
                                       3);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_vui_parameters_t,
                                       vui_display_box_size,
                                       3);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_vui_parameters_t,
                                       vui_anchor_point,
                                       3);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_vui_parameters_t,
                             hp,
                             fvv_hrd_parameters_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_vui_parameters_t,
                             mcvr,
                             fvv_max_coded_video_resolution_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_vui_parameters_t,
                             csp,
                             fvv_coordinate_system_parameters_t);

  fvv_ret_t (*pack)(fvv_vui_parameters_t *self);
  fvv_ret_t (*copy_from)(fvv_vui_parameters_t *self,
                         fvv_vui_parameters_t *other);
};

fvv_ret_t
          fvv_vui_parameters_init(fvv_vui_parameters_t                    *self,
                                  fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                                  fvv_bitstream_t *data);
fvv_ret_t fvv_vui_parameters_destroy(fvv_vui_parameters_t *self);
fvv_ret_t fvv_vui_parameters_pack(fvv_vui_parameters_t *self);
fvv_ret_t fvv_vui_parameters_copy_from(fvv_vui_parameters_t *self,
                                       fvv_vui_parameters_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_timing_info_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_num_units_in_tick);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t, vui_time_scale);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_poc_proportional_to_timing_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_num_ticks_poc_diff_one_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_hrd_parameters_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_tile_restrictions_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_fixed_atlas_tile_structure_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_fixed_video_tile_structure_flag);
FVV_DECLARE_SCALAR_SETTER(
    fvv_vui_parameters_t,
    vui_constrained_tiles_across_v3c_components_idc);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_max_num_tiles_per_atlas_minus1);
FVV_DECLARE_SCALAR_SETTER(
    fvv_vui_parameters_t,
    vui_max_coded_video_resolution_present_flag);
FVV_DECLARE_SCALAR_SETTER(
    fvv_vui_parameters_t,
    vui_coordinate_system_parameters_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_unit_in_metres_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_display_box_info_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_vui_parameters_t,
                          vui_anchor_point_present_flag);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_vui_parameters_t,
                                 vui_display_box_origin,
                                 3);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_vui_parameters_t,
                                 vui_display_box_size,
                                 3);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_vui_parameters_t,
                                 vui_anchor_point,
                                 3);
FVV_DECLARE_OBJ_SETTER(fvv_vui_parameters_t,
                       hp,
                       fvv_hrd_parameters_t);
FVV_DECLARE_OBJ_SETTER(fvv_vui_parameters_t,
                       mcvr,
                       fvv_max_coded_video_resolution_t);
FVV_DECLARE_OBJ_SETTER(fvv_vui_parameters_t,
                       csp,
                       fvv_coordinate_system_parameters_t);

#endif // FVV_SYNTAX_VUI_PARAMETERS_H
