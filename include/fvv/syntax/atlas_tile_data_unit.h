#ifndef FVV_ATLAS_TILE_DATA_UNIT_H
#define FVV_ATLAS_TILE_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// TODO: here, keep working here bro

// 8.3.7.1 General atlas tile data unit syntax
struct fvv_atlas_tile_data_unit_t
{
  uint64_t         atdu_patch_mode;

  fvv_bitstream_t *data;

};

#endif // FVV_ATLAS_TILE_DATA_UNIT_H