#include <fvv/bitstream.h>
#include <fvv/syntax/user_data_registered_itu_t_t35.h>

// F.2.3 User data registered by Recommendation ITU-T T.35 SEI message
// syntax
fvv_ret_t fvv_user_data_registered_itu_t_t35_init(
    fvv_user_data_registered_itu_t_t35_t *self, fvv_bitstream_t *data)
{
  *self      = (fvv_user_data_registered_itu_t_t35_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_user_data_registered_itu_t_t35_t,
                     itu_t_t35_country_code);
  FVV_SET_SETTER_PTR(fvv_user_data_registered_itu_t_t35_t,
                     itu_t_t35_country_code_extension_byte);
  FVV_SET_SETTER_PTR(fvv_user_data_registered_itu_t_t35_t,
                     itu_t_t35_payload_byte);

  self->pack      = fvv_user_data_registered_itu_t_t35_pack;
  self->copy_from = fvv_user_data_registered_itu_t_t35_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_user_data_registered_itu_t_t35_destroy(
    fvv_user_data_registered_itu_t_t35_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_user_data_registered_itu_t_t35_t,
                     itu_t_t35_payload_byte);
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_user_data_registered_itu_t_t35_pack(
    fvv_user_data_registered_itu_t_t35_t *self, uint64_t payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->itu_t_t35_country_code,
                   FVV_BIT_ITU_T_T35_COUNTRY_CODE,
                   FVV_DESCRIPTOR_ITU_T_T35_COUNTRY_CODE);

  if (self->itu_t_t35_country_code != 0xFF)
  {
    i = 1;
  }
  else
  {
    buff->write_bits(
        buff,
        self->itu_t_t35_country_code_extension_byte,
        FVV_BIT_ITU_T_T35_COUNTRY_CODE_EXTENSION_BYTE,
        FVV_DESCRIPTOR_ITU_T_T35_COUNTRY_CODE_EXTENSION_BYTE);
    i = 2;
  }

  do
  {
    buff->write_bits(
        buff,
        self->itu_t_t35_payload_byte
            [i - ((self->itu_t_t35_country_code != 0xFF) ? 1 : 2)],
        FVV_BIT_ITU_T_T35_PAYLOAD_BYTE,
        FVV_DESCRIPTOR_ITU_T_T35_PAYLOAD_BYTE);
    i++;
  } while (i < payloadSize);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_user_data_registered_itu_t_t35_copy_from(
    fvv_user_data_registered_itu_t_t35_t *self,
    fvv_user_data_registered_itu_t_t35_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_itu_t_t35_country_code(self,
                                   other->itu_t_t35_country_code);
  self->set_itu_t_t35_country_code_extension_byte(
      self, other->itu_t_t35_country_code_extension_byte);
  self->set_itu_t_t35_payload_byte(
      self,
      other->itu_t_t35_payload_byte,
      other->itu_t_t35_payload_byte_size);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_user_data_registered_itu_t_t35_t,
                         itu_t_t35_country_code);
FVV_DEFINE_SCALAR_SETTER(fvv_user_data_registered_itu_t_t35_t,
                         itu_t_t35_country_code_extension_byte);
FVV_DEFINE_1D_ARR_SETTER(fvv_user_data_registered_itu_t_t35_t,
                         itu_t_t35_payload_byte);