#include <fvv/syntax/attribute_information.h>

// 8.3.4.5 Attribute information syntax
// {
fvv_ret_t
fvv_attribute_information_init(fvv_attribute_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data)
{
  *self           = (fvv_attribute_information_t){0};

  self->vps       = vps;
  self->data      = data;

  self->pack      = fvv_attribute_information_pack;
  self->copy_from = fvv_attribute_information_copy_from;
  self->set_ai_attribute_count =
      fvv_attribute_information_set_ai_attribute_count;
  self->set_ai_attribute_type_id =
      fvv_attribute_information_set_ai_attribute_type_id;
  self->set_ai_attribute_codec_id =
      fvv_attribute_information_set_ai_attribute_codec_id;
  self->set_ai_auxiliary_attribute_codec_id =
      fvv_attribute_information_set_ai_auxiliary_attribute_codec_id;
  self->set_ai_attribute_map_absolute_coding_persistence_flag =
      fvv_attribute_information_set_ai_attribute_map_absolute_coding_persistence_flag;
  self->set_ai_attribute_dimension_minus1 =
      fvv_attribute_information_set_ai_attribute_dimension_minus1;
  self->set_ai_attribute_dimension_partitions_minus1 =
      fvv_attribute_information_set_ai_attribute_dimension_partitions_minus1;
  self->set_ai_attribute_partition_channels_minus1 =
      fvv_attribute_information_set_ai_attribute_partition_channels_minus1;
  self->set_ai_attribute_2d_bit_depth_minus1 =
      fvv_attribute_information_set_ai_attribute_2d_bit_depth_minus1;
  self->set_ai_attribute_MSB_align_flag =
      fvv_attribute_information_set_ai_attribute_MSB_align_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_destroy(fvv_attribute_information_t *self)
{
  (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  *self = (fvv_attribute_information_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_attribute_information_pack(fvv_attribute_information_t *self,
                               uint64_t                     atlasID)
{
  (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff                = FVV_NULL;
  uint64_t         i                   = 0;
  uint64_t         j                   = 0;
  uint64_t         k                   = 0;
  uint64_t         remainingDimensions = 0;
  buff                                 = self->data;

  buff->pad(buff,
            self->ai_attribute_count[atlasID],
            FVV_BIT_AI_ATTRIBUTE_COUNT);
  for (i = 0; i < self->ai_attribute_count[atlasID]; i++)
  {
    buff->pad(buff,
              self->ai_attribute_type_id[atlasID][i],
              FVV_BIT_AI_ATTRIBUTE_TYPE_ID);
    buff->pad(buff,
              self->ai_attribute_codec_id[atlasID][i],
              FVV_BIT_AI_ATTRIBUTE_CODEC_ID);
    if (self->vps_auxiliary_video_present_flag[atlasID])
    {
      buff->pad(buff,
                self->ai_auxiliary_attribute_codec_id[atlasID][i],
                FVV_BIT_AI_AUXILIARY_ATTRIBUTE_CODEC_ID);
    }
    if (self->vps_map_count_minus1[atlasID] > 0)
    {
      buff->pad(
          buff,
          self->ai_attribute_map_absolute_coding_persistence_flag
              [atlasID][i],
          FVV_BIT_AI_ATTRIBUTE_MAP_ABSOLUTE_CODING_PERSISTENCE_FLAG);
    }
    buff->pad(buff,
              self->ai_attribute_dimension_minus1[atlasID][i],
              FVV_BIT_AI_ATTRIBUTE_DIMENSION_MINUS1);
    if (self->ai_attribute_dimension_minus1[atlasID][i] > 0)
    {
      buff->pad(
          buff,
          self->ai_attribute_dimension_partitions_minus1[atlasID][i],
          FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1);

      remainingDimensions =
          self->ai_attribute_dimension_minus1[atlasID][i];
      k = self->ai_attribute_dimension_partitions_minus1[atlasID][i];
      for (j = 0; j < k; j++)
      {
        if (k - j == remainingDimensions)
        {
          self->ai_attribute_partition_channels_minus1[atlasID][i]
                                                      [j] = 0;
        }
        else
        {
          buff->pad(
              buff,
              self->ai_attribute_partition_channels_minus1[atlasID]
                                                          [i][j],
              FVV_BIT_AI_ATTRIBUTE_PARTITION_CHANNELS_MINUS1);
        }
        remainingDimensions -=
            self->ai_attribute_partition_channels_minus1[atlasID][i]
                                                        [j] +
            1;
      }
      self->ai_attribute_partition_channels_minus1[atlasID][i][k] =
          remainingDimensions;
    }
    buff->pad(buff,
              self->ai_attribute_2d_bit_depth_minus1[atlasID][i],
              FVV_BIT_AI_ATTRIBUTE_2D_BIT_DEPTH_MINUS1);
    buff->pad(buff,
              self->ai_attribute_MSB_align_flag[atlasID][i],
              FVV_BIT_AI_ATTRIBUTE_MSB_ALIGN_FLAG);
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_attribute_information_copy_from(
    fvv_attribute_information_t *self,
    fvv_attribute_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ai_attribute_count(self, other->ai_attribute_count);
  self->set_ai_attribute_type_id(self, other->ai_attribute_type_id);
  self->set_ai_attribute_codec_id(self,
                                  other->ai_attribute_codec_id);
  self->set_ai_auxiliary_attribute_codec_id(
      self, other->ai_auxiliary_attribute_codec_id);
  self->set_ai_attribute_map_absolute_coding_persistence_flag(
      self,
      other->ai_attribute_map_absolute_coding_persistence_flag);
  self->set_ai_attribute_dimension_minus1(
      self, other->ai_attribute_dimension_minus1);
  self->set_ai_attribute_dimension_partitions_minus1(
      self, other->ai_attribute_dimension_partitions_minus1);
  self->set_ai_attribute_partition_channels_minus1(
      self, other->ai_attribute_partition_channels_minus1);
  self->set_ai_attribute_2d_bit_depth_minus1(
      self, other->ai_attribute_2d_bit_depth_minus1);
  self->set_ai_attribute_MSB_align_flag(
      self, other->ai_attribute_MSB_align_flag);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_attribute_information_set_ai_attribute_count(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_count[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_count,
         ai_attribute_count,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_attribute_information_set_ai_attribute_type_id(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_type_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                                 [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_type_id,
         ai_attribute_type_id,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_attribute_information_set_ai_attribute_codec_id(
    fvv_attribute_information_t *self,
    uint64_t
        ai_attribute_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                             [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_codec_id,
         ai_attribute_codec_id,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_set_ai_auxiliary_attribute_codec_id(
    fvv_attribute_information_t *self,
    uint64_t                     ai_auxiliary_attribute_codec_id
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_auxiliary_attribute_codec_id,
         ai_auxiliary_attribute_codec_id,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_set_ai_attribute_map_absolute_coding_persistence_flag(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_map_absolute_coding_persistence_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_map_absolute_coding_persistence_flag,
         ai_attribute_map_absolute_coding_persistence_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_set_ai_attribute_dimension_minus1(
    fvv_attribute_information_t *self,
    uint64_t
        ai_attribute_dimension_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]
                                     [0x1
                                      << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_dimension_minus1,
         ai_attribute_dimension_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_set_ai_attribute_dimension_partitions_minus1(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_dimension_partitions_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_dimension_partitions_minus1,
         ai_attribute_dimension_partitions_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_set_ai_attribute_partition_channels_minus1(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_partition_channels_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(
      self->ai_attribute_partition_channels_minus1,
      ai_attribute_partition_channels_minus1,
      sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
          (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT) *
          (0x1 << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_attribute_information_set_ai_attribute_2d_bit_depth_minus1(
    fvv_attribute_information_t *self,
    uint64_t                     ai_attribute_2d_bit_depth_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_2d_bit_depth_minus1,
         ai_attribute_2d_bit_depth_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_attribute_information_set_ai_attribute_MSB_align_flag(
    fvv_attribute_information_t *self,
    uint64_t
        ai_attribute_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID]
                                   [0x1
                                    << FVV_BIT_AI_ATTRIBUTE_COUNT])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ai_attribute_MSB_align_flag,
         ai_attribute_MSB_align_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT));
  return FVV_RET_SUCCESS;
}

// }