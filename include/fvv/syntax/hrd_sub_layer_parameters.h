#ifndef FVV_SYNTAX_HRD_SUB_LAYER_PARAMETERS_H
#define FVV_SYNTAX_HRD_SUB_LAYER_PARAMETERS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// G.2.3 Sub-layer HRD parameters syntax
struct fvv_hrd_sub_layer_parameters_t
{
  fvv_hrd_parameters_t *hp;
  fvv_bitstream_t      *data;

  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_hrd_sub_layer_parameters_t,
                                hrd_bit_rate_value_minus1);
  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_hrd_sub_layer_parameters_t,
                                hrd_cab_size_value_minus1);
  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_hrd_sub_layer_parameters_t,
                                hrd_cbr_flag);

  fvv_ret_t (*pack)(fvv_hrd_sub_layer_parameters_t *self,
                    uint64_t                        hrdMode,
                    uint64_t                        subLayerID);
  fvv_ret_t (*copy_from)(fvv_hrd_sub_layer_parameters_t *self,
                         fvv_hrd_sub_layer_parameters_t *other);
};

fvv_ret_t fvv_hrd_sub_layer_parameters_init(
    fvv_hrd_sub_layer_parameters_t *self,
    fvv_hrd_parameters_t           *hp,
    fvv_bitstream_t                *data);
fvv_ret_t fvv_hrd_sub_layer_parameters_destroy(
    fvv_hrd_sub_layer_parameters_t *self);
fvv_ret_t fvv_hrd_sub_layer_parameters_pack(
    fvv_hrd_sub_layer_parameters_t *self,
    uint64_t                        hrdMode,
    uint64_t                        subLayerID);
fvv_ret_t fvv_hrd_sub_layer_parameters_copy_from(
    fvv_hrd_sub_layer_parameters_t *self,
    fvv_hrd_sub_layer_parameters_t *other);

FVV_DECLARE_3D_ARR_SETTER(fvv_hrd_sub_layer_parameters_t,
                          hrd_bit_rate_value_minus1);
FVV_DECLARE_3D_ARR_SETTER(fvv_hrd_sub_layer_parameters_t,
                          hrd_cab_size_value_minus1);
FVV_DECLARE_3D_ARR_SETTER(fvv_hrd_sub_layer_parameters_t,
                          hrd_cbr_flag);

#endif // FVV_SYNTAX_HRD_SUB_LAYER_PARAMETERS_H