#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/inter_patch_data_unit.h>
// 8.3.7.6 Inter patch data unit syntax
// {
fvv_ret_t fvv_inter_patch_data_unit_init(fvv_inter_patch_data_unit_t *self, fvv_atlas_sequence_parameter_set_rbsp_t *aspsr, fvv_bitstream_t *data)
{
  *self           = (fvv_inter_patch_data_unit_t){0};
  self->data      = data;
  self->aspsr     = aspsr;
  self->pack      = fvv_inter_patch_data_unit_pack;
  self->copy_from = fvv_inter_patch_data_unit_copy_from;

  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_ref_index);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_patch_index);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_pos_x);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_pos_y);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_x);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_y);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_u);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_v);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_d);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, ipdu_3d_range_d);
  FVV_SET_SETTER_PTR(fvv_inter_patch_data_unit_t, pd, fvv_plr_data_t);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_inter_patch_data_unit_destroy(fvv_inter_patch_data_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_ref_index);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_patch_index);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_2d_pos_x);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_2d_pos_y);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_x);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_y);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_u);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_v);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_3d_offset_d);
  FVV_DESTROY_2D_ARR(fvv_inter_patch_data_unit_t, ipdu_3d_range_d);
  FVV_DESTROY_OBJ(fvv_inter_patch_data_unit_t, pd, fvv_plr_data_t);
  *self = (fvv_inter_patch_data_unit_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_inter_patch_data_unit_pack(fvv_inter_patch_data_unit_t *self, uint64_t tileID, uint64_t patchIdx)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;
  if (NumRefIdxActive > 1)
  {
    buff->pad(buff, self->ipdu_ref_index[tileID][patchIdx], FVV_BIT_IPDU_REF_INDEX);
  }
  buff->pad(buff, self->ipdu_patch_index[tileID][patchIdx], FVV_BIT_IPDU_PATCH_INDEX);
  buff->pad(buff, self->ipdu_2d_pos_x[tileID][patchIdx], FVV_BIT_IPDU_2D_POS_X);
  buff->pad(buff, self->ipdu_2d_pos_y[tileID][patchIdx], FVV_BIT_IPDU_2D_POS_Y);
  buff->pad(buff, self->ipdu_2d_delta_size_x[tileID][patchIdx], FVV_BIT_IPDU_2D_DELTA_SIZE_X);
  buff->pad(buff, self->ipdu_2d_delta_size_y[tileID][patchIdx], FVV_BIT_IPDU_2D_DELTA_SIZE_Y);
  buff->pad(buff, self->ipdu_3d_offset_u[tileID][patchIdx], FVV_BIT_IPDU_3D_OFFSET_U);
  buff->pad(buff, self->ipdu_3d_offset_v[tileID][patchIdx], FVV_BIT_IPDU_3D_OFFSET_V);
  buff->pad(buff, self->ipdu_3d_offset_d[tileID][patchIdx], FVV_BIT_IPDU_3D_OFFSET_D);
  if (self->aspsr->asps_normal_axis_max_delta_value_enabled_flag)
  {
    buff->pad(buff, self->ipdu_3d_range_d[tileID][patchIdx], FVV_BIT_IPDU_3D_RANGE_D);
  }
  if (self->aspsr->asps_plr_enabled_flag)
  {
    self->pd->pack(self->pd, tileID, patchIdx);
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_inter_patch_data_unit_copy_from(fvv_inter_patch_data_unit_t *self, fvv_inter_patch_data_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ipdu_ref_index(self, other->ipdu_ref_index, other->ipdu_ref_index_size);
  self->set_ipdu_patch_index(self, other->ipdu_patch_index, other->ipdu_patch_index_size);
  self->set_ipdu_2d_pos_x(self, other->ipdu_2d_pos_x, other->ipdu_2d_pos_x_size);
  self->set_ipdu_2d_pos_y(self, other->ipdu_2d_pos_y, other->ipdu_2d_pos_y_size);
  self->set_ipdu_2d_delta_size_x(self, other->ipdu_2d_delta_size_x, other->ipdu_2d_delta_size_x_size);
  self->set_ipdu_2d_delta_size_y(self, other->ipdu_2d_delta_size_y, other->ipdu_2d_delta_size_y_size);
  self->set_ipdu_3d_offset_u(self, other->ipdu_3d_offset_u, other->ipdu_3d_offset_u_size);
  self->set_ipdu_3d_offset_v(self, other->ipdu_3d_offset_v, other->ipdu_3d_offset_v_size);
  self->set_ipdu_3d_offset_d(self, other->ipdu_3d_offset_d, other->ipdu_3d_offset_d_size);
  self->set_ipdu_3d_range_d(self, other->ipdu_3d_range_d, other->ipdu_3d_range_d_size);
  self->set_pd(self, other->pd);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_ref_index);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_patch_index);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_pos_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_pos_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_2d_delta_size_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_offset_u);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_offset_v);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_offset_d);
FVV_DEFINE_2D_ARR_SETTER(fvv_inter_patch_data_unit_t, ipdu_3d_range_d);
FVV_DEFINE_OBJ_SETTER(fvv_inter_patch_data_unit_t, pd, fvv_plr_data_t);
// }