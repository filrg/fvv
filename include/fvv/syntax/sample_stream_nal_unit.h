#ifndef FVV_SYNTAX_SAMPLE_STREAM_NAL_UNIT_H
#define FVV_SYNTAX_SAMPLE_STREAM_NAL_UNIT_H
// D.2.2 Sample stream NAL unit syntax
struct fvv_sample_stream_nal_unit_t
{
  fvv_atlas_sub_bitstream_t *asb;
  fvv_bitstream_t           *data;

  uint64_t                   ssnu_nal_unit_size; // u(v)
  fvv_nal_unit_t            *nu;

  fvv_ret_t (*pack)(fvv_sample_stream_nal_unit_t *self);
  fvv_ret_t (*copy_from)(fvv_sample_stream_nal_unit_t *self,
                         fvv_sample_stream_nal_unit_t *other);
  fvv_ret_t (*set_ssnu_nal_unit_size)(
      fvv_sample_stream_nal_unit_t *self,
      uint64_t                      ssnu_nal_unit_size);
  fvv_ret_t (*set_nu)(fvv_sample_stream_nal_unit_t *self,
                      fvv_nal_unit_t               *nu);
};
fvv_ret_t
fvv_sample_stream_nal_unit_init(fvv_sample_stream_nal_unit_t *self,
                                fvv_atlas_sub_bitstream_t    *asb,
                                fvv_bitstream_t              *data);
fvv_ret_t fvv_sample_stream_nal_unit_destroy(
    fvv_sample_stream_nal_unit_t *self);

fvv_ret_t
fvv_sample_stream_nal_unit_pack(fvv_sample_stream_nal_unit_t *self);
fvv_ret_t fvv_sample_stream_nal_unit_copy_from(
    fvv_sample_stream_nal_unit_t *self,
    fvv_sample_stream_nal_unit_t *other);
fvv_ret_t fvv_sample_stream_nal_unit_set_ssnu_nal_unit_size(
    fvv_sample_stream_nal_unit_t *self, uint64_t ssnu_nal_unit_size);
fvv_ret_t
fvv_sample_stream_nal_unit_set_nu(fvv_sample_stream_nal_unit_t *self,
                                  fvv_nal_unit_t               *nu);

#endif // FVV_SYNTAX_SAMPLE_STREAM_NAL_UNIT_H