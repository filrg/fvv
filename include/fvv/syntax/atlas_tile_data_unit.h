#ifndef FVV_ATLAS_TILE_DATA_UNIT_H
#define FVV_ATLAS_TILE_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.1 General atlas tile data unit syntax
struct fvv_atlas_tile_data_unit_t
{
  uint64_t                    **atdu_patch_mode;
  fvv_skip_patch_data_unit_t   *spdu;
  fvv_patch_information_data_t *pid;

  uint64_t                      atdu_patch_mode_size[2];

  fvv_atlas_tile_header_t      *ath;
  fvv_bitstream_t              *data;

  fvv_ret_t (*pack)(fvv_atlas_tile_data_unit_t *self,
                    uint64_t                    tileID);
  fvv_ret_t (*copy_from)(fvv_atlas_tile_data_unit_t *self,
                         fvv_atlas_tile_data_unit_t *other);

  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_atlas_tile_data_unit_t, atdu_patch_mode);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_data_unit_t, spdu, fvv_skip_patch_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_data_unit_t, pid, fvv_patch_information_data_t);
};

fvv_ret_t
fvv_atlas_tile_data_unit_init(fvv_atlas_tile_data_unit_t *self,
                              fvv_atlas_tile_header_t    *ath,
                              fvv_bitstream_t            *data);
fvv_ret_t
fvv_atlas_tile_data_unit_destroy(fvv_atlas_tile_data_unit_t *self);
fvv_ret_t
          fvv_atlas_tile_data_unit_pack(fvv_atlas_tile_data_unit_t *self,
                                        uint64_t                    tileID);
fvv_ret_t fvv_atlas_tile_data_unit_copy_from(
    fvv_atlas_tile_data_unit_t *self,
    fvv_atlas_tile_data_unit_t *other);
FVV_DECLARE_2D_ARR_SETTER(fvv_atlas_tile_data_unit_t, atdu_patch_mode);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_data_unit_t, spdu, fvv_skip_patch_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_data_unit_t, pid, fvv_patch_information_data_t);
#endif // FVV_ATLAS_TILE_DATA_UNIT_H
