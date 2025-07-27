#include <fvv/syntax/byte_alignment.h>

// 8.3.3 Byte alignment syntax
// {
fvv_ret_t fvv_byte_alignment_init(fvv_byte_alignment_t *self,
                                  fvv_bitstream_t      *data)
{
  *self                             = (fvv_byte_alignment_t){0};

  self->alignment_bit_equal_to_one  = 0x1;
  self->alignment_bit_equal_to_zero = 0x0;

  self->data                        = data;
  self->pack                        = fvv_byte_alignment_pack;

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_byte_alignment_destroy(fvv_byte_alignment_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_byte_alignment_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_byte_alignment_pack(fvv_byte_alignment_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff         = FVV_NULL;
  fvv_bool_t       byte_aligned = FVV_FALSE;

  buff                          = self->data;

  buff->pad(buff,
            self->alignment_bit_equal_to_one,
            FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ONE);
  buff->byte_aligned(buff, &byte_aligned);
  while (!byte_aligned)
  {
    buff->pad(buff,
              self->alignment_bit_equal_to_zero,
              FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ZERO);
    buff->byte_aligned(buff, &byte_aligned);
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_byte_alignment_copy_from(fvv_byte_alignment_t *self,
                                       fvv_byte_alignment_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_alignment_bit_equal_to_one(
      self, other->alignment_bit_equal_to_one);
  self->set_alignment_bit_equal_to_zero(
      self, other->alignment_bit_equal_to_zero);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_byte_alignment_set_alignment_bit_equal_to_one(
    fvv_byte_alignment_t *self, uint64_t alignment_bit_equal_to_one)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->alignment_bit_equal_to_one = alignment_bit_equal_to_one;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_byte_alignment_set_alignment_bit_equal_to_zero(
    fvv_byte_alignment_t *self, uint64_t alignment_bit_equal_to_zero)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->alignment_bit_equal_to_zero = alignment_bit_equal_to_zero;
  return FVV_RET_SUCCESS;
}
// }
