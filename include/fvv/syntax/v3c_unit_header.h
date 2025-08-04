#ifndef FVV_SYNTAX_V3C_UNIT_HEADER_H
#define FVV_SYNTAX_V3C_UNIT_HEADER_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.2.2 V3C unit header syntax
struct fvv_v3c_unit_header_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;
  fvv_ret_t (*pack)(fvv_v3c_unit_header_t *self);
  fvv_ret_t (*copy_from)(fvv_v3c_unit_header_t *self,
                         fvv_v3c_unit_header_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_unit_type);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_v3c_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_atlas_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_attribute_index);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_attribute_partition_index);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_map_index);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_auxiliary_video_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_reserved_zero_12bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_reserved_zero_17bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_v3c_unit_header_t, vuh_reserved_zero_27bits);
};

fvv_ret_t fvv_v3c_unit_header_init(fvv_v3c_unit_header_t *self,
                                   fvv_v3c_unit_t        *vu,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_v3c_unit_header_destroy(fvv_v3c_unit_header_t *self);

fvv_ret_t fvv_v3c_unit_header_pack(fvv_v3c_unit_header_t *self);
fvv_ret_t
fvv_v3c_unit_header_copy_from(fvv_v3c_unit_header_t *self,
                              fvv_v3c_unit_header_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_unit_type);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_v3c_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_atlas_id);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_attribute_index);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_attribute_partition_index);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_map_index);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_auxiliary_video_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_reserved_zero_12bits);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_reserved_zero_17bits);
FVV_DECLARE_SCALAR_SETTER(fvv_v3c_unit_header_t, vuh_reserved_zero_27bits);

#endif // FVV_SYNTAX_V3C_UNIT_HEADER_H
