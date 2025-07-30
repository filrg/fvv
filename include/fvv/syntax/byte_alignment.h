#ifndef FVV_SYNTAX_BYTE_ALIGNMENT_H
#define FVV_SYNTAX_BYTE_ALIGNMENT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// typedef struct fvv_byte_alignment_t fvv_byte_alignment_t;

// 8.3.3 Byte alignment syntax
struct fvv_byte_alignment_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  uint64_t         alignment_bit_equal_to_one;  // f(1)
  uint64_t         alignment_bit_equal_to_zero; // f(1)

  fvv_ret_t (*pack)(fvv_byte_alignment_t *self);
  fvv_ret_t (*copy_from)(fvv_byte_alignment_t *self,
                         fvv_byte_alignment_t *other);
  fvv_ret_t (*set_alignment_bit_equal_to_one)(
      fvv_byte_alignment_t *self,
      uint64_t              alignment_bit_equal_to_one);
  fvv_ret_t (*set_alignment_bit_equal_to_zero)(
      fvv_byte_alignment_t *self,
      uint64_t              alignment_bit_equal_to_zero);
};

fvv_ret_t fvv_byte_alignment_init(fvv_byte_alignment_t *self,
                                  fvv_v3c_unit_t       *vu,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_byte_alignment_destroy(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_pack(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_copy_from(fvv_byte_alignment_t *self,
                                       fvv_byte_alignment_t *other);
fvv_ret_t fvv_byte_alignment_set_alignment_bit_equal_to_one(
    fvv_byte_alignment_t *self, uint64_t alignment_bit_equal_to_one);
fvv_ret_t fvv_byte_alignment_set_alignment_bit_equal_to_zero(
    fvv_byte_alignment_t *self,
    uint64_t              alignment_bit_equal_to_zero);
#endif // FVV_SYNTAX_BYTE_ALIGNMENT_H