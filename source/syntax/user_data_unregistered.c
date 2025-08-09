#include <fvv/bitstream.h>
#include <fvv/syntax/user_data_unregistered.h>

// F.2.4 User data unregistered SEI message syntax
fvv_ret_t
fvv_user_data_unregistered_init(fvv_user_data_unregistered_t *self,
                                fvv_bitstream_t              *data)
{
  *self      = (fvv_user_data_unregistered_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(
      fvv_user_data_unregistered_t, uuid_iso_iec_11578, 2);
  FVV_SET_SETTER_PTR(fvv_user_data_unregistered_t,
                     user_data_payload_byte);

  self->pack      = fvv_user_data_unregistered_pack;
  self->copy_from = fvv_user_data_unregistered_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_user_data_unregistered_destroy(fvv_user_data_unregistered_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_user_data_unregistered_t,
                     user_data_payload_byte);
  *self = (fvv_user_data_unregistered_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_user_data_unregistered_pack(fvv_user_data_unregistered_t *self,
                                uint64_t payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->uuid_iso_iec_11578[0],
                   FVV_BIT_UUID_ISO_IEC_11578 / 2,
                   FVV_DESCRIPTOR_UUID_ISO_IEC_11578);
  buff->write_bits(buff,
                   self->uuid_iso_iec_11578[1],
                   FVV_BIT_UUID_ISO_IEC_11578 / 2,
                   FVV_DESCRIPTOR_UUID_ISO_IEC_11578);

  for (i = 16; i < payloadSize; i++)
  {
    buff->write_bits(buff,
                     self->user_data_payload_byte[i - 16],
                     FVV_BIT_USER_DATA_PAYLOAD_BYTE,
                     FVV_DESCRIPTOR_USER_DATA_PAYLOAD_BYTE);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_user_data_unregistered_copy_from(
    fvv_user_data_unregistered_t *self,
    fvv_user_data_unregistered_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_uuid_iso_iec_11578(self, other->uuid_iso_iec_11578);
  self->set_user_data_payload_byte(
      self,
      other->user_data_payload_byte,
      other->user_data_payload_byte_size);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_user_data_unregistered_t,
                                uuid_iso_iec_11578,
                                2);
FVV_DEFINE_1D_ARR_SETTER(fvv_user_data_unregistered_t,
                         user_data_payload_byte);