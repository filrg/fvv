#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_frame_parameter_set_rbsp.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/patch_data_unit.h>
#include <string.h>

// 8.3.7.3 Patch data unit syntax
// {
fvv_ret_t fvv_patch_data_unit_init(
    fvv_patch_data_unit_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_atlas_frame_parameter_set_rbsp_t    *afpsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_patch_data_unit_t){0};
  self->data      = data;
  self->afpsr     = afpsr;
  self->aspsr     = aspsr;

  self->pack      = fvv_patch_data_unit_pack;
  self->copy_from = fvv_patch_data_unit_copy_from;

  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_2d_pos_x);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_2d_pos_y);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_2d_size_x_minus1);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_2d_size_y_minus1);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_3d_offset_u);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_3d_offset_v);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_3d_offset_d);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_3d_range_d);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_projection_id);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_orientation_index);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_lod_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_lod_scale_x_minus1);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pdu_lod_scale_y_idc);
  FVV_SET_SETTER_PTR(fvv_patch_data_unit_t, pd, fvv_plr_data_t);

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
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_2d_pos_x);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_2d_pos_y);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_2d_size_x_minus1);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_2d_size_y_minus1);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_3d_offset_u);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_3d_offset_v);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_3d_offset_d);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_3d_range_d);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_projection_id);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_orientation_index);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_lod_enabled_flag);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_lod_scale_x_minus1);
  FVV_DESTROY_2D_ARR(fvv_patch_data_unit_t, pdu_lod_scale_y_idc);
  FVV_DESTROY_OBJ(fvv_patch_data_unit_t, pd, fvv_plr_data_t);
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
  buff->write_bits(buff,
            self->pdu_2d_pos_x[tileID][patchIdx],
            FVV_BIT_PDU_2D_POS_X);
  buff->write_bits(buff,
            self->pdu_2d_pos_y[tileID][patchIdx],
            FVV_BIT_PDU_2D_POS_Y);
  buff->write_bits(buff,
            self->pdu_2d_size_x_minus1[tileID][patchIdx],
            FVV_BIT_PDU_2D_SIZE_X_MINUS1);
  buff->write_bits(buff,
            self->pdu_2d_size_y_minus1[tileID][patchIdx],
            FVV_BIT_PDU_2D_SIZE_Y_MINUS1);
  buff->write_bits(buff,
            self->pdu_3d_offset_u[tileID][patchIdx],
            FVV_BIT_PDU_3D_OFFSET_U);
  buff->write_bits(buff,
            self->pdu_3d_offset_v[tileID][patchIdx],
            FVV_BIT_PDU_3D_OFFSET_V);
  buff->write_bits(buff,
            self->pdu_3d_offset_d[tileID][patchIdx],
            FVV_BIT_PDU_3D_OFFSET_D);
  if (self->aspsr->asps_normal_axis_max_delta_value_enabled_flag)
    buff->write_bits(buff,
              self->pdu_3d_range_d[tileID][patchIdx],
              FVV_BIT_PDU_3D_RANGE_D);
  buff->write_bits(buff,
            self->pdu_projection_id[tileID][patchIdx],
            FVV_BIT_PDU_PROJECTION_ID);
  buff->write_bits(buff,
            self->pdu_orientation_index[tileID][patchIdx],
            FVV_BIT_PDU_ORIENTATION_INDEX);
  if (self->afpsr->afps_lod_mode_enabled_flag)
  {
    buff->write_bits(buff,
              self->pdu_lod_enabled_flag[tileID][patchIdx],
              FVV_BIT_PDU_LOD_ENABLED_FLAG);
    if (self->pdu_lod_enabled_flag[tileID][patchIdx] > 0)
    {
      buff->write_bits(buff,
                self->pdu_lod_scale_x_minus1[tileID][patchIdx],
                FVV_BIT_PDU_LOD_SCALE_X_MINUS1);
      buff->write_bits(buff,
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
                              fvv_patch_data_unit_t *other)
{
}
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_2d_pos_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_2d_pos_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_2d_size_x_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_2d_size_y_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_offset_u);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_offset_v);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_offset_d);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_range_d);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_projection_id);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_orientation_index);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_lod_enabled_flag);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_lod_scale_x_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_lod_scale_y_idc);
FVV_DEFINE_OBJ_SETTER(fvv_patch_data_unit_t, pd, fvv_plr_data_t);
// }