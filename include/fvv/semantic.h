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
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, TileIDToIndex);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_semantic_t, TileIndexToID);

  fvv_ret_t (*NumPartitionsInAtlasFrame)(
      fvv_semantic_t                          *self,
      fvv_atlas_sequence_parameter_set_rbsp_t *asps,
      fvv_atlas_frame_tile_information_t      *afti,
      uint64_t                                *ret);
  fvv_ret_t (*RlsIdx)(fvv_semantic_t                          *self,
                      fvv_atlas_tile_header_t                 *ath,
                      fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                      uint64_t                                *ret);
  fvv_ret_t (*NumLtrAtlasFrmEntries)(fvv_semantic_t        *self,
                                     fvv_ref_list_struct_t *rls,
                                     uint64_t               rlsIdx,
                                     uint64_t              *ret);
  fvv_ret_t (*NumRefIdxActive)(
      fvv_semantic_t                          *self,
      fvv_atlas_tile_header_t                 *ath,
      fvv_atlas_frame_parameter_set_rbsp_t    *afps,
      fvv_atlas_sequence_parameter_set_rbsp_t *asps,
      uint64_t                                *ret);
  fvv_ret_t (*rangeDBitDepth)(
      fvv_semantic_t                          *self,
      fvv_atlas_sequence_parameter_set_rbsp_t *asps,
      uint64_t                                *ret);
};

fvv_ret_t fvv_semantic_init(fvv_semantic_t *self);
fvv_ret_t fvv_semantic_destroy(fvv_semantic_t *self);
fvv_ret_t fvv_semantic_NumPartitionsInAtlasFrame(
    fvv_semantic_t                          *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_atlas_frame_tile_information_t      *afti,
    uint64_t                                *ret);
fvv_ret_t
fvv_semantic_RlsIdx(fvv_semantic_t                          *self,
                    fvv_atlas_tile_header_t                 *ath,
                    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                    uint64_t                                *ret);
fvv_ret_t
          fvv_semantic_NumLtrAtlasFrmEntries(fvv_semantic_t        *self,
                                             fvv_ref_list_struct_t *rls,
                                             uint64_t               rlsIdx,
                                             uint64_t              *ret);
fvv_ret_t fvv_semantic_NumRefIdxActive(
    fvv_semantic_t                          *self,
    fvv_atlas_tile_header_t                 *ath,
    fvv_atlas_frame_parameter_set_rbsp_t    *afps,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    uint64_t                                *ret);
fvv_ret_t fvv_semantic_rangeDBitDepth(
    fvv_semantic_t                          *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    uint64_t                                *ret);

FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, TileIDToIndex);
FVV_DECLARE_1D_ARR_SETTER(fvv_semantic_t, TileIndexToID);

#endif
