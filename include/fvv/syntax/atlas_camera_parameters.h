#ifndef FVV_SYNTAX_ATLAS_CAMERA_PARAMETERS_H
#define FVV_SYNTAX_ATLAS_CAMERA_PARAMETERS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// H.8.3.6.3.3 Atlas camera parameters syntax

struct fvv_atlas_camera_parameters_t
{
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(struct fvv_atlas_camera_parameters_t *self);
  fvv_ret_t (*copy_from)(
      struct fvv_atlas_camera_parameters_t *self,
      struct fvv_atlas_camera_parameters_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_camera_model);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_scale_enabled_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_offset_enabled_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_enabled_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_qx);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_qy);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_rotation_qz);

  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_scale_on_axis, 3);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_atlas_camera_parameters_t, acp_offset_on_axis, 3);
};

fvv_ret_t
          fvv_atlas_camera_parameters_init(fvv_atlas_camera_parameters_t *self,
                                           fvv_bitstream_t               *data);

fvv_ret_t fvv_atlas_camera_parameters_destroy(
    fvv_atlas_camera_parameters_t *self);

fvv_ret_t fvv_atlas_camera_parameters_pack(
    fvv_atlas_camera_parameters_t *self);
fvv_ret_t fvv_atlas_camera_parameters_copy_from(
    fvv_atlas_camera_parameters_t *self,
    fvv_atlas_camera_parameters_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_camera_model);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_scale_enabled_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_offset_enabled_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_enabled_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_qx);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_qy);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_camera_parameters_t, acp_rotation_qz);

FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_atlas_camera_parameters_t, acp_scale_on_axis, 3);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_atlas_camera_parameters_t, acp_offset_on_axis, 3);

#endif // FVV_SYNTAX_ATLAS_CAMERA_PARAMETERS_H