#ifndef FVV_SYNTAX_PROFILE_TIER_LEVEL_H
#define FVV_SYNTAX_PROFILE_TIER_LEVEL_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// typedef struct fvv_v3c_parameter_set_t  fvv_v3c_parameter_set_t;
// typedef struct fvv_profile_tier_level_t fvv_profile_tier_level_t;
// typedef struct fvv_profile_toolset_constraints_information_t
//     fvv_profile_toolset_constraints_information_t;

// 8.3.4.2 Profile, tier, and level syntax
struct fvv_profile_tier_level_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint64_t                 ptl_tier_flag;                  // u(1)
  uint64_t                 ptl_profile_codec_group_idc;    // u(7)
  uint64_t                 ptl_profile_toolset_idc;        // u(8)
  uint64_t                 ptl_profile_reconstruction_idc; // u(8)
  uint64_t                 ptl_reserved_zero_16bits;       // u(16)
  uint64_t                 ptl_reserved_0xffff_16bits;     // u(16)
  uint64_t                 ptl_level_idc;                  // u(8)
  uint64_t                 ptl_num_sub_profiles;           // u(6)
  uint64_t                 ptl_extended_sub_profile_flag;  // u(1)
  uint64_t
           ptl_sub_profile_idc[0x1
                          << FVV_BIT_PTL_NUM_SUB_PROFILES]; // u(v)
  uint64_t ptl_tool_constraints_present_flag; // u(1)

  fvv_profile_toolset_constraints_information_t *ptci;

  fvv_ret_t (*pack)(fvv_profile_tier_level_t *self);
  fvv_ret_t (*copy_from)(fvv_profile_tier_level_t *self,
                         fvv_profile_tier_level_t *other);
  fvv_ret_t (*set_ptl_tier_flag)(fvv_profile_tier_level_t *self,
                                 uint64_t ptl_tier_flag);
  fvv_ret_t (*set_ptl_profile_codec_group_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_profile_codec_group_idc);
  fvv_ret_t (*set_ptl_profile_toolset_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_profile_toolset_idc);
  fvv_ret_t (*set_ptl_profile_reconstruction_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_profile_reconstruction_idc);
  fvv_ret_t (*set_ptl_reserved_zero_16bits)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_reserved_zero_16bits);
  fvv_ret_t (*set_ptl_reserved_0xffff_16bits)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_reserved_0xffff_16bits);
  fvv_ret_t (*set_ptl_level_idc)(fvv_profile_tier_level_t *self,
                                 uint64_t ptl_level_idc);
  fvv_ret_t (*set_ptl_num_sub_profiles)(
      fvv_profile_tier_level_t *self, uint64_t ptl_num_sub_profiles);
  fvv_ret_t (*set_ptl_extended_sub_profile_flag)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_extended_sub_profile_flag);
  fvv_ret_t (*set_ptl_sub_profile_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t
          ptl_sub_profile_idc[0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES]);
  fvv_ret_t (*set_ptl_tool_constraints_present_flag)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_tool_constraints_present_flag);
  fvv_ret_t (*set_ptci)(
      fvv_profile_tier_level_t                      *self,
      fvv_profile_toolset_constraints_information_t *ptci);
};

fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t *data);
fvv_ret_t
fvv_profile_tier_level_destroy(fvv_profile_tier_level_t *self);

fvv_ret_t
fvv_profile_tier_level_pack(fvv_profile_tier_level_t *self);
fvv_ret_t
fvv_profile_tier_level_copy_from(fvv_profile_tier_level_t *self,
                                 fvv_profile_tier_level_t *other);
fvv_ret_t fvv_profile_tier_level_set_ptl_tier_flag(
    fvv_profile_tier_level_t *self, uint64_t ptl_tier_flag);
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_codec_group_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_codec_group_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_toolset_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_toolset_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_reconstruction_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_reconstruction_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_reserved_zero_16bits(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_reserved_zero_16bits);
fvv_ret_t fvv_profile_tier_level_set_ptl_reserved_0xffff_16bits(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_reserved_0xffff_16bits);
fvv_ret_t fvv_profile_tier_level_set_ptl_level_idc(
    fvv_profile_tier_level_t *self, uint64_t ptl_level_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_num_sub_profiles(
    fvv_profile_tier_level_t *self, uint64_t ptl_num_sub_profiles);
fvv_ret_t fvv_profile_tier_level_set_ptl_extended_sub_profile_flag(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_extended_sub_profile_flag);
fvv_ret_t fvv_profile_tier_level_set_ptl_sub_profile_idc(
    fvv_profile_tier_level_t *self,
    uint64_t
        ptl_sub_profile_idc[0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES]);
fvv_ret_t
fvv_profile_tier_level_set_ptl_tool_constraints_present_flag(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_tool_constraints_present_flag);
fvv_ret_t fvv_profile_tier_level_set_ptci(
    fvv_profile_tier_level_t                      *self,
    fvv_profile_toolset_constraints_information_t *ptci);
#endif // FVV_SYNTAX_PROFILE_TIER_LEVEL_H