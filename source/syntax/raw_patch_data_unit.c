#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_tile_header.h>
#include <fvv/syntax/raw_patch_data_unit.h>

// 8.3.7.7 Raw patch data unit syntax
// {
fvv_ret_t
fvv_raw_patch_data_unit_init(fvv_raw_patch_data_unit_t *self,
                             fvv_atlas_tile_header_t   *ath,
                             fvv_bitstream_t           *data)
{
  *self           = (fvv_raw_patch_data_unit_t){0};
  self->ath       = ath;
  self->data      = data;
  self->pack      = fvv_raw_patch_data_unit_pack;
  self->copy_from = fvv_raw_patch_data_unit_copy_from;

  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t,
                     rpdu_patch_in_auxiliary_video_flag);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_2d_pos_x);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_2d_pos_y);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t,
                     rpdu_2d_size_x_minus1);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t,
                     rpdu_2d_size_y_minus1);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_u);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_v);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_d);
  FVV_SET_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_points_minus1);

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_raw_patch_data_unit_destroy(fvv_raw_patch_data_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t,
                     rpdu_patch_in_auxiliary_video_flag);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t, rpdu_2d_pos_x);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t, rpdu_2d_pos_y);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t,
                     rpdu_2d_size_x_minus1);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t,
                     rpdu_2d_size_y_minus1);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_u);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_v);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_d);
  FVV_DESTROY_2D_ARR(fvv_raw_patch_data_unit_t, rpdu_points_minus1);

  *self = (fvv_raw_patch_data_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_raw_patch_data_unit_pack(fvv_raw_patch_data_unit_t *self,
                             uint64_t                   tileID,
                             uint64_t                   patchIdx)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  if (AuxTileHeight[TileIDToIndex[tileID]] > 0)
  {
    buff->write_bits(
        buff,
        self->rpdu_patch_in_auxiliary_video_flag[tileID][patchIdx],
        FVV_BIT_RPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG,
        FVV_DESCRIPTOR_RPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG);
  }

  buff->write_bits(buff,
                   self->rpdu_2d_pos_x[tileID][patchIdx],
                   FVV_BIT_RPDU_2D_POS_X,
                   FVV_DESCRIPTOR_RPDU_2D_POS_X);
  buff->write_bits(buff,
                   self->rpdu_2d_pos_y[tileID][patchIdx],
                   FVV_BIT_RPDU_2D_POS_Y,
                   FVV_DESCRIPTOR_RPDU_2D_POS_Y);
  buff->write_bits(buff,
                   self->rpdu_2d_size_x_minus1[tileID][patchIdx],
                   FVV_BIT_RPDU_2D_SIZE_X_MINUS1,
                   FVV_DESCRIPTOR_RPDU_2D_SIZE_X_MINUS1);
  buff->write_bits(buff,
                   self->rpdu_2d_size_y_minus1[tileID][patchIdx],
                   FVV_BIT_RPDU_2D_SIZE_Y_MINUS1,
                   FVV_DESCRIPTOR_RPDU_2D_SIZE_Y_MINUS1);
  buff->write_bits(
      buff,
      self->rpdu_3d_offset_u[tileID][patchIdx],
      self->ath->ath_raw_3d_offset_axis_bit_count_minus1 + 1,
      FVV_DESCRIPTOR_RPDU_3D_OFFSET_U);
  buff->write_bits(
      buff,
      self->rpdu_3d_offset_v[tileID][patchIdx],
      self->ath->ath_raw_3d_offset_axis_bit_count_minus1 + 1,
      FVV_DESCRIPTOR_RPDU_3D_OFFSET_V);
  buff->write_bits(
      buff,
      self->rpdu_3d_offset_d[tileID][patchIdx],
      self->ath->ath_raw_3d_offset_axis_bit_count_minus1 + 1,
      FVV_DESCRIPTOR_RPDU_3D_OFFSET_D);
  buff->write_bits(buff,
                   self->rpdu_points_minus1[tileID][patchIdx],
                   FVV_BIT_RPDU_POINTS_MINUS1,
                   FVV_DESCRIPTOR_RPDU_POINTS_MINUS1);

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_raw_patch_data_unit_copy_from(fvv_raw_patch_data_unit_t *self,
                                  fvv_raw_patch_data_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_rpdu_patch_in_auxiliary_video_flag(
      self,
      other->rpdu_patch_in_auxiliary_video_flag,
      other->rpdu_patch_in_auxiliary_video_flag_size);
  self->set_rpdu_2d_pos_x(
      self, other->rpdu_2d_pos_x, other->rpdu_2d_pos_x_size);
  self->set_rpdu_2d_pos_y(
      self, other->rpdu_2d_pos_y, other->rpdu_2d_pos_y_size);
  self->set_rpdu_2d_size_x_minus1(self,
                                  other->rpdu_2d_size_x_minus1,
                                  other->rpdu_2d_size_x_minus1_size);
  self->set_rpdu_2d_size_y_minus1(self,
                                  other->rpdu_2d_size_y_minus1,
                                  other->rpdu_2d_size_y_minus1_size);
  self->set_rpdu_3d_offset_u(
      self, other->rpdu_3d_offset_u, other->rpdu_3d_offset_u_size);
  self->set_rpdu_3d_offset_v(
      self, other->rpdu_3d_offset_v, other->rpdu_3d_offset_v_size);
  self->set_rpdu_3d_offset_d(
      self, other->rpdu_3d_offset_d, other->rpdu_3d_offset_d_size);
  self->set_rpdu_points_minus1(self,
                               other->rpdu_points_minus1,
                               other->rpdu_points_minus1_size);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t,
                         rpdu_patch_in_auxiliary_video_flag);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_2d_pos_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_2d_pos_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t,
                         rpdu_2d_size_x_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t,
                         rpdu_2d_size_y_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_3d_offset_u);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_3d_offset_v);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_3d_offset_d);
FVV_DEFINE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t,
                         rpdu_points_minus1);
// }
