#include <fvv/bitstream.h>
#include <fvv/syntax/v3c_unit_header.h>

// 8.3.2.2 V3C unit header syntax
// {
fvv_ret_t fvv_v3c_unit_header_init(fvv_v3c_unit_header_t *self,
                                   fvv_v3c_unit_t        *vu,
                                   fvv_bitstream_t       *data)
{
  *self                   = (fvv_v3c_unit_header_t){0};
  self->pack              = fvv_v3c_unit_header_pack;
  self->copy_from         = fvv_v3c_unit_header_copy_from;
  self->set_vuh_unit_type = fvv_v3c_unit_header_set_vuh_unit_type;
  self->set_vuh_v3c_parameter_set_id =
      fvv_v3c_unit_header_set_vuh_v3c_parameter_set_id;
  self->set_vuh_atlas_id = fvv_v3c_unit_header_set_vuh_atlas_id;
  self->set_vuh_attribute_index =
      fvv_v3c_unit_header_set_vuh_attribute_index;
  self->set_vuh_attribute_partition_index =
      fvv_v3c_unit_header_set_vuh_attribute_partition_index;
  self->set_vuh_map_index = fvv_v3c_unit_header_set_vuh_map_index;
  self->set_vuh_auxiliary_video_flag =
      fvv_v3c_unit_header_set_vuh_auxiliary_video_flag;
  self->set_vuh_reserved_zero_12bits =
      fvv_v3c_unit_header_set_vuh_reserved_zero_12bits;
  self->set_vuh_reserved_zero_17bits =
      fvv_v3c_unit_header_set_vuh_reserved_zero_17bits;
  self->set_vuh_reserved_zero_27bits =
      fvv_v3c_unit_header_set_vuh_reserved_zero_27bits;

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

fvv_ret_t fvv_v3c_unit_header_copy_from(fvv_v3c_unit_header_t *self,
                                        fvv_v3c_unit_header_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_vuh_unit_type(self, other->vuh_unit_type);
  self->set_vuh_v3c_parameter_set_id(
      self, other->vuh_v3c_parameter_set_id);
  self->set_vuh_atlas_id(self, other->vuh_atlas_id);
  self->set_vuh_attribute_index(self, other->vuh_attribute_index);
  self->set_vuh_attribute_partition_index(
      self, other->vuh_attribute_partition_index);
  self->set_vuh_map_index(self, other->vuh_map_index);
  self->set_vuh_auxiliary_video_flag(
      self, other->vuh_auxiliary_video_flag);
  self->set_vuh_reserved_zero_12bits(
      self, other->vuh_reserved_zero_12bits);
  self->set_vuh_reserved_zero_17bits(
      self, other->vuh_reserved_zero_17bits);
  self->set_vuh_reserved_zero_27bits(
      self, other->vuh_reserved_zero_27bits);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_v3c_unit_header_set_vuh_unit_type(fvv_v3c_unit_header_t *self,
                                      uint64_t vuh_unit_type)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_unit_type = vuh_unit_type;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_unit_header_set_vuh_v3c_parameter_set_id(
    fvv_v3c_unit_header_t *self, uint64_t vuh_v3c_parameter_set_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_v3c_parameter_set_id = vuh_v3c_parameter_set_id;
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_v3c_unit_header_set_vuh_atlas_id(fvv_v3c_unit_header_t *self,
                                     uint64_t vuh_atlas_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_atlas_id = vuh_atlas_id;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_set_vuh_attribute_index(
    fvv_v3c_unit_header_t *self, uint64_t vuh_attribute_index)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_attribute_index = vuh_attribute_index;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_set_vuh_attribute_partition_index(
    fvv_v3c_unit_header_t *self,
    uint64_t               vuh_attribute_partition_index)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_attribute_partition_index =
      vuh_attribute_partition_index;
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_v3c_unit_header_set_vuh_map_index(fvv_v3c_unit_header_t *self,
                                      uint64_t vuh_map_index)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_map_index = vuh_map_index;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_set_vuh_auxiliary_video_flag(
    fvv_v3c_unit_header_t *self, uint64_t vuh_auxiliary_video_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_auxiliary_video_flag = vuh_auxiliary_video_flag;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_12bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_12bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_reserved_zero_12bits = vuh_reserved_zero_12bits;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_17bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_17bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_reserved_zero_17bits = vuh_reserved_zero_17bits;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_27bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_27bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh_reserved_zero_27bits = vuh_reserved_zero_27bits;
  return FVV_RET_SUCCESS;
}

// }