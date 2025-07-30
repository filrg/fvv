#ifndef FVV_SYNTAX_V3C_UNIT_HEADER_H
#define FVV_SYNTAX_V3C_UNIT_HEADER_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.2.2 V3C unit header syntax
struct fvv_v3c_unit_header_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  uint64_t         vuh_unit_type;                 // u(5)
  uint64_t         vuh_v3c_parameter_set_id;      // u(4)
  uint64_t         vuh_atlas_id;                  // u(6)
  uint64_t         vuh_attribute_index;           // u(7)
  uint64_t         vuh_attribute_partition_index; // u(5)
  uint64_t         vuh_map_index;                 // u(4)
  uint64_t         vuh_auxiliary_video_flag;      // u(1)
  uint64_t         vuh_reserved_zero_12bits;      // u(12)
  uint64_t         vuh_reserved_zero_17bits;      // u(17)
  uint64_t         vuh_reserved_zero_27bits;      // u(27)

  fvv_ret_t (*pack)(fvv_v3c_unit_header_t *self);
  fvv_ret_t (*copy_from)(fvv_v3c_unit_header_t *self,
                         fvv_v3c_unit_header_t *other);

  fvv_ret_t (*set_vuh_unit_type)(fvv_v3c_unit_header_t *self,
                                 uint64_t vuh_unit_type);
  fvv_ret_t (*set_vuh_v3c_parameter_set_id)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_v3c_parameter_set_id);
  fvv_ret_t (*set_vuh_atlas_id)(fvv_v3c_unit_header_t *self,
                                uint64_t               vuh_atlas_id);
  fvv_ret_t (*set_vuh_attribute_index)(fvv_v3c_unit_header_t *self,
                                       uint64_t vuh_attribute_index);
  fvv_ret_t (*set_vuh_attribute_partition_index)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_attribute_partition_index);
  fvv_ret_t (*set_vuh_map_index)(fvv_v3c_unit_header_t *self,
                                 uint64_t vuh_map_index);
  fvv_ret_t (*set_vuh_auxiliary_video_flag)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_auxiliary_video_flag);
  fvv_ret_t (*set_vuh_reserved_zero_12bits)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_reserved_zero_12bits);
  fvv_ret_t (*set_vuh_reserved_zero_17bits)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_reserved_zero_17bits);
  fvv_ret_t (*set_vuh_reserved_zero_27bits)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_reserved_zero_27bits);
};

fvv_ret_t fvv_v3c_unit_header_init(fvv_v3c_unit_header_t *self,
                                   fvv_v3c_unit_t        *vu,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_v3c_unit_header_destroy(fvv_v3c_unit_header_t *self);

fvv_ret_t fvv_v3c_unit_header_pack(fvv_v3c_unit_header_t *self);
fvv_ret_t
fvv_v3c_unit_header_copy_from(fvv_v3c_unit_header_t *self,
                              fvv_v3c_unit_header_t *other);

fvv_ret_t
fvv_v3c_unit_header_set_vuh_unit_type(fvv_v3c_unit_header_t *self,
                                      uint64_t vuh_unit_type);
fvv_ret_t fvv_v3c_unit_header_set_vuh_v3c_parameter_set_id(
    fvv_v3c_unit_header_t *self, uint64_t vuh_v3c_parameter_set_id);
fvv_ret_t
fvv_v3c_unit_header_set_vuh_atlas_id(fvv_v3c_unit_header_t *self,
                                     uint64_t vuh_atlas_id);
fvv_ret_t fvv_v3c_unit_header_set_vuh_attribute_index(
    fvv_v3c_unit_header_t *self, uint64_t vuh_attribute_index);
fvv_ret_t fvv_v3c_unit_header_set_vuh_attribute_partition_index(
    fvv_v3c_unit_header_t *self,
    uint64_t               vuh_attribute_partition_index);
fvv_ret_t
fvv_v3c_unit_header_set_vuh_map_index(fvv_v3c_unit_header_t *self,
                                      uint64_t vuh_map_index);
fvv_ret_t fvv_v3c_unit_header_set_vuh_auxiliary_video_flag(
    fvv_v3c_unit_header_t *self, uint64_t vuh_auxiliary_video_flag);
fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_12bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_12bits);
fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_17bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_17bits);
fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_27bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_27bits);

#endif // FVV_SYNTAX_V3C_UNIT_HEADER_H