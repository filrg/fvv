#include <fvv/bitstream.h>
#include <fvv/syntax/occupancy_information.h>
// 8.3.4.3 Occupancy information syntax
// {
fvv_ret_t
fvv_occupancy_information_init(fvv_occupancy_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data)
{
  *self           = (fvv_occupancy_information_t){0};

  self->vps       = vps;
  self->data      = data;

  self->pack      = fvv_occupancy_information_pack;
  self->copy_from = fvv_occupancy_information_copy_from;
  self->set_oi_occupancy_codec_id =
      fvv_occupancy_information_set_oi_occupancy_codec_id;
  self->set_oi_lossy_occupancy_compression_threshold =
      fvv_occupancy_information_set_oi_lossy_occupancy_compression_threshold;
  self->set_oi_occupancy_2d_bit_depth_minus1 =
      fvv_occupancy_information_set_oi_occupancy_2d_bit_depth_minus1;
  self->set_oi_occupancy_MSB_align_flag =
      fvv_occupancy_information_set_oi_occupancy_MSB_align_flag;

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_occupancy_information_destroy(fvv_occupancy_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_occupancy_information_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_occupancy_information_pack(fvv_occupancy_information_t *self,
                               uint64_t                     atlasID)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->pad(buff,
            self->oi_occupancy_codec_id[atlasID],
            FVV_BIT_OI_OCCUPANCY_CODEC_ID);
  buff->pad(buff,
            self->oi_lossy_occupancy_compression_threshold[atlasID],
            FVV_BIT_OI_LOSSY_OCCUPANCY_COMPRESSION_THRESHOLD);
  buff->pad(buff,
            self->oi_occupancy_2d_bit_depth_minus1[atlasID],
            FVV_BIT_OI_OCCUPANCY_2D_BIT_DEPTH_MINUS1);
  buff->pad(buff,
            self->oi_occupancy_MSB_align_flag[atlasID],
            FVV_BIT_OI_OCCUPANCY_MSB_ALIGN_FLAG);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_occupancy_information_copy_from(
    fvv_occupancy_information_t *self,
    fvv_occupancy_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_oi_occupancy_codec_id(self,
                                  other->oi_occupancy_codec_id);
  self->set_oi_lossy_occupancy_compression_threshold(
      self, other->oi_lossy_occupancy_compression_threshold);
  self->set_oi_occupancy_2d_bit_depth_minus1(
      self, other->oi_occupancy_2d_bit_depth_minus1);
  self->set_oi_occupancy_MSB_align_flag(
      self, other->oi_occupancy_MSB_align_flag);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_occupancy_information_set_oi_occupancy_codec_id(
    fvv_occupancy_information_t *self,
    uint64_t oi_occupancy_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->oi_occupancy_codec_id,
         oi_occupancy_codec_id,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_occupancy_information_set_oi_lossy_occupancy_compression_threshold(
    fvv_occupancy_information_t *self,
    uint64_t oi_lossy_occupancy_compression_threshold
        [0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->oi_lossy_occupancy_compression_threshold,
         oi_lossy_occupancy_compression_threshold,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_occupancy_information_set_oi_occupancy_2d_bit_depth_minus1(
    fvv_occupancy_information_t *self,
    uint64_t
        oi_occupancy_2d_bit_depth_minus1[0x1
                                         << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->oi_occupancy_2d_bit_depth_minus1,
         oi_occupancy_2d_bit_depth_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_occupancy_information_set_oi_occupancy_MSB_align_flag(
    fvv_occupancy_information_t *self,
    uint64_t
        oi_occupancy_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->oi_occupancy_MSB_align_flag,
         oi_occupancy_MSB_align_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
// }