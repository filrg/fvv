#include <fvv/bitstream.h>

fvv_ret_t fvv_bitstream_init(fvv_bitstream_t *self)
{
  *self                = (fvv_bitstream_t){0};

  self->alloc          = fvv_bitstream_alloc;
  self->free           = fvv_bitstream_free;
  self->pad            = fvv_bitstream_pad;
  self->byte_aligned   = fvv_bitstream_byte_aligned;
  self->more_rbsp_data = fvv_bitstream_more_rbsp_data;
  self->next_bits      = fvv_bitstream_next_bits;
  self->read_bits      = fvv_bitstream_read_bits;
  self->more_data      = fvv_bitstream_more_data;

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

static fvv_ret_t fvv_bitstream_padb(fvv_bitstream_t *self,
                                    uint64_t         value,
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
  return FVV_RET_SUCCESS;
}

static fvv_ret_t fvv_bitstream_padf(fvv_bitstream_t *self,
                                    uint64_t         value,
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
  return FVV_RET_SUCCESS;
}

static fvv_ret_t fvv_bitstream_padfl(fvv_bitstream_t *self,
                                     uint64_t         value,
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
  return FVV_RET_SUCCESS;
}

static fvv_ret_t fvv_bitstream_padi(fvv_bitstream_t *self,
                                    uint64_t         value,
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
  return FVV_RET_SUCCESS;
}

static fvv_ret_t fvv_bitstream_padse(fvv_bitstream_t *self,
                                     uint64_t         value,
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
  return FVV_RET_SUCCESS;
}
static fvv_ret_t fvv_bitstream_padst(fvv_bitstream_t *self,
                                     uint64_t         value,
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
  return FVV_RET_SUCCESS;
}

static fvv_ret_t fvv_bitstream_padu(fvv_bitstream_t *self,
                                    uint64_t         value,
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
  // done first chunk, now make up the 2nd chunk (8 bytes)

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

static fvv_ret_t fvv_bitstream_padue(fvv_bitstream_t *self,
                                     uint64_t         value,
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
fvv_ret_t fvv_bitstream_more_rbsp_data(fvv_bitstream_t *self,
                                       fvv_bool_t      *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bool_t more_data = 0;
  self->more_data(self, &more_data);

  if (!more_data)
  {
    // If there is no more data in the raw byte sequence payload
    // (RBSP), the return value of more_rbsp_data() is equal to
    // FALSE.
    *ret = FVV_FALSE;
    return FVV_RET_SUCCESS;
  }

  uint64_t byte_pos   = self->byte_pos;
  uint8_t  bit_offset = self->bit_offset;

  // skip first bit. It may be part of a RBSP or a rbsp_one_stop_bit.
  self->read_bits(self, 1, FVV_NULL);

  self->more_data(self, &more_data);
  while (more_data)
  {
    uint64_t read = 0;
    self->read_bits(self, 1, &read);
    if (read)
    {
      // If there is more data in an RBSP before the
      // rbsp_trailing_bits() syntax structure, the return value of
      // more_rbsp_data() is equal to TRUE.
      self->byte_pos   = byte_pos;
      self->bit_offset = bit_offset;
      *ret             = FVV_TRUE;
      return FVV_RET_SUCCESS;
    }
    self->more_data(self, &more_data);
  }
  // Otherwise, the return value of more_rbsp_data() is equal to
  // FALSE.
  *ret = FVV_FALSE;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_bitstream_next_bits(fvv_bitstream_t *self,
                                  uint64_t         n,
                                  uint64_t        *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  uint64_t byte_pos      = 0;
  uint8_t  bit_offset    = 0;
  uint64_t buffer        = 0;
  uint64_t bytes_to_read = 0;
  byte_pos               = self->byte_pos;
  bit_offset             = self->bit_offset;

  if ((self->byte_count - byte_pos) * FVV_BITS_PER_BYTE -
          bit_offset <
      n)
  {
    return FVV_RET_FAIL;
  }

  bytes_to_read =
      (bit_offset + n + FVV_BITS_PER_BYTE - 1) / FVV_BITS_PER_BYTE;

  for (uint64_t i = 0; i < bytes_to_read; ++i)
  {
    buffer =
        (buffer << FVV_BITS_PER_BYTE) | self->byte[byte_pos + i];
  }

  // align buffer to bit_offset
  uint8_t total_bits = bytes_to_read * FVV_BITS_PER_BYTE;
  buffer <<= bit_offset;
  buffer >>= total_bits - n;

  if (ret)
  {
    *ret = buffer;
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_bitstream_read_bits(fvv_bitstream_t *self,
                                  uint64_t         n,
                                  uint64_t        *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_ret_t status        = 0;
  uint64_t  total_bit_pos = 0;
  status                  = self->next_bits(self, n, ret);
  if (status != FVV_RET_SUCCESS)
  {
    return status;
  }

  // Advance the internal bit position
  total_bit_pos =
      self->byte_pos * FVV_BITS_PER_BYTE + self->bit_offset + n;

  self->byte_pos   = total_bit_pos / FVV_BITS_PER_BYTE;
  self->bit_offset = total_bit_pos % FVV_BITS_PER_BYTE;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_bitstream_more_data(fvv_bitstream_t *self,
                                  fvv_bool_t      *ret)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *ret = self->byte_pos < self->byte_count ? FVV_TRUE : FVV_FALSE;
  return FVV_RET_SUCCESS;
}
