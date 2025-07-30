#ifndef FVV_SYNTAX_RBSP_TRAILING_BITS_H
#define FVV_SYNTAX_RBSP_TRAILING_BITS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.10 RBSP trailing bit syntax
struct fvv_rbsp_trailing_bits_t
{
  uint64_t rbsp_stop_one_bit;       // /* equal to 1 */ f(1)
  uint64_t rbsp_alignment_zero_bit; // /* equal to 0 */

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_rbsp_trailing_bits_t *self);
  fvv_ret_t (*copy_from)(fvv_rbsp_trailing_bits_t *self,
                         fvv_rbsp_trailing_bits_t *other);
  fvv_ret_t (*set_rbsp_stop_one_bit)(fvv_rbsp_trailing_bits_t *self,
                                     uint64_t rbsp_stop_one_bit);
  fvv_ret_t (*set_rbsp_alignment_zero_bit)(
      fvv_rbsp_trailing_bits_t *self,
      uint64_t                  rbsp_alignment_zero_bit);
};

fvv_ret_t fvv_rbsp_trailing_bits_init(
    fvv_rbsp_trailing_bits_t                *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_rbsp_trailing_bits_destroy(fvv_rbsp_trailing_bits_t *self);
fvv_ret_t
fvv_rbsp_trailing_bits_pack(fvv_rbsp_trailing_bits_t *self);
fvv_ret_t fvv_rbsp_trailing_bits_copy_from(fvv_rbsp_trailing_bits_t *self,
                     fvv_rbsp_trailing_bits_t *other);
fvv_ret_t fvv_rbsp_trailing_bits_set_rbsp_stop_one_bit(fvv_rbsp_trailing_bits_t *self,
                                 uint64_t rbsp_stop_one_bit);
fvv_ret_t fvv_rbsp_trailing_bits_set_rbsp_alignment_zero_bit(
    fvv_rbsp_trailing_bits_t *self,
    uint64_t                  rbsp_alignment_zero_bit);
#endif // FVV_SYNTAX_RBSP_TRAILING_BITS_H
