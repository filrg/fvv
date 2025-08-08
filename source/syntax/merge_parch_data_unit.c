#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/merge_patch_data_unit.h>
#include <string.h>
// 8.3.7.5 Merge patch data unit syntax
// {
fvv_ret_t fvv_merge_patch_data_unit_init(
    fvv_merge_patch_data_unit_t             *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_merge_patch_data_unit_t){0};
  self->data      = data;
  self->asps     = asps;
  self->pack      = fvv_merge_patch_data_unit_pack;
  self->copy_from = fvv_merge_patch_data_unit_copy_from;

  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_ref_index);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t,
                     mpdu_override_2d_params_flag);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_2d_pos_x);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_2d_pos_y);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t,
                     mpdu_2d_delta_size_x);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t,
                     mpdu_2d_delta_size_y);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t,
                     mpdu_override_3d_params_flag);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_3d_offset_u);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_3d_offset_v);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_3d_offset_d);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, mpdu_3d_range_d);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t,
                     mpdu_override_plr_flag);
  FVV_SET_SETTER_PTR(fvv_merge_patch_data_unit_t, pd, fvv_plr_data_t);

  self->pd = (fvv_plr_data_t *)malloc(sizeof(fvv_plr_data_t));
  fvv_plr_data_init(self->pd, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_merge_patch_data_unit_destroy(fvv_merge_patch_data_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_ref_index);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t,
                     mpdu_override_2d_params_flag);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_2d_pos_x);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_2d_pos_y);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t,
                     mpdu_2d_delta_size_x);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t,
                     mpdu_2d_delta_size_y);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t,
                     mpdu_override_3d_params_flag);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_3d_offset_u);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_3d_offset_v);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_3d_offset_d);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t, mpdu_3d_range_d);
  FVV_DESTROY_2D_ARR(fvv_merge_patch_data_unit_t,
                     mpdu_override_plr_flag);
  FVV_DESTROY_OBJ(fvv_merge_patch_data_unit_t, pd, fvv_plr_data_t);
  *self = (fvv_merge_patch_data_unit_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_merge_patch_data_unit_pack(fvv_merge_patch_data_unit_t *self,
                               uint64_t                     tileID,
                               uint64_t                     patchIdx)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff            = FVV_NULL;
  uint64_t         OverridePlrFlag = 0;
  buff                             = self->data;

  if (NumRefIdxActive > 1)
  {
    buff->write_bits(buff,
                     self->mpdu_ref_index[tileID][patchIdx],
                     FVV_BIT_MPDU_REF_INDEX,
                     FVV_DESCRIPTOR_MPDU_REF_INDEX);
  }
  OverridePlrFlag = 0;
  buff->write_bits(
      buff,
      self->mpdu_override_2d_params_flag[tileID][patchIdx],
      FVV_BIT_MPDU_OVERRIDE_2D_PARAMS_FLAG,
      FVV_DESCRIPTOR_MPDU_OVERRIDE_2D_PARAMS_FLAG);
  if (self->mpdu_override_2d_params_flag[tileID][patchIdx])
  {
    buff->write_bits(buff,
                     self->mpdu_2d_pos_x[tileID][patchIdx],
                     FVV_BIT_MPDU_2D_POS_X,
                     FVV_DESCRIPTOR_MPDU_2D_POS_X);
    buff->write_bits(buff,
                     self->mpdu_2d_pos_y[tileID][patchIdx],
                     FVV_BIT_MPDU_2D_POS_Y,
                     FVV_DESCRIPTOR_MPDU_2D_POS_Y);
    buff->write_bits(buff,
                     self->mpdu_2d_delta_size_x[tileID][patchIdx],
                     FVV_BIT_MPDU_2D_DELTA_SIZE_X,
                     FVV_DESCRIPTOR_MPDU_2D_DELTA_SIZE_X);
    buff->write_bits(buff,
                     self->mpdu_2d_delta_size_y[tileID][patchIdx],
                     FVV_BIT_MPDU_2D_DELTA_SIZE_Y,
                     FVV_DESCRIPTOR_MPDU_2D_DELTA_SIZE_Y);
    if (self->asps->asps_plr_enabled_flag)
      OverridePlrFlag = 1;
  }
  else
  {
    buff->write_bits(
        buff,
        self->mpdu_override_3d_params_flag[tileID][patchIdx],
        FVV_BIT_MPDU_OVERRIDE_3D_PARAMS_FLAG,
        FVV_DESCRIPTOR_MPDU_OVERRIDE_3D_PARAMS_FLAG);
    if (self->mpdu_override_3d_params_flag[tileID][patchIdx])
    {
      buff->write_bits(buff,
                       self->mpdu_3d_offset_u[tileID][patchIdx],
                       FVV_BIT_MPDU_3D_OFFSET_U,
                       FVV_DESCRIPTOR_MPDU_3D_OFFSET_U);
      buff->write_bits(buff,
                       self->mpdu_3d_offset_v[tileID][patchIdx],
                       FVV_BIT_MPDU_3D_OFFSET_V,
                       FVV_DESCRIPTOR_MPDU_3D_OFFSET_V);
      buff->write_bits(buff,
                       self->mpdu_3d_offset_d[tileID][patchIdx],
                       FVV_BIT_MPDU_3D_OFFSET_D,
                       FVV_DESCRIPTOR_MPDU_3D_OFFSET_D);
      if (self->asps->asps_normal_axis_max_delta_value_enabled_flag)
        buff->write_bits(buff,
                         self->mpdu_3d_range_d[tileID][patchIdx],
                         FVV_BIT_MPDU_3D_RANGE_D,
                         FVV_DESCRIPTOR_MPDU_3D_RANGE_D);
      if (self->asps->asps_plr_enabled_flag)
      {
        buff->write_bits(
            buff,
            self->mpdu_override_plr_flag[tileID][patchIdx],
            FVV_BIT_MPDU_OVERRIDE_PLR_FLAG,
            FVV_DESCRIPTOR_MPDU_OVERRIDE_PLR_FLAG);
        OverridePlrFlag =
            self->mpdu_override_plr_flag[tileID][patchIdx];
      }
    }
  }
  if (OverridePlrFlag && self->asps->asps_plr_enabled_flag)
    self->pd->pack(self->pd, tileID, patchIdx);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_copy_from(
    fvv_merge_patch_data_unit_t *self,
    fvv_merge_patch_data_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_mpdu_ref_index(
      self, other->mpdu_ref_index, other->mpdu_ref_index_size);
  self->set_mpdu_override_2d_params_flag(
      self,
      other->mpdu_override_2d_params_flag,
      other->mpdu_override_2d_params_flag_size);
  self->set_mpdu_2d_pos_x(
      self, other->mpdu_2d_pos_x, other->mpdu_2d_pos_x_size);
  self->set_mpdu_2d_pos_y(
      self, other->mpdu_2d_pos_y, other->mpdu_2d_pos_y_size);
  self->set_mpdu_2d_delta_size_x(self,
                                 other->mpdu_2d_delta_size_x,
                                 other->mpdu_2d_delta_size_x_size);
  self->set_mpdu_2d_delta_size_y(self,
                                 other->mpdu_2d_delta_size_y,
                                 other->mpdu_2d_delta_size_y_size);
  self->set_mpdu_override_3d_params_flag(
      self,
      other->mpdu_override_3d_params_flag,
      other->mpdu_override_3d_params_flag_size);
  self->set_mpdu_3d_offset_u(
      self, other->mpdu_3d_offset_u, other->mpdu_3d_offset_u_size);
  self->set_mpdu_3d_offset_v(
      self, other->mpdu_3d_offset_v, other->mpdu_3d_offset_v_size);
  self->set_mpdu_3d_offset_d(
      self, other->mpdu_3d_offset_d, other->mpdu_3d_offset_d_size);
  self->set_mpdu_3d_range_d(
      self, other->mpdu_3d_range_d, other->mpdu_3d_range_d_size);
  self->set_mpdu_override_plr_flag(
      self,
      other->mpdu_override_plr_flag,
      other->mpdu_override_plr_flag_size);
  self->set_pd(self, other->pd);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t, mpdu_ref_index);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_override_2d_params_flag);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t, mpdu_2d_pos_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t, mpdu_2d_pos_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_2d_delta_size_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_2d_delta_size_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_override_3d_params_flag);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_3d_offset_u);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_3d_offset_v);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_3d_offset_d);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_3d_range_d);
FVV_DEFINE_2D_ARR_SETTER(fvv_merge_patch_data_unit_t,
                         mpdu_override_plr_flag);
FVV_DEFINE_OBJ_SETTER(fvv_merge_patch_data_unit_t,
                      pd,
                      fvv_plr_data_t);
// }