#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sub_bitstream.h>
#include <fvv/syntax/nal_unit.h>
#include <fvv/syntax/sample_stream_nal_header.h>
#include <fvv/syntax/sample_stream_nal_unit.h>

// D.2.2 Sample stream NAL unit syntax
// {
fvv_ret_t
fvv_sample_stream_nal_unit_init(fvv_sample_stream_nal_unit_t *self,
                                fvv_v3c_unit_t               *asb,
                                fvv_bitstream_t              *data)
{
  *self      = (fvv_sample_stream_nal_unit_t){0};
  self->data = data;
  self->asb  = asb;

  self->pack = fvv_sample_stream_nal_unit_pack;
  FVV_SET_SETTER_PTR(fvv_sample_stream_nal_unit_t,
                     ssnu_nal_unit_size);
  FVV_SET_SETTER_PTR(
      fvv_sample_stream_nal_unit_t, nu, fvv_nal_unit_t);

  self->nu = (fvv_nal_unit_t *)malloc(sizeof(fvv_nal_unit_t));

  fvv_nal_unit_init(self->nu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_sample_stream_nal_unit_destroy(fvv_sample_stream_nal_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_sample_stream_nal_unit_t, nu, fvv_nal_unit_t);
  *self = (fvv_sample_stream_nal_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_sample_stream_nal_unit_pack(fvv_sample_stream_nal_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff                                  = FVV_NULL;
  fvv_nal_unit_t  *nu                                    = FVV_NULL;
  uint64_t         ssnh_unit_size_precision_bytes_minus1 = 0;

  buff                                                   = self->data;
  nu                                                     = self->nu;

  ssnh_unit_size_precision_bytes_minus1 =
      self->asb->ssnh->ssnh_unit_size_precision_bytes_minus1;

  buff->write_bits(buff,
                   self->ssnu_nal_unit_size,
                   (ssnh_unit_size_precision_bytes_minus1 + 1) *
                       FVV_BITS_PER_BYTE,
                   FVV_DESCRIPTOR_SSNU_NAL_UNIT_SIZE);
  nu->pack(nu, self->ssnu_nal_unit_size);
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sample_stream_nal_unit_copy_from(
    fvv_sample_stream_nal_unit_t *self,
    fvv_sample_stream_nal_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (!other)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ssnu_nal_unit_size(self, other->ssnu_nal_unit_size);
  self->set_nu(self, other->nu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sample_stream_nal_unit_set_ssnu_nal_unit_size(
    fvv_sample_stream_nal_unit_t *self, uint64_t ssnu_nal_unit_size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ssnu_nal_unit_size = ssnu_nal_unit_size;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_sample_stream_nal_unit_set_nu(fvv_sample_stream_nal_unit_t *self,
                                  fvv_nal_unit_t               *nu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->nu->copy_from(self->nu, nu);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(fvv_sample_stream_nal_unit_t,
                         ssnu_nal_unit_size);
FVV_DEFINE_OBJ_SETTER(fvv_sample_stream_nal_unit_t,
                      nu,
                      fvv_nal_unit_t);
// }
