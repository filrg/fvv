#include <fvv/bitstream.h>
#include <fvv/syntax/aaps_vpcc_extension.h>
#include <fvv/syntax/atlas_camera_parameters.h>
// H.8.3.6.3.2 AAPS V-PCC extension syntax
// {
fvv_ret_t
fvv_aaps_vpcc_extension_init(fvv_aaps_vpcc_extension_t *self,
                             fvv_bitstream_t           *data)
{
  *self           = (fvv_aaps_vpcc_extension_t){0};

  self->data      = data;

  self->pack      = fvv_aaps_vpcc_extension_pack;
  self->copy_from = fvv_aaps_vpcc_extension_copy_from;

  FVV_SET_SETTER_PTR(fvv_aaps_vpcc_extension_t, aaps_vpcc_camera_parameters_present_flag);
  FVV_SET_SETTER_PTR(fvv_aaps_vpcc_extension_t, acp, fvv_atlas_camera_parameters_t);

  self->acp = (fvv_atlas_camera_parameters_t *)malloc(
      sizeof(fvv_atlas_camera_parameters_t));

  fvv_atlas_camera_parameters_init(self->acp, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_aaps_vpcc_extension_destroy(fvv_aaps_vpcc_extension_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->acp)
  {
    fvv_atlas_camera_parameters_destroy(self->acp);
    free(self->acp);
  }
  *self = (fvv_aaps_vpcc_extension_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_aaps_vpcc_extension_pack(fvv_aaps_vpcc_extension_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->pad(buff,
            self->aaps_vpcc_camera_parameters_present_flag,
            FVV_BIT_AAPS_VPCC_CAMERA_PARAMETERS_PRESENT_FLAG);

  if (self->aaps_vpcc_camera_parameters_present_flag)
  {
    self->acp->pack(self->acp);
  }

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_aaps_vpcc_extension_copy_from(fvv_aaps_vpcc_extension_t *self,
                                  fvv_aaps_vpcc_extension_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_aaps_vpcc_camera_parameters_present_flag(
      self, other->aaps_vpcc_camera_parameters_present_flag);
  self->set_acp(self, other->acp);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_aaps_vpcc_extension_t, aaps_vpcc_camera_parameters_present_flag);
FVV_DEFINE_OBJ_SETTER(fvv_aaps_vpcc_extension_t, acp, fvv_atlas_camera_parameters_t);

// }