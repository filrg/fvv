#ifndef FVV_SYNTAX_ATLAS_CAMERA_PARAMETERS_H
#define FVV_SYNTAX_ATLAS_CAMERA_PARAMETERS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// H.8.3.6.3.3 Atlas camera parameters syntax

struct fvv_atlas_camera_parameters_t
{
  uint64_t         acp_camera_model;
  uint64_t         acp_scale_enabled_flag;
  uint64_t         acp_offset_enabled_flag;
  uint64_t         acp_rotation_enabled_flag;
  uint64_t         acp_scale_on_axis[3];
  uint64_t         acp_offset_on_axis[3];
  uint64_t         acp_rotation_qx;
  uint64_t         acp_rotation_qy;
  uint64_t         acp_rotation_qz;

  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(struct fvv_atlas_camera_parameters_t *self);
  fvv_ret_t (*copy_from)(
      struct fvv_atlas_camera_parameters_t *self,
      struct fvv_atlas_camera_parameters_t *other);
  fvv_ret_t (*set_acp_camera_model)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_camera_model);
  fvv_ret_t (*set_acp_scale_enabled_flag)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_scale_enabled_flag);
  fvv_ret_t (*set_acp_offset_enabled_flag)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_offset_enabled_flag);
  fvv_ret_t (*set_acp_rotation_enabled_flag)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t acp_rotation_enabled_flag);
  fvv_ret_t (*set_acp_scale_on_axis)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_scale_on_axis[3]);
  fvv_ret_t (*set_acp_offset_on_axis)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_offset_on_axis[3]);
  fvv_ret_t (*set_acp_rotation_qx)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_rotation_qx);
  fvv_ret_t (*set_acp_rotation_qy)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_rotation_qy);
  fvv_ret_t (*set_acp_rotation_qz)(
      struct fvv_atlas_camera_parameters_t *self,
      uint64_t                              acp_rotation_qz);
};

fvv_ret_t
fvv_atlas_camera_parameters_init(fvv_atlas_camera_parameters_t *self,
                                 fvv_bitstream_t *data);

fvv_ret_t fvv_atlas_camera_parameters_destroy(
    fvv_atlas_camera_parameters_t *self);

fvv_ret_t fvv_atlas_camera_parameters_pack(
    fvv_atlas_camera_parameters_t *self);
fvv_ret_t fvv_atlas_camera_parameters_copy_from(
    fvv_atlas_camera_parameters_t *self,
    fvv_atlas_camera_parameters_t *other);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_camera_model(
    fvv_atlas_camera_parameters_t *self, uint64_t acp_camera_model);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_scale_enabled_flag(
    fvv_atlas_camera_parameters_t *self,
    uint64_t                       acp_scale_enabled_flag);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_offset_enabled_flag(
    fvv_atlas_camera_parameters_t *self,
    uint64_t                       acp_offset_enabled_flag);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_rotation_enabled_flag(
    fvv_atlas_camera_parameters_t *self,
    uint64_t                       acp_rotation_enabled_flag);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_scale_on_axis(
    fvv_atlas_camera_parameters_t *self,
    uint64_t                       acp_scale_on_axis[3]);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_offset_on_axis(
    fvv_atlas_camera_parameters_t *self,
    uint64_t                       acp_offset_on_axis[3]);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_rotation_qx(
    fvv_atlas_camera_parameters_t *self, uint64_t acp_rotation_qx);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_rotation_qy(
    fvv_atlas_camera_parameters_t *self, uint64_t acp_rotation_qy);
fvv_ret_t fvv_atlas_camera_parameters_set_acp_rotation_qz(
    fvv_atlas_camera_parameters_t *self, uint64_t acp_rotation_qz);

#endif // FVV_SYNTAX_ATLAS_CAMERA_PARAMETERS_H