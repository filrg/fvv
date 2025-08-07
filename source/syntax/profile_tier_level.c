#include <fvv/bitstream.h>
#include <fvv/syntax/profile_tier_level.h>
#include <fvv/syntax/profile_toolset_constraints_information.h>
#include <string.h>

// 8.3.4.2 Profile, tier, and level syntax
// {
fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t          *data)
{
  *self           = (fvv_profile_tier_level_t){0};

  self->vps       = vps;
  self->data      = data;
  self->pack      = fvv_profile_tier_level_pack;
  self->copy_from = fvv_profile_tier_level_copy_from;
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t, ptl_tier_flag);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_profile_codec_group_idc);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_profile_toolset_idc);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_profile_reconstruction_idc);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_reserved_zero_16bits);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_reserved_0xffff_16bits);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t, ptl_level_idc);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t, ptl_num_sub_profiles);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_extended_sub_profile_flag);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_tool_constraints_present_flag);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptl_sub_profile_idc,
                     0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES);
  FVV_SET_SETTER_PTR(fvv_profile_tier_level_t,
                     ptci,
                     fvv_profile_toolset_constraints_information_t);

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
  FVV_DESTROY_OBJ(fvv_profile_tier_level_t,
                  ptci,
                  fvv_profile_toolset_constraints_information_t);
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

  buff->write_bits(buff,
                   self->ptl_tier_flag,
                   FVV_BIT_PTL_TIER_FLAG,
                   FVV_DESCRIPTOR_PTL_TIER_FLAG);
  buff->write_bits(buff,
                   self->ptl_profile_codec_group_idc,
                   FVV_BIT_PTL_PROFILE_CODEC_GROUP_IDC,
                   FVV_DESCRIPTOR_PTL_PROFILE_CODEC_GROUP_IDC);
  buff->write_bits(buff,
                   self->ptl_profile_toolset_idc,
                   FVV_BIT_PTL_PROFILE_TOOLSET_IDC,
                   FVV_DESCRIPTOR_PTL_PROFILE_TOOLSET_IDC);
  buff->write_bits(buff,
                   self->ptl_profile_reconstruction_idc,
                   FVV_BIT_PTL_PROFILE_RECONSTRUCTION_IDC,
                   FVV_DESCRIPTOR_PTL_PROFILE_RECONSTRUCTION_IDC);
  buff->write_bits(buff,
                   self->ptl_reserved_zero_16bits,
                   FVV_BIT_PTL_RESERVED_ZERO_16BITS,
                   FVV_DESCRIPTOR_PTL_RESERVED_ZERO_16BITS);
  buff->write_bits(buff,
                   self->ptl_reserved_0xffff_16bits,
                   FVV_BIT_PTL_RESERVED_0XFFFF_16BITS,
                   FVV_DESCRIPTOR_PTL_RESERVED_0XFFFF_16BITS);
  buff->write_bits(buff,
                   self->ptl_level_idc,
                   FVV_BIT_PTL_LEVEL_IDC,
                   FVV_DESCRIPTOR_PTL_LEVEL_IDC);
  buff->write_bits(buff,
                   self->ptl_num_sub_profiles,
                   FVV_BIT_PTL_NUM_SUB_PROFILES,
                   FVV_DESCRIPTOR_PTL_NUM_SUB_PROFILES);
  buff->write_bits(buff,
                   self->ptl_extended_sub_profile_flag,
                   FVV_BIT_PTL_EXTENDED_SUB_PROFILE_FLAG,
                   FVV_DESCRIPTOR_PTL_EXTENDED_SUB_PROFILE_FLAG);

  for (i = 0; i < self->ptl_num_sub_profiles; i++)
  {
    buff->write_bits(buff,
                     self->ptl_sub_profile_idc[i],
                     FVV_BIT_PTL_SUB_PROFILE_IDC,
                     FVV_DESCRIPTOR_PTL_SUB_PROFILE_IDC);
  }
  buff->write_bits(buff,
                   self->ptl_tool_constraints_present_flag,
                   FVV_BIT_PTL_TOOL_CONSTRAINTS_PRESENT_FLAG,
                   FVV_DESCRIPTOR_PTL_TOOL_CONSTRAINTS_PRESENT_FLAG);
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
  self->set_ptl_reserved_zero_16bits(self,
                                     other->ptl_reserved_zero_16bits);
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

FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_tier_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_profile_codec_group_idc);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_profile_toolset_idc);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_profile_reconstruction_idc);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_reserved_zero_16bits);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_reserved_0xffff_16bits);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_level_idc);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_num_sub_profiles);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_extended_sub_profile_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_profile_tier_level_t,
                         ptl_tool_constraints_present_flag);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_profile_tier_level_t,
                                ptl_sub_profile_idc,
                                0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES);
FVV_DEFINE_OBJ_SETTER(fvv_profile_tier_level_t,
                      ptci,
                      fvv_profile_toolset_constraints_information_t);
// }