#include <fvv/bitstream.h>
#include <fvv/syntax/aaps_vpcc_extension.h>
#include <fvv/syntax/atlas_adaptation_parameter_set_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.3 Atlas adaptation parameter set RBSP syntax
// {

fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_init(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_bitstream_t                           *data)
{
  *self           = (fvv_atlas_adaptation_parameter_set_rbsp_t){0};

  self->data      = data;

  self->pack      = fvv_atlas_adaptation_parameter_set_rbsp_pack;
  self->copy_from = fvv_atlas_adaptation_parameter_set_rbsp_copy_from;

  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     aaps_atlas_adaptation_parameter_set_id);
  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     aaps_extension_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     aaps_vpcc_extension_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     aaps_extension_7bits);
  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     aaps_extension_data_flag);

  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     ave,
                     fvv_aaps_vpcc_extension_t);
  FVV_SET_SETTER_PTR(fvv_atlas_adaptation_parameter_set_rbsp_t,
                     rtb,
                     fvv_rbsp_trailing_bits_t);

  self->ave = (fvv_aaps_vpcc_extension_t *)malloc(
      sizeof(fvv_aaps_vpcc_extension_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_aaps_vpcc_extension_init(self->ave, data);
  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_destroy(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_atlas_adaptation_parameter_set_rbsp_t,
                  ave,
                  fvv_aaps_vpcc_extension_t);
  FVV_DESTROY_OBJ(fvv_atlas_adaptation_parameter_set_rbsp_t,
                  rtb,
                  fvv_rbsp_trailing_bits_t);
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
  fvv_bool_t       more_rbsp_data = 0;
  buff                            = self->data;

  buff->write_bits(
      buff,
      self->aaps_atlas_adaptation_parameter_set_id,
      FVV_BIT_AAPS_ATLAS_ADAPTATION_PARAMETER_SET_ID,
      FVV_DESCRIPTOR_AAPS_ATLAS_ADAPTATION_PARAMETER_SET_ID);
  buff->write_bits(buff,
                   self->aaps_extension_present_flag,
                   FVV_BIT_AAPS_EXTENSION_PRESENT_FLAG,
                   FVV_DESCRIPTOR_AAPS_EXTENSION_PRESENT_FLAG);
  if (self->aaps_extension_present_flag)
  {
    buff->write_bits(buff,
                     self->aaps_vpcc_extension_present_flag,
                     FVV_BIT_AAPS_VPCC_EXTENSION_PRESENT_FLAG,
                     FVV_DESCRIPTOR_AAPS_VPCC_EXTENSION_PRESENT_FLAG);
    buff->write_bits(buff,
                     self->aaps_extension_7bits,
                     FVV_BIT_AAPS_EXTENSION_7BITS,
                     FVV_DESCRIPTOR_AAPS_EXTENSION_7BITS);
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
      buff->write_bits(buff,
                       self->aaps_extension_data_flag,
                       FVV_BIT_AAPS_EXTENSION_DATA_FLAG,
                       FVV_DESCRIPTOR_AAPS_EXTENSION_DATA_FLAG);
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
  self->set_aaps_extension_data_flag(self,
                                     other->aaps_extension_data_flag);

  self->set_ave(self, other->ave);
  self->set_rtb(self, other->rtb);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                         aaps_atlas_adaptation_parameter_set_id);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                         aaps_extension_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                         aaps_vpcc_extension_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                         aaps_extension_7bits);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                         aaps_extension_data_flag);

FVV_DEFINE_OBJ_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                      ave,
                      fvv_aaps_vpcc_extension_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_adaptation_parameter_set_rbsp_t,
                      rtb,
                      fvv_rbsp_trailing_bits_t);

// }
