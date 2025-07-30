#ifndef FVV_SYNTAX_ACCESS_UNIT_DELIMITER_RBSP_H
#define FVV_SYNTAX_ACCESS_UNIT_DELIMITER_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.5 Access unit delimiter RBSP syntax
struct fvv_access_unit_delimiter_rbsp_t
{
  uint64_t                                 aframe_type; // u(3)
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_access_unit_delimiter_rbsp_t *self);

  fvv_ret_t (*copy_from)(fvv_access_unit_delimiter_rbsp_t *self,
                         fvv_access_unit_delimiter_rbsp_t *other);
  fvv_ret_t (*set_aframe_type)(
      fvv_access_unit_delimiter_rbsp_t *self, uint64_t aframe_type);
  fvv_ret_t (*set_rtb)(fvv_access_unit_delimiter_rbsp_t *self,
                       fvv_rbsp_trailing_bits_t         *rtb);
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
fvv_ret_t fvv_access_unit_delimiter_rbsp_set_aframe_type(
    fvv_access_unit_delimiter_rbsp_t *self, uint64_t aframe_type);
fvv_ret_t fvv_access_unit_delimiter_rbsp_set_rtb(
    fvv_access_unit_delimiter_rbsp_t *self,
    fvv_rbsp_trailing_bits_t         *rtb);

#endif // FVV_SYNTAX_ACCESS_UNIT_DELIMITER_RBSP_H
