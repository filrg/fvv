#include <fvv/bitstream.h>
#include <fvv/syntax/attribute_information.h>
#include <fvv/syntax/byte_alignment.h>
#include <fvv/syntax/geometry_information.h>
#include <fvv/syntax/occupancy_information.h>
#include <fvv/syntax/profile_tier_level.h>
#include <fvv/syntax/v3c_parameter_set.h>

// 8.3.4.1 General V3C parameter set syntax
// {
fvv_ret_t fvv_v3c_parameter_set_init(fvv_v3c_parameter_set_t *self,
                                     fvv_v3c_unit_t          *vu,
                                     fvv_bitstream_t         *data)
{
  *self           = (fvv_v3c_parameter_set_t){0};
  self->vu        = vu;
  self->data      = data;
  self->pack      = fvv_v3c_parameter_set_pack;
  self->copy_from = fvv_v3c_parameter_set_copy_from;
  self->set_vps_v3c_parameter_set_id =
      fvv_v3c_parameter_set_set_vps_v3c_parameter_set_id;
  self->set_vps_reserved_zero_8bits =
      fvv_v3c_parameter_set_set_vps_reserved_zero_8bits;
  self->set_vps_atlas_count_minus1 =
      fvv_v3c_parameter_set_set_vps_atlas_count_minus1;
  self->set_vps_atlas_id = fvv_v3c_parameter_set_set_vps_atlas_id;
  self->set_vps_frame_width =
      fvv_v3c_parameter_set_set_vps_frame_width;
  self->set_vps_frame_height =
      fvv_v3c_parameter_set_set_vps_frame_height;
  self->set_vps_map_count_minus1 =
      fvv_v3c_parameter_set_set_vps_map_count_minus1;
  self->set_vps_multiple_map_streams_present_flag =
      fvv_v3c_parameter_set_set_vps_multiple_map_streams_present_flag;
  self->set_vps_map_absolute_coding_enabled_flag =
      fvv_v3c_parameter_set_set_vps_map_absolute_coding_enabled_flag;
  self->set_vps_map_predictor_index_diff =
      fvv_v3c_parameter_set_set_vps_map_predictor_index_diff;
  self->set_vps_auxiliary_video_present_flag =
      fvv_v3c_parameter_set_set_vps_auxiliary_video_present_flag;
  self->set_vps_occupancy_video_present_flag =
      fvv_v3c_parameter_set_set_vps_occupancy_video_present_flag;
  self->set_vps_geometry_video_present_flag =
      fvv_v3c_parameter_set_set_vps_geometry_video_present_flag;
  self->set_vps_attribute_video_present_flag =
      fvv_v3c_parameter_set_set_vps_attribute_video_present_flag;
  self->set_vps_extension_present_flag =
      fvv_v3c_parameter_set_set_vps_extension_present_flag;
  self->set_vps_extension_8bits =
      fvv_v3c_parameter_set_set_vps_extension_8bits;
  self->set_vps_extension_length_minus1 =
      fvv_v3c_parameter_set_set_vps_extension_length_minus1;
  self->set_vps_extension_data_byte =
      fvv_v3c_parameter_set_set_vps_extension_data_byte;
  self->set_ptl = fvv_v3c_parameter_set_set_ptl;
  self->set_oi  = fvv_v3c_parameter_set_set_oi;
  self->set_gi  = fvv_v3c_parameter_set_set_gi;
  self->set_ai  = fvv_v3c_parameter_set_set_ai;
  self->set_ba  = fvv_v3c_parameter_set_set_ba;

  self->ptl     = (fvv_profile_tier_level_t *)malloc(
      sizeof(fvv_profile_tier_level_t));
  self->oi = (fvv_occupancy_information_t *)malloc(
      sizeof(fvv_occupancy_information_t));
  self->gi = (fvv_geometry_information_t *)malloc(
      sizeof(fvv_geometry_information_t));
  self->ai = (fvv_attribute_information_t *)malloc(
      sizeof(fvv_attribute_information_t));
  self->ba =
      (fvv_byte_alignment_t *)malloc(sizeof(fvv_byte_alignment_t));

  fvv_profile_tier_level_init(self->ptl, self, data);
  fvv_occupancy_information_init(self->oi, self, data);
  fvv_geometry_information_init(self->gi, self, data);
  fvv_attribute_information_init(self->ai, self, data);
  fvv_byte_alignment_init(self->ba, self->vu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_destroy(fvv_v3c_parameter_set_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ptl)
  {
    fvv_profile_tier_level_destroy(self->ptl);
    free(self->ptl);
  }
  if (self->oi)
  {
    fvv_occupancy_information_destroy(self->oi);
    free(self->oi);
  }
  if (self->gi)
  {
    fvv_geometry_information_destroy(self->gi);
    free(self->gi);
  }
  if (self->ai)
  {
    fvv_attribute_information_destroy(self->ai);
    free(self->ai);
  }
  if (self->ba)
  {
    fvv_byte_alignment_destroy(self->ba);
    free(self->ba);
  }
  *self = (fvv_v3c_parameter_set_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_parameter_set_pack(fvv_v3c_parameter_set_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         k    = 0;
  uint64_t         j    = 0;
  uint64_t         i    = 0;
  buff                  = self->data;

  self->ptl->pack(self->ptl);
  buff->pad(buff,
            self->vps_v3c_parameter_set_id,
            FVV_BIT_VPS_V3C_PARAMETER_SET_ID);
  buff->pad(buff,
            self->vps_reserved_zero_8bits,
            FVV_BIT_VPS_RESERVED_ZERO_8BITS);
  buff->pad(buff,
            self->vps_atlas_count_minus1,
            FVV_BIT_VPS_ATLAS_COUNT_MINUS1);
  for (k = 0; k < self->vps_atlas_count_minus1 + 1; k++)
  {
    buff->pad(buff, self->vps_atlas_id[k], FVV_BIT_VPS_ATLAS_ID);
    j = self->vps_atlas_id[k];
    buff->pad(
        buff, self->vps_frame_width[j], FVV_BIT_VPS_FRAME_WIDTH);
    buff->pad(
        buff, self->vps_frame_height[j], FVV_BIT_VPS_FRAME_HEIGHT);
    buff->pad(buff,
              self->vps_map_count_minus1[j],
              FVV_BIT_VPS_MAP_COUNT_MINUS1);
    if (self->vps_map_count_minus1[j] > 0)
    {
      buff->pad(buff,
                self->vps_multiple_map_streams_present_flag[j],
                FVV_BIT_VPS_MULTIPLE_MAP_STREAMS_PRESENT_FLAG);
    }
    self->vps_map_absolute_coding_enabled_flag[j][0] = 1;
    self->vps_map_predictor_index_diff[j][0]         = 0;
    for (i = 1, i <= self->vps_map_count_minus1[j]; i++)
    {
      if (self->vps_multiple_map_streams_present_flag[j])
      {
        buff->pad(buff,
                  self->vps_map_absolute_coding_enabled_flag[j][i],
                  FVV_BIT_VPS_MAP_ABSOLUTE_CODING_ENABLED_FLAG);
      }
      else
      {
        self->vps_map_absolute_coding_enabled_flag[j][i] = 1;
      }
      if (self->vps_map_absolute_coding_enabled_flag[j][i] == 0)
      {
        buff->pad(buff,
                  self->vps_map_predictor_index_diff[j][i],
                  FVV_BIT_VPS_MAP_PREDICTOR_INDEX_DIFF);
      }
    }
    buff->pad(buff,
              self->vps_auxiliary_video_present_flag[j],
              FVV_BIT_VPS_AUXILIARY_VIDEO_PRESENT_FLAG);
    buff->pad(buff,
              self->vps_occupancy_video_present_flag[j],
              FVV_BIT_VPS_OCCUPANCY_VIDEO_PRESENT_FLAG);
    buff->pad(buff,
              self->vps_geometry_video_present_flag[j],
              FVV_BIT_VPS_GEOMETRY_VIDEO_PRESENT_FLAG);
    buff->pad(buff,
              self->vps_attribute_video_present_flag[j],
              FVV_BIT_VPS_ATTRIBUTE_VIDEO_PRESENT_FLAG);
    if (self->vps_occupancy_video_present_flag[j])
    {
      self->oi->pack(self->oi, j);
    }
    if (self->vps_geometry_video_present_flag[j])
    {
      self->gi->pack(self->gi, j);
    }
    if (self->vps_attribute_video_present_flag[j])
    {
      self->ai->pack(self->ai, j);
    }
  }
  buff->pad(buff,
            self->vps_extension_present_flag,
            FVV_BIT_VPS_EXTENSION_PRESENT_FLAG);
  if (self->vps_extension_present_flag)
  {
    buff->pad(buff,
              self->vps_extension_8bits,
              FVV_BIT_VPS_EXTENSION_8BITS);
  }
  if (self->vps_extension_8bits)
  {
    buff->pad(buff,
              self->vps_extension_length_minus1,
              FVV_BIT_VPS_EXTENSION_LENGTH_MINUS1);
    for (j = 0; j < self->vps_extension_length_minus1 + 1; j++)
    {
      buff->pad(buff,
                self->vps_extension_data_byte,
                FVV_BIT_VPS_EXTENSION_DATA_BYTE);
    }
  }
  self->ba->pack(self->ba);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_v3c_parameter_set_id(
    fvv_v3c_parameter_set_t *self, uint64_t vps_v3c_parameter_set_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_v3c_parameter_set_id = vps_v3c_parameter_set_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_reserved_zero_8bits(
    fvv_v3c_parameter_set_t *self, uint64_t vps_reserved_zero_8bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_reserved_zero_8bits = vps_reserved_zero_8bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_atlas_count_minus1(
    fvv_v3c_parameter_set_t *self, uint64_t vps_atlas_count_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_atlas_count_minus1 = vps_atlas_count_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_atlas_id(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_atlas_id,
         vps_atlas_id,
         sizeof(uint64_t) *
             ((0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_frame_width(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_frame_width,
         vps_frame_width,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_frame_height(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_frame_height,
         vps_frame_height,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_map_count_minus1(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_map_count_minus1,
         vps_map_count_minus1,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_set_vps_multiple_map_streams_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_multiple_map_streams_present_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_multiple_map_streams_present_flag,
         vps_multiple_map_streams_present_flag,
         sizeof(uint64_t) * 0x1 << FVV_BIT_VPS_ATLAS_ID);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_set_vps_map_absolute_coding_enabled_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_map_absolute_coding_enabled_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_map_absolute_coding_enabled_flag,
         vps_map_absolute_coding_enabled_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_map_predictor_index_diff(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_map_predictor_index_diff
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_map_predictor_index_diff,
         vps_map_predictor_index_diff,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID) *
             (0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_auxiliary_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_auxiliary_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_auxiliary_video_present_flag,
         vps_auxiliary_video_present_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_occupancy_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_occupancy_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_occupancy_video_present_flag,
         vps_occupancy_video_present_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_geometry_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_geometry_video_present_flag[0x1 << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_geometry_video_present_flag,
         vps_geometry_video_present_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_attribute_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_attribute_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->vps_attribute_video_present_flag,
         vps_attribute_video_present_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_VPS_ATLAS_ID));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_extension_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_extension_present_flag = vps_extension_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_8bits(
    fvv_v3c_parameter_set_t *self, uint64_t vps_extension_8bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_extension_8bits = vps_extension_8bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_length_minus1(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_extension_length_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_extension_length_minus1 = vps_extension_length_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_data_byte(
    fvv_v3c_parameter_set_t *self, uint64_t vps_extension_data_byte)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vps_extension_data_byte = vps_extension_data_byte;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_set_ptl(fvv_v3c_parameter_set_t  *self,
                              fvv_profile_tier_level_t *ptl)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl->copy_from(self->ptl, ptl);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_set_oi(fvv_v3c_parameter_set_t     *self,
                             fvv_occupancy_information_t *oi)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->oi->copy_from(self->oi, oi);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_set_gi(fvv_v3c_parameter_set_t    *self,
                             fvv_geometry_information_t *gi)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->gi->copy_from(self->gi, gi);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_parameter_set_set_ai(fvv_v3c_parameter_set_t     *self,
                             fvv_attribute_information_t *ai)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ai->copy_from(self->ai, ai);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_parameter_set_set_ba(fvv_v3c_parameter_set_t *self,
                                       fvv_byte_alignment_t    *ba)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ba->copy_from(self->ba, ba);
  return FVV_RET_SUCCESS;
}
// }