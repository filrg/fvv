#ifndef FVV_SYNTAX_HRD_PARAMETERS_H
#define FVV_SYNTAX_HRD_PARAMETERS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// G.2.2 HRD parameters syntax
struct fvv_hrd_parameters_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_nal_parameters_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_acl_parameters_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_bit_rate_scale);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_cab_size_scale);

  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_fixed_atlas_rate_general_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_fixed_atlas_rate_within_cas_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_elemental_duration_in_tc_minus1);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_low_delay_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_hrd_parameters_t,
                                hrd_cab_cnt_minus1);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_hrd_parameters_t,
                             hslp,
                             fvv_hrd_sub_layer_parameters_t);

  fvv_ret_t (*pack)(fvv_hrd_parameters_t *self,
                    uint64_t              maxNumSubLayersMinus1);
  fvv_ret_t (*copy_from)(fvv_hrd_parameters_t *self,
                         fvv_hrd_parameters_t *other);
};

fvv_ret_t fvv_hrd_parameters_init(fvv_hrd_parameters_t *self,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_hrd_parameters_destroy(fvv_hrd_parameters_t *self);
fvv_ret_t fvv_hrd_parameters_pack(fvv_hrd_parameters_t *self,
                                  uint64_t maxNumSubLayersMinus1);
fvv_ret_t fvv_hrd_parameters_copy_from(fvv_hrd_parameters_t *self,
                                       fvv_hrd_parameters_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_hrd_parameters_t,
                          hrd_nal_parameters_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_hrd_parameters_t,
                          hrd_acl_parameters_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_hrd_parameters_t, hrd_bit_rate_scale);
FVV_DECLARE_SCALAR_SETTER(fvv_hrd_parameters_t, hrd_cab_size_scale);

FVV_DECLARE_1D_ARR_SETTER(fvv_hrd_parameters_t,
                          hrd_fixed_atlas_rate_general_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_hrd_parameters_t,
                          hrd_fixed_atlas_rate_within_cas_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_hrd_parameters_t,
                          hrd_elemental_duration_in_tc_minus1);
FVV_DECLARE_1D_ARR_SETTER(fvv_hrd_parameters_t, hrd_low_delay_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_hrd_parameters_t, hrd_cab_cnt_minus1);
FVV_DECLARE_OBJ_SETTER(fvv_hrd_parameters_t,
                       hslp,
                       fvv_hrd_sub_layer_parameters_t);

#endif // FVV_SYNTAX_HRD_PARAMETERS_H
