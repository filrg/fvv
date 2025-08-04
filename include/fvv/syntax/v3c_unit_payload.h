#ifndef FVV_SYNTAX_V3C_UNIT_PAYLOAD_H
#define FVV_SYNTAX_V3C_UNIT_PAYLOAD_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.2.3 V3C unit payload syntax
struct fvv_v3c_unit_payload_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_v3c_unit_payload_t *self,
                    uint64_t                numBytesInV3CPayload);
  fvv_ret_t (*copy_from)(fvv_v3c_unit_payload_t *self,
                         fvv_v3c_unit_payload_t *other);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_unit_payload_t, vps, fvv_v3c_parameter_set_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_unit_payload_t, asb, fvv_atlas_sub_bitstream_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_v3c_unit_payload_t, vsb, fvv_video_sub_bitstream_t);
};

fvv_ret_t fvv_v3c_unit_payload_init(fvv_v3c_unit_payload_t *self,
                                    fvv_v3c_unit_t         *vu,
                                    fvv_bitstream_t        *data);
fvv_ret_t fvv_v3c_unit_payload_destroy(fvv_v3c_unit_payload_t *self);

fvv_ret_t fvv_v3c_unit_payload_pack(fvv_v3c_unit_payload_t *self,
                                    uint64_t                numBytesInV3CPayload);
fvv_ret_t
fvv_v3c_unit_payload_copy_from(fvv_v3c_unit_payload_t *self,
                               fvv_v3c_unit_payload_t *other);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_unit_payload_t, vps, fvv_v3c_parameter_set_t);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_unit_payload_t, asb, fvv_atlas_sub_bitstream_t);
FVV_DECLARE_OBJ_SETTER(fvv_v3c_unit_payload_t, vsb, fvv_video_sub_bitstream_t);
#endif // FVV_SYNTAX_V3C_UNIT_PAYLOAD_H