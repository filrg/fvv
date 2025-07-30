#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sub_bitstream.h>
#include <fvv/syntax/sample_stream_nal_header.h>
#include <fvv/syntax/sample_stream_nal_unit.h>
#include <fvv/syntax/v3c_unit.h>
#include <fvv/syntax/v3c_unit_payload.h>

// 8.3.2.4 Atlas sub-bitstream syntax
// {
fvv_ret_t
fvv_atlas_sub_bitstream_init(fvv_atlas_sub_bitstream_t *self,
                             fvv_v3c_unit_t            *vu,
                             fvv_bitstream_t           *data)
{
  *self      = (fvv_atlas_sub_bitstream_t){0};

  self->vu   = vu;
  self->data = data;

  self->ssnh = (fvv_sample_stream_nal_header_t *)malloc(
      sizeof(fvv_sample_stream_nal_header_t));
  self->ssnu = (fvv_sample_stream_nal_unit_t *)malloc(
      sizeof(fvv_sample_stream_nal_unit_t));

  fvv_sample_stream_nal_header_init(self->ssnh, vu, data);
  fvv_sample_stream_nal_unit_init(self->ssnu, vu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sub_bitstream_destroy(fvv_atlas_sub_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ssnh)
  {
    fvv_sample_stream_nal_header_destroy(self->ssnh);
    free(self->ssnh);
  }
  if (self->ssnu)
  {
    fvv_sample_stream_nal_unit_destroy(self->ssnu);
    free(self->ssnu);
  }

  *self = (fvv_atlas_sub_bitstream_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_sub_bitstream_pack(fvv_atlas_sub_bitstream_t *self,
                             uint64_t                   numBytes)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t                *buff = FVV_NULL;
  fvv_v3c_unit_t                 *vu   = FVV_NULL;
  fvv_sample_stream_nal_header_t *ssnh = FVV_NULL;
  fvv_sample_stream_nal_unit_t   *ssnu = FVV_NULL;

  vu                                   = self->vu;
  buff                                 = self->data;
  ssnh                                 = vu->vup->asb->ssnh;
  ssnu                                 = vu->vup->asb->ssnu;

  ssnh->pack(ssnh);
  numBytes--;
  while (numBytes > 0)
  {
    ssnu->pack(ssnu);
    numBytes -= ssnu->ssnu_nal_unit_size +
                ssnh->ssnh_unit_size_precision_bytes_minus1 + 1;
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sub_bitstream_copy_from(fvv_atlas_sub_bitstream_t *self,
                                  fvv_atlas_sub_bitstream_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ssnh(self, other->ssnh);
  self->set_ssnu(self, other->ssnu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sub_bitstream_set_ssnh(
    fvv_atlas_sub_bitstream_t      *self,
    fvv_sample_stream_nal_header_t *ssnh)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ssnh->copy_from(self->ssnh, ssnh);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sub_bitstream_set_ssnu(fvv_atlas_sub_bitstream_t    *self,
                                 fvv_sample_stream_nal_unit_t *ssnu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ssnu->copy_from(self->ssnu, ssnu);
  return FVV_RET_SUCCESS;
}

// }