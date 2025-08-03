#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_frame_parameter_set_rbsp.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/patch_data_unit.h>
#include <string.h>
fvv_ret_t fvv_patch_data_unit_init(
    fvv_patch_data_unit_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_atlas_frame_parameter_set_rbsp_t    *afpsr,
    fvv_bitstream_t                         *data)
{
  *self                  = (fvv_patch_data_unit_t){0};
  self->data             = data;
  self->afpsr            = afpsr;
  self->aspsr            = aspsr;

  self->pack             = fvv_patch_data_unit_pack;
  self->copy_from        = fvv_patch_data_unit_copy_from;

  self->set_pd           = fvv_patch_data_unit_set_pd;
  self->set_pdu_2d_pos_x = fvv_patch_data_unit_set_pdu_2d_pos_x;
  self->set_pdu_2d_pos_y = fvv_patch_data_unit_set_pdu_2d_pos_y;
  self->set_pdu_2d_size_x_minus1 =
      fvv_patch_data_unit_set_pdu_2d_size_x_minus1;
  self->set_pdu_2d_size_y_minus1 =
      fvv_patch_data_unit_set_pdu_2d_size_y_minus1;
  self->set_pdu_3d_offset_u =
      fvv_patch_data_unit_set_pdu_3d_offset_u;
  self->set_pdu_3d_offset_v =
      fvv_patch_data_unit_set_pdu_3d_offset_v;
  self->set_pdu_3d_offset_d =
      fvv_patch_data_unit_set_pdu_3d_offset_d;
  self->set_pdu_3d_range_d = fvv_patch_data_unit_set_pdu_3d_range_d;
  self->set_pdu_projection_id =
      fvv_patch_data_unit_set_pdu_projection_id;
  self->set_pdu_orientation_index =
      fvv_patch_data_unit_set_pdu_orientation_index;
  self->set_pdu_lod_enabled_flag =
      fvv_patch_data_unit_set_pdu_lod_enabled_flag;
  self->set_pdu_lod_scale_x_minus1 =
      fvv_patch_data_unit_set_pdu_lod_scale_x_minus1;
  self->set_pdu_lod_scale_y_idc =
      fvv_patch_data_unit_set_pdu_lod_scale_y_idc;

  self->pd = (fvv_plr_data_t *)malloc(sizeof(fvv_plr_data_t));

  fvv_plr_data_init(self->pd, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_destroy(fvv_patch_data_unit_t *self)
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
  *self = (fvv_patch_data_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_patch_data_unit_pack(fvv_patch_data_unit_t *self,
                                   uint64_t               tileID,
                                   uint64_t               patchIdx)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;
  buff->pad(buff,
            self->pdu_2d_pos_x[tileID][patchIdx],
            FVV_BIT_PDU_2D_POS_X);
  buff->pad(buff,
            self->pdu_2d_pos_y[tileID][patchIdx],
            FVV_BIT_PDU_2D_POS_Y);
  buff->pad(buff,
            self->pdu_2d_size_x_minus1[tileID][patchIdx],
            FVV_BIT_PDU_2D_SIZE_X_MINUS1);
  buff->pad(buff,
            self->pdu_2d_size_y_minus1[tileID][patchIdx],
            FVV_BIT_PDU_2D_SIZE_Y_MINUS1);
  buff->pad(buff,
            self->pdu_3d_offset_u[tileID][patchIdx],
            FVV_BIT_PDU_3D_OFFSET_U);
  buff->pad(buff,
            self->pdu_3d_offset_v[tileID][patchIdx],
            FVV_BIT_PDU_3D_OFFSET_V);
  buff->pad(buff,
            self->pdu_3d_offset_d[tileID][patchIdx],
            FVV_BIT_PDU_3D_OFFSET_D);
  if (self->aspsr->asps_normal_axis_max_delta_value_enabled_flag)
    buff->pad(buff,
              self->pdu_3d_range_d[tileID][patchIdx],
              FVV_BIT_PDU_3D_RANGE_D);
  buff->pad(buff,
            self->pdu_projection_id[tileID][patchIdx],
            FVV_BIT_PDU_PROJECTION_ID);
  buff->pad(buff,
            self->pdu_orientation_index[tileID][patchIdx],
            FVV_BIT_PDU_ORIENTATION_INDEX);
  if (self->afpsr->afps_lod_mode_enabled_flag)
  {
    buff->pad(buff,
              self->pdu_lod_enabled_flag[tileID][patchIdx],
              FVV_BIT_PDU_LOD_ENABLED_FLAG);
    if (self->pdu_lod_enabled_flag[tileID][patchIdx] > 0)
    {
      buff->pad(buff,
                self->pdu_lod_scale_x_minus1[tileID][patchIdx],
                FVV_BIT_PDU_LOD_SCALE_X_MINUS1);
      buff->pad(buff,
                self->pdu_lod_scale_y_idc[tileID][patchIdx],
                FVV_BIT_PDU_LOD_SCALE_Y_IDC);
    }
  }
  if (self->aspsr->asps_plr_enabled_flag)
    self->pd->pack(self->pd, tileID, patchIdx);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
          fvv_patch_data_unit_copy_from(fvv_patch_data_unit_t *self,
                                        fvv_patch_data_unit_t *other);
fvv_ret_t fvv_patch_data_unit_set_pd(fvv_patch_data_unit_t *self,
                                     fvv_plr_data_t        *pd);

fvv_ret_t
fvv_patch_data_unit_set_pdu_2d_pos_x(fvv_patch_data_unit_t *self,
                                     uint64_t **pdu_2d_pos_x,
                                     uint64_t   pdu_2d_pos_x_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_2d_pos_x)
  {
    for (uint64_t i = 0; i < self->pdu_2d_pos_x_size[0]; i++)
    {
      free(self->pdu_2d_pos_x[i]);
    }
    free(self->pdu_2d_pos_x);
  }
  self->pdu_2d_pos_x =
      (uint64_t **)malloc(sizeof(uint64_t *) * pdu_2d_pos_x_size[0]);
  for (uint64_t i = 0; i < pdu_2d_pos_x_size[0]; i++)
  {
    memcpy(self->pdu_2d_pos_x[i],
           pdu_2d_pos_x[i],
           pdu_2d_pos_x_size[1]);
  }
  self->pdu_2d_pos_x_size[0] = pdu_2d_pos_x_size[0];
  self->pdu_2d_pos_x_size[1] = pdu_2d_pos_x_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_patch_data_unit_set_pdu_2d_pos_y(fvv_patch_data_unit_t *self,
                                     uint64_t **pdu_2d_pos_y,
                                     uint64_t   pdu_2d_pos_y_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_2d_pos_y)
  {
    for (uint64_t i = 0; i < self->pdu_2d_pos_y_size[0]; i++)
    {
      free(self->pdu_2d_pos_y[i]);
    }
    free(self->pdu_2d_pos_y);
  }
  self->pdu_2d_pos_y =
      (uint64_t **)malloc(sizeof(uint64_t *) * pdu_2d_pos_y_size[0]);
  for (uint64_t i = 0; i < pdu_2d_pos_y_size[0]; i++)
  {
    memcpy(self->pdu_2d_pos_y[i],
           pdu_2d_pos_y[i],
           pdu_2d_pos_y_size[1]);
  }
  self->pdu_2d_pos_y_size[0] = pdu_2d_pos_y_size[0];
  self->pdu_2d_pos_y_size[1] = pdu_2d_pos_y_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_2d_size_x_minus1(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_2d_size_x_minus1,
    uint64_t               pdu_2d_size_x_minus1_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_2d_size_x_minus1)
  {
    for (uint64_t i = 0; i < self->pdu_2d_size_x_minus1_size[0]; i++)
    {
      free(self->pdu_2d_size_x_minus1[i]);
    }
    free(self->pdu_2d_size_x_minus1);
  }
  self->pdu_2d_size_x_minus1 = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_2d_size_x_minus1_size[0]);
  for (uint64_t i = 0; i < pdu_2d_size_x_minus1_size[0]; i++)
  {
    memcpy(self->pdu_2d_size_x_minus1[i],
           pdu_2d_size_x_minus1[i],
           pdu_2d_size_x_minus1_size[1]);
  }
  self->pdu_2d_size_x_minus1_size[0] = pdu_2d_size_x_minus1_size[0];
  self->pdu_2d_size_x_minus1_size[1] = pdu_2d_size_x_minus1_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_2d_size_y_minus1(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_2d_size_y_minus1,
    uint64_t               pdu_2d_size_y_minus1_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_2d_size_y_minus1)
  {
    for (uint64_t i = 0; i < self->pdu_2d_size_y_minus1_size[0]; i++)
    {
      free(self->pdu_2d_size_y_minus1[i]);
    }
    free(self->pdu_2d_size_y_minus1);
  }
  self->pdu_2d_size_y_minus1 = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_2d_size_y_minus1_size[0]);
  for (uint64_t i = 0; i < pdu_2d_size_y_minus1_size[0]; i++)
  {
    memcpy(self->pdu_2d_size_y_minus1[i],
           pdu_2d_size_y_minus1[i],
           pdu_2d_size_y_minus1_size[1]);
  }
  self->pdu_2d_size_y_minus1_size[0] = pdu_2d_size_y_minus1_size[0];
  self->pdu_2d_size_y_minus1_size[1] = pdu_2d_size_y_minus1_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_offset_u(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_offset_u,
    uint64_t               pdu_3d_offset_u_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_3d_offset_u)
  {
    for (uint64_t i = 0; i < self->pdu_3d_offset_u_size[0]; i++)
    {
      free(self->pdu_3d_offset_u[i]);
    }
    free(self->pdu_3d_offset_u);
  }
  self->pdu_3d_offset_u = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_3d_offset_u_size[0]);
  for (uint64_t i = 0; i < pdu_3d_offset_u_size[0]; i++)
  {
    memcpy(self->pdu_3d_offset_u[i],
           pdu_3d_offset_u[i],
           pdu_3d_offset_u_size[1]);
  }
  self->pdu_3d_offset_u_size[0] = pdu_3d_offset_u_size[0];
  self->pdu_3d_offset_u_size[1] = pdu_3d_offset_u_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_offset_v(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_offset_v,
    uint64_t               pdu_3d_offset_v_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_3d_offset_v)
  {
    for (uint64_t i = 0; i < self->pdu_3d_offset_v_size[0]; i++)
    {
      free(self->pdu_3d_offset_v[i]);
    }
    free(self->pdu_3d_offset_v);
  }
  self->pdu_3d_offset_v = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_3d_offset_v_size[0]);
  for (uint64_t i = 0; i < pdu_3d_offset_v_size[0]; i++)
  {
    memcpy(self->pdu_3d_offset_v[i],
           pdu_3d_offset_v[i],
           pdu_3d_offset_v_size[1]);
  }
  self->pdu_3d_offset_v_size[0] = pdu_3d_offset_v_size[0];
  self->pdu_3d_offset_v_size[1] = pdu_3d_offset_v_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_offset_d(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_offset_d,
    uint64_t               pdu_3d_offset_d_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_3d_offset_d)
  {
    for (uint64_t i = 0; i < self->pdu_3d_offset_d_size[0]; i++)
    {
      free(self->pdu_3d_offset_d[i]);
    }
    free(self->pdu_3d_offset_d);
  }
  self->pdu_3d_offset_d = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_3d_offset_d_size[0]);
  for (uint64_t i = 0; i < pdu_3d_offset_d_size[0]; i++)
  {
    memcpy(self->pdu_3d_offset_d[i],
           pdu_3d_offset_d[i],
           pdu_3d_offset_d_size[1]);
  }
  self->pdu_3d_offset_d_size[0] = pdu_3d_offset_d_size[0];
  self->pdu_3d_offset_d_size[1] = pdu_3d_offset_d_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_range_d(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_range_d,
    uint64_t               pdu_3d_range_d_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_3d_range_d)
  {
    for (uint64_t i = 0; i < self->pdu_3d_range_d_size[0]; i++)
    {
      free(self->pdu_3d_range_d[i]);
    }
    free(self->pdu_3d_range_d);
  }
  self->pdu_3d_range_d = (uint64_t **)malloc(sizeof(uint64_t *) *
                                             pdu_3d_range_d_size[0]);
  for (uint64_t i = 0; i < pdu_3d_range_d_size[0]; i++)
  {
    memcpy(self->pdu_3d_range_d[i],
           pdu_3d_range_d[i],
           pdu_3d_range_d_size[1]);
  }
  self->pdu_3d_range_d_size[0] = pdu_3d_range_d_size[0];
  self->pdu_3d_range_d_size[1] = pdu_3d_range_d_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_projection_id(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_projection_id,
    uint64_t               pdu_projection_id_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_projection_id)
  {
    for (uint64_t i = 0; i < self->pdu_projection_id_size[0]; i++)
    {
      free(self->pdu_projection_id[i]);
    }
    free(self->pdu_projection_id);
  }
  self->pdu_projection_id = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_projection_id_size[0]);
  for (uint64_t i = 0; i < pdu_projection_id_size[0]; i++)
  {
    memcpy(self->pdu_projection_id[i],
           pdu_projection_id[i],
           pdu_projection_id_size[1]);
  }
  self->pdu_projection_id_size[0] = pdu_projection_id_size[0];
  self->pdu_projection_id_size[1] = pdu_projection_id_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_orientation_index(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_orientation_index,
    uint64_t               pdu_orientation_index_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_orientation_index)
  {
    for (uint64_t i = 0; i < self->pdu_orientation_index_size[0];
         i++)
    {
      free(self->pdu_orientation_index[i]);
    }
    free(self->pdu_orientation_index);
  }
  self->pdu_orientation_index = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_orientation_index_size[0]);
  for (uint64_t i = 0; i < pdu_orientation_index_size[0]; i++)
  {
    memcpy(self->pdu_orientation_index[i],
           pdu_orientation_index[i],
           pdu_orientation_index_size[1]);
  }
  self->pdu_orientation_index_size[0] =
      pdu_orientation_index_size[0];
  self->pdu_orientation_index_size[1] =
      pdu_orientation_index_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_lod_enabled_flag(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_lod_enabled_flag,
    uint64_t               pdu_lod_enabled_flag_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_lod_enabled_flag)
  {
    for (uint64_t i = 0; i < self->pdu_lod_enabled_flag_size[0]; i++)
    {
      free(self->pdu_lod_enabled_flag[i]);
    }
    free(self->pdu_lod_enabled_flag);
  }
  self->pdu_lod_enabled_flag = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_lod_enabled_flag_size[0]);
  for (uint64_t i = 0; i < pdu_lod_enabled_flag_size[0]; i++)
  {
    memcpy(self->pdu_lod_enabled_flag[i],
           pdu_lod_enabled_flag[i],
           pdu_lod_enabled_flag_size[1]);
  }
  self->pdu_lod_enabled_flag_size[0] = pdu_lod_enabled_flag_size[0];
  self->pdu_lod_enabled_flag_size[1] = pdu_lod_enabled_flag_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_lod_scale_x_minus1(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_lod_scale_x_minus1,
    uint64_t               pdu_lod_scale_x_minus1_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_lod_scale_x_minus1)
  {
    for (uint64_t i = 0; i < self->pdu_lod_scale_x_minus1_size[0];
         i++)
    {
      free(self->pdu_lod_scale_x_minus1[i]);
    }
    free(self->pdu_lod_scale_x_minus1);
  }
  self->pdu_lod_scale_x_minus1 = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_lod_scale_x_minus1_size[0]);
  for (uint64_t i = 0; i < pdu_lod_scale_x_minus1_size[0]; i++)
  {
    memcpy(self->pdu_lod_scale_x_minus1[i],
           pdu_lod_scale_x_minus1[i],
           pdu_lod_scale_x_minus1_size[1]);
  }
  self->pdu_lod_scale_x_minus1_size[0] =
      pdu_lod_scale_x_minus1_size[0];
  self->pdu_lod_scale_x_minus1_size[1] =
      pdu_lod_scale_x_minus1_size[1];
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_data_unit_set_pdu_lod_scale_y_idc(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_lod_scale_y_idc,
    uint64_t               pdu_lod_scale_y_idc_size[2])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->pdu_lod_scale_y_idc)
  {
    for (uint64_t i = 0; i < self->pdu_lod_scale_y_idc_size[0]; i++)
    {
      free(self->pdu_lod_scale_y_idc[i]);
    }
    free(self->pdu_lod_scale_y_idc);
  }
  self->pdu_lod_scale_y_idc = (uint64_t **)malloc(
      sizeof(uint64_t *) * pdu_lod_scale_y_idc_size[0]);
  for (uint64_t i = 0; i < pdu_lod_scale_y_idc_size[0]; i++)
  {
    memcpy(self->pdu_lod_scale_y_idc[i],
           pdu_lod_scale_y_idc[i],
           pdu_lod_scale_y_idc_size[1]);
  }
  self->pdu_lod_scale_y_idc_size[0] = pdu_lod_scale_y_idc_size[0];
  self->pdu_lod_scale_y_idc_size[1] = pdu_lod_scale_y_idc_size[1];
  return FVV_RET_SUCCESS;
}