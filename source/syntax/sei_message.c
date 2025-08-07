#include <fvv/bitstream.h>
#include <fvv/syntax/sei_message.h>

fvv_ret_t fvv_sei_message_init(fvv_sei_message_t *self,
                               fvv_bitstream_t   *data)
{
  *self           = (fvv_sei_message_t){0};
  self->data      = data;
  self->pack      = fvv_sei_message_pack;
  self->copy_from = fvv_sei_message_copy_from;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_message_t,
                                sm_payload_type_byte);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_message_t,
                                sm_payload_size_byte);
  FVV_DECLARE_OBJ_SETTER_PTR(
      fvv_sei_message_t, sp, fvv_sei_payload_t);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_message_destroy(fvv_sei_message_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_sei_message_t, sp, fvv_sei_payload_t);
  *self = (fvv_sei_message_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_message_pack(fvv_sei_message_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  uint64_t payloadType  = 0;
  uint64_t payloadSize  = 0;

  do
  {
    buff->write_bits(buff,
                     self->sm_payload_type_byte,
                     FVV_BIT_SM_PAYLOAD_TYPE_BYTE,
                     FVV_DESCRIPTOR_SM_PAYLOAD_TYPE_BYTE);
    payloadType += self->sm_payload_type_byte;
  } while (self->sm_payload_type_byte == 0xFF);
  payloadSize = 0;
  do
  {
    buff->write_bits(buff,
                     self->sm_payload_size_byte,
                     FVV_BIT_SM_PAYLOAD_SIZE_BYTE,
                     FVV_DESCRIPTOR_SM_PAYLOAD_SIZE_BYTE);
    payloadSize += self->sm_payload_size_byte;
  } while (self->sm_payload_size_byte == 0xFF);
  self->sp->pack(self->sp, payloadType, payloadSize);
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_message_copy_from(fvv_sei_message_t *self,
                                    fvv_sei_message_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_sm_payload_type_byte(self, other->sm_payload_type_byte);
  self->set_sm_payload_size_byte(self, other->sm_payload_size_byte);
  self->set_sp(self, other->sp);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_sei_message_t, sm_payload_type_byte);
FVV_DEFINE_SCALAR_SETTER(fvv_sei_message_t, sm_payload_size_byte);
FVV_DEFINE_OBJ_SETTER(fvv_sei_message_t, sp, fvv_sei_payload_t);