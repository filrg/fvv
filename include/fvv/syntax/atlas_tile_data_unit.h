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
  fvv_ret_t (*set_atdu_patch_mode)(fvv_atlas_tile_data_unit_t *self,
                                   uint64_t **atdu_patch_mode,
                                   uint64_t atdu_patch_mode_size[2]);
  fvv_ret_t (*set_spdu)(fvv_atlas_tile_data_unit_t *self,
                        fvv_skip_patch_data_unit_t *spdu);
  fvv_ret_t (*set_pid)(fvv_atlas_tile_data_unit_t   *self,
                       fvv_patch_information_data_t *pid);
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
fvv_ret_t fvv_atlas_tile_data_unit_set_atdu_patch_mode(
    fvv_atlas_tile_data_unit_t *self,
    uint64_t                  **atdu_patch_mode,
    uint64_t                    atdu_patch_mode_size[2]);
fvv_ret_t
fvv_atlas_tile_data_unit_set_spdu(fvv_atlas_tile_data_unit_t *self,
                                  fvv_skip_patch_data_unit_t *spdu);
fvv_ret_t
fvv_atlas_tile_data_unit_set_pid(fvv_atlas_tile_data_unit_t   *self,
                                 fvv_patch_information_data_t *pid);
#endif // FVV_ATLAS_TILE_DATA_UNIT_H
