#ifndef FVV_SYNTAX_ACCESS_UNIT_DELIMITER_RBSP_H
#define FVV_SYNTAX_ACCESS_UNIT_DELIMITER_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.5 Access unit delimiter RBSP syntax
struct fvv_access_unit_delimiter_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_access_unit_delimiter_rbsp_t *self);

  fvv_ret_t (*copy_from)(fvv_access_unit_delimiter_rbsp_t *self,
                         fvv_access_unit_delimiter_rbsp_t *other);

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_access_unit_delimiter_rbsp_t, aframe_type);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_access_unit_delimiter_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
};
fvv_ret_t fvv_access_unit_delimiter_rbsp_init(
    fvv_access_unit_delimiter_rbsp_t        *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_access_unit_delimiter_rbsp_destroy(
    fvv_access_unit_delimiter_rbsp_t *self);
fvv_ret_t fvv_access_unit_delimiter_rbsp_pack(
    fvv_access_unit_delimiter_rbsp_t *self);
fvv_ret_t fvv_access_unit_delimiter_rbsp_copy_from(
    fvv_access_unit_delimiter_rbsp_t *self,
    fvv_access_unit_delimiter_rbsp_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_access_unit_delimiter_rbsp_t, aframe_type);
FVV_DECLARE_OBJ_SETTER(fvv_access_unit_delimiter_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

#endif // FVV_SYNTAX_ACCESS_UNIT_DELIMITER_RBSP_H
