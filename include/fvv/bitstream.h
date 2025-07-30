#ifndef FVV_BITSTREAM_H
#define FVV_BITSTREAM_H

#include <fvv/defs.h>

struct fvv_bitstream_t
{
  uint8_t *byte;       // pointer to start of the buffer
  uint64_t byte_count; // total buffer size in bytes
  uint64_t byte_pos;   // current write position in bytes
  uint8_t  bit_offset; // current bit offset (0–7) within current
                      // bytes which bit is not written yet, 0 is MSB

  fvv_ret_t (*alloc)(fvv_bitstream_t *self, uint64_t size);
  fvv_ret_t (*free)(fvv_bitstream_t *self);
  fvv_ret_t (*pad)(fvv_bitstream_t *self,
                   uint64_t         value,
                   uint8_t          bit_width);

  fvv_ret_t (*byte_aligned)(fvv_bitstream_t *self, fvv_bool_t *ret);
  fvv_ret_t (*more_rbsp_data)(fvv_bitstream_t *self,
                              fvv_bool_t      *ret);
  fvv_ret_t (*next_bits)(fvv_bitstream_t *self,
                         uint64_t         n,
                         uint64_t        *ret);
  fvv_ret_t (*read_bits)(fvv_bitstream_t *self,
                         uint64_t         n,
                         uint64_t        *ret);

  fvv_ret_t (*more_data)(fvv_bitstream_t *self, fvv_bool_t *ret);
};

fvv_ret_t fvv_bitstream_init(fvv_bitstream_t *self);
fvv_ret_t fvv_bitstream_destroy(fvv_bitstream_t *self);

fvv_ret_t fvv_bitstream_alloc(fvv_bitstream_t *self, uint64_t size);
fvv_ret_t fvv_bitstream_free(fvv_bitstream_t *self);
fvv_ret_t fvv_bitstream_pad(fvv_bitstream_t *self,
                            uint64_t         value,
                            uint8_t          bit_width);
fvv_ret_t fvv_bitstream_byte_aligned(fvv_bitstream_t *self,
                                     fvv_bool_t      *ret);
fvv_ret_t fvv_bitstream_more_rbsp_data(fvv_bitstream_t *self,
                                       fvv_bool_t      *ret);
fvv_ret_t fvv_bitstream_next_bits(fvv_bitstream_t *self,
                                  uint64_t         n,
                                  uint64_t        *ret);
fvv_ret_t fvv_bitstream_read_bits(fvv_bitstream_t *self,
                                  uint64_t         n,
                                  uint64_t        *ret);

fvv_ret_t fvv_bitstream_more_data(fvv_bitstream_t *self,
                                  fvv_bool_t      *ret);

#endif
