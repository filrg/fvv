#ifndef FVV_SYNTAX_ATLAS_TILE_LAYER_RBSP_H
#define FVV_SYNTAX_ATLAS_TILE_LAYER_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.9 Atlas tile layer RBSP syntax
struct fvv_atlas_tile_layer_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *asps;
  fvv_atlas_frame_tile_information_t      *afps;
  fvv_nal_unit_header_t                   *nuh;

  fvv_bitstream_t                         *data;

  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_layer_rbsp_t, ath, fvv_atlas_tile_header_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_layer_rbsp_t, atdu, fvv_atlas_tile_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_layer_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
};

fvv_ret_t fvv_atlas_tile_layer_rbsp_init(
    fvv_atlas_tile_layer_rbsp_t             *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_atlas_frame_tile_information_t      *afps,
    fvv_nal_unit_header_t                   *nuh,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_destroy(fvv_atlas_tile_layer_rbsp_t *self);
fvv_ret_t
          fvv_atlas_tile_layer_rbsp_pack(fvv_atlas_tile_layer_rbsp_t *self);
fvv_ret_t fvv_atlas_tile_layer_rbsp_copy_from(
    fvv_atlas_tile_layer_rbsp_t *self,
    fvv_atlas_tile_layer_rbsp_t *other);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_layer_rbsp_t, ath, fvv_atlas_tile_header_t);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_layer_rbsp_t, atdu, fvv_atlas_tile_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_layer_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

#endif // FVV_SYNTAX_ATLAS_TILE_LAYER_RBSP_H
