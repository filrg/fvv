#ifndef FVV_SYNTAX_FILLER_DATA_RBSP_H
#define FVV_SYNTAX_FILLER_DATA_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.8 Filler data RBSP syntax
struct fvv_filler_data_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *asps;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_filler_data_rbsp_t *self);
  fvv_ret_t (*copy_from)(fvv_filler_data_rbsp_t *self,
                         fvv_filler_data_rbsp_t *other);

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_filler_data_rbsp_t, ff_byte);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_filler_data_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
};
fvv_ret_t fvv_filler_data_rbsp_init(
    fvv_filler_data_rbsp_t                  *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_filler_data_rbsp_destroy(fvv_filler_data_rbsp_t *self);
fvv_ret_t fvv_filler_data_rbsp_pack(fvv_filler_data_rbsp_t *self);
fvv_ret_t
fvv_filler_data_rbsp_copy_from(fvv_filler_data_rbsp_t *self,
                               fvv_filler_data_rbsp_t *other);
                               
FVV_DECLARE_SCALAR_SETTER(fvv_filler_data_rbsp_t, ff_byte);
FVV_DECLARE_OBJ_SETTER(fvv_filler_data_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

#endif // FVV_SYNTAX_FILLER_DATA_RBSP_H
