#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_tile_header.h>
#include <fvv/syntax/atlas_tile_layer_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.9 Atlas tile layer RBSP syntax
fvv_ret_t fvv_atlas_tile_layer_rbsp_init(
    fvv_atlas_tile_layer_rbsp_t             *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_atlas_frame_tile_information_t      *afps,
    fvv_nal_unit_header_t                   *nuh,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_atlas_tile_layer_rbsp_t){0};

  self->asps     = asps;
  self->afps     = afps;
  self->nuh       = nuh;
  self->data      = data;

  self->pack      = fvv_atlas_tile_layer_rbsp_pack;
  self->copy_from = fvv_atlas_tile_layer_rbsp_copy_from;

  FVV_SET_SETTER_PTR(fvv_atlas_tile_layer_rbsp_t, ath, fvv_atlas_tile_header_t);
  FVV_SET_SETTER_PTR(fvv_atlas_tile_layer_rbsp_t, atdu, fvv_atlas_tile_data_unit_t);
  FVV_SET_SETTER_PTR(fvv_atlas_tile_layer_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

  self->ath = (fvv_atlas_tile_header_t *)malloc(
      sizeof(fvv_atlas_tile_header_t));
  self->atdu = (fvv_atlas_tile_data_unit_t *)malloc(
      sizeof(fvv_atlas_tile_data_unit_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_atlas_tile_header_init(
      self->ath, self->asps, self->afps, self->nuh, data);
  fvv_atlas_tile_data_unit_init(self->ath, data);
  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_destroy(fvv_atlas_tile_layer_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_atlas_tile_layer_rbsp_t, ath, fvv_atlas_tile_header_t);
  FVV_DESTROY_OBJ(fvv_atlas_tile_layer_rbsp_t, atdu, fvv_atlas_tile_data_unit_t);
  FVV_DESTROY_OBJ(fvv_atlas_tile_layer_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
  *self = (fvv_atlas_tile_layer_rbsp_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_pack(fvv_atlas_tile_layer_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;
  self->ath->pack(self->ath);
  self->atdu->pack(self->atdu, self->ath->ath_id);
  self->rtb->pack(self->rtb);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_layer_rbsp_copy_from(
    fvv_atlas_tile_layer_rbsp_t *self,
    fvv_atlas_tile_layer_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ath(self, other->ath);
  self->set_atdu(self, other->atdu);
  self->set_rtb(self, other->rtb);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_OBJ_SETTER(fvv_atlas_tile_layer_rbsp_t, ath, fvv_atlas_tile_header_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_tile_layer_rbsp_t, atdu, fvv_atlas_tile_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_tile_layer_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);