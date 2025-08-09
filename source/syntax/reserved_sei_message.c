#include <fvv/bitstream.h>
#include <fvv/syntax/reserved_sei_message.h>

// F.2.7 Reserved SEI message syntax
fvv_ret_t
fvv_reserved_sei_message_init(fvv_reserved_sei_message_t *self,
                              fvv_bitstream_t            *data)
{
  *self      = (fvv_reserved_sei_message_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_reserved_sei_message_t,
                     reserved_sei_message_payload_byte);

  self->pack      = fvv_reserved_sei_message_pack;
  self->copy_from = fvv_reserved_sei_message_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_reserved_sei_message_destroy(fvv_reserved_sei_message_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_reserved_sei_message_t,
                     reserved_sei_message_payload_byte);
  *self = (fvv_reserved_sei_message_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_reserved_sei_message_pack(fvv_reserved_sei_message_t *self,
                              uint64_t                    payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  for (i = 0; i < payloadSize; i++)
  {
    buff->write_bits(
        buff,
        self->reserved_sei_message_payload_byte[i],
        FVV_BIT_RESERVED_SEI_MESSAGE_PAYLOAD_BYTE,
        FVV_DESCRIPTOR_RESERVED_SEI_MESSAGE_PAYLOAD_BYTE);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_reserved_sei_message_copy_from(fvv_reserved_sei_message_t *self,
                                   fvv_reserved_sei_message_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_reserved_sei_message_payload_byte(
      self, other->reserved_sei_message_payload_byte);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_1D_ARR_SETTER(fvv_reserved_sei_message_t,
                         reserved_sei_message_payload_byte);