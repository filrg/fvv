#ifndef FVV_SYNTAX_SAMPLE_STREAM_NAL_UNIT_H
#define FVV_SYNTAX_SAMPLE_STREAM_NAL_UNIT_H
// D.2.2 Sample stream NAL unit syntax
struct fvv_sample_stream_nal_unit_t
{
  fvv_atlas_sub_bitstream_t *asb;
  fvv_bitstream_t           *data;
  fvv_ret_t (*pack)(fvv_sample_stream_nal_unit_t *self);
  fvv_ret_t (*copy_from)(fvv_sample_stream_nal_unit_t *self,
                         fvv_sample_stream_nal_unit_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sample_stream_nal_unit_t, ssnu_nal_unit_size);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sample_stream_nal_unit_t, nu, fvv_nal_unit_t);
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
FVV_DECLARE_SCALAR_SETTER(fvv_sample_stream_nal_unit_t, ssnu_nal_unit_size);
FVV_DECLARE_OBJ_SETTER(fvv_sample_stream_nal_unit_t, nu, fvv_nal_unit_t);
#endif // FVV_SYNTAX_SAMPLE_STREAM_NAL_UNIT_H