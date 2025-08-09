#ifndef FVV_SYNTAX_SEI_MANIFEST_H
#define FVV_SYNTAX_SEI_MANIFEST_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.8 SEI manifest SEI message syntax
struct fvv_sei_manifest_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_manifest_t,
                                manifest_num_sei_msg_types);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_sei_manifest_t,
      manifest_sei_payload_type,
      0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_sei_manifest_t,
      manifest_sei_description,
      0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);

  fvv_ret_t (*pack)(fvv_sei_manifest_t *self, uint64_t payloadSize);
  fvv_ret_t (*copy_from)(fvv_sei_manifest_t *self,
                         fvv_sei_manifest_t *other);
};

fvv_ret_t fvv_sei_manifest_init(fvv_sei_manifest_t *self,
                                fvv_bitstream_t    *data);
fvv_ret_t fvv_sei_manifest_destroy(fvv_sei_manifest_t *self);
fvv_ret_t fvv_sei_manifest_pack(fvv_sei_manifest_t *self,
                                uint64_t            payloadSize);
fvv_ret_t fvv_sei_manifest_copy_from(fvv_sei_manifest_t *self,
                                     fvv_sei_manifest_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_sei_manifest_t,
                          manifest_num_sei_msg_types);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_sei_manifest_t,
    manifest_sei_payload_type,
    0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_sei_manifest_t,
    manifest_sei_description,
    0x1 << FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES);

#endif // FVV_SYNTAX_SEI_MANIFEST_H