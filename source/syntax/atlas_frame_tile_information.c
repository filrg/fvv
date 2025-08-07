#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_frame_tile_information.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <string.h>
// 8.3.6.2.2 Atlas frame tile information syntax
// {
fvv_ret_t fvv_atlas_frame_tile_information_init(
    fvv_atlas_frame_tile_information_t      *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_atlas_frame_tile_information_t){0};
  self->aspsr     = aspsr;
  self->data      = data;
  self->pack      = fvv_atlas_frame_tile_information_pack;
  self->copy_from = fvv_atlas_frame_tile_information_copy_from;

  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_single_tile_in_atlas_frame_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_uniform_partition_spacing_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_partition_cols_width_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_partition_rows_height_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_num_partition_columns_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_num_partition_rows_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_single_partition_per_tile_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_num_tiles_in_atlas_frame_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_auxiliary_video_tile_row_width_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_signalled_tile_id_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_signalled_tile_id_length_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_partition_column_width_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_partition_row_height_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_top_left_partition_idx);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_bottom_right_partition_column_offset);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_bottom_right_partition_row_offset);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_auxiliary_video_tile_row_height);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_tile_information_t,
                     afti_tile_id);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_frame_tile_information_destroy(
    fvv_atlas_frame_tile_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_partition_column_width_minus1);
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_partition_row_height_minus1);
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_top_left_partition_idx);
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_bottom_right_partition_column_offset);
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_bottom_right_partition_row_offset);
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_auxiliary_video_tile_row_height);
  FVV_DESTROY_1D_ARR(fvv_atlas_frame_tile_information_t,
                     afti_tile_id);
  *self = (fvv_atlas_frame_tile_information_t){0};
  return FVV_RET_SUCCESS;
}
// TODO: this function need a look, DRAFT is unclear
fvv_ret_t fvv_atlas_frame_tile_information_pack(
    fvv_atlas_frame_tile_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  buff->write_bits(
      buff,
      self->afti_single_tile_in_atlas_frame_flag,
      FVV_BIT_AFTI_SINGLE_TILE_IN_ATLAS_FRAME_FLAG,
      FVV_DESCRIPTOR_AFTI_SINGLE_TILE_IN_ATLAS_FRAME_FLAG);
  if (!self->afti_single_tile_in_atlas_frame_flag)
  {
    buff->write_bits(
        buff,
        self->afti_uniform_partition_spacing_flag,
        FVV_BIT_AFTI_UNIFORM_PARTITION_SPACING_FLAG,
        FVV_DESCRIPTOR_AFTI_UNIFORM_PARTITION_SPACING_FLAG);
    if (self->afti_uniform_partition_spacing_flag)
    {
      buff->write_bits(
          buff,
          self->afti_partition_cols_width_minus1,
          FVV_BIT_AFTI_PARTITION_COLS_WIDTH_MINUS1,
          FVV_DESCRIPTOR_AFTI_PARTITION_COLS_WIDTH_MINUS1);
      buff->write_bits(
          buff,
          self->afti_partition_rows_height_minus1,
          FVV_BIT_AFTI_PARTITION_ROWS_HEIGHT_MINUS1,
          FVV_DESCRIPTOR_AFTI_PARTITION_ROWS_HEIGHT_MINUS1);
    }
    else
    {
      buff->write_bits(
          buff,
          self->afti_num_partition_columns_minus1,
          FVV_BIT_AFTI_NUM_PARTITION_COLUMNS_MINUS1,
          FVV_DESCRIPTOR_AFTI_NUM_PARTITION_COLUMNS_MINUS1);
      buff->write_bits(buff,
                       self->afti_num_partition_rows_minus1,
                       FVV_BIT_AFTI_NUM_PARTITION_ROWS_MINUS1,
                       FVV_DESCRIPTOR_AFTI_NUM_PARTITION_ROWS_MINUS1);
      for (i = 0; i < self->afti_num_partition_columns_minus1; i++)
        buff->write_bits(
            buff,
            self->afti_partition_column_width_minus1[i],
            FVV_BIT_AFTI_PARTITION_COLUMN_WIDTH_MINUS1,
            FVV_DESCRIPTOR_AFTI_PARTITION_COLUMN_WIDTH_MINUS1);
      for (i = 0; i < self->afti_num_partition_rows_minus1; i++)
        buff->write_bits(
            buff,
            self->afti_partition_row_height_minus1[i],
            FVV_BIT_AFTI_PARTITION_ROW_HEIGHT_MINUS1,
            FVV_DESCRIPTOR_AFTI_PARTITION_ROW_HEIGHT_MINUS1);
    }
    buff->write_bits(
        buff,
        self->afti_single_partition_per_tile_flag,
        FVV_BIT_AFTI_SINGLE_PARTITION_PER_TILE_FLAG,
        FVV_DESCRIPTOR_AFTI_SINGLE_PARTITION_PER_TILE_FLAG);
    if (!self->afti_single_partition_per_tile_flag)
    {
      buff->write_bits(
          buff,
          self->afti_num_tiles_in_atlas_frame_minus1,
          FVV_BIT_AFTI_NUM_TILES_IN_ATLAS_FRAME_MINUS1,
          FVV_DESCRIPTOR_AFTI_NUM_TILES_IN_ATLAS_FRAME_MINUS1);
      for (i = 0; i < self->afti_num_tiles_in_atlas_frame_minus1 + 1;
           i++)
      {
        buff->write_bits(buff,
                         self->afti_top_left_partition_idx[i],
                         FVV_BIT_AFTI_TOP_LEFT_PARTITION_IDX,
                         FVV_DESCRIPTOR_AFTI_TOP_LEFT_PARTITION_IDX);
        buff->write_bits(
            buff,
            self->afti_bottom_right_partition_column_offset[i],
            FVV_BIT_AFTI_BOTTOM_RIGHT_PARTITION_COLUMN_OFFSET,
            FVV_DESCRIPTOR_AFTI_BOTTOM_RIGHT_PARTITION_COLUMN_OFFSET);
        buff->write_bits(
            buff,
            self->afti_bottom_right_partition_row_offset[i],
            FVV_BIT_AFTI_BOTTOM_RIGHT_PARTITION_ROW_OFFSET,
            FVV_DESCRIPTOR_AFTI_BOTTOM_RIGHT_PARTITION_ROW_OFFSET);
      }
    }
    else
      self->afti_num_tiles_in_atlas_frame_minus1 =
          NumPartitionsInAtlasFrame - 1;
  }
  else
  {
    self->afti_num_tiles_in_atlas_frame_minus1 = 0;
  }
  if (self->aspsr->asps_auxiliary_video_enabled_flag)
  {
    buff->write_bits(
        buff,
        self->afti_auxiliary_video_tile_row_width_minus1,
        FVV_BIT_AFTI_AUXILIARY_VIDEO_TILE_ROW_WIDTH_MINUS1,
        FVV_DESCRIPTOR_AFTI_AUXILIARY_VIDEO_TILE_ROW_WIDTH_MINUS1);
    for (i = 0; i < self->afti_num_tiles_in_atlas_frame_minus1 + 1;
         i++)
    {
      buff->write_bits(
          buff,
          self->afti_auxiliary_video_tile_row_height[i],
          FVV_BIT_AFTI_AUXILIARY_VIDEO_TILE_ROW_HEIGHT,
          FVV_DESCRIPTOR_AFTI_AUXILIARY_VIDEO_TILE_ROW_HEIGHT);
    }
  }
  buff->write_bits(buff,
                   self->afti_signalled_tile_id_flag,
                   FVV_BIT_AFTI_SIGNALLED_TILE_ID_FLAG,
                   FVV_DESCRIPTOR_AFTI_SIGNALLED_TILE_ID_FLAG);
  if (self->afti_signalled_tile_id_flag)
  {
    buff->write_bits(
        buff,
        self->afti_signalled_tile_id_length_minus1,
        FVV_BIT_AFTI_SIGNALLED_TILE_ID_LENGTH_MINUS1,
        FVV_DESCRIPTOR_AFTI_SIGNALLED_TILE_ID_LENGTH_MINUS1);
    for (i = 0; i < self->afti_num_tiles_in_atlas_frame_minus1 + 1;
         i++)
    {
      buff->write_bits(buff,
                       self->afti_tile_id[i],
                       FVV_BIT_AFTI_TILE_ID,
                       FVV_DESCRIPTOR_AFTI_TILE_ID);
      TileIDToIndex[self->afti_tile_id[i]] = i;
      TileIndexToID[i]                     = self->afti_tile_id[i];
    }
  }
  else
    for (i = 0; i < self->afti_num_tiles_in_atlas_frame_minus1 + 1;
         i++)
    {
      self->afti_tile_id[i] = i;
      TileIDToIndex[i]      = i;
      TileIndexToID[i]      = i;
    }

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_frame_tile_information_copy_from(
    fvv_atlas_frame_tile_information_t *self,
    fvv_atlas_frame_tile_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_afti_single_tile_in_atlas_frame_flag(
      self, other->afti_single_tile_in_atlas_frame_flag);
  self->set_afti_uniform_partition_spacing_flag(
      self, other->afti_uniform_partition_spacing_flag);
  self->set_afti_partition_cols_width_minus1(
      self, other->afti_partition_cols_width_minus1);
  self->set_afti_partition_rows_height_minus1(
      self, other->afti_partition_rows_height_minus1);
  self->set_afti_num_partition_columns_minus1(
      self, other->afti_num_partition_columns_minus1);
  self->set_afti_num_partition_rows_minus1(
      self, other->afti_num_partition_rows_minus1);
  self->set_afti_single_partition_per_tile_flag(
      self, other->afti_single_partition_per_tile_flag);
  self->set_afti_num_tiles_in_atlas_frame_minus1(
      self, other->afti_num_tiles_in_atlas_frame_minus1);
  self->set_afti_auxiliary_video_tile_row_width_minus1(
      self, other->afti_auxiliary_video_tile_row_width_minus1);
  self->set_afti_signalled_tile_id_flag(
      self, other->afti_signalled_tile_id_flag);
  self->set_afti_signalled_tile_id_length_minus1(
      self, other->afti_signalled_tile_id_length_minus1);

  self->set_afti_partition_column_width_minus1(
      self,
      other->afti_partition_column_width_minus1,
      other->afti_partition_column_width_minus1_size);
  self->set_afti_partition_row_height_minus1(
      self,
      other->afti_partition_row_height_minus1,
      other->afti_partition_row_height_minus1_size);
  self->set_afti_top_left_partition_idx(
      self,
      other->afti_top_left_partition_idx,
      other->afti_top_left_partition_idx_size);
  self->set_afti_bottom_right_partition_column_offset(
      self,
      other->afti_bottom_right_partition_column_offset,
      other->afti_bottom_right_partition_column_offset_size);
  self->set_afti_bottom_right_partition_row_offset(
      self,
      other->afti_bottom_right_partition_row_offset,
      other->afti_bottom_right_partition_row_offset_size);
  self->set_afti_auxiliary_video_tile_row_height(
      self,
      other->afti_auxiliary_video_tile_row_height,
      other->afti_auxiliary_video_tile_row_height_size);
  self->set_afti_tile_id(
      self, other->afti_tile_id, other->afti_tile_id_size);

  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_single_tile_in_atlas_frame_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_uniform_partition_spacing_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_partition_cols_width_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_partition_rows_height_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_num_partition_columns_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_num_partition_rows_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_single_partition_per_tile_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_num_tiles_in_atlas_frame_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_auxiliary_video_tile_row_width_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_signalled_tile_id_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_signalled_tile_id_length_minus1);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_partition_column_width_minus1);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_partition_row_height_minus1);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_top_left_partition_idx);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_bottom_right_partition_column_offset);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_bottom_right_partition_row_offset);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_auxiliary_video_tile_row_height);
FVV_DEFINE_1D_ARR_SETTER(fvv_atlas_frame_tile_information_t,
                         afti_tile_id);
// }
