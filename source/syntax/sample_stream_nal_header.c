#include <fvv/bitstream.h>
#include <fvv/syntax/sample_stream_nal_header.h>

// D.2.1 Sample stream NAL header syntax
// {
fvv_ret_t fvv_sample_stream_nal_header_init(
    fvv_sample_stream_nal_header_t *self,
    fvv_atlas_sub_bitstream_t      *asb,
    fvv_bitstream_t                *data)
{
  *self      = (fvv_sample_stream_nal_header_t){0};
  self->asb  = asb;
  self->data = data;
  self->pack = fvv_sample_stream_nal_header_pack;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sample_stream_nal_header_destroy(
    fvv_sample_stream_nal_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_sample_stream_nal_header_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sample_stream_nal_header_pack(
    fvv_sample_stream_nal_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->pad(buff,
            self->ssnh_unit_size_precision_bytes_minus1,
            FVV_BIT_SSNH_UNIT_SIZE_PRECISION_BYTES_MINUS1);
  buff->pad(buff,
            self->ssnh_reserved_zero_5bits,
            FVV_BIT_SSNH_RESERVED_ZEREO_5BITS);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sample_stream_nal_header_copy_from(
    fvv_sample_stream_nal_header_t *self,
    fvv_sample_stream_nal_header_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ssnh_unit_size_precision_bytes_minus1(
      self, other->ssnh_unit_size_precision_bytes_minus1);
  self->set_ssnh_reserved_zero_5bits(
      self, other->ssnh_reserved_zero_5bits);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_sample_stream_nal_header_set_ssnh_unit_size_precision_bytes_minus1(
    fvv_sample_stream_nal_header_t *self,
    uint64_t ssnh_unit_size_precision_bytes_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ssnh_unit_size_precision_bytes_minus1 =
      ssnh_unit_size_precision_bytes_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sample_stream_nal_header_set_ssnh_reserved_zero_5bits(
    fvv_sample_stream_nal_header_t *self,
    uint64_t                        ssnh_reserved_zero_5bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ssnh_reserved_zero_5bits = ssnh_reserved_zero_5bits;
  return FVV_RET_SUCCESS;
}
// }