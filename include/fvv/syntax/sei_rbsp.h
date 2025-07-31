#ifndef FVV_SYNTAX_SEI_RBSP_H
#define FVV_SYNTAX_SEI_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.4 Supplemental enhancement information RBSP syntax
struct fvv_sei_rbsp_t
{
  fvv_sei_message_t         *sm;
  fvv_rbsp_trailing_bits_t  *rtb;

  fvv_atlas_sub_bitstream_t *asb;
  fvv_bitstream_t           *data;

  fvv_ret_t (*pack)(fvv_sei_rbsp_t *self);

  fvv_ret_t (*copy_from)(fvv_sei_rbsp_t *self,
                         fvv_sei_rbsp_t *other);

  fvv_ret_t (*set_sm)(fvv_sei_rbsp_t *self, fvv_sei_rbsp_t *sm);
  fvv_ret_t (*set_rtb)(fvv_sei_rbsp_t           *self,
                       fvv_rbsp_trailing_bits_t *rtb);
};

fvv_ret_t fvv_sei_rbsp_init(fvv_sei_rbsp_t            *self,
                            fvv_atlas_sub_bitstream_t *asb,
                            fvv_bitstream_t           *data);
fvv_ret_t fvv_sei_rbsp_destroy(fvv_sei_rbsp_t *self);
fvv_ret_t fvv_sei_rbsp_pack(fvv_sei_rbsp_t *self);
fvv_ret_t fvv_sei_rbsp_copy_from(fvv_sei_rbsp_t *self,
                                 fvv_sei_rbsp_t *other);
fvv_ret_t fvv_sei_rbsp_set_sm(fvv_sei_rbsp_t    *self,
                              fvv_sei_message_t *sm);
fvv_ret_t fvv_sei_rbsp_set_rtb(fvv_sei_rbsp_t           *self,
                               fvv_rbsp_trailing_bits_t *rtb);

#endif // FVV_SYNTAX_SEI_RBSP_H
