#include <fvv/bitstream.h>
#include <fvv/syntax/filler_data_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.8 Filler data RBSP syntax
// {
fvv_ret_t fvv_filler_data_rbsp_init(
    fvv_filler_data_rbsp_t                  *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_filler_data_rbsp_t){0};

  self->aspsr     = aspsr;
  self->data      = data;

  self->pack      = fvv_filler_data_rbsp_pack;
  self->copy_from = fvv_filler_data_rbsp_copy_from;

  FVV_SET_SETTER_PTR(fvv_filler_data_rbsp_t, ff_byte);
  FVV_SET_SETTER_PTR(fvv_filler_data_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));
  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_filler_data_rbsp_destroy(fvv_filler_data_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_filler_data_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

  *self = (fvv_filler_data_rbsp_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_filler_data_rbsp_pack(fvv_filler_data_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff      = FVV_NULL;
  uint64_t         next_bits = 0;
  buff                       = self->data;

  buff->next_bits(buff, 8, &next_bits);
  while (next_bits == 0xFF)
  {
    buff->pad(buff, self->ff_byte, FVV_BIT_FF_BYTE);
    buff->next_bits(buff, 8, &next_bits);
  }
  self->rtb->pack(self->rtb);

  return FVV_RET_SUCCESS;
}
fvv_filler_data_rbsp_copy_from(fvv_filler_data_rbsp_t *self,
                               fvv_filler_data_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ff_byte(self, other->ff_byte);
  self->set_rtb(self, other->rtb);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(fvv_filler_data_rbsp_t, ff_byte);
FVV_DEFINE_OBJ_SETTER(fvv_filler_data_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

// }
