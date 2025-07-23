#include <fvv/bitstream.h>

fvv_ret_t fvv_bitstream_init(fvv_bitstream_t *self)
{
  *self              = (fvv_bitstream_t){0};

  self->alloc        = fvv_bitstream_alloc;
  self->free         = fvv_bitstream_free;
  self->pad          = fvv_bitstream_pad;
  self->byte_aligned = fvv_bitstream_byte_aligned;
  self->next_bits    = fvv_bitstream_next_bits;
  self->read_bits    = fvv_bitstream_read_bits;

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_bitstream_destroy(fvv_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->free(self);

  *self = (fvv_bitstream_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_bitstream_alloc(fvv_bitstream_t *self, uint64_t size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->byte_count = size;
  self->byte       = (uint8_t *)calloc(size, sizeof(uint8_t));

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_bitstream_free(fvv_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->byte != FVV_NULL)
  {
    free(self->byte);
  }
  self->byte_count = 0;
  self->byte_pos   = 0;
  self->bit_offset = 0;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_bitstream_pad(fvv_bitstream_t *self,
                            uint32_t         value,
                            uint8_t          bit_width)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->byte_pos >= self->byte_count)
  {
    return FVV_RET_ILLEGAL_MEMORY_ACCESS;
  }
  if (bit_width == 0 || bit_width > sizeof(value))
  {
    return FVV_RET_FAIL;
  }

  uint8_t *start_byte     = FVV_NULL;
  uint8_t  chk1_bit_width = 0;
  uint8_t  chk1           = 0xFF;
  uint8_t *value_byte     = FVV_NULL;

  start_byte              = &(self->byte[self->byte_pos]);
  chk1_bit_width          = FVV_BITS_PER_BYTE - self->bit_offset;
  value_byte              = (uint8_t *)&value;

  value <<= sizeof(value) * FVV_BITS_PER_BYTE - bit_width;

  chk1 <<= self->bit_offset;
  chk1 &= value_byte[sizeof(value) - 1];
  chk1 >>= self->bit_offset;

  start_byte[0] |= chk1;
  // done first chunk, now make up the 2nd chunk (4 bytes)

  if (self->bit_offset + bit_width > FVV_BITS_PER_BYTE)
  {
    value <<= chk1_bit_width;
    for (int i = 0;
         i < sizeof(value) && self->byte_pos + i < self->byte_count;
         i++)
    {
      start_byte[i + 1] = value_byte[sizeof(value) - 1 - i];
    }
  }
  // done, now update the counter
  self->byte_pos +=
      (self->bit_offset + bit_width) / FVV_BITS_PER_BYTE;
  self->bit_offset =
      (self->bit_offset + bit_width) % FVV_BITS_PER_BYTE;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_bitstream_byte_aligned(fvv_bitstream_t *self,
                                     fvv_bool_t      *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *ret = self->bit_offset == FVV_BITS_PER_BYTE - 1 ? FVV_TRUE
                                                   : FVV_FALSE;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_bitstream_next_bits(fvv_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_bitstream_read_bits(fvv_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  return FVV_RET_SUCCESS;
}
