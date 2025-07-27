#ifndef FVV_SYNTAX_FILLER_DATA_RBSP_H
#define FVV_SYNTAX_FILLER_DATA_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.8 Filler data RBSP syntax
struct fvv_filler_data_rbsp_t
{
  uint64_t                                 ff_byte; // f(8)
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_filler_data_rbsp_t *self);
};
fvv_ret_t fvv_filler_data_rbsp_init(
    fvv_filler_data_rbsp_t                  *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_filler_data_rbsp_destroy(fvv_filler_data_rbsp_t *self);
fvv_ret_t fvv_filler_data_rbsp_pack(fvv_filler_data_rbsp_t *self);

#endif // FVV_SYNTAX_FILLER_DATA_RBSP_H