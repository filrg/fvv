#include <fvv/syntax/geometry_information.h>
#include <fvv/bitstream.h>
// 8.3.4.4 Geometry information syntax
// {
fvv_ret_t
fvv_geometry_information_init(fvv_geometry_information_t *self,
                              fvv_v3c_parameter_set_t    *vps,
                              fvv_bitstream_t            *data)
{
  *self           = (fvv_geometry_information_t){0};

  self->vps       = vps;
  self->data      = data;
  self->pack      = fvv_geometry_information_pack;
  self->copy_from = fvv_geometry_information_copy_from;
  self->set_gi_geometry_codec_id =
      fvv_geometry_information_set_gi_geometry_codec_id;
  self->set_gi_geometry_2d_bit_depth_minus1 =
      fvv_geometry_information_set_gi_geometry_2d_bit_depth_minus1;
  self->set_gi_geometry_MSB_align_flag =
      fvv_geometry_information_set_gi_geometry_MSB_align_flag;
  self->set_gi_geometry_3d_coordinates_bit_depth_minus1 =
      fvv_geometry_information_set_gi_geometry_3d_coordinates_bit_depth_minus1;
  self->set_gi_auxiliary_geometry_codec_id =
      fvv_geometry_information_set_gi_auxiliary_geometry_codec_id;
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_geometry_information_destroy(fvv_geometry_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_geometry_information_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_geometry_information_pack(fvv_geometry_information_t *self,
                              uint64_t                    atlasID)
{

  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;
  buff->pad(buff,
            self->gi_geometry_codec_id[atlasID],
            FVV_BIT_GI_GEOMETRY_CODEC_ID);
  buff->pad(buff,
            self->gi_geometry_2d_bit_depth_minus1[atlasID],
            FVV_BIT_GI_GEOMETRY_2D_BIT_DEPTH_MINUS1);
  buff->pad(buff,
            self->gi_geometry_MSB_align_flag[atlasID],
            FVV_BIT_GI_GEOMETRY_MSB_ALIGN_FLAG);
  buff->pad(
      buff,
      self->gi_geometry_3d_coordinates_bit_depth_minus1[atlasID],
      FVV_BIT_GI_GEOMETRY_3D_COORDINATES_BIT_DEPTH_MINUS1);
  if (self->vps_auxiliary_video_present_flag[atlasID])
  {
    buff->pad(buff,
              self->gi_auxiliary_geometry_codec_id[atlasID],
              FVV_BIT_GI_AUXILIARY_GEOMETRY_CODEC_ID);
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_geometry_information_copy_from(fvv_geometry_information_t *self,
                                   fvv_geometry_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_gi_geometry_codec_id(self, other->gi_geometry_codec_id);
  self->set_gi_geometry_2d_bit_depth_minus1(
      self, other->gi_geometry_2d_bit_depth_minus1);
  self->set_gi_geometry_MSB_align_flag(
      self, other->gi_geometry_MSB_align_flag);
  self->set_gi_geometry_3d_coordinates_bit_depth_minus1(
      self, other->gi_geometry_3d_coordinates_bit_depth_minus1);
  self->set_gi_auxiliary_geometry_codec_id(
      self, other->gi_auxiliary_geometry_codec_id);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_geometry_information_set_gi_geometry_codec_id(
    fvv_geometry_information_t *self,
    uint64_t gi_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->gi_geometry_codec_id,
         gi_geometry_codec_id,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_geometry_information_set_gi_geometry_2d_bit_depth_minus1(
    fvv_geometry_information_t *self,
    uint64_t
        gi_geometry_2d_bit_depth_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->gi_geometry_2d_bit_depth_minus1,
         gi_geometry_2d_bit_depth_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_geometry_information_set_gi_geometry_MSB_align_flag(
    fvv_geometry_information_t *self,
    uint64_t gi_geometry_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->gi_geometry_MSB_align_flag,
         gi_geometry_MSB_align_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_geometry_information_set_gi_geometry_3d_coordinates_bit_depth_minus1(
    fvv_geometry_information_t *self,
    uint64_t gi_geometry_3d_coordinates_bit_depth_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->gi_geometry_3d_coordinates_bit_depth_minus1,
         gi_geometry_3d_coordinates_bit_depth_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_geometry_information_set_gi_auxiliary_geometry_codec_id(
    fvv_geometry_information_t *self,
    uint64_t
        gi_auxiliary_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->gi_auxiliary_geometry_codec_id,
         gi_auxiliary_geometry_codec_id,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
// }