#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_camera_parameters.h>
#include <string.h>

// H.8.3.6.3.3 Atlas camera parameters syntax
// {
fvv_ret_t
fvv_atlas_camera_parameters_init(fvv_atlas_camera_parameters_t *self,
                                 fvv_bitstream_t               *data)
{
  *self           = (fvv_atlas_camera_parameters_t){0};
  self->data      = data;
  self->pack      = fvv_atlas_camera_parameters_pack;
  self->copy_from = fvv_atlas_camera_parameters_copy_from;

  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_camera_model);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_scale_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_offset_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_qx);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_qy);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_qz);

  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_scale_on_axis, 3);
  FVV_SET_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_offset_on_axis, 3);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_atlas_camera_parameters_destroy(
    fvv_atlas_camera_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_atlas_camera_parameters_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_camera_parameters_pack(fvv_atlas_camera_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         d    = 0;
  buff                  = self->data;

  buff->pad(buff, self->acp_camera_model, FVV_BIT_ACP_CAMERA_MODEL);
  if (self->acp_camera_model == 1)
  {
    buff->pad(buff,
              self->acp_scale_enabled_flag,
              FVV_BIT_ACP_SCALE_ENABLED_FLAG);
    buff->pad(buff,
              self->acp_offset_enabled_flag,
              FVV_BIT_ACP_OFFSET_ENABLED_FLAG);
    buff->pad(buff,
              self->acp_rotation_enabled_flag,
              FVV_BIT_ACP_ROTATION_ENABLED_FLAG);
    if (self->acp_scale_enabled_flag)
    {
      for (d = 0; d < 3; d++)
      {
        buff->pad(buff,
                  self->acp_scale_on_axis[d],
                  FVV_BIT_ACP_SCALE_ON_AXIS);
      }
    }
    if (self->acp_offset_enabled_flag)
    {
      for (d = 0; d < 3; d++)
      {
        buff->pad(buff,
                  self->acp_offset_on_axis[d],
                  FVV_BIT_ACP_OFFSET_ON_AXIS);
      }
    }
    if (self->acp_rotation_enabled_flag)
    {
      buff->pad(
          buff, self->acp_rotation_qx, FVV_BIT_ACP_ROTATION_QX);
      buff->pad(
          buff, self->acp_rotation_qy, FVV_BIT_ACP_ROTATION_QY);
      buff->pad(
          buff, self->acp_rotation_qz, FVV_BIT_ACP_ROTATION_QZ);
    }
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_camera_parameters_copy_from(
    fvv_atlas_camera_parameters_t *self,
    fvv_atlas_camera_parameters_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_acp_camera_model(self, other->acp_camera_model);
  self->set_acp_scale_enabled_flag(self,
                                   other->acp_scale_enabled_flag);
  self->set_acp_offset_enabled_flag(self,
                                    other->acp_offset_enabled_flag);
  self->set_acp_rotation_enabled_flag(
      self, other->acp_rotation_enabled_flag);
  self->set_acp_scale_on_axis(self, other->acp_scale_on_axis);
  self->set_acp_offset_on_axis(self, other->acp_offset_on_axis);
  self->set_acp_rotation_qx(self, other->acp_rotation_qx);
  self->set_acp_rotation_qy(self, other->acp_rotation_qy);
  self->set_acp_rotation_qz(self, other->acp_rotation_qz);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_camera_model);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_scale_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_offset_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_qx);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_qy);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_qz);

FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_atlas_camera_parameters_t, acp_scale_on_axis, 3);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_atlas_camera_parameters_t, acp_offset_on_axis, 3);