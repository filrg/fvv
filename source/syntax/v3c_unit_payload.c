#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sub_bitstream.h>
#include <fvv/syntax/v3c_parameter_set.h>
#include <fvv/syntax/v3c_unit.h>
#include <fvv/syntax/v3c_unit_header.h>
#include <fvv/syntax/v3c_unit_payload.h>
// #include <fvv/syntax/video_sub_bitstream.h>

// 8.3.2.3 V3C unit payload syntax
// {
fvv_ret_t fvv_v3c_unit_payload_init(fvv_v3c_unit_payload_t *self,
                                    fvv_v3c_unit_t         *vu,
                                    fvv_bitstream_t        *data)
{
  *self           = (fvv_v3c_unit_payload_t){0};

  self->pack      = fvv_v3c_unit_payload_pack;
  self->copy_from = fvv_v3c_unit_copy_from;
  self->vu        = vu;
  self->data      = data;

  FVV_SET_SETTER_PTR(fvv_v3c_unit_payload_t, vps, fvv_v3c_parameter_set_t);
  FVV_SET_SETTER_PTR(fvv_v3c_unit_payload_t, asb, fvv_atlas_sub_bitstream_t);
  FVV_SET_SETTER_PTR(fvv_v3c_unit_payload_t, vsb, fvv_video_sub_bitstream_t);

  self->vps = (fvv_v3c_parameter_set_t *)malloc(
      sizeof(fvv_v3c_parameter_set_t));
  self->asb = (fvv_atlas_sub_bitstream_t *)malloc(
      sizeof(fvv_atlas_sub_bitstream_t));
  self->vsb = (fvv_video_sub_bitstream_t *)malloc(
      sizeof(fvv_video_sub_bitstream_t));

  fvv_v3c_parameter_set_init(self->vps, vu, data);
  fvv_atlas_sub_bitstream_init(self->asb, vu, data);
  fvv_video_sub_bitstream_init(self->vsb, vu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_unit_payload_destroy(fvv_v3c_unit_payload_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_v3c_unit_payload_t, vps, fvv_v3c_parameter_set_t);
  FVV_DESTROY_OBJ(fvv_v3c_unit_payload_t, asb, fvv_atlas_sub_bitstream_t);
  FVV_DESTROY_OBJ(fvv_v3c_unit_payload_t, vsb, fvv_video_sub_bitstream_t);
  *self = (fvv_v3c_unit_payload_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_payload_pack(fvv_v3c_unit_payload_t *self,
                                    uint64_t                numBytesInV3CPayload)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t           *buff = FVV_NULL;
  fvv_v3c_unit_header_t     *vuh  = FVV_NULL;
  fvv_v3c_parameter_set_t   *vps  = FVV_NULL;
  fvv_atlas_sub_bitstream_t *asb  = FVV_NULL;
  fvv_video_sub_bitstream_t *vsb  = FVV_NULL;

  vuh                             = self->vu->vuh;
  buff                            = self->data;
  vps                             = self->vps;
  asb                             = self->asb;
  vsb                             = self->vsb;

  if (vuh->vuh_unit_type == FVV_V3C_VPS)
  {
    vps->pack(vps);
  }
  else if (vuh->vuh_unit_type == FVV_V3C_AD)
  {
    asb->pack(asb, numBytesInV3CPayload);
  }
  else if (vuh->vuh_unit_type == FVV_V3C_OVD ||
           vuh->vuh_unit_type == FVV_V3C_GVD ||
           vuh->vuh_unit_type == FVV_V3C_AVD)
  {
    vsb->pack(vsb, numBytesInV3CPayload);
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_unit_payload_copy_from(fvv_v3c_unit_payload_t *self,
                               fvv_v3c_unit_payload_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_vps(self, other->vps);
  self->set_asb(self, other->asb);
  self->set_vsb(self, other->vsb);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_OBJ_SETTER(fvv_v3c_unit_payload_t, vps, fvv_v3c_parameter_set_t);
FVV_DEFINE_OBJ_SETTER(fvv_v3c_unit_payload_t, asb, fvv_atlas_sub_bitstream_t);
FVV_DEFINE_OBJ_SETTER(fvv_v3c_unit_payload_t, vsb, fvv_video_sub_bitstream_t);

// }