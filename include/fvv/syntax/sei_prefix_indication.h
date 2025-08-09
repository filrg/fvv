#ifndef FVV_SYNTAX_SEI_PREFIX_INDICATION_H
#define FVV_SYNTAX_SEI_PREFIX_INDICATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.9 SEI prefix indication SEI message syntax
struct fvv_sei_prefix_indication_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_prefix_indication_t,
                                prefix_sei_payload_type);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_prefix_indication_t,
                                num_sei_prefix_indications_minus1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_sei_prefix_indication_t,
      num_bits_in_prefix_indication_minus1,
      0x1 << FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(
      fvv_sei_prefix_indication_t,
      sei_prefix_data_bit,
      0x1 << FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1,
      0x1 << FVV_BIT_NUM_BITS_IN_PREFIX_INDICATION_MINUS1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_prefix_indication_t,
                                byte_alignment_bit_equal_to_one);

  fvv_ret_t (*pack)(fvv_sei_prefix_indication_t *self,
                    uint64_t                     payloadSize);
  fvv_ret_t (*copy_from)(fvv_sei_prefix_indication_t *self,
                         fvv_sei_prefix_indication_t *other);
};

fvv_ret_t
fvv_sei_prefix_indication_init(fvv_sei_prefix_indication_t *self,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_sei_prefix_indication_destroy(fvv_sei_prefix_indication_t *self);
fvv_ret_t
fvv_sei_prefix_indication_pack(fvv_sei_prefix_indication_t *self,
                               uint64_t payloadSize);
fvv_ret_t fvv_sei_prefix_indication_copy_from(
    fvv_sei_prefix_indication_t *self,
    fvv_sei_prefix_indication_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_sei_prefix_indication_t,
                          prefix_sei_payload_type);
FVV_DECLARE_SCALAR_SETTER(fvv_sei_prefix_indication_t,
                          num_sei_prefix_indications_minus1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_sei_prefix_indication_t,
    num_bits_in_prefix_indication_minus1,
    0x1 << FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1);
FVV_DECLARE_2D_STATIC_ARR_SETTER(
    fvv_sei_prefix_indication_t,
    sei_prefix_data_bit,
    0x1 << FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1,
    0x1 << FVV_BIT_NUM_BITS_IN_PREFIX_INDICATION_MINUS1);
FVV_DECLARE_SCALAR_SETTER(fvv_sei_prefix_indication_t,
                          byte_alignment_bit_equal_to_one);

#endif // FVV_SYNTAX_SEI_PREFIX_INDICATION_H