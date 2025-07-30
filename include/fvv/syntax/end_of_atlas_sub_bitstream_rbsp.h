#ifndef FVV_SYNTAX_END_OF_ATLAS_SUB_BITSTREAM_RBSP_H
#define FVV_SYNTAX_END_OF_ATLAS_SUB_BITSTREAM_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.7 End of bitstream RBSP syntax
struct fvv_end_of_atlas_sub_bitstream_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_end_of_atlas_sub_bitstream_rbsp_t *self);
  fvv_ret_t (*copy_from)(fvv_end_of_atlas_sub_bitstream_rbsp_t *self, fvv_end_of_atlas_sub_bitstream_rbsp_t *other);
};

fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_init(
    fvv_end_of_atlas_sub_bitstream_rbsp_t   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_destroy(
    fvv_end_of_atlas_sub_bitstream_rbsp_t *self);
fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_pack(
    fvv_end_of_atlas_sub_bitstream_rbsp_t *self);
fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_copy_from(fvv_end_of_atlas_sub_bitstream_rbsp_t *self, fvv_end_of_atlas_sub_bitstream_rbsp_t *other);
#endif // FVV_SYNTAX_END_OF_ATLAS_SUB_BITSTREAM_RBSP_H
