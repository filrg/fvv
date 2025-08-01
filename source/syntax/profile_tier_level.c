#include <fvv/bitstream.h>
#include <fvv/syntax/profile_tier_level.h>
#include <fvv/syntax/profile_toolset_constraints_information.h>
// 8.3.4.2 Profile, tier, and level syntax
// {
fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t          *data)
{
  *self                   = (fvv_profile_tier_level_t){0};

  self->vps               = vps;
  self->data              = data;
  self->pack              = fvv_profile_tier_level_pack;
  self->copy_from         = fvv_profile_tier_level_copy_from;
  self->set_ptl_tier_flag = fvv_profile_tier_level_set_ptl_tier_flag;
  self->set_ptl_profile_codec_group_idc =
      fvv_profile_tier_level_set_ptl_profile_codec_group_idc;
  self->set_ptl_profile_toolset_idc =
      fvv_profile_tier_level_set_ptl_profile_toolset_idc;
  self->set_ptl_profile_reconstruction_idc =
      fvv_profile_tier_level_set_ptl_profile_reconstruction_idc;
  self->set_ptl_reserved_zero_16bits =
      fvv_profile_tier_level_set_ptl_reserved_zero_16bits;
  self->set_ptl_reserved_0xffff_16bits =
      fvv_profile_tier_level_set_ptl_reserved_0xffff_16bits;
  self->set_ptl_level_idc = fvv_profile_tier_level_set_ptl_level_idc;
  self->set_ptl_num_sub_profiles =
      fvv_profile_tier_level_set_ptl_num_sub_profiles;
  self->set_ptl_extended_sub_profile_flag =
      fvv_profile_tier_level_set_ptl_extended_sub_profile_flag;
  self->set_ptl_sub_profile_idc =
      fvv_profile_tier_level_set_ptl_sub_profile_idc;
  self->set_ptl_tool_constraints_present_flag =
      fvv_profile_tier_level_set_ptl_tool_constraints_present_flag;
  self->set_ptci = fvv_profile_tier_level_set_ptci;

  self->ptci =
      (fvv_profile_toolset_constraints_information_t *)malloc(
          sizeof(fvv_profile_toolset_constraints_information_t));

  fvv_profile_toolset_constraint_information_init(
      self->ptci, vps, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_tier_level_destroy(fvv_profile_tier_level_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
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
  uint64_t i            = 0;

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
  if (self->ptl_tool_constraints_present_flag)
  {
    self->ptci->pack(self->ptci);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_profile_tier_level_copy_from(fvv_profile_tier_level_t *self,
                                 fvv_profile_tier_level_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ptl_tier_flag(self, other->ptl_tier_flag);
  self->set_ptl_profile_codec_group_idc(
      self, other->ptl_profile_codec_group_idc);
  self->set_ptl_profile_toolset_idc(self,
                                    other->ptl_profile_toolset_idc);
  self->set_ptl_profile_reconstruction_idc(
      self, other->ptl_profile_reconstruction_idc);
  self->set_ptl_reserved_zero_16bits(
      self, other->ptl_reserved_zero_16bits);
  self->set_ptl_reserved_0xffff_16bits(
      self, other->ptl_reserved_0xffff_16bits);
  self->set_ptl_level_idc(self, other->ptl_level_idc);
  self->set_ptl_num_sub_profiles(self, other->ptl_num_sub_profiles);
  self->set_ptl_extended_sub_profile_flag(
      self, other->ptl_extended_sub_profile_flag);
  self->set_ptl_sub_profile_idc(self, other->ptl_sub_profile_idc);
  self->set_ptl_tool_constraints_present_flag(
      self, other->ptl_tool_constraints_present_flag);
  self->set_ptci(self, other->ptci);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_profile_tier_level_set_ptl_tier_flag(
    fvv_profile_tier_level_t *self, uint64_t ptl_tier_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_tier_flag = ptl_tier_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_codec_group_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_codec_group_idc)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_profile_codec_group_idc = ptl_profile_codec_group_idc;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_toolset_idc(
    fvv_profile_tier_level_t *self, uint64_t ptl_profile_toolset_idc)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_profile_toolset_idc = ptl_profile_toolset_idc;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_reconstruction_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_reconstruction_idc)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_profile_reconstruction_idc =
      ptl_profile_reconstruction_idc;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_reserved_zero_16bits(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_reserved_zero_16bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_reserved_zero_16bits = ptl_reserved_zero_16bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_reserved_0xffff_16bits(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_reserved_0xffff_16bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_reserved_0xffff_16bits = ptl_reserved_0xffff_16bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_level_idc(
    fvv_profile_tier_level_t *self, uint64_t ptl_level_idc)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_level_idc = ptl_level_idc;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_num_sub_profiles(
    fvv_profile_tier_level_t *self, uint64_t ptl_num_sub_profiles)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_num_sub_profiles = ptl_num_sub_profiles;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_extended_sub_profile_flag(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_extended_sub_profile_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_extended_sub_profile_flag =
      ptl_extended_sub_profile_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptl_sub_profile_idc(
    fvv_profile_tier_level_t *self,
    uint64_t
        ptl_sub_profile_idc[0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->ptl_sub_profile_idc,
         ptl_sub_profile_idc,
         sizeof(uint64_t) * (0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES));
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_profile_tier_level_set_ptl_tool_constraints_present_flag(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_tool_constraints_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptl_tool_constraints_present_flag =
      ptl_tool_constraints_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_profile_tier_level_set_ptci(
    fvv_profile_tier_level_t                      *self,
    fvv_profile_toolset_constraints_information_t *ptci)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ptci->copy_from(self->ptci, ptci);
  return FVV_RET_SUCCESS;
}

// }