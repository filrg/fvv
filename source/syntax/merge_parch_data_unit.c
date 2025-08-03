#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/merge_patch_data_unit.h>
#include <string.h>
// 8.3.7.5 Merge patch data unit syntax
// {
fvv_ret_t fvv_merge_patch_data_unit_init(
    fvv_merge_patch_data_unit_t             *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_merge_patch_data_unit_t){0};
  self->data      = data;
  self->aspsr     = aspsr;
  self->pack      = fvv_merge_patch_data_unit_pack;
  self->copy_from = fvv_merge_patch_data_unit_copy_from;

  self->set_mpdu_ref_index =
      fvv_merge_patch_data_unit_set_mpdu_ref_index;
  self->set_mpdu_override_2d_params_flag =
      fvv_merge_patch_data_unit_set_mpdu_override_2d_params_flag;
  self->set_mpdu_2d_pos_x =
      fvv_merge_patch_data_unit_set_mpdu_2d_pos_x;
  self->set_mpdu_2d_pos_y =
      fvv_merge_patch_data_unit_set_mpdu_2d_pos_y;
  self->set_mpdu_2d_delta_size_x =
      fvv_merge_patch_data_unit_set_mpdu_2d_delta_size_x;
  self->set_mpdu_2d_delta_size_y =
      fvv_merge_patch_data_unit_set_mpdu_2d_delta_size_y;
  self->set_mpdu_override_3d_params_flag =
      fvv_merge_patch_data_unit_set_mpdu_override_3d_params_flag;
  self->set_mpdu_3d_offset_u =
      fvv_merge_patch_data_unit_set_mpdu_3d_offset_u;
  self->set_mpdu_3d_offset_v =
      fvv_merge_patch_data_unit_set_mpdu_3d_offset_v;
  self->set_mpdu_3d_offset_d =
      fvv_merge_patch_data_unit_set_mpdu_3d_offset_d;
  self->set_mpdu_3d_range_d =
      fvv_merge_patch_data_unit_set_mpdu_3d_range_d;
  self->set_mpdu_override_plr_flag =
      fvv_merge_patch_data_unit_set_mpdu_override_plr_flag;
  self->set_pd = fvv_merge_patch_data_unit_set_pd;

  self->pd     = (fvv_plr_data_t *)malloc(sizeof(fvv_plr_data_t));
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
  if (self->pd)
  {
    fvv_plr_data_destroy(self->pd);
    free(self->pd);
  }
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
    buff->pad(buff,
              self->mpdu_ref_index[tileID][patchIdx],
              FVV_BIT_MPDU_REF_INDEX);
  }
  OverridePlrFlag = 0;
  buff->pad(buff,
            self->mpdu_override_2d_params_flag[tileID][patchIdx],
            FVV_BIT_MPDU_OVERRIDE_2D_PARAMS_FLAG);
  if (mpdu_override_2d_params_flag[tileID][patchIdx])
  {
    buff->pad(buff,
              self->mpdu_2d_pos_x[tileID][patchIdx],
              FVV_BIT_MPDU_2D_POS_X);
    buff->pad(buff,
              self->mpdu_2d_pos_y[tileID][patchIdx],
              FVV_BIT_MPDU_2D_POS_Y);
    buff->pad(buff,
              self->mpdu_2d_delta_size_x[tileID][patchIdx],
              FVV_BIT_MPDU_2D_DELTA_SIZE_X);
    buff->pad(buff,
              self->mpdu_2d_delta_size_y[tileID][patchIdx],
              FVV_BIT_MPDU_2D_DELTA_SIZE_Y);
    if (self->aspsr->asps_plr_enabled_flag)
      OverridePlrFlag = 1;
  }
  else
  {
    buff->pad(buff,
              self->mpdu_override_3d_params_flag[tileID][patchIdx],
              FVV_BIT_MPDU_OVERRIDE_3D_PARAMS_FLAG);
    if (self->mpdu_override_3d_params_flag[tileID][patchIdx])
    {
      buff->pad(buff,
                self->mpdu_3d_offset_u[tileID][patchIdx],
                FVV_BIT_MPDU_3D_OFFSET_U);
      buff->pad(buff,
                self->mpdu_3d_offset_v[tileID][patchIdx],
                FVV_BIT_MPDU_3D_OFFSET_V);
      buff->pad(buff,
                self->mpdu_3d_offset_d[tileID][patchIdx],
                FVV_BIT_MPDU_3D_OFFSET_D);
      if (self->aspsr->asps_normal_axis_max_delta_value_enabled_flag)
        buff->pad(buff,
                  self->mpdu_3d_range_d[tileID][patchIdx],
                  FVV_BIT_MPDU_3D_RANGE_D);
      if (self->aspsr->asps_plr_enabled_flag)
      {
        buff->pad(buff,
                  self->mpdu_override_plr_flag[tileID][patchIdx],
                  FVV_BIT_MPDU_OVERRIDE_PLR_FLAG);
        OverridePlrFlag =
            self->mpdu_override_plr_flag[tileID][patchIdx];
      }
    }
  }
  if (OverridePlrFlag && self->aspsr->asps_plr_enabled_flag)
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

fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_ref_index(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_ref_index,
    uint64_t                     mpdu_ref_index_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_ref_index)
  {
    for (uint64_t i = 0; i < self->mpdu_ref_index_size[0]; i++)
    {
      free(self->mpdu_ref_index[i]);
    }
    free(self->mpdu_ref_index);
    self->mpdu_ref_index_size[0] = 0;
    self->mpdu_ref_index_size[1] = 0;
  }
  self->mpdu_ref_index =
      (uint64_t **)malloc(sizeof(uint64_t) * mpdu_ref_index_size[0]);
  for (uint64_t i = 0; i < mpdu_ref_index_size[0]; i++)
  {
    memcpy(self->mpdu_ref_index,
           mpdu_ref_index,
           sizeof(uint64_t) * mpdu_ref_index_size[1]);
  }
  self->mpdu_ref_index_size[0] = mpdu_ref_index_size[0];
  self->mpdu_ref_index_size[1] = mpdu_ref_index_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_override_2d_params_flag(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_override_2d_params_flag,
    uint64_t mpdu_override_2d_params_flag_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_override_2d_params_flag)
  {
    for (uint64_t i = 0;
         i < self->mpdu_override_2d_params_flag_size[0];
         i++)
    {
      free(self->mpdu_override_2d_params_flag[i]);
    }
    free(self->mpdu_override_2d_params_flag);
    self->mpdu_override_2d_params_flag_size[0] = 0;
    self->mpdu_override_2d_params_flag_size[1] = 0;
  }
  self->mpdu_override_2d_params_flag = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_override_2d_params_flag_size[0]);
  for (uint64_t i = 0; i < mpdu_override_2d_params_flag_size[0]; i++)
  {
    memcpy(self->mpdu_override_2d_params_flag,
           mpdu_override_2d_params_flag,
           sizeof(uint64_t) * mpdu_override_2d_params_flag_size[1]);
  }
  self->mpdu_override_2d_params_flag_size[0] =
      mpdu_override_2d_params_flag_size[0];
  self->mpdu_override_2d_params_flag_size[1] =
      mpdu_override_2d_params_flag_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_pos_x(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_2d_pos_x,
    uint64_t                     mpdu_2d_pos_x_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_2d_pos_x)
  {
    for (uint64_t i = 0; i < self->mpdu_2d_pos_x_size[0]; i++)
    {
      free(self->mpdu_2d_pos_x[i]);
    }
    free(self->mpdu_2d_pos_x);
    self->mpdu_2d_pos_x_size[0] = 0;
    self->mpdu_2d_pos_x_size[1] = 0;
  }
  self->mpdu_2d_pos_x =
      (uint64_t **)malloc(sizeof(uint64_t) * mpdu_2d_pos_x_size[0]);
  for (uint64_t i = 0; i < mpdu_2d_pos_x_size[0]; i++)
  {
    memcpy(self->mpdu_2d_pos_x,
           mpdu_2d_pos_x,
           sizeof(uint64_t) * mpdu_2d_pos_x_size[1]);
  }
  self->mpdu_2d_pos_x_size[0] = mpdu_2d_pos_x_size[0];
  self->mpdu_2d_pos_x_size[1] = mpdu_2d_pos_x_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_pos_y(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_2d_pos_y,
    uint64_t                     mpdu_2d_pos_y_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_2d_pos_y)
  {
    for (uint64_t i = 0; i < self->mpdu_2d_pos_y_size[0]; i++)
    {
      free(self->mpdu_2d_pos_y[i]);
    }
    free(self->mpdu_2d_pos_y);
    self->mpdu_2d_pos_y_size[0] = 0;
    self->mpdu_2d_pos_y_size[1] = 0;
  }
  self->mpdu_2d_pos_y =
      (uint64_t **)malloc(sizeof(uint64_t) * mpdu_2d_pos_y_size[0]);
  for (uint64_t i = 0; i < mpdu_2d_pos_y_size[0]; i++)
  {
    memcpy(self->mpdu_2d_pos_y,
           mpdu_2d_pos_y,
           sizeof(uint64_t) * mpdu_2d_pos_y_size[1]);
  }
  self->mpdu_2d_pos_y_size[0] = mpdu_2d_pos_y_size[0];
  self->mpdu_2d_pos_y_size[1] = mpdu_2d_pos_y_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_delta_size_x(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_2d_delta_size_x,
    uint64_t                     mpdu_2d_delta_size_x_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_2d_delta_size_x)
  {
    for (uint64_t i = 0; i < self->mpdu_2d_delta_size_x_size[0]; i++)
    {
      free(self->mpdu_2d_delta_size_x[i]);
    }
    free(self->mpdu_2d_delta_size_x);
    self->mpdu_2d_delta_size_x_size[0] = 0;
    self->mpdu_2d_delta_size_x_size[1] = 0;
  }
  self->mpdu_2d_delta_size_x = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_2d_delta_size_x_size[0]);
  for (uint64_t i = 0; i < mpdu_2d_delta_size_x_size[0]; i++)
  {
    memcpy(self->mpdu_2d_delta_size_x,
           mpdu_2d_delta_size_x,
           sizeof(uint64_t) * mpdu_2d_delta_size_x_size[1]);
  }
  self->mpdu_2d_delta_size_x_size[0] = mpdu_2d_delta_size_x_size[0];
  self->mpdu_2d_delta_size_x_size[1] = mpdu_2d_delta_size_x_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_delta_size_y(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_2d_delta_size_y,
    uint64_t                     mpdu_2d_delta_size_y_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_2d_delta_size_y)
  {
    for (uint64_t i = 0; i < self->mpdu_2d_delta_size_y_size[0]; i++)
    {
      free(self->mpdu_2d_delta_size_y[i]);
    }
    free(self->mpdu_2d_delta_size_y);
    self->mpdu_2d_delta_size_y_size[0] = 0;
    self->mpdu_2d_delta_size_y_size[1] = 0;
  }
  self->mpdu_2d_delta_size_y = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_2d_delta_size_y_size[0]);
  for (uint64_t i = 0; i < mpdu_2d_delta_size_y_size[0]; i++)
  {
    memcpy(self->mpdu_2d_delta_size_y,
           mpdu_2d_delta_size_y,
           sizeof(uint64_t) * mpdu_2d_delta_size_y_size[1]);
  }
  self->mpdu_2d_delta_size_y_size[0] = mpdu_2d_delta_size_y_size[0];
  self->mpdu_2d_delta_size_y_size[1] = mpdu_2d_delta_size_y_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_override_3d_params_flag(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_override_3d_params_flag,
    uint64_t mpdu_override_3d_params_flag_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_override_3d_params_flag)
  {
    for (uint64_t i = 0;
         i < self->mpdu_override_3d_params_flag_size[0];
         i++)
    {
      free(self->mpdu_override_3d_params_flag[i]);
    }
    free(self->mpdu_override_3d_params_flag);
    self->mpdu_override_3d_params_flag_size[0] = 0;
    self->mpdu_override_3d_params_flag_size[1] = 0;
  }
  self->mpdu_override_3d_params_flag = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_override_3d_params_flag_size[0]);
  for (uint64_t i = 0; i < mpdu_override_3d_params_flag_size[0]; i++)
  {
    memcpy(self->mpdu_override_3d_params_flag,
           mpdu_override_3d_params_flag,
           sizeof(uint64_t) * mpdu_override_3d_params_flag_size[1]);
  }
  self->mpdu_override_3d_params_flag_size[0] =
      mpdu_override_3d_params_flag_size[0];
  self->mpdu_override_3d_params_flag_size[1] =
      mpdu_override_3d_params_flag_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_offset_u(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_3d_offset_u,
    uint64_t                     mpdu_3d_offset_u_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_3d_offset_u)
  {
    for (uint64_t i = 0; i < self->mpdu_3d_offset_u_size[0]; i++)
    {
      free(self->mpdu_3d_offset_u[i]);
    }
    free(self->mpdu_3d_offset_u);
    self->mpdu_3d_offset_u_size[0] = 0;
    self->mpdu_3d_offset_u_size[1] = 0;
  }
  self->mpdu_3d_offset_u = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_3d_offset_u_size[0]);
  for (uint64_t i = 0; i < mpdu_3d_offset_u_size[0]; i++)
  {
    memcpy(self->mpdu_3d_offset_u,
           mpdu_3d_offset_u,
           sizeof(uint64_t) * mpdu_3d_offset_u_size[1]);
  }
  self->mpdu_3d_offset_u_size[0] = mpdu_3d_offset_u_size[0];
  self->mpdu_3d_offset_u_size[1] = mpdu_3d_offset_u_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_offset_v(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_3d_offset_v,
    uint64_t                     mpdu_3d_offset_v_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_3d_offset_v)
  {
    for (uint64_t i = 0; i < self->mpdu_3d_offset_v_size[0]; i++)
    {
      free(self->mpdu_3d_offset_v[i]);
    }
    free(self->mpdu_3d_offset_v);
    self->mpdu_3d_offset_v_size[0] = 0;
    self->mpdu_3d_offset_v_size[1] = 0;
  }
  self->mpdu_3d_offset_v = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_3d_offset_v_size[0]);
  for (uint64_t i = 0; i < mpdu_3d_offset_v_size[0]; i++)
  {
    memcpy(self->mpdu_3d_offset_v,
           mpdu_3d_offset_v,
           sizeof(uint64_t) * mpdu_3d_offset_v_size[1]);
  }
  self->mpdu_3d_offset_v_size[0] = mpdu_3d_offset_v_size[0];
  self->mpdu_3d_offset_v_size[1] = mpdu_3d_offset_v_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_offset_d(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_3d_offset_d,
    uint64_t                     mpdu_3d_offset_d_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_3d_offset_d)
  {
    for (uint64_t i = 0; i < self->mpdu_3d_offset_d_size[0]; i++)
    {
      free(self->mpdu_3d_offset_d[i]);
    }
    free(self->mpdu_3d_offset_d);
    self->mpdu_3d_offset_d_size[0] = 0;
    self->mpdu_3d_offset_d_size[1] = 0;
  }
  self->mpdu_3d_offset_d = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_3d_offset_d_size[0]);
  for (uint64_t i = 0; i < mpdu_3d_offset_d_size[0]; i++)
  {
    memcpy(self->mpdu_3d_offset_d,
           mpdu_3d_offset_d,
           sizeof(uint64_t) * mpdu_3d_offset_d_size[1]);
  }
  self->mpdu_3d_offset_d_size[0] = mpdu_3d_offset_d_size[0];
  self->mpdu_3d_offset_d_size[1] = mpdu_3d_offset_d_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_range_d(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_3d_range_d,
    uint64_t                     mpdu_3d_range_d_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_3d_range_d)
  {
    for (uint64_t i = 0; i < self->mpdu_3d_range_d_size[0]; i++)
    {
      free(self->mpdu_3d_range_d[i]);
    }
    free(self->mpdu_3d_range_d);
    self->mpdu_3d_range_d_size[0] = 0;
    self->mpdu_3d_range_d_size[1] = 0;
  }
  self->mpdu_3d_range_d = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_3d_range_d_size[0]);
  for (uint64_t i = 0; i < mpdu_3d_range_d_size[0]; i++)
  {
    memcpy(self->mpdu_3d_range_d,
           mpdu_3d_range_d,
           sizeof(uint64_t) * mpdu_3d_range_d_size[1]);
  }
  self->mpdu_3d_range_d_size[0] = mpdu_3d_range_d_size[0];
  self->mpdu_3d_range_d_size[1] = mpdu_3d_range_d_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_override_plr_flag(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                   **mpdu_override_plr_flag,
    uint64_t                     mpdu_override_plr_flag_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->mpdu_override_plr_flag)
  {
    for (uint64_t i = 0; i < self->mpdu_override_plr_flag_size[0];
         i++)
    {
      free(self->mpdu_override_plr_flag[i]);
    }
    free(self->mpdu_override_plr_flag);
    self->mpdu_override_plr_flag_size[0] = 0;
    self->mpdu_override_plr_flag_size[1] = 0;
  }
  self->mpdu_override_plr_flag = (uint64_t **)malloc(
      sizeof(uint64_t) * mpdu_override_plr_flag_size[0]);
  for (uint64_t i = 0; i < mpdu_override_plr_flag_size[0]; i++)
  {
    memcpy(self->mpdu_override_plr_flag,
           mpdu_override_plr_flag,
           sizeof(uint64_t) * mpdu_override_plr_flag_size[1]);
  }
  self->mpdu_override_plr_flag_size[0] =
      mpdu_override_plr_flag_size[0];
  self->mpdu_override_plr_flag_size[1] =
      mpdu_override_plr_flag_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_merge_patch_data_unit_set_pd(fvv_merge_patch_data_unit_t *self,
                                 fvv_plr_data_t              *pd)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->pd->copy_from(self->pd, pd);
  return FVV_RET_SUCCESS;
}
// }