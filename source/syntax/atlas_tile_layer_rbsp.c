#include <fvv/syntax/atlas_tile_layer_rbsp.h>
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
  fvv_atlas_tile_data_unit_init(self->ath, )

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_destroy(fvv_atlas_tile_layer_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINTIALIZED;
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
  *self           = (fvv_atlas_tile_layer_rbsp_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_layer_rbsp_pack(fvv_atlas_tile_layer_rbsp_t *self,
                               uint64_t                     tileID)
{
  if (!self)
  {
    return FVV_RET_UNINTIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff = self->data;



}
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
