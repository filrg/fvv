#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_tile_layer_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.9 Atlas tile layer RBSP syntax
fvv_ret_t fvv_atlas_tile_layer_rbsp_init(
    fvv_atlas_tile_layer_rbsp_t             *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_atlas_tile_layer_rbsp_t){0};
  self->aspsr     = aspsr;
  self->data      = data;

  self->pack      = fvv_atlas_tile_layer_rbsp_pack;
  self->copy_from = fvv_atlas_tile_layer_rbsp_copy_from;
  self->set_ath   = fvv_atlas_tile_layer_rbsp_set_ath;
  self->set_atdu  = fvv_atlas_tile_layer_rbsp_set_atdu;
  self->set_rtb   = fvv_atlas_tile_layer_rbsp_set_rtb;

  self->ath       = (fvv_atlas_tile_header_t *)malloc(
      sizeof(fvv_atlas_tile_header_t));
  self->atdu = (fvv_atlas_tile_data_unit_t *)malloc(
      sizeof(fvv_atlas_tile_data_unit_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_atlas_tile_header_init(self->ath, aspsr, data);
  fvv_atlas_tile_data_unit_init(self->ath, aspsr, data);
  fvv_rbsp_trailing_bits_init(self->rtb, aspsr, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_destroy(fvv_atlas_tile_layer_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ath)
  {
    fvv_atlas_tile_header_destroy(self->ath);
    free(self->ath);
  }
  if (self->atdu)
  {
    fvv_atlas_tile_data_unit_destroy(self->atdu);
    free(self->atdu);
  }
  if (self->rtb)
  {
    fvv_rbsp_trailing_bits_destroy(self->rtb);
    free(self->rtb);
  }
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
fvv_ret_t
fvv_atlas_tile_layer_rbsp_set_ath(fvv_atlas_tile_layer_rbsp_t *self,
                                  fvv_atlas_tile_header_t     *ath)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath->copy_from(self->ath, ath);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_set_atdu(fvv_atlas_tile_layer_rbsp_t *self,
                                   fvv_atlas_tile_data_unit_t  *atdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->atdu->copy_from(self->atdu, atdu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_set_rtb(fvv_atlas_tile_layer_rbsp_t *self,
                                  fvv_rbsp_trailing_bits_t    *rtb)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rtb->copy_from(self->rtb, rtb);
  return FVV_RET_SUCCESS;
}
