#ifndef FVV_SYNTAX_ATLAS_TILE_LAYER_RBSP_H
#define FVV_SYNTAX_ATLAS_TILE_LAYER_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.9 Atlas tile layer RBSP syntax
struct fvv_atlas_tile_layer_rbsp_t
{
  fvv_atlas_tile_header_t    *ath;
  fvv_atlas_tile_data_unit_t *atdu;
  fvv_rbsp_trailing_bits_t   *rtb;

  fvv_atlas_sub_bitstream_t  *asb;
  fvv_bitstream_t            *data;

  fvv_ret_t (*pack)(fvv_atlas_tile_layer_rbsp_t *self);
  fvv_ret_t (*copy_from)(fvv_atlas_tile_layer_rbsp_t *self,
                         fvv_atlas_tile_layer_rbsp_t *other);
  fvv_ret_t (*set_ath)(fvv_atlas_tile_layer_rbsp_t *self,
                       fvv_atlas_tile_header_t     *ath);
  fvv_ret_t (*set_atdu)(fvv_atlas_tile_layer_rbsp_t *self,
                        fvv_atlas_tile_data_unit_t  *atdu);
  fvv_ret_t (*set_rtb)(fvv_atlas_tile_layer_rbsp_t *self,
                       fvv_rbsp_trailing_bits_t    *rtb);
};

fvv_ret_t
fvv_atlas_tile_layer_rbsp_init(fvv_atlas_tile_layer_rbsp_t *self,
                               fvv_atlas_sub_bitstream_t   *asb,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_destroy(fvv_atlas_tile_layer_rbsp_t *self);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_pack(fvv_atlas_tile_layer_rbsp_t *self);
fvv_ret_t fvv_atlas_tile_layer_rbsp_copy_from(
    fvv_atlas_tile_layer_rbsp_t *self,
    fvv_atlas_tile_layer_rbsp_t *other);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_set_ath(fvv_atlas_tile_layer_rbsp_t *self,
                                  fvv_atlas_tile_header_t     *ath);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_set_atdu(fvv_atlas_tile_layer_rbsp_t *self,
                                   fvv_atlas_tile_data_unit_t *atdu);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_set_rtb(fvv_atlas_tile_layer_rbsp_t *self,
                                  fvv_rbsp_trailing_bits_t    *rtb);

#endif // FVV_SYNTAX_ATLAS_TILE_LAYER_RBSP_H
