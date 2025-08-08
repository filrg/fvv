#include <fvv/math.h>
#include <fvv/process/tile_partition_scanning.h>
#include <fvv/semantic.h>
#include <fvv/syntax/atlas_frame_parameter_set_rbsp.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/atlas_tile_header.h>
#include <fvv/syntax/ref_list_struct.h>
fvv_ret_t fvv_semantic_init(fvv_semantic_t *self)
{
  *self = (fvv_semantic_t){0};
  self->NumPartitionsInAtlasFrame =
      fvv_semantic_NumPartitionsInAtlasFrame;
  self->RlsIdx                = fvv_semantic_RlsIdx;
  self->NumLtrAtlasFrmEntries = fvv_semantic_NumLtrAtlasFrmEntries;
  self->NumRefIdxActive       = fvv_semantic_NumRefIdxActive;
  self->rangeDBitDepth        = fvv_semantic_rangeDBitDepth;

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
  FVV_DESTROY_1D_ARR(fvv_semantic_t, TileIDToIndex);
  FVV_DESTROY_1D_ARR(fvv_semantic_t, TileIndexToID);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_semantic_NumPartitionsInAtlasFrame(
    fvv_semantic_t                          *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_atlas_frame_tile_information_t      *afti,
    uint64_t                                *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_tile_partition_scanning_t scan = {0};
  fvv_tile_partition_scanning_init(&scan);
  scan.run(&scan, afti, asps);

  *ret = scan.NumPartitionColumns * scan.NumPartitionRows;

  fvv_tile_partition_scanning_destroy(&scan);
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_semantic_RlsIdx(fvv_semantic_t                          *self,
                    fvv_atlas_tile_header_t                 *ath,
                    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                    uint64_t                                *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *ret = ath->ath_ref_atlas_frame_list_asps_flag
           ? ath->ath_ref_atlas_frame_list_idx
           : asps->asps_num_ref_atlas_frame_lists_in_asps;
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_semantic_NumLtrAtlasFrmEntries(fvv_semantic_t        *self,
                                   fvv_ref_list_struct_t *rls,
                                   uint64_t               rlsIdx,
                                   uint64_t              *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  uint64_t NumLtrAtlasFrmEntries = 0;
  uint64_t i                     = 0;
  for (i = 0; i < rls->num_ref_entries[rlsIdx]; i++)
    if (!rls->st_ref_atlas_frame_flag[rlsIdx][i])
      NumLtrAtlasFrmEntries++;

  *ret = NumLtrAtlasFrmEntries;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_semantic_NumRefIdxActive(
    fvv_semantic_t                          *self,
    fvv_atlas_tile_header_t                 *ath,
    fvv_atlas_frame_parameter_set_rbsp_t    *afps,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    uint64_t                                *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  uint64_t NumRefIdxActive = 0;
  uint64_t RlsIdx          = 0;
  if (ath->ath_type == FVV_P_TILE || ath->ath_type == FVV_SKIP_TILE)
  {
    if (ath->ath_num_ref_idx_active_override_flag == 1)
      NumRefIdxActive = ath->ath_num_ref_idx_active_minus1 + 1;
    else
    {
      self->RlsIdx(self, ath, asps, &RlsIdx);
      if (asps->rls->num_ref_entries[RlsIdx] >=
          afps->afps_num_ref_idx_default_active_minus1 + 1)
        NumRefIdxActive =
            afps->afps_num_ref_idx_default_active_minus1 + 1;
      else
        NumRefIdxActive = num_ref_entries[RlsIdx];
    }
  }
  else
    NumRefIdxActive = 0;

  *ret = NumRefIdxActive;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_semantic_rangeDBitDepth(
    fvv_semantic_t                          *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    uint64_t                                *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *ret = fvv_min(asps->asps_geometry_2d_bit_depth_minus1,
                 asps->asps_geometry_3d_bit_depth_minus1) +
         1;
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, TileIDToIndex);
FVV_DEFINE_1D_ARR_SETTER(fvv_semantic_t, TileIndexToID);
