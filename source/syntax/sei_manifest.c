#include <fvv/bitstream.h>
#include <fvv/syntax/sei_manifest.h>

// F.2.8 SEI manifest SEI message syntax
fvv_ret_t fvv_sei_manifest_init(fvv_sei_manifest_t *self,
                                fvv_bitstream_t    *data)
{
  *self      = (fvv_sei_manifest_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_sei_manifest_t, manifest_num_sei_msg_types);
  FVV_SET_SETTER_PTR(fvv_sei_manifest_t,
                     manifest_sei_payload_type,
                     0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);
  FVV_SET_SETTER_PTR(fvv_sei_manifest_t,
                     manifest_sei_description,
                     0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);

  self->pack      = fvv_sei_manifest_pack;
  self->copy_from = fvv_sei_manifest_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_manifest_destroy(fvv_sei_manifest_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_sei_manifest_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_manifest_pack(fvv_sei_manifest_t *self,
                                uint64_t            payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->manifest_num_sei_msg_types,
                   FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES,
                   FVV_DESCRIPTOR_MANIFEST_NUM_SEI_MSG_TYPES);

  for (i = 0; i < self->manifest_num_sei_msg_types; i++)
  {
    buff->write_bits(buff,
                     self->manifest_sei_payload_type[i],
                     FVV_BIT_MANIFEST_SEI_PAYLOAD_TYPE,
                     FVV_DESCRIPTOR_MANIFEST_SEI_PAYLOAD_TYPE);
    buff->write_bits(buff,
                     self->manifest_sei_description[i],
                     FVV_BIT_MANIFEST_SEI_DESCRIPTION,
                     FVV_DESCRIPTOR_MANIFEST_SEI_DESCRIPTION);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_manifest_copy_from(fvv_sei_manifest_t *self,
                                     fvv_sei_manifest_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_manifest_num_sei_msg_types(
      self, other->manifest_num_sei_msg_types);
  self->set_manifest_sei_payload_type(
      self, other->manifest_sei_payload_type);
  self->set_manifest_sei_description(self,
                                     other->manifest_sei_description);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_sei_manifest_t,
                         manifest_num_sei_msg_types);
FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_sei_manifest_t,
    manifest_sei_payload_type,
    0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);
FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_sei_manifest_t,
    manifest_sei_description,
    0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);