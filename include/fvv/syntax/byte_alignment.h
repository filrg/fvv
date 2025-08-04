#ifndef FVV_SYNTAX_BYTE_ALIGNMENT_H
#define FVV_SYNTAX_BYTE_ALIGNMENT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.3 Byte alignment syntax
struct fvv_byte_alignment_t
{
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_byte_alignment_t *self);
  fvv_ret_t (*copy_from)(fvv_byte_alignment_t *self,
                         fvv_byte_alignment_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_byte_alignment_t, alignment_bit_equal_to_one);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_byte_alignment_t, alignment_bit_equal_to_zero);
};

fvv_ret_t fvv_byte_alignment_init(fvv_byte_alignment_t *self,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_byte_alignment_destroy(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_pack(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_copy_from(fvv_byte_alignment_t *self,
                                       fvv_byte_alignment_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_byte_alignment_t, alignment_bit_equal_to_one);
FVV_DECLARE_SCALAR_SETTER(fvv_byte_alignment_t, alignment_bit_equal_to_zero);
#endif // FVV_SYNTAX_BYTE_ALIGNMENT_H