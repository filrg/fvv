#ifndef FVV_SYNTAX_PROFILE_TIER_LEVEL_H
#define FVV_SYNTAX_PROFILE_TIER_LEVEL_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.4.2 Profile, tier, and level syntax
struct fvv_profile_tier_level_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;
  fvv_ret_t (*pack)(fvv_profile_tier_level_t *self);
  fvv_ret_t (*copy_from)(fvv_profile_tier_level_t *self,
                         fvv_profile_tier_level_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_tier_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_profile_codec_group_idc);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_profile_toolset_idc);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_profile_reconstruction_idc);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_reserved_zero_16bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_reserved_0xffff_16bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_level_idc);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_num_sub_profiles);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_extended_sub_profile_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_tier_level_t, ptl_tool_constraints_present_flag);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_profile_tier_level_t, ptl_sub_profile_idc, 0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_profile_tier_level_t, ptci, fvv_profile_toolset_constraints_information_t);
};

fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t          *data);
fvv_ret_t
          fvv_profile_tier_level_destroy(fvv_profile_tier_level_t *self);

fvv_ret_t fvv_profile_tier_level_pack(fvv_profile_tier_level_t *self);
fvv_ret_t fvv_profile_tier_level_copy_from(fvv_profile_tier_level_t *self,
                                           fvv_profile_tier_level_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_tier_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_profile_codec_group_idc);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_profile_toolset_idc);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_profile_reconstruction_idc);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_reserved_zero_16bits);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_reserved_0xffff_16bits);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_level_idc);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_num_sub_profiles);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_extended_sub_profile_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_tier_level_t, ptl_tool_constraints_present_flag);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_profile_tier_level_t, ptl_sub_profile_idc, 0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES);
FVV_DECLARE_OBJ_SETTER(fvv_profile_tier_level_t, ptci, fvv_profile_toolset_constraints_information_t);
#endif // FVV_SYNTAX_PROFILE_TIER_LEVEL_H