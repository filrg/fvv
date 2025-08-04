#ifndef FVV_SYNTAX_PROFILE_TOOLSET_CONSTRAINTS_INFORMATION_H
#define FVV_SYNTAX_PROFILE_TOOLSET_CONSTRAINTS_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.4.6 Profile toolset constraints information syntax
struct fvv_profile_toolset_constraints_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;
  fvv_ret_t (*pack)(
      fvv_profile_toolset_constraints_information_t *self);
  fvv_ret_t (*copy_from)(
      fvv_profile_toolset_constraints_information_t *self,
      fvv_profile_toolset_constraints_information_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_one_v3c_frame_only_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_eom_constraint_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_max_map_count_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_max_atlas_count_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_multiple_map_streams_constraint_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_plr_constraint_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_attribute_max_dimension_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_attribute_max_dimension_partitions_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_no_eight_orientations_constraint_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_no_45degree_projection_patch_constraint_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_reserved_zero_6bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_num_reserved_constraint_bytes);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_profile_toolset_constraints_information_t, ptc_reserved_constraint_byte, 0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES);
};
fvv_ret_t fvv_profile_toolset_constraints_information_init(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_v3c_parameter_set_t                       *vps,
    fvv_bitstream_t                               *data);
fvv_ret_t fvv_profile_toolset_constraints_information_destroy(
    fvv_profile_toolset_constraints_information_t *self);
fvv_ret_t fvv_profile_toolset_constraints_information_pack(
    fvv_profile_toolset_constraints_information_t *self);
fvv_ret_t fvv_profile_toolset_constraints_information_copy_from(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_profile_toolset_constraints_information_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_one_v3c_frame_only_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_eom_constraint_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_max_map_count_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_max_atlas_count_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_multiple_map_streams_constraint_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_plr_constraint_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_attribute_max_dimension_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_attribute_max_dimension_partitions_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_no_eight_orientations_constraint_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_no_45degree_projection_patch_constraint_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_reserved_zero_6bits);
FVV_DECLARE_SCALAR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_num_reserved_constraint_bytes);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_profile_toolset_constraints_information_t, ptc_reserved_constraint_byte, 0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES);

#endif // FVV_SYNTAX_PROFILE_TOOLSET_CONSTRAINTS_INFORMATION_H