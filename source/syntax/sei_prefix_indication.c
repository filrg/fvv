#include <fvv/bitstream.h>
#include <fvv/syntax/sei_prefix_indication.h>

// F.2.9 SEI prefix indication SEI message syntax
fvv_ret_t
fvv_sei_prefix_indication_init(fvv_sei_prefix_indication_t *self,
                               fvv_bitstream_t             *data)
{
  *self      = (fvv_sei_prefix_indication_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_sei_prefix_indication_t,
                     prefix_sei_payload_type);
  FVV_SET_SETTER_PTR(fvv_sei_prefix_indication_t,
                     num_sei_prefix_indications_minus1);
  FVV_SET_SETTER_PTR(fvv_sei_prefix_indication_t,
                     num_bits_in_prefix_indication_minus1);
  FVV_SET_SETTER_PTR(fvv_sei_prefix_indication_t,
                     sei_prefix_data_bit);
  FVV_SET_SETTER_PTR(fvv_sei_prefix_indication_t,
                     byte_alignment_bit_equal_to_one);

  self->byte_alignment_bit_equal_to_one = 0x1;

  self->pack      = fvv_sei_prefix_indication_pack;
  self->copy_from = fvv_sei_prefix_indication_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_sei_prefix_indication_destroy(fvv_sei_prefix_indication_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_sei_prefix_indication_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_sei_prefix_indication_pack(fvv_sei_prefix_indication_t *self,
                               uint64_t payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  uint64_t         j    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->prefix_sei_payload_type,
                   FVV_BIT_PREFIX_SEI_PAYLOAD_TYPE,
                   FVV_DESCRIPTOR_PREFIX_SEI_PAYLOAD_TYPE);
  buff->write_bits(buff,
                   self->num_sei_prefix_indications_minus1,
                   FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1,
                   FVV_DESCRIPTOR_NUM_SEI_PREFIX_INDICATIONS_MINUS1);

  for (i = 0; i <= self->num_sei_prefix_indications_minus1; i++)
  {
    buff->write_bits(
        buff,
        self->num_bits_in_prefix_indication_minus1[i],
        FVV_BIT_NUM_BITS_IN_PREFIX_INDICATION_MINUS1,
        FVV_DESCRIPTOR_NUM_BITS_IN_PREFIX_INDICATION_MINUS1);

    for (j = 0; j <= self->num_bits_in_prefix_indication_minus1[i];
         j++)
    {
      buff->write_bits(buff,
                       self->sei_prefix_data_bit[i][j],
                       FVV_BIT_SEI_PREFIX_DATA_BIT,
                       FVV_DESCRIPTOR_SEI_PREFIX_DATA_BIT);
    }

    while (!byte_aligned())
    {
      buff->write_bits(
          buff,
          self->byte_alignment_bit_equal_to_one, /* equal to 1 */
          FVV_BIT_BYTE_ALIGNMENT_BIT_EQUAL_TO_ONE,
          FVV_DESCRIPTOR_BYTE_ALIGNMENT_BIT_EQUAL_TO_ONE);
    }
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_prefix_indication_copy_from(
    fvv_sei_prefix_indication_t *self,
    fvv_sei_prefix_indication_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_prefix_sei_payload_type(self,
                                    other->prefix_sei_payload_type);
  self->set_num_sei_prefix_indications_minus1(
      self, other->num_sei_prefix_indications_minus1);
  self->set_num_bits_in_prefix_indication_minus1(
      self, other->num_bits_in_prefix_indication_minus1);
  self->set_sei_prefix_data_bit(self, other->sei_prefix_data_bit);
  self->set_byte_alignment_bit_equal_to_one(
      self, other->byte_alignment_bit_equal_to_one);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_sei_prefix_indication_t,
                         prefix_sei_payload_type);
FVV_DEFINE_SCALAR_SETTER(fvv_sei_prefix_indication_t,
                         num_sei_prefix_indications_minus1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_sei_prefix_indication_t,
    num_bits_in_prefix_indication_minus1,
    0x1 << FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1);
FVV_DEFINE_2D_STATIC_ARR_SETTER(
    fvv_sei_prefix_indication_t,
    sei_prefix_data_bit,
    0x1 << FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1,
    0x1 << FVV_BIT_NUM_BITS_IN_PREFIX_INDICATION_MINUS1);
FVV_DEFINE_SCALAR_SETTER(fvv_sei_prefix_indication_t,
                         byte_alignment_bit_equal_to_one);