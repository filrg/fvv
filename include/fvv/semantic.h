#ifndef FVV_SEMANTIC_H
#define FVV_SEMANTIC_H

#include <fvv/defs.h>

// TODO: recheck the naming, should this even be named semantic, or
// should it be process or what ? Depends on what we gonna put in
// here. All the process, or just what inside semantic. In my opinion,
// TileIDToIndex stuff should stays, and tile_partition_scanning
// process should be put on another struct, meant for processes only.
// Here will only be the variable defined in semantic. Then this will
// use the processes struct stuff.
struct fvv_semantic_t
{
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_semantic_t, NumPartitionColumns);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, PartitionWidth);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, PartitionPosX);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_semantic_t, NumPartitionRows);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, PartitionHeight);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, PartitionPosY);

  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, TileIDToIndex);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, TileIndexToID);

  fvv_ret_t (*tile_partition_scan)(
      fvv_semantic_t                          *self,
      fvv_atlas_frame_tile_information_t      *afti,
      fvv_atlas_sequence_parameter_set_rbsp_t *asps);
};

fvv_ret_t fvv_semantic_init(fvv_semantic_t *self);
fvv_ret_t fvv_semantic_destroy(fvv_semantic_t *self);
fvv_ret_t fvv_semantic_tile_partition_scan(
    fvv_semantic_t                          *self,
    fvv_atlas_frame_tile_information_t      *afti,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps);

FVV_DECLARE_SCALAR_SETTER(fvv_semantic_t, NumPartitionColumns);
FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, PartitionWidth);
FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, PartitionPosX);
FVV_DECLARE_SCALAR_SETTER(fvv_semantic_t, NumPartitionRows);
FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, PartitionHeight);
FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, PartitionPosY);

FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, TileIDToIndex);
FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, TileIndexToID);

#endif
