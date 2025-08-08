#include <fvv/bitstream.h>
#include <fvv/syntax/hrd_parameters.h>
#include <fvv/syntax/hrd_sub_layer_parameters.h>

fvv_ret_t fvv_hrd_parameters_init(fvv_hrd_parameters_t *self,
                                  fvv_bitstream_t      *data)
{
  *self           = (fvv_hrd_parameters_t){0};
  self->data      = data;
  self->pack      = fvv_hrd_parameters_pack;
  self->copy_from = fvv_hrd_parameters_copy_from;

  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t,
                     hrd_nal_parameters_present_flag);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t,
                     hrd_acl_parameters_present_flag);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t, hrd_bit_rate_scale);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t, hrd_cab_size_scale);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t,
                     hrd_fixed_atlas_rate_general_flag);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t,
                     hrd_fixed_atlas_rate_within_cas_flag);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t,
                     hrd_elemental_duration_in_tc_minus1);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t, hrd_low_delay_flag);
  FVV_SET_SETTER_PTR(fvv_hrd_parameters_t, hrd_cab_cnt_minus1);
  FVV_SET_SETTER_PTR(
      fvv_hrd_parameters_t, hslp, fvv_hrd_sub_layer_parameters_t);
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_hrd_parameters_destroy(fvv_hrd_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_hrd_parameters_t,
                     hrd_fixed_atlas_rate_general_flag);
  FVV_DESTROY_1D_ARR(fvv_hrd_parameters_t,
                     hrd_fixed_atlas_rate_within_cas_flag);
  FVV_DESTROY_1D_ARR(fvv_hrd_parameters_t,
                     hrd_elemental_duration_in_tc_minus1);
  FVV_DESTROY_1D_ARR(fvv_hrd_parameters_t, hrd_low_delay_flag);
  FVV_DESTROY_1D_ARR(fvv_hrd_parameters_t, hrd_cab_cnt_minus1);
  FVV_DESTROY_OBJ(
      fvv_hrd_parameters_t, hslp, fvv_hrd_sub_layer_parameters_t);
  *self = (fvv_hrd_parameters_t){0};

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_hrd_parameters_pack(fvv_hrd_parameters_t *self,
                                  uint64_t maxNumSubLayersMinus1)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  fvv_bitstream_t *buff = self->data;
  uint32_t         i    = 0;

  buff->write_bits(buff,
                   self->hrd_nal_parameters_present_flag,
                   FVV_BIT_HRD_NAL_PARAMETERS_PRESENT_FLAG,
                   FVV_DESCRIPTOR_HRD_NAL_PARAMETERS_PRESENT_FLAG);
  buff->write_bits(buff,
                   self->hrd_acl_parameters_present_flag,
                   FVV_BIT_HRD_ACL_PARAMETERS_PRESENT_FLAG,
                   FVV_DESCRIPTOR_HRD_ACL_PARAMETERS_PRESENT_FLAG);

  if (self->hrd_nal_parameters_present_flag ||
      self->hrd_acl_parameters_present_flag)
  {
    buff->write_bits(buff,
                     self->hrd_bit_rate_scale,
                     FVV_BIT_HRD_BIT_RATE_SCALE,
                     FVV_DESCRIPTOR_HRD_BIT_RATE_SCALE);
    buff->write_bits(buff,
                     self->hrd_cab_size_scale,
                     FVV_BIT_HRD_CAB_SIZE_SCALE,
                     FVV_DESCRIPTOR_HRD_CAB_SIZE_SCALE);
  }

  for (i = 0; i <= maxNumSubLayersMinus1; i++)
  {
    buff->write_bits(
        buff,
        self->hrd_fixed_atlas_rate_general_flag[i],
        FVV_BIT_HRD_FIXED_ATLAS_RATE_GENERAL_FLAG,
        FVV_DESCRIPTOR_HRD_FIXED_ATLAS_RATE_GENERAL_FLAG);

    if (!self->hrd_fixed_atlas_rate_general_flag[i])
    {
      buff->write_bits(
          buff,
          self->hrd_fixed_atlas_rate_within_cas_flag[i],
          FVV_BIT_HRD_FIXED_ATLAS_RATE_WITHIN_CAS_FLAG,
          FVV_DESCRIPTOR_HRD_FIXED_ATLAS_RATE_WITHIN_CAS_FLAG);
    }

    if (self->hrd_fixed_atlas_rate_within_cas_flag[i])
    {
      buff->write_bits(
          buff,
          self->hrd_elemental_duration_in_tc_minus1[i],
          FVV_BIT_HRD_ELEMENTAL_DURATION_IN_TC_MINUS1,
          FVV_DESCRIPTOR_HRD_ELEMENTAL_DURATION_IN_TC_MINUS1);
      self->hrd_low_delay_flag[i] = 0;
    }
    else
    {
      buff->write_bits(buff,
                       self->hrd_low_delay_flag[i],
                       FVV_BIT_HRD_LOW_DELAY_FLAG,
                       FVV_DESCRIPTOR_HRD_LOW_DELAY_FLAG);
    }

    if (!self->hrd_low_delay_flag[i])
    {
      buff->write_bits(buff,
                       self->hrd_cab_cnt_minus1[i],
                       FVV_BIT_HRD_CAB_CNT_MINUS1,
                       FVV_DESCRIPTOR_HRD_CAB_CNT_MINUS1);
    }

    if (self->hrd_nal_parameters_present_flag)
      self->hslp->pack(self->hslp, 0, i);
    if (self->hrd_acl_parameters_present_flag)
      self->hslp->pack(self->hslp, 1, i);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_hrd_parameters_copy_from(fvv_hrd_parameters_t *self,
                                       fvv_hrd_parameters_t *other)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  self->set_hrd_nal_parameters_present_flag(
      self, other->hrd_nal_parameters_present_flag);
  self->set_hrd_acl_parameters_present_flag(
      self, other->hrd_acl_parameters_present_flag);
  self->set_hrd_bit_rate_scale(self, other->hrd_bit_rate_scale);
  self->set_hrd_cab_size_scale(self, other->hrd_cab_size_scale);

  self->set_hrd_fixed_atlas_rate_general_flag(
      self,
      other->hrd_fixed_atlas_rate_general_flag,
      other->hrd_fixed_atlas_rate_general_flag_size);
  self->set_hrd_fixed_atlas_rate_within_cas_flag(
      self,
      other->hrd_fixed_atlas_rate_within_cas_flag,
      other->hrd_fixed_atlas_rate_within_cas_flag_size);
  self->set_hrd_elemental_duration_in_tc_minus1(
      self,
      other->hrd_elemental_duration_in_tc_minus1,
      other->hrd_elemental_duration_in_tc_minus1_size);
  self->set_hrd_low_delay_flag(self,
                               other->hrd_low_delay_flag,
                               other->hrd_low_delay_flag_size);
  self->set_hrd_cab_cnt_minus1(self,
                               other->hrd_cab_cnt_minus1,
                               other->hrd_cab_cnt_minus1_size);

  self->set_hslp(self, other->hslp);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_hrd_parameters_t,
                         hrd_nal_parameters_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_hrd_parameters_t,
                         hrd_acl_parameters_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_hrd_parameters_t, hrd_bit_rate_scale);
FVV_DEFINE_SCALAR_SETTER(fvv_hrd_parameters_t, hrd_cab_size_scale);

FVV_DEFINE_1D_ARR_SETTER(fvv_hrd_parameters_t,
                         hrd_fixed_atlas_rate_general_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_hrd_parameters_t,
                         hrd_fixed_atlas_rate_within_cas_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_hrd_parameters_t,
                         hrd_elemental_duration_in_tc_minus1);
FVV_DEFINE_1D_ARR_SETTER(fvv_hrd_parameters_t, hrd_low_delay_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_hrd_parameters_t, hrd_cab_cnt_minus1);

FVV_DEFINE_OBJ_SETTER(fvv_hrd_parameters_t,
                      hslp,
                      fvv_hrd_sub_layer_parameters_t);