#include <fvv/bitstream.h>
#include <fvv/syntax/access_unit_delimiter_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.5 Access unit delimiter RBSP syntax
// {
fvv_ret_t fvv_access_unit_delimiter_rbsp_init(
    fvv_access_unit_delimiter_rbsp_t        *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_access_unit_delimiter_rbsp_t){0};
  self->asps     = asps;
  self->data      = data;
  self->pack      = fvv_access_unit_delimiter_rbsp_pack;
  self->copy_from = fvv_access_unit_delimiter_rbsp_copy_from;

  FVV_SET_SETTER_PTR(fvv_access_unit_delimiter_rbsp_t, aframe_type);
  FVV_SET_SETTER_PTR(fvv_access_unit_delimiter_rbsp_t,
                     rtb,
                     fvv_rbsp_trailing_bits_t);

  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_access_unit_delimiter_rbsp_destroy(
    fvv_access_unit_delimiter_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_access_unit_delimiter_rbsp_t,
                  rtb,
                  fvv_rbsp_trailing_bits_t);
  *self = (fvv_access_unit_delimiter_rbsp_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_access_unit_delimiter_rbsp_pack(
    fvv_access_unit_delimiter_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->aframe_type,
                   FVV_BIT_AFRAME_TYPE,
                   FVV_DESCRIPTOR_AFRAME_TYPE);

  self->rtb->pack(self->rtb);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_access_unit_delimiter_rbsp_copy_from(
    fvv_access_unit_delimiter_rbsp_t *self,
    fvv_access_unit_delimiter_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_aframe_type(self, other->aframe_type);
  self->set_rtb(self, other->rtb);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_access_unit_delimiter_rbsp_t,
                         aframe_type);
FVV_DEFINE_OBJ_SETTER(fvv_access_unit_delimiter_rbsp_t,
                      rtb,
                      fvv_rbsp_trailing_bits_t);

// }
