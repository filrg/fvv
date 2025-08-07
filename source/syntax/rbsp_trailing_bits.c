#include <fvv/bitstream.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.10 RBSP trailing bit syntax
// {
fvv_ret_t fvv_rbsp_trailing_bits_init(fvv_rbsp_trailing_bits_t *self,
                                      fvv_bitstream_t          *data)
{
  *self           = (fvv_rbsp_trailing_bits_t){0};
  self->data      = data;

  self->pack      = fvv_rbsp_trailing_bits_pack;
  self->copy_from = fvv_rbsp_trailing_bits_copy_from;
  FVV_SET_SETTER_PTR(fvv_rbsp_trailing_bits_t, rbsp_stop_one_bit);
  FVV_SET_SETTER_PTR(fvv_rbsp_trailing_bits_t,
                     rbsp_alignment_zero_bit);

  self->rbsp_stop_one_bit       = 0x1;
  self->rbsp_alignment_zero_bit = 0x0;

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_rbsp_trailing_bits_destroy(fvv_rbsp_trailing_bits_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_rbsp_trailing_bits_pack(fvv_rbsp_trailing_bits_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff         = FVV_NULL;
  fvv_bool_t      *byte_aligned = 0;
  buff                          = self->data;

  buff->write_bits(buff,
                   self->rbsp_stop_one_bit,
                   FVV_BIT_RBSP_STOP_ONE_BIT,
                   FVV_DESCRIPTOR_RBSP_STOP_ONE_BIT);

  buff->byte_aligned(buff, &byte_aligned);
  while (!byte_aligned)
  {
    buff->write_bits(buff,
                     self->rbsp_alignment_zero_bit,
                     FVV_BIT_RBSP_ALIGNMENT_ZERO_BIT,
                     FVV_DESCRIPTOR_RBSP_ALIGNMENT_ZERO_BIT);
    buff->byte_aligned(buff, &byte_aligned);
  }

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_rbsp_trailing_bits_copy_from(fvv_rbsp_trailing_bits_t *self,
                                 fvv_rbsp_trailing_bits_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_rbsp_stop_one_bit(self, other->rbsp_stop_one_bit);
  self->set_rbsp_alignment_zero_bit(self,
                                    other->rbsp_alignment_zero_bit);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(fvv_rbsp_trailing_bits_t, rbsp_stop_one_bit);
FVV_DEFINE_SCALAR_SETTER(fvv_rbsp_trailing_bits_t,
                         rbsp_alignment_zero_bit);
// }
