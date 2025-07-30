#include <syntax/atlas_adaptation_parameter_set_rbsp.h>

// 8.3.6.3 Atlas adaptation parameter set RBSP syntax
// {

fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_init(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_atlas_sequence_parameter_set_rbsp_t   *aspsr,
    fvv_bitstream_t                           *data)
{
  *self       = (fvv_atlas_adaptation_parameter_set_rbsp_t){0};

  self->aspsr = aspsr;
  self->data  = data;

  self->pack  = fvv_atlas_adaptation_parameter_set_rbsp_pack;
  self->copy_from =
      fvv_atlas_adaptation_parameter_set_rbsp_copy_from;
  self->set_aaps_atlas_adaptation_parameter_set_id =
      fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_atlas_adaptation_parameter_set_id;
  self->set_aaps_extension_present_flag =
      fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_present_flag;
  self->set_aaps_vpcc_extension_present_flag =
      fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_vpcc_extension_present_flag;
  self->set_aaps_extension_7bits =
      fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_7bits;
  self->set_aaps_extension_data_flag =
      fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_data_flag;
  self->set_ave = fvv_atlas_adaptation_parameter_set_rbsp_set_ave;
  self->set_rtb = fvv_atlas_adaptation_parameter_set_rbsp_set_rtb;

  self->ave     = (fvv_aaps_vpcc_extension_t *)malloc(
      sizeof(fvv_aaps_vpcc_extension_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_aaps_vpcc_extension_init(self->ave, data);
  fvv_rbsp_trailing_bits_init(self->rtb, aspsr, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_destroy(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ave)
  {
    fvv_aaps_vpcc_extension_destroy(self->ave);
    free(self->ave);
  }
  if (self->rtb)
  {
    fvv_rbsp_trailing_bits_destroy(self->rtb);
    free(self->rtb);
  }
  *self = (fvv_atlas_adaptation_parameter_set_rbsp_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_pack(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff           = FVV_NULL;
  uint64_t         more_rbsp_data = 0;
  buff                            = self->data;

  buff->pad(buff,
            self->aaps_atlas_adaptation_parameter_set_id,
            FVV_BIT_AAPS_ATLAS_ADAPTATION_PARAMETER_SET_ID);
  buff->pad(buff,
            self->aaps_extension_present_flag,
            FVV_BIT_AAPS_EXTENSION_PRESENT_FLAG);
  if (self->aaps_extension_present_flag)
  {
    buff->pad(buff,
              self->aaps_vpcc_extension_present_flag,
              FVV_BIT_AAPS_VPCC_EXTENSION_PRESENT_FLAG);
    buff->pad(buff,
              self->aaps_extension_7bits,
              FVV_BIT_AAPS_EXTENSION_7BITS);
  }
  if (self->aaps_vpcc_extension_present_flag)
  {
    self->ave->pack(self->ave);
  }
  if (self->aaps_extension_7bits)
  {
    buff->more_rbsp_data(buff, &more_rbsp_data);
    while (more_rbsp_data)
    {
      buff->pad(buff,
                self->aaps_extension_data_flag,
                FVV_BIT_AAPS_EXTENSION_DATA_FLAG);
      buff->more_rbsp_data(buff, &more_rbsp_data);
    }
  }
  self->rtb->pack(self->rtb);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_copy_from(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_atlas_adaptation_parameter_set_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_aaps_atlas_adaptation_parameter_set_id(
      self, other->aaps_atlas_adaptation_parameter_set_id);
  self->set_aaps_extension_present_flag(
      self, other->aaps_extension_present_flag);
  self->set_aaps_vpcc_extension_present_flag(
      self, other->aaps_vpcc_extension_present_flag);
  self->set_aaps_extension_7bits(self, other->aaps_extension_7bits);
  self->set_aaps_extension_data_flag(
      self, other->aaps_extension_data_flag);

  self->set_ave(self, other->ave);
  self->set_rtb(self, other->rtb);
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_atlas_adaptation_parameter_set_id(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_atlas_adaptation_parameter_set_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->aaps_atlas_adaptation_parameter_set_id =
      aaps_atlas_adaptation_parameter_set_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_present_flag(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_extension_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->aaps_extension_present_flag = aaps_extension_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_vpcc_extension_present_flag(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_vpcc_extension_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->aaps_vpcc_extension_present_flag =
      aaps_vpcc_extension_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_7bits(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t                                   aaps_extension_7bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->aaps_extension_7bits = aaps_extension_7bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_data_flag(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_extension_data_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->aaps_extension_data_flag = aaps_extension_data_flag;
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_set_ave(
    *self, fvv_aaps_vpcc_extension_t *ave)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ave->copy_from(self->ave, ave);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_set_rtb(
    *self, fvv_rbsp_trailing_bits_t *rtb)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rtb->copy_from(self->rtb, rtb);
  return FVV_RET_SUCCESS;
}

// }
