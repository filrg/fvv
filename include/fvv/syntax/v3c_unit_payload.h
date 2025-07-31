#ifndef FVV_SYNTAX_V3C_UNIT_PAYLOAD_H
#define FVV_SYNTAX_V3C_UNIT_PAYLOAD_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.2.3 V3C unit payload syntax
struct fvv_v3c_unit_payload_t
{
  fvv_v3c_unit_t            *vu;
  fvv_bitstream_t           *data;

  fvv_v3c_parameter_set_t   *vps;
  fvv_atlas_sub_bitstream_t *asb;
  fvv_video_sub_bitstream_t *vsb;

  fvv_ret_t (*pack)(fvv_v3c_unit_payload_t *self,
                    uint64_t                numBytesInV3CPayload);
  fvv_ret_t (*copy_from)(fvv_v3c_unit_payload_t *self,
                         fvv_v3c_unit_payload_t *other);
  fvv_ret_t (*set_vps)(fvv_v3c_unit_payload_t  *self,
                       fvv_v3c_parameter_set_t *vps);
  fvv_ret_t (*set_asb)(fvv_v3c_unit_payload_t    *self,
                       fvv_atlas_sub_bitstream_t *asb);
  fvv_ret_t (*set_vsb)(fvv_v3c_unit_payload_t    *self,
                       fvv_video_sub_bitstream_t *vsb);
};

fvv_ret_t fvv_v3c_unit_payload_init(fvv_v3c_unit_payload_t *self,
                                    fvv_v3c_unit_t         *vu,
                                    fvv_bitstream_t        *data);
fvv_ret_t fvv_v3c_unit_payload_destroy(fvv_v3c_unit_payload_t *self);

fvv_ret_t fvv_v3c_unit_payload_pack(fvv_v3c_unit_payload_t *self,
                                    uint64_t numBytesInV3CPayload);
fvv_ret_t
fvv_v3c_unit_payload_copy_from(fvv_v3c_unit_payload_t *self,
                               fvv_v3c_unit_payload_t *other);
fvv_ret_t fvv_v3c_unit_payload_set_vps(fvv_v3c_unit_payload_t  *self,
                                       fvv_v3c_parameter_set_t *vps);
fvv_ret_t
fvv_v3c_unit_payload_set_asb(fvv_v3c_unit_payload_t    *self,
                             fvv_atlas_sub_bitstream_t *asb);
fvv_ret_t
fvv_v3c_unit_payload_set_vsb(fvv_v3c_unit_payload_t    *self,
                             fvv_video_sub_bitstream_t *vsb);

#endif // FVV_SYNTAX_V3C_UNIT_PAYLOAD_H