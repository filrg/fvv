#include <fvv/syntax/profile_toolset_constraints_information.h>

// 8.3.4.6 Profile toolset constraints information syntax
// {
fvv_ret_t fvv_profile_toolset_constraints_information_init(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_v3c_parameter_set_t                       *vps,
    fvv_bitstream_t                               *data)
{
  *self      = (fvv_profile_toolset_constraints_information_t){0};
  self->vps  = vps;
  self->data = data;

  self->pack = fvv_profile_toolset_constraints_information_pack;
  self->copy_from =
      fvv_profile_toolset_constraints_information_copy_from;
  self->set_ptc_one_v3c_frame_only_flag =
      fvv_profile_toolset_constraints_information_set_ptc_one_v3c_frame_only_flag;
  self->set_ptc_eom_constraint_flag =
      fvv_profile_toolset_constraints_information_set_ptc_eom_constraint_flag;
  self->set_ptc_max_map_count_minus1 =
      fvv_profile_toolset_constraints_information_set_ptc_max_map_count_minus1;
  self->set_ptc_max_atlas_count_minus1 =
      fvv_profile_toolset_constraints_information_set_ptc_max_atlas_count_minus1;
  self->set_ptc_multiple_map_streams_constraint_flag =
      fvv_profile_toolset_constraints_information_set_ptc_multiple_map_streams_constraint_flag;
  self->set_ptc_plr_constraint_flag =
      fvv_profile_toolset_constraints_information_set_ptc_plr_constraint_flag;
  self->set_ptc_attribute_max_dimension_minus1 =
      fvv_profile_toolset_constraints_information_set_ptc_attribute_max_dimension_minus1;
  self->set_ptc_attribute_max_dimension_partitions_minus1 =
      fvv_profile_toolset_constraints_information_set_ptc_attribute_max_dimension_partitions_minus1;
  self->set_ptc_no_eight_orientations_constraint_flag =
      fvv_profile_toolset_constraints_information_set_ptc_no_eight_orientations_constraint_flag;
  self->set_ptc_no_45degree_projection_patch_constraint_flag =
      fvv_profile_toolset_constraints_information_set_ptc_no_45degree_projection_patch_constraint_flag;
  self->set_ptc_reserved_zero_6bits =
      fvv_profile_toolset_constraints_information_set_ptc_reserved_zero_6bits;
  self->set_ptc_num_reserved_constraint_bytes =
      fvv_profile_toolset_constraints_information_set_ptc_num_reserved_constraint_bytes;
  self->set_ptc_reserved_constraint_byte =
      fvv_profile_toolset_constraints_information_set_ptc_reserved_constraint_byte;
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
fvv_ret_t fvv_profile_toolset_constraints_information_copy_from(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_profile_toolset_constraints_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ptc_one_v3c_frame_only_flag(
      self, other->ptc_one_v3c_frame_only_flag);
  self->set_ptc_eom_constraint_flag(self,
                                    other->ptc_eom_constraint_flag);
  self->set_ptc_max_map_count_minus1(
      self, other->ptc_max_map_count_minus1);
  self->set_ptc_max_atlas_count_minus1(
      self, other->ptc_max_atlas_count_minus1);
  self->set_ptc_multiple_map_streams_constraint_flag(
      self, other->ptc_multiple_map_streams_constraint_flag);
  self->set_ptc_plr_constraint_flag(self,
                                    other->ptc_plr_constraint_flag);
  self->set_ptc_attribute_max_dimension_minus1(
      self, other->ptc_attribute_max_dimension_minus1);
  self->set_ptc_attribute_max_dimension_partitions_minus1(
      self, other->ptc_attribute_max_dimension_partitions_minus1);
  self->set_ptc_no_eight_orientations_constraint_flag(
      self, other->ptc_no_eight_orientations_constraint_flag);
  self->set_ptc_no_45degree_projection_patch_constraint_flag(
      self, other->ptc_no_45degree_projection_patch_constraint_flag);
  self->set_ptc_reserved_zero_6bits(self,
                                    other->ptc_reserved_zero_6bits);
  self->set_ptc_num_reserved_constraint_bytes(
      self, other->ptc_num_reserved_constraint_bytes);
  self->set_ptc_reserved_constraint_byte(
      self, other->ptc_reserved_constraint_byte);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_one_v3c_frame_only_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_one_v3c_frame_only_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_one_v3c_frame_only_flag = ptc_one_v3c_frame_only_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_eom_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_eom_constraint_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_eom_constraint_flag = ptc_eom_constraint_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_max_map_count_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_max_map_count_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_max_map_count_minus1 = ptc_max_map_count_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_max_atlas_count_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_max_atlas_count_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_max_atlas_count_minus1 = ptc_max_atlas_count_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_multiple_map_streams_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_multiple_map_streams_constraint_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_multiple_map_streams_constraint_flag =
      ptc_multiple_map_streams_constraint_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_plr_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_plr_constraint_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_plr_constraint_flag = ptc_plr_constraint_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_attribute_max_dimension_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_attribute_max_dimension_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_attribute_max_dimension_minus1 =
      ptc_attribute_max_dimension_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_attribute_max_dimension_partitions_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_attribute_max_dimension_partitions_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_attribute_max_dimension_partitions_minus1 =
      ptc_attribute_max_dimension_partitions_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_no_eight_orientations_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_no_eight_orientations_constraint_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_no_eight_orientations_constraint_flag =
      ptc_no_eight_orientations_constraint_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_no_45degree_projection_patch_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_no_45degree_projection_patch_constraint_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_no_45degree_projection_patch_constraint_flag =
      ptc_no_45degree_projection_patch_constraint_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_reserved_zero_6bits(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_reserved_zero_6bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_reserved_zero_6bits = ptc_reserved_zero_6bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_num_reserved_constraint_bytes(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_num_reserved_constraint_bytes)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptc_num_reserved_constraint_bytes =
      ptc_num_reserved_constraint_bytes;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_reserved_constraint_byte(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_reserved_constraint_byte
        [0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ptc_reserved_constraint_byte,
         ptc_reserved_constraint_byte,
         sizeof(uint64_t) *
             (0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES));
  return FVV_RET_SUCCESS;
}

// }