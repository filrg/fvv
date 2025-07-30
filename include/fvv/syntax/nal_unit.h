#ifndef FVV_SYNTAX_NAL_UNIT_H
#define FVV_SYNTAX_NAL_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.5.1 General NAL unit syntax
struct fvv_nal_unit_t
{
  uint64_t              *rbsp_byte;
  fvv_nal_unit_header_t *nuh;

  fvv_v3c_unit_t        *vu;
  fvv_bitstream_t       *data;

  uint64_t               rbsp_byte_size;

  fvv_ret_t (*pack)(fvv_nal_unit_t *self,
                    uint64_t        NumBytesInNalUnit);
  fvv_ret_t (*copy_from)(fvv_nal_unit_t *self,
                         fvv_nal_unit_t *other);
  fvv_ret_t (*set_rbsp_byte)(fvv_nal_unit_t *self,
                             uint64_t       *rbsp_byte,
                             uint64_t        rbsp_byte_size);
  fvv_ret_t (*set_nal_unit_header)(fvv_nal_unit_t        *self,
                                   fvv_nal_unit_header_t *nuh);
};

fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t  *self,
                            fvv_v3c_unit_t  *vu,
                            fvv_bitstream_t *data);

fvv_ret_t fvv_nal_unit_destroy(fvv_nal_unit_t *self);

fvv_ret_t fvv_nal_unit_pack(fvv_nal_unit_t *self,
                            uint64_t        NumBytesInNalUnit);
fvv_ret_t fvv_nal_unit_copy_from(fvv_nal_unit_t *self,
                                 fvv_nal_unit_t *other);
fvv_ret_t fvv_nal_unit_set_rbsp_byte(fvv_nal_unit_t *self,
                                     uint64_t       *rbsp_byte,
                                     uint64_t        rbsp_byte_size);
fvv_ret_t
fvv_nal_unit_set_nal_unit_header(fvv_nal_unit_t        *self,
                                 fvv_nal_unit_header_t *nuh);
#endif // FVV_SYNTAX_NAL_UNIT_H