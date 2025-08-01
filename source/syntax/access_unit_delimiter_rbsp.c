#include <fvv/bitstream.h>
#include <fvv/syntax/access_unit_delimiter_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.5 Access unit delimiter RBSP syntax
// {
fvv_ret_t fvv_access_unit_delimiter_rbsp_init(
    fvv_access_unit_delimiter_rbsp_t        *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_access_unit_delimiter_rbsp_t){0};
  self->aspsr     = aspsr;
  self->data      = data;
  self->pack      = fvv_access_unit_delimiter_rbsp_pack;
  self->copy_from = fvv_access_unit_delimiter_rbsp_copy_from;
  self->set_aframe_type =
      fvv_access_unit_delimiter_rbsp_set_aframe_type;
  self->set_rtb = fvv_access_unit_delimiter_rbsp_set_rtb;

  self->rtb     = (fvv_rbsp_trailing_bits_t *)malloc(
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
  if (self->rtb)
  {
    fvv_rbsp_trailing_bits_destroy(self->rtb);
    free(self->rtb);
  }
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

  buff->pad(buff, self->aframe_type, FVV_BIT_AFRAME_TYPE);

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
fvv_ret_t fvv_access_unit_delimiter_rbsp_set_aframe_type(
    fvv_access_unit_delimiter_rbsp_t *self, uint64_t aframe_type)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->aframe_type = aframe_type;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_access_unit_delimiter_rbsp_set_rtb(
    fvv_access_unit_delimiter_rbsp_t *self,
    fvv_rbsp_trailing_bits_t         *rtb)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rtb->copy_from(self->rtb, rtb);
  return FVV_RET_SUCCESS;
}

// }
