#include <fvv/syntax/nal_unit_header.h>

// 8.3.5.2 NAL unit header syntax
// {
fvv_ret_t fvv_nal_unit_header_init(fvv_nal_unit_header_t *self,
                                   fvv_bitstream_t       *data)
{
  *self           = (fvv_nal_unit_header_t){0};
  self->data      = data;

  self->pack      = fvv_nal_unit_header_pack;
  self->copy_from = fvv_nal_unit_header_copy_from;
  self->set_nal_forbidden_zero_bit =
      fvv_nal_unit_header_set_nal_forbidden_zero_bit;
  self->set_nal_unit_type = fvv_nal_unit_header_set_nal_unit_type;
  self->set_nal_layer_id  = fvv_nal_unit_header_set_nal_layer_id;
  self->set_nal_temporal_id_plus1 =
      fvv_nal_unit_header_set_nal_temporal_id_plus1;

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_header_destroy(fvv_nal_unit_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_nal_unit_header_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_header_pack(fvv_nal_unit_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;
  buff->pad(buff,
            self->nal_forbidden_zero_bit,
            FVV_BIT_NAL_FORBIDDEN_ZERO_BIT);
  buff->pad(buff, self->nal_unit_type, FVV_BIT_NAL_UNIT_TYPE);
  buff->pad(buff, self->nal_layer_id, FVV_BIT_NAL_LAYER_ID);
  buff->pad(buff,
            self->nal_temporal_id_plus1,
            FVV_BIT_NAL_TEMPORAL_ID_PLUS1);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_header_copy_from(fvv_nal_unit_header_t *self,
                                        fvv_nal_unit_header_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_nal_forbidden_zero_bit(self,
                                   other->nal_forbidden_zero_bit);
  self->set_nal_unit_type(self, other->nal_unit_type);
  self->set_nal_layer_id(self, other->nal_layer_id);
  self->set_nal_temporal_id_plus1(self,
                                  other->nal_temporal_id_plus1);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_header_set_nal_forbidden_zero_bit(
    fvv_nal_unit_header_t *self, uint64_t nal_forbidden_zero_bit)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->nal_forbidden_zero_bit = nal_forbidden_zero_bit;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_nal_unit_header_set_nal_unit_type(fvv_nal_unit_header_t *self,
                                      uint64_t nal_unit_type)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->nal_unit_type = nal_unit_type;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_nal_unit_header_set_nal_layer_id(fvv_nal_unit_header_t *self,
                                     uint64_t nal_layer_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->nal_layer_id = nal_layer_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_header_set_nal_temporal_id_plus1(
    fvv_nal_unit_header_t *self, uint64_t nal_temporal_id_plus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->nal_temporal_id_plus1 = nal_temporal_id_plus1;
  return FVV_RET_SUCCESS;
}
// }