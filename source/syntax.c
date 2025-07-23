#include <fvv/syntax.h>

// {
// 8.3.2 V3C unit syntax

// {
// 8.3.2.1 General V3C unit syntax
fvv_ret_t fvv_v3c_unit_init(fvv_v3c_unit_t  *self,
                            fvv_bitstream_t *data)
{
  *self      = (fvv_v3c_unit_t){0};
  self->pack = fvv_v3c_unit_pack;
  self->data = data;

  self->vuh =
      (fvv_v3c_unit_header_t *)malloc(sizeof(fvv_v3c_unit_header_t));
  self->vup = (fvv_v3c_unit_payload_t *)malloc(
      sizeof(fvv_v3c_unit_payload_t));

  fvv_v3c_unit_header_init(self->vuh, self, data);
  fvv_v3c_unit_payload_init(self->vup, self, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_unit_destroy(fvv_v3c_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->vuh)
  {
    fvv_v3c_unit_header_destroy(self->vuh);
    free(self->vuh);
  }
  if (self->vup)
  {
    fvv_v3c_unit_payload_destroy(self->vup);
    free(self->vup);
  }

  *self = (fvv_v3c_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_pack(fvv_v3c_unit_t *self,
                            uint64_t        numBytesInV3CUnit)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_v3c_unit_header_t  *vuh = FVV_NULL;
  fvv_v3c_unit_payload_t *vup = FVV_NULL;

  vuh                         = self->vuh;
  vup                         = self->vup;

  vuh->pack(vuh);
  vup->pack(vup, numBytesInV3CUnit - 4);

  return FVV_RET_SUCCESS;
}
// }

// {
// 8.3.2.2 V3C unit header syntax
fvv_ret_t fvv_v3c_unit_header_init(fvv_v3c_unit_header_t *self,
                                   fvv_v3c_unit_t        *vu,
                                   fvv_bitstream_t       *data)
{
  *self      = (fvv_v3c_unit_header_t){0};
  self->pack = fvv_v3c_unit_header_pack;
  self->vu   = vu;
  self->data = data;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_destroy(fvv_v3c_unit_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_v3c_unit_header_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_pack(fvv_v3c_unit_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  // now fill the buffer
  buff->pad(buff, self->vuh_unit_type, FVV_BIT_VUH_UNIT_TYPE);
  if (self->vuh_unit_type == FVV_V3C_AVD ||
      self->vuh_unit_type == FVV_V3C_GVD ||
      self->vuh_unit_type == FVV_V3C_OVD ||
      self->vuh_unit_type == FVV_V3C_AD)
  {
    buff->pad(buff,
              self->vuh_v3c_parameter_set_id,
              FVV_BIT_VUH_V3C_PARAMETER_SET_ID);
    buff->pad(buff, self->vuh_atlas_id, FVV_BIT_VUH_ATLAS_ID);
  }
  if (self->vuh_unit_type == FVV_V3C_AVD)
  {
    buff->pad(buff,
              self->vuh_attribute_index,
              FVV_BIT_VUH_ATTRIBUTE_INDEX);
    buff->pad(buff,
              self->vuh_attribute_partition_index,
              FVV_BIT_VUH_ATTRIBUTE_PARTITION_INDEX);
    buff->pad(buff, self->vuh_map_index, FVV_BIT_VUH_MAP_INDEX);
    buff->pad(buff,
              self->vuh_auxiliary_video_flag,
              FVV_BIT_VUH_AUXILIARY_VIDEO_FLAG);
  }
  else if (self->vuh_unit_type == FVV_V3C_GVD)
  {
    buff->pad(buff, self->vuh_map_index, FVV_BIT_VUH_MAP_INDEX);
    buff->pad(buff,
              self->vuh_auxiliary_video_flag,
              FVV_BIT_VUH_AUXILIARY_VIDEO_FLAG);
    buff->pad(buff,
              self->vuh_reserved_zero_12bits,
              FVV_BIT_VUH_RESERVED_ZERO_12BITS);
  }
  else if (self->vuh_unit_type == FVV_V3C_OVD ||
           self->vuh_unit_type == FVV_V3C_AD)
  {
    buff->pad(buff,
              self->vuh_reserved_zero_17bits,
              FVV_BIT_VUH_RESERVED_ZERO_17BITS);
  }
  else
  {
    buff->pad(buff,
              self->vuh_reserved_zero_27bits,
              FVV_BIT_VUH_RESERVED_ZERO_27BITS);
  }
  return FVV_RET_SUCCESS;
}
// }

// {
// 8.3.2.3 V3C unit payload syntax
fvv_ret_t fvv_v3c_unit_payload_init(fvv_v3c_unit_payload_t *self,
                                    fvv_v3c_unit_t         *vu,
                                    fvv_bitstream_t        *data)
{
  *self      = (fvv_v3c_unit_payload_t){0};

  self->pack = fvv_v3c_unit_payload_pack;
  self->vu   = vu;
  self->data = data;

  self->vps  = (fvv_v3c_parameter_set_t *)malloc(
      sizeof(fvv_v3c_parameter_set_t));
  self->asb = (fvv_atlas_sub_bitstream_t *)malloc(
      sizeof(fvv_atlas_sub_bitstream_t));
  self->vsb = (fvv_video_sub_bitstream_t *)malloc(
      sizeof(fvv_video_sub_bitstream_t));

  fvv_v3c_parameter_set_init(self->vps, vu, data);
  fvv_atlas_sub_bitstream_init(self->asb, vu, data);
  fvv_video_sub_bitstream_init(self->vsb, vu, data);

  return FVV_RET_SUCESS;
}
fvv_ret_t fvv_v3c_unit_payload_destroy(fvv_v3c_unit_payload_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->vps)
  {
    fvv_v3c_parameter_set_destroy(self->vps);
    free(self->vps);
  }
  if (self->asb)
  {
    fvv_atlas_sub_bitstream_destroy(self->asb);
    free(self->asb);
  }
  if (self->vsb)
  {
    fvv_video_sub_bitstream_destroy(self->vsb);
    free(self->vsb);
  }

  *self = (fvv_v3c_unit_payload_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_payload_pack(fvv_v3c_unit_payload_t *self,
                                    uint64_t numBytesInV3CPayload)
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
  vsp                             = self->vps;
  asb                             = self->asb;
  vsb                             = self->vsb;

  if (vuh->vuh_unit_type == FVV_V3C_VPS)
  {
    vps->pack(vsp, numBytesInV3CPayload);
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
// }

// {
// 8.3.2.4 Atlas sub-bitstream syntax
fvv_ret_t
fvv_atlas_sub_bitstream_init(fvv_atlas_sub_bitstream_t *self,
                             fvv_v3c_unit_t            *vu,
                             fvv_bitstream_t           *data)
{
  *self      = (fvv_atlas_sub_bitstream_t){0};

  self->vu   = vu;
  self->data = data;

  self->ssnh = (fvv_sample_stream_nal_header_t *)malloc(
      sizeof(fvv_sample_stream_nal_header_t));
  self->ssnu = (fvv_sample_stream_nal_unit_t *)malloc(
      sizeof(fvv_sample_stream_nal_unit_t));

  fvv_sample_stream_nal_header_init(self->ssnh, vu, data);
  fvv_sample_stream_nal_unit_init(self->ssnu, vu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sub_bitstream_destroy(fvv_atlas_sub_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ssnh)
  {
    fvv_sample_stream_nal_header_destroy(self->ssnh);
    free(self->ssnh);
  }
  if (self->ssnu)
  {
    fvv_sample_stream_nal_unit_destroy(self->ssnu);
    free(self->ssnu);
  }

  *self = (fvv_atlas_sub_bitstream_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_sub_bitstream_pack(fvv_atlas_sub_bitstream_t *self,
                             uint64_t                   numBytes)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t                *buff = FVV_NULL;
  fvv_v3c_unit_t                 *vu   = FVV_NULL;
  fvv_sample_stream_nal_header_t *ssnh = FVV_NULL;
  fvv_sample_stream_nal_unit_t   *ssnu = FVV_NULL;

  vu                                   = self->vu;
  buff                                 = self->data;
  ssnh                                 = vu->vup->asb->ssnh;
  ssnu                                 = vu->vup->asb->ssnu;

  ssnh->pack(ssnh);
  numBytes--;
  while (numBytes > 0)
  {
    ssnu->pack(ssnu);
    numBytes -= ssnu->ssnu_nal_unit_size +
                ssnh->ssnh_unit_size_precision_bytes_minus1 + 1;
  }
  return FVV_RET_SUCCESS;
}
// }

// }

// {
// D.2 Sample stream NAL unit

// {
// D.2.1 Sample stream NAL header syntax
fvv_ret_t fvv_sample_stream_nal_header_init(
    fvv_sample_stream_nal_header_t *self,
    fvv_v3c_unit_t                 *vu,
    fvv_bitstream_t                *data)
{
  *self      = (fvv_sample_stream_nal_header_t){0};
  self->vu   = vu;
  self->data = data;
  self->pack = fvv_sample_stream_nal_header_pack;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sample_stream_nal_header_destroy(
    fvv_sample_stream_nal_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_sample_stream_nal_header_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sample_stream_nal_header_pack(
    fvv_sample_stream_nal_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->pad(buff,
            self->ssnh_unit_size_precision_bytes_minus1,
            FVV_BIT_SSNH_UNIT_SIZE_PRECISION_BYTES_MINUS1);
  buff->pad(buff,
            self->ssnh_reserved_zero_5bits,
            FVV_BIT_SSNH_RESERVED_ZEREO_5BITS);

  return FVV_RET_SUCCESS;
}
// }

// {
// D.2.2 Sample stream NAL unit syntax
fvv_ret_t
fvv_sample_stream_nal_unit_init(fvv_sample_stream_nal_unit_t *self,
                                fvv_v3c_unit_t               *vu,
                                fvv_bitstream_t              *data)
{
  *self      = (fvv_sample_stream_nal_unit_t){0};
  self->data = data;
  self->vu   = vu;

  self->pack = fvv_sample_stream_nal_unit_pack;

  self->nu   = (fvv_nal_unit_t *)malloc(sizeof(fvv_nal_unit_t));

  fvv_nal_unit_init(self->nu, data, vu->ssnu_nal_unit_size);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sample_stream_nal_unit_destroy(
    fvv_sample_stream_nal_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->nu)
  {
    fvv_nal_unit_destroy(self->nu);
    free(self->nu);
  }
  *self = (fvv_sample_stream_nal_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_sample_stream_nal_unit_pack(fvv_sample_stream_nal_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff                                  = FVV_NULL;
  fvv_nal_unit_t  *nu                                    = FVV_NULL;
  uint32_t         ssnh_unit_size_precision_bytes_minus1 = 0;

  buff = self->data;
  nu   = self->nu;

  ssnh_unit_size_precision_bytes_minus1 =
      self->vu->ssnh_unit_size_precision_bytes_minus1;

  buff->pad(buff,
            self->ssnu_nal_unit_size,
            (ssnh_unit_size_precision_bytes_minus1 + 1) *
                FVV_BITS_PER_BYTE);
  nu->pack(nu);
  return FVV_RET_SUCCESS;
}
// }

// }

// {
// 8.3.3 Byte alignment syntax
fvv_ret_t fvv_byte_alignment_init(fvv_byte_alignment_t *self,
                                  fvv_bitstream_t      *data)
{
  *self                             = (fvv_byte_alignment_t){0};

  self->alignment_bit_equal_to_one  = 0x1;
  self->alignment_bit_equal_to_zero = 0x0;

  sellf->data                       = data;
  self->pack                        = fvv_byte_alignment_pack;

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_byte_alignment_destroy(fvv_byte_alignment_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_byte_alignment_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_byte_alignment_pack(fvv_byte_alignment_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff         = FVV_NULL;
  fvv_bool_t       byte_aligned = FVV_FALSE;

  buff                          = self->data;

  buff->pad(buff,
            self->alignment_bit_equal_to_one,
            FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ONE);
  buff->byte_aligned(buff, &byte_aligned);
  while (!byte_aligned)
  {
    buff->pad(buff,
              self->alignment_bit_equal_to_zero,
              FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ZERO);
    buff->byte_aligned(buff, &byte_aligned);
  }
  return FVV_RET_SUCCESS;
}
// }

// {
// 8.3.4 V3C parameter set syntax

// {
// 8.3.4.1 General V3C parameter set syntax
fvv_ret_t fvv_v3c_parameter_set_init(fvv_v3c_parameter_set_t *self,
                                     fvv_bitstream_t         *data)
{
  *self      = (fvv_v3c_parameter_set_t){0};
  self->data = data;
  self->pack = fvv_v3c_parameter_set_pack;

  self->ptl  = (fvv_profile_tier_level_t *)malloc(
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
  fvv_byte_alignment_init(self->ba, data);

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
    free(self_ > ptl);
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
    fvv_byte_alignment_init(self->ba);
    free(self->ba);
  }
  *self = (fvv_v3c_parameter_set_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_parameter_set_pack(fvv_v3c_parameter_set_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALZIED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint32_t         k    = 0;
  uint32_t         j    = 0;
  uint32_t         i    = 0;
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
      if (vps_map_absolute_coding_enabled_flag[j][i] == 0)
      {
        buff->pad(buff,
                  vps_map_predictor_index_diff[j][i],
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
// }

// {
// 8.3.4.2 Profile, tier, and level syntax
fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t          *data)
{
  *self      = (fvv_profile_tier_level_t){0};

  self->vps  = vps;
  self->data = data;

  self->pack = fvv_profile_tier_level_pack;

  self->ptci =
      (fvv_profile_toolset_constraint_information_t *)malloc(
          sizeof(fvv_profile_toolset_constraint_information_t));

  fvv_profile_toolset_constraint_information_init(
      self->ptci, vps, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_tier_level_destroy(fvv_profile_tier_level_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIIALIZED;
  }
  if (self->ptci)
  {
    fvv_profile_toolset_constraint_information_destroy(self->ptci);
    free(self->ptci);
  }
  *self = (fvv_profile_tier_level_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_profile_tier_level_pack(fvv_profile_tier_level_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;
  uint32_t i            = 0;

  buff->pad(buff, self->ptl_tier_flag, FVV_BIT_PTL_TIER_FLAG);
  buff->pad(buff,
            self->ptl_profile_codec_group_idc,
            FVV_BIT_PTL_PROFILE_CODEC_GROUP_IDC);
  buff->pad(buff,
            self->ptl_profile_toolset_idc,
            FVV_BIT_PTL_PROFILE_TOOLSET_IDC);
  buff->pad(buff,
            self->ptl_profile_reconstruction_idc,
            FVV_BIT_PTL_PROFILE_RECONSTRUCTION_IDC);
  buff->pad(buff,
            self->ptl_reserved_zero_16bits,
            FVV_BIT_PTL_RESERVED_ZERO_16BITS);
  buff->pad(buff,
            self->ptl_reserved_0xffff_16bits,
            FVV_BIT_PTL_RESERVED_0XFFFF_16BITS);
  buff->pad(buff, self->ptl_level_idc, FVV_BIT_PTL_LEVEL_IDC);
  buff->pad(buff,
            self->ptl_num_sub_profiles,
            FVV_BIT_PTL_NUM_SUB_PROFILES);
  buff->pad(buff,
            self->ptl_extended_sub_profile_flag,
            FVV_BIT_PTL_EXTENDED_SUB_PROFILE_FLAG);

  for (i = 0; i < self->ptl_num_sub_profiles; i++)
  {
    buff->pad(buff,
              self->ptl_sub_profile_idc[i],
              FVV_BIT_PTL_SUB_PROFILE_IDC);
  }
  buff->pad(buff,
            self->ptl_tool_constraints_present_flag,
            FVV_BIT_PTL_TOOL_CONSTRAINTS_PRESENT_FLAG);
  if (self->ptl_toolset_constraints_present_flag)
  {
    self->ptci->pack(self->ptci);
  }

  return FVV_RET_SUCCESS;
}
// }

// {
// 8.3.4.3 Occupancy information syntax
fvv_occupancy_information_init(fvv_occupancy_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data)
{
  *self      = (fvv_occupancy_information_t){0};

  self->vps  = vps;
  self->data = data;

  self->pack = fvv_occupancy_information_pack;

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
// }

// {
// 8.3.4.4 Geometry information syntax
fvv_ret_t
fvv_geometry_information_init(fvv_geometry_information_t *self,
                              fvv_v3c_parameter_set_t    *vps,
                              fvv_bitstream_t            *data)
{
  *self      = (fvv_geometry_information_t){0};

  self->vps  = vps;
  self->data = data;
  self->pack = fvv_geometry_information_pack;

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
// }

// {
// 8.3.4.5 Attribute information syntax
fvv_ret_t
fvv_attribute_information_init(fvv_attribute_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data)
{
  *self      = (fvv_attribute_information_t){0};

  self->vps  = vps;
  self->data = data;

  self->fvv_attribute_information_pack;

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
  uint32_t         i                   = 0;
  uint32_t         j                   = 0;
  uint32_t         k                   = 0;
  uint32_t         remainingDimensions = 0;
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
        if (k – j == remainingDimensions)
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
        remainingDimensions –=
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
// }

// {
// 8.3.4.6 Profile toolset constraints information syntax
fvv_ret_t fvv_profile_toolset_constraints_information_init(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_v3c_parameter_set_t                       *vps,
    fvv_bitstream_t                               *data)
{
  *self      = (fvv_profile_toolset_constraints_information_t){0};
  self->vps  = vps;
  self->data = data;

  self->pack = fvv_profile_toolset_constraints_information_pack;

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_toolset_constraints_information_destroy(
    fvv_profile_toolset_constraints_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_profile_toolset_constraints_information_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_toolset_constraints_information_pack(
    fvv_profile_toolset_constraints_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  buff->pad(buff,
            self->ptc_one_v3c_frame_only_flag,
            FVV_BIT_PTC_ONE_V3C_FRAME_ONLY_FLAG);
  buff->pad(buff,
            self->ptc_eom_constraint_flag,
            FVV_BIT_PTC_EOM_CONSTRAINT_FLAG);
  buff->pad(buff,
            self->ptc_max_map_count_minus1,
            FVV_BIT_PTC_MAX_MAP_COUNT_MINUS1);
  buff->pad(buff,
            self->ptc_max_atlas_count_minus1,
            FVV_BIT_PTC_MAX_ATLAS_COUNT_MINUS1);
  buff->pad(buff,
            self->ptc_multiple_map_streams_constraint_flag,
            FVV_BIT_PTC_MULTIPLE_MAP_STREAMS_CONSTRAINT_FLAG);
  buff->pad(buff,
            self->ptc_plr_constraint_flag,
            FVV_BIT_PTC_PLR_CONSTRAINT_FLAG);
  buff->pad(buff,
            self->ptc_attribute_max_dimension_minus1,
            FVV_BIT_PTC_ATTRIBUTE_MAX_DIMENSION_MINUS1);
  buff->pad(buff,
            self->ptc_attribute_max_dimension_partitions_minus1,
            FVV_BIT_PTC_ATTRIBUTE_MAX_DIMENSION_PARTITIONS_MINUS1);
  buff->pad(buff,
            self->ptc_no_eight_orientations_constraint_flag,
            FVV_BIT_PTC_NO_EIGHT_ORIENTATIONS_CONSTRAINT_FLAG);
  buff->pad(
      buff,
      self->ptc_no_45degree_projection_patch_constraint_flag,
      FVV_BIT_PTC_NO_45DEGREE_PROJECTION_PATCH_CONSTRAINT_FLAG);
  buff->pad(buff,
            self->ptc_reserved_zero_6bits,
            FVV_BIT_PTC_RESERVED_ZERO_6BITS);
  buff->pad(buff,
            self->ptc_num_reserved_constraint_bytes,
            FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES);

  for (i = 0; i < self->ptc_num_reserved_constraint_bytes; i++)
  {
    buff->pad(buff,
              self->ptc_reserved_constraint_byte[i],
              fvv_bit_ptc_reserved_constraint_byte);
  }
  return FVV_RET_SUCCESS;
}
// }
// }

// {
// 8.3.5 NAL unit syntax
// {
// 8.3.5.1 General NAL unit syntax
fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t  *self,
                            fvv_bitstream_t *data,
                            uint64_t         rbsp_size)
{
  *self           = (fvv_nal_unit_t){0};

  self->data      = data;
  self->rbsp_size = rbsp_size;

  self->pack      = fvv_nal_unit_pack;

  self->nuh =
      (fvv_nal_unit_header_t *)malloc(sizeof(fvv_nal_unit_header_t));
  fvv_nal_unit_header_init(self->nuh, data);

  self->rbsp = (uint32_t *)calloc(rbsp_size, sizeof(uint32_t));

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_destroy(fvv_nal_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->rbsp_byte)
  {
    free(self->rbsp_byte);
  }
  if (self->nuh)
  {
    fvv_nal_unit_header_destroy(self->nuh);
    free(self->nuh);
  }
  *self = (fvv_nal_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_nal_unit_pack(fvv_nal_unit_t *self,
                            uint64_t        NumBytesInNalUnit)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->pad(buff,
            self->nal_forbidden_zero_bit,
            FVV_BIT_NAL_FORBIDDEN_ZERO_BIT);
  buff->pad(buff, self->nal_unit_type, FVV_BIT_NAL_UNIT_TYPE);
  buff->pad(buff, self->nal_layer_id, FVV_BIT_NAL_LAYER_ID);
  buff->pad(buff,
            self->nal_temporal_id_plus1,
            FVV_BIT_NAL_TEMPORAL_ID_PLUS1);

  return FVV_RET_SUCCESS;
}
// }
// }
