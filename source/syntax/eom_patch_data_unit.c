#include <fvv/bitstream.h>
#include <fvv/syntax/eom_patch_data_unit.h>

// 8.3.7.8 EOM patch data unit syntax
// {
fvv_ret_t
fvv_eom_patch_data_unit_init(fvv_eom_patch_data_unit_t *self,
                             fvv_bitstream_t           *data)
{
  *self           = (fvv_eom_patch_data_unit_t){0};
  self->data      = data;
  self->pack      = fvv_eom_patch_data_unit_pack;
  self->copy_from = fvv_eom_patch_data_unit_copy_from;

  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t,
                     epdu_patch_in_auxiliary_video_flag);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t, epdu_2d_pos_x);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t, epdu_2d_pos_y);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t,
                     epdu_2d_size_x_minus1);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t,
                     epdu_2d_size_y_minus1);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t,
                     epdu_patch_count_minus1);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t,
                     epdu_associated_patch_idx);
  FVV_SET_SETTER_PTR(fvv_eom_patch_data_unit_t, epdu_points);

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_eom_patch_data_unit_destroy(fvv_eom_patch_data_unit_t *self)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  FVV_DESTROY_2D_ARR(fvv_eom_patch_data_unit_t,
                     epdu_patch_in_auxiliary_video_flag);
  FVV_DESTROY_2D_ARR(fvv_eom_patch_data_unit_t, epdu_2d_pos_x);
  FVV_DESTROY_2D_ARR(fvv_eom_patch_data_unit_t, epdu_2d_pos_y);
  FVV_DESTROY_2D_ARR(fvv_eom_patch_data_unit_t,
                     epdu_2d_size_x_minus1);
  FVV_DESTROY_2D_ARR(fvv_eom_patch_data_unit_t,
                     epdu_2d_size_y_minus1);
  FVV_DESTROY_2D_ARR(fvv_eom_patch_data_unit_t,
                     epdu_patch_count_minus1);
  FVV_DESTROY_3D_ARR(fvv_eom_patch_data_unit_t,
                     epdu_associated_patch_idx);
  FVV_DESTROY_3D_ARR(fvv_eom_patch_data_unit_t, epdu_points);

  *self = (fvv_eom_patch_data_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_eom_patch_data_unit_pack(fvv_eom_patch_data_unit_t *self,
                             uint64_t                   tileID,
                             uint64_t                   patchIdx)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  fvv_bitstream_t *buff = self->data;

  if (AuxTileHeight[TileIDToIndex[tileID]] > 0)
  {
    buff->write_bits(
        buff,
        self->epdu_patch_in_auxiliary_video_flag[tileID][patchIdx],
        FVV_BIT_EPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG,
        FVV_DESCRIPTOR_EPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG);
  }

  buff->write_bits(buff,
                   self->epdu_2d_pos_x[tileID][patchIdx],
                   FVV_BIT_EPDU_2D_POS_X,
                   FVV_DESCRIPTOR_EPDU_2D_POS_X);
  buff->write_bits(buff,
                   self->epdu_2d_pos_y[tileID][patchIdx],
                   FVV_BIT_EPDU_2D_POS_Y,
                   FVV_DESCRIPTOR_EPDU_2D_POS_Y);
  buff->write_bits(buff,
                   self->epdu_2d_size_x_minus1[tileID][patchIdx],
                   FVV_BIT_EPDU_2D_SIZE_X_MINUS1,
                   FVV_DESCRIPTOR_EPDU_2D_SIZE_X_MINUS1);
  buff->write_bits(buff,
                   self->epdu_2d_size_y_minus1[tileID][patchIdx],
                   FVV_BIT_EPDU_2D_SIZE_Y_MINUS1,
                   FVV_DESCRIPTOR_EPDU_2D_SIZE_Y_MINUS1);
  buff->write_bits(buff,
                   self->epdu_patch_count_minus1[tileID][patchIdx],
                   FVV_BIT_EPDU_PATCH_COUNT_MINUS1,
                   FVV_DESCRIPTOR_EPDU_PATCH_COUNT_MINUS1);

  uint64_t count =
      self->epdu_patch_count_minus1[tileID][patchIdx] + 1;
  for (uint64_t i = 0; i < count; ++i)
  {
    buff->write_bits(
        buff,
        self->epdu_associated_patch_idx[tileID][patchIdx][i],
        FVV_BIT_EPDU_ASSOCIATED_PATCH_IDX,
        FVV_DESCRIPTOR_EPDU_ASSOCIATED_PATCH_IDX);
    buff->write_bits(buff,
                     self->epdu_points[tileID][patchIdx][i],
                     FVV_BIT_EPDU_POINTS,
                     FVV_DESCRIPTOR_EPDU_POINTS);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_eom_patch_data_unit_copy_from(fvv_eom_patch_data_unit_t *self,
                                  fvv_eom_patch_data_unit_t *other)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  self->set_epdu_patch_in_auxiliary_video_flag(
      self,
      other->epdu_patch_in_auxiliary_video_flag,
      other->epdu_patch_in_auxiliary_video_flag_size);
  self->set_epdu_2d_pos_x(
      self, other->epdu_2d_pos_x, other->epdu_2d_pos_x_size);
  self->set_epdu_2d_pos_y(
      self, other->epdu_2d_pos_y, other->epdu_2d_pos_y_size);
  self->set_epdu_2d_size_x_minus1(self,
                                  other->epdu_2d_size_x_minus1,
                                  other->epdu_2d_size_x_minus1_size);
  self->set_epdu_2d_size_y_minus1(self,
                                  other->epdu_2d_size_y_minus1,
                                  other->epdu_2d_size_y_minus1_size);
  self->set_epdu_patch_count_minus1(
      self,
      other->epdu_patch_count_minus1,
      other->epdu_patch_count_minus1_size);
  self->set_epdu_associated_patch_idx(
      self,
      other->epdu_associated_patch_idx,
      other->epdu_associated_patch_idx_size);
  self->set_epdu_points(
      self, other->epdu_points, other->epdu_points_size);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                         epdu_patch_in_auxiliary_video_flag);
FVV_DEFINE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t, epdu_2d_pos_x);
FVV_DEFINE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t, epdu_2d_pos_y);
FVV_DEFINE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                         epdu_2d_size_x_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                         epdu_2d_size_y_minus1);
FVV_DEFINE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                         epdu_patch_count_minus1);
FVV_DEFINE_3D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                         epdu_associated_patch_idx);
FVV_DEFINE_3D_ARR_SETTER(fvv_eom_patch_data_unit_t, epdu_points);
// }
