#ifndef FVV_SYNTAX_SEI_RBSP_H
#define FVV_SYNTAX_SEI_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.4 Supplemental enhancement information RBSP syntax
struct fvv_sei_rbsp_t
{
  fvv_sei_message_t                       *se;
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_sei_rbsp_t *self);
};

fvv_ret_t
          fvv_sei_rbsp_init(fvv_sei_rbsp_t                          *self,
                            fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
                            fvv_bitstream_t                         *data);
fvv_ret_t fvv_sei_rbsp_destroy(fvv_sei_rbsp_t *self);
fvv_ret_t fvv_sei_rbsp_pack(fvv_sei_rbsp_t *self);
#endif // FVV_SYNTAX_SEI_RBSP_H