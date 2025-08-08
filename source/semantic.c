#include <fvv/semantic.h>
#include <fvv/syntax/atlas_frame_tile_information.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>

static fvv_ret_t
fvv_semantic_tile_partition_scan_columns_alloc(fvv_semantic_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->PartitionPosX_size = self->NumPartitionColumns;
  self->PartitionPosX =
      (uint64_t *)calloc(self->PartitionPosX_size, sizeof(uint64_t));
  self->PartitionWidth_size = self->NumPartitionColumns;
  self->PartitionWidth =
      (uint64_t *)calloc(self->PartitionWidth_size, sizeof(uint64_t));

  return FVV_RET_SUCCESS;
}
static fvv_ret_t
fvv_semantic_tile_partition_scan_rows_alloc(fvv_semantic_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->PartitionPosY_size = self->NumPartitionRows;
  self->PartitionPosY =
      (uint64_t *)calloc(self->PartitionPosY_size, sizeof(uint64_t));
  self->PartitionHeight_size = self->NumPartitionRows;
  self->PartitionHeight      = (uint64_t *)calloc(
      self->PartitionHeight_size, sizeof(uint64_t));

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_semantic_init(fvv_semantic_t *self)
{
  *self                     = (fvv_semantic_t){0};

  self->tile_partition_scan = fvv_semantic_tile_partition_scan;

  FVV_SET_SETTER_PTR(fvv_semantic_t, NumPartitionColumns);
  FVV_SET_SETTER_PTR(fvv_semantic_t, PartitionWidth);
  FVV_SET_SETTER_PTR(fvv_semantic_t, PartitionPosX);
  FVV_SET_SETTER_PTR(fvv_semantic_t, NumPartitionRows);
  FVV_SET_SETTER_PTR(fvv_semantic_t, PartitionHeight);
  FVV_SET_SETTER_PTR(fvv_semantic_t, PartitionPosY);

  FVV_SET_SETTER_PTR(fvv_semantic_t, TileIDToIndex);
  FVV_SET_SETTER_PTR(fvv_semantic_t, TileIndexToID);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_semantic_destroy(fvv_semantic_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionWidth);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionPosX);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionHeight);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionPosY);

  FVV_DESTROY_1D_ARR(fvv_semantic_t, TileIDToIndex);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, TileIndexToID);

  return FVV_RET_SUCCESS;
}
// 7.5 Tile partition scanning process
fvv_ret_t fvv_semantic_tile_partition_scan(
    fvv_semantic_t                          *self,
    fvv_atlas_frame_tile_information_t      *afti,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionWidth);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionPosX);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionHeight);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, PartitionPosY);

  uint64_t i               = 0;
  uint64_t j               = 0;
  uint64_t partitionWidth  = 0;
  uint64_t partitionHeight = 0;

  // Columns
  if (afti->afti_uniform_partition_spacing_flag)
  {
    partitionWidth =
        (afti->afti_partition_cols_width_minus1 + 1) * 64;
    self->NumPartitionColumns =
        asps->asps_frame_width / partitionWidth;

    fvv_semantic_tile_partition_scan_columns_alloc(self);

    self->PartitionPosX[0]  = 0;
    self->PartitionWidth[0] = partitionWidth;
    for (i = 1; i < self->NumPartitionColumns - 1; i++)
    {
      PartitionPosX[i] = PartitionPosX[i - 1] + PartitionWidth[i - 1];
      PartitionWidth[i] = partitionWidth;
    }
  }
  else
  {
    self->NumPartitionColumns =
        afti->afti_num_partition_columns_minus1 + 1;

    fvv_semantic_tile_partition_scan_columns_alloc(self);

    PartitionPosX[0] = 0;
    PartitionWidth[0] =
        (afti->afti_partition_column_width_minus1[0] + 1) * 64;
    for (i = 1; i < self->NumPartitionColumns - 1; i++)
    {
      PartitionPosX[i] = PartitionPosX[i - 1] + PartitionWidth[i - 1];
      PartitionWidth[i] =
          (afti_partition_column_width_minus1[i] + 1) * 64;
    }
  }
  if (self->NumPartitionColumns > 1)
  {
    PartitionPosX[self->NumPartitionColumns - 1] =
        PartitionPosX[self->NumPartitionColumns - 2] +
        PartitionWidth[self->NumPartitionColumns - 2];

    PartitionWidth[self->NumPartitionColumns - 1] =
        asps->asps_frame_width -
        PartitionPosX[self->NumPartitionColumns - 1];
  }

  // Rows
  if (afti->afti_uniform_partition_spacing_flag)
  {
    partitionHeight =
        (afti->afti_partition_rows_height_minus1 + 1) * 64;
    self->NumPartitionRows =
        asps->asps_frame_height / partitionHeight;

    fvv_semantic_tile_partition_scan_rows_alloc(self);

    PartitionPosY[0]   = 0;
    PartitionHeight[0] = partitionHeight;
    for (j = 1; j < self->NumPartitionRows - 1; j++)
    {
      PartitionPosY[j] =
          PartitionPosY[j - 1] + PartitionHeight[j - 1];
      PartitionHeight[j] = partitionHeight;
    }
  }
  else
  {
    self->NumPartitionRows = afti->afti_num_partition_rows_minus1 + 1;
    fvv_semantic_tile_partition_scan_rows_alloc(self);
    PartitionPosY[0] = 0;
    PartitionHeight[0] =
        (afti_partition_row_height_minus1[0] + 1) * 64;
    for (j = 1; j < self->NumPartitionRows - 1; j++)
    {
      PartitionPosY[j] =
          PartitionPosY[j - 1] + PartitionHeight[j - 1];
      PartitionHeight[j] =
          (afti_partition_row_height_minus1[j] + 1) * 64;
    }
  }
  if (self->NumPartitionRows > 1)
  {
    PartitionPosY[self->NumPartitionRows - 1] =
        PartitionPosY[self->NumPartitionRows - 2] +
        PartitionHeight[self->NumPartitionRows - 2];
    PartitionHeight[self->NumPartitionRows - 1] =
        asps->asps_frame_height -
        PartitionPosY[self->NumPartitionRows - 1];
  }

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_semantic_t, NumPartitionColumns);
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, PartitionWidth);
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, PartitionPosX);
FVV_DEFINE_SCALAR_SETTER(fvv_semantic_t, NumPartitionRows);
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, PartitionHeight);
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, PartitionPosY);

FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, TileIDToIndex);
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, TileIndexToID);
