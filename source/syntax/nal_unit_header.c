#include <fvv/bitstream.h>
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
  FVV_SET_SETTER_PTR(fvv_nal_unit_header_t, nal_forbidden_zero_bit);
  FVV_SET_SETTER_PTR(fvv_nal_unit_header_t, nal_unit_type);
  FVV_SET_SETTER_PTR(fvv_nal_unit_header_t, nal_layer_id);
  FVV_SET_SETTER_PTR(fvv_nal_unit_header_t, nal_temporal_id_plus1);

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
FVV_DEFINE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_forbidden_zero_bit);
FVV_DEFINE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_unit_type);
FVV_DEFINE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_layer_id);
FVV_DEFINE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_temporal_id_plus1);
// }