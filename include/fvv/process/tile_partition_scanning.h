#ifndef FVV_PROCESS_TILE_PARTITION_SCANNING
#define FVV_PROCESS_TILE_PARTITION_SCANNING
#include <fvv/defs.h>
// 7.5 Tile partition scanning process

struct fvv_tile_partition_scanning_t
{
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_tile_partition_scanning_t,
                                NumPartitionColumns);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_tile_partition_scanning_t,
                                PartitionWidth);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_tile_partition_scanning_t,
                                PartitionPosX);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_tile_partition_scanning_t,
                                NumPartitionRows);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_tile_partition_scanning_t,
                                PartitionHeight);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_tile_partition_scanning_t,
                                PartitionPosY);

  fvv_ret_t (*run)(fvv_tile_partition_scanning_t           *self,
                   fvv_atlas_frame_tile_information_t      *afti,
                   fvv_atlas_sequence_parameter_set_rbsp_t *asps);
};

fvv_ret_t
fvv_tile_partition_scanning_init(fvv_tile_partition_scanning_t *self);
fvv_ret_t fvv_tile_partition_scanning_destroy(
    fvv_tile_partition_scanning_t *self);
fvv_ret_t fvv_tile_partition_scanning_run(
    fvv_tile_partition_scanning_t           *self,
    fvv_atlas_frame_tile_information_t      *afti,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps);

FVV_DECLARE_SCALAR_SETTER(fvv_tile_partition_scanning_t,
                          NumPartitionColumns);
FVV_DECLARE_1D_ARR_SETTER(fvv_tile_partition_scanning_t,
                          PartitionWidth);
FVV_DECLARE_1D_ARR_SETTER(fvv_tile_partition_scanning_t,
                          PartitionPosX);
FVV_DECLARE_SCALAR_SETTER(fvv_tile_partition_scanning_t,
                          NumPartitionRows);
FVV_DECLARE_1D_ARR_SETTER(fvv_tile_partition_scanning_t,
                          PartitionHeight);
FVV_DECLARE_1D_ARR_SETTER(fvv_tile_partition_scanning_t,
                          PartitionPosY);
#endif // FVV_PROCESS_TILE_PARTITION_SCANNING
