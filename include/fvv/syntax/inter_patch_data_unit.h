#ifndef FVV_SYNTAX_INTER_PATCH_DATA_UNIT_H
#define FVV_SYNTAX_INTER_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.6 Inter patch data unit syntax
struct fvv_inter_patch_data_unit_t
{
  fvv_bitstream_t                         *data;
  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;

  fvv_ret_t (*pack)(fvv_inter_patch_data_unit_t *self, uint64_t tileID, uint64_t patchIdx);
  fvv_ret_t (*copy_from)(fvv_inter_patch_data_unit_t *self, fvv_inter_patch_data_unit_t *other);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_ref_index);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_patch_index);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_pos_x);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_pos_y);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_x);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_y);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_u);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_v);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_d);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_range_d);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_inter_patch_data_unit_t, pd, fvv_plr_data_t);
};
fvv_ret_t fvv_inter_patch_data_unit_init(fvv_inter_patch_data_unit_t *self, fvv_atlas_sequence_parameter_set_rbsp_t *aspsr, fvv_bitstream_t *data);
fvv_ret_t fvv_inter_patch_data_unit_destroy(fvv_inter_patch_data_unit_t *self);
fvv_ret_t fvv_inter_patch_data_unit_pack(fvv_inter_patch_data_unit_t *self, uint64_t tileID, uint64_t patchIdx);
fvv_ret_t fvv_inter_patch_data_unit_copy_from(fvv_inter_patch_data_unit_t *self, fvv_inter_patch_data_unit_t *other);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_ref_index);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_patch_index);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_pos_x);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_pos_y);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_x);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_y);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_offset_u);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_offset_v);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_offset_d);
FVV_DECLARE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_range_d);
FVV_DECLARE_OBJ_SETTER(fvv_inter_patch_data_unit_t, pd, fvv_plr_data_t);

#endif // FVV_SYNTAX_INTER_PATCH_DATA_UNIT_H
