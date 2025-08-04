#ifndef FVV_SYNTAX_NAL_UNIT_HEADER_H
#define FVV_SYNTAX_NAL_UNIT_HEADER_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.5.2 NAL unit header syntax
struct fvv_nal_unit_header_t
{
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_nal_unit_header_t *self);
  fvv_ret_t (*copy_from)(fvv_nal_unit_header_t *self,
                         fvv_nal_unit_header_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_nal_unit_header_t, nal_forbidden_zero_bit);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_nal_unit_header_t, nal_unit_type);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_nal_unit_header_t, nal_layer_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_nal_unit_header_t, nal_temporal_id_plus1);
};

fvv_ret_t fvv_nal_unit_header_init(fvv_nal_unit_header_t *self,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_nal_unit_header_destroy(fvv_nal_unit_header_t *self);
fvv_ret_t fvv_nal_unit_header_pack(fvv_nal_unit_header_t *self);
fvv_ret_t
fvv_nal_unit_header_copy_from(fvv_nal_unit_header_t *self,
                              fvv_nal_unit_header_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_forbidden_zero_bit);
FVV_DECLARE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_unit_type);
FVV_DECLARE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_layer_id);
FVV_DECLARE_SCALAR_SETTER(fvv_nal_unit_header_t, nal_temporal_id_plus1);
#endif // FVV_SYNTAX_NAL_UNIT_HEADER_H