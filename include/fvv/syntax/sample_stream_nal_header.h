#ifndef FVV_SYNTAX_SAMPLE_STREAM_NAL_HEADER_H
#define FVV_SYNTAX_SAMPLE_STREAM_NAL_HEADER_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// D.2.1 Sample stream NAL header syntax
struct fvv_sample_stream_nal_header_t
{
  fvv_bitstream_t *data;
  fvv_v3c_unit_t  *vu;

  uint64_t         ssnh_unit_size_precision_bytes_minus1; // u(3)
  uint64_t         ssnh_reserved_zero_5bits;              // u(5)

  fvv_ret_t (*pack)(fvv_sample_stream_nal_header_t *self);
  fvv_ret_t (*copy_from)(fvv_sample_stream_nal_header_t *self,
                         fvv_sample_stream_nal_header_t *other);
  fvv_ret_t (*set_ssnh_unit_size_precision_bytes_minus1)(
      fvv_sample_stream_nal_header_t *self,
      uint64_t ssnh_unit_size_precision_bytes_minus1);
  fvv_ret_t (*set_ssnh_reserved_zero_5bits)(
      fvv_sample_stream_nal_header_t *self,
      uint64_t                        ssnh_reserved_zero_5bits);
};
fvv_ret_t fvv_sample_stream_nal_header_init(
    fvv_sample_stream_nal_header_t *self,
    fvv_v3c_unit_t                 *vu,
    fvv_bitstream_t                *data);
fvv_ret_t fvv_sample_stream_nal_header_destroy(
    fvv_sample_stream_nal_header_t *self);

fvv_ret_t fvv_sample_stream_nal_header_pack(
    fvv_sample_stream_nal_header_t *self);
fvv_ret_t fvv_sample_stream_nal_header_copy_from(
    fvv_sample_stream_nal_header_t *self,
    fvv_sample_stream_nal_header_t *other);
fvv_ret_t
fvv_sample_stream_nal_header_set_ssnh_unit_size_precision_bytes_minus1(
    fvv_sample_stream_nal_header_t *self,
    uint64_t ssnh_unit_size_precision_bytes_minus1);
fvv_ret_t fvv_sample_stream_nal_header_set_ssnh_reserved_zero_5bits(
    fvv_sample_stream_nal_header_t *self,
    uint64_t                        ssnh_reserved_zero_5bits);
#endif // FVV_SYNTAX_SAMPLE_STREAM_NAL_HEADER_H