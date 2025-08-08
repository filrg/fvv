#include <fvv/bitstream.h>
#include <fvv/syntax/hrd_parameters.h>
#include <fvv/syntax/hrd_sub_layer_parameters.h>

// G.2.3 Sub-layer HRD parameters syntax
fvv_ret_t fvv_hrd_sub_layer_parameters_init(
    fvv_hrd_sub_layer_parameters_t *self,
    fvv_hrd_parameters_t           *hp,
    fvv_bitstream_t                *data)
{
  *self      = (fvv_hrd_sub_layer_parameters_t){0};
  self->data = data;
  self->hp   = hp;

  FVV_SET_SETTER_PTR(fvv_hrd_sub_layer_parameters_t,
                     hrd_bit_rate_value_minus1);
  FVV_SET_SETTER_PTR(fvv_hrd_sub_layer_parameters_t,
                     hrd_cab_size_value_minus1);
  FVV_SET_SETTER_PTR(fvv_hrd_sub_layer_parameters_t, hrd_cbr_flag);

  self->pack      = fvv_hrd_sub_layer_parameters_pack;
  self->copy_from = fvv_hrd_sub_layer_parameters_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_hrd_sub_layer_parameters_destroy(
    fvv_hrd_sub_layer_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_3D_ARR(fvv_hrd_sub_layer_parameters_t,
                     hrd_bit_rate_value_minus1);
  FVV_DESTROY_3D_ARR(fvv_hrd_sub_layer_parameters_t,
                     hrd_cab_size_value_minus1);
  FVV_DESTROY_3D_ARR(fvv_hrd_sub_layer_parameters_t, hrd_cbr_flag);
  *self = (fvv_hrd_sub_layer_parameters_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_hrd_sub_layer_parameters_pack(
    fvv_hrd_sub_layer_parameters_t *self,
    uint64_t                        hrdMode,
    uint64_t                        subLayerID)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         j    = 0;
  buff                  = self->data;

  for (j = 0; j <= self->hp->hrd_cab_cnt_minus1[subLayerID]; j++)
  {
    buff->write_bits(
        buff,
        self->hrd_bit_rate_value_minus1[hrdMode][subLayerID][j],
        FVV_BIT_HRD_BIT_RATE_VALUE_MINUS1,
        FVV_DESCRIPTOR_HRD_BIT_RATE_VALUE_MINUS1);
    buff->write_bits(
        buff,
        self->hrd_cab_size_value_minus1[hrdMode][subLayerID][j],
        FVV_BIT_HRD_CAB_SIZE_VALUE_MINUS1,
        FVV_DESCRIPTOR_HRD_CAB_SIZE_VALUE_MINUS1);
    buff->write_bits(buff,
                     self->hrd_cbr_flag[hrdMode][subLayerID][j],
                     FVV_BIT_HRD_CBR_FLAG,
                     FVV_DESCRIPTOR_HRD_CBR_FLAG);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_hrd_sub_layer_parameters_copy_from(
    fvv_hrd_sub_layer_parameters_t *self,
    fvv_hrd_sub_layer_parameters_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_hrd_bit_rate_value_minus1(
      self,
      other->hrd_bit_rate_value_minus1,
      other->hrd_bit_rate_value_minus1_size);
  self->set_hrd_cab_size_value_minus1(
      self,
      other->hrd_cab_size_value_minus1,
      other->hrd_cab_size_value_minus1_size);
  self->set_hrd_cbr_flag(
      self, other->hrd_cbr_flag, other->hrd_cbr_flag_size);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_3D_ARR_SETTER(fvv_hrd_sub_layer_parameters_t,
                         hrd_bit_rate_value_minus1);
FVV_DEFINE_3D_ARR_SETTER(fvv_hrd_sub_layer_parameters_t,
                         hrd_cab_size_value_minus1);
FVV_DEFINE_3D_ARR_SETTER(fvv_hrd_sub_layer_parameters_t,
                         hrd_cbr_flag);