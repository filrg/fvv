#ifndef FVV_SYNTAX_ATLAS_ADAPTATION_PARAMETER_SET_RBSP_H
#define FVV_SYNTAX_ATLAS_ADAPTATION_PARAMETER_SET_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.3 Atlas adaptation parameter set RBSP syntax
struct fvv_atlas_adaptation_parameter_set_rbsp_t
{

  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_atlas_adaptation_parameter_set_rbsp_t *self);
  fvv_ret_t (*copy_from)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      fvv_atlas_adaptation_parameter_set_rbsp_t *other);

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_atlas_adaptation_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_extension_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_vpcc_extension_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_extension_7bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_extension_data_flag);

  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, ave, fvv_aaps_vpcc_extension_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
};

fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_init(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_bitstream_t                           *data);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_destroy(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_pack(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_copy_from(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_atlas_adaptation_parameter_set_rbsp_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_atlas_adaptation_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_extension_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_vpcc_extension_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_extension_7bits);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, aaps_extension_data_flag);

FVV_DECLARE_OBJ_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, ave, fvv_aaps_vpcc_extension_t);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

#endif // FVV_SYNTAX_ATLAS_ADAPTATION_PARAMETER_SET_RBSP_H
