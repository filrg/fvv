#ifndef FVV_SYNTAX_V3C_UNIT_H
#define FVV_SYNTAX_V3C_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.2 V3C unit syntax
// 8.3.2.1 General V3C unit syntax
struct fvv_v3c_unit_t
{
  fvv_bitstream_t        *data;

  fvv_v3c_unit_header_t  *vuh;
  fvv_v3c_unit_payload_t *vup;

  fvv_ret_t (*pack)(fvv_v3c_unit_t *self,
                    uint64_t        numBytesInV3CUnit);

  fvv_ret_t (*copy_from)(fvv_v3c_unit_t *self,
                         fvv_v3c_unit_t *other);

  fvv_ret_t (*set_vuh)(fvv_v3c_unit_t        *self,
                       fvv_v3c_unit_header_t *vuh);
  fvv_ret_t (*set_vup)(fvv_v3c_unit_t         *self,
                       fvv_v3c_unit_payload_t *vup);
};

fvv_ret_t fvv_v3c_unit_init(fvv_v3c_unit_t  *self,
                            fvv_bitstream_t *data);
fvv_ret_t fvv_v3c_unit_destroy(fvv_v3c_unit_t *self);

fvv_ret_t fvv_v3c_unit_pack(fvv_v3c_unit_t *self,
                            uint64_t        numBytesInV3CUnit);

fvv_ret_t fvv_v3c_unit_copy_from(fvv_v3c_unit_t *self,
                                 fvv_v3c_unit_t *other);
fvv_ret_t fvv_v3c_unit_set_vuh(fvv_v3c_unit_t        *self,
                               fvv_v3c_unit_header_t *vuh);
fvv_ret_t fvv_v3c_unit_set_vup(fvv_v3c_unit_t         *self,
                               fvv_v3c_unit_payload_t *vup);

#endif