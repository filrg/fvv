#ifndef FVV_SYNTAX_NAL_UNIT_H
#define FVV_SYNTAX_NAL_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.5.1 General NAL unit syntax
struct fvv_nal_unit_t
{
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_nal_unit_t *self,
                    uint64_t        NumBytesInNalUnit);
  fvv_ret_t (*copy_from)(fvv_nal_unit_t *self,
                         fvv_nal_unit_t *other);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_nal_unit_t, rbsp_byte);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_nal_unit_t, nuh, fvv_nal_unit_header_t);
};

fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t  *self,
                            fvv_bitstream_t *data);

fvv_ret_t fvv_nal_unit_destroy(fvv_nal_unit_t *self);

fvv_ret_t fvv_nal_unit_pack(fvv_nal_unit_t *self,
                            uint64_t        NumBytesInNalUnit);
fvv_ret_t fvv_nal_unit_copy_from(fvv_nal_unit_t *self,
                                 fvv_nal_unit_t *other);
FVV_DECLARE_1D_ARR_SETTER(fvv_nal_unit_t, rbsp_byte);
FVV_DECLARE_OBJ_SETTER(fvv_nal_unit_t, nuh, fvv_nal_unit_header_t);
#endif // FVV_SYNTAX_NAL_UNIT_H