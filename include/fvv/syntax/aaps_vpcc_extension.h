#ifndef FVV_SYNTAX_AAPS_VPCC_EXTENSION_H
#define FVV_SYNTAX_AAPS_VPCC_EXTENSION_H

// H.8.3.6.3.2 AAPS V-PCC extension syntax

#include <fvv/defs.h>
#include <fvv/semantic.h>

struct fvv_aaps_vpcc_extension_t
{
  uint64_t                       aaps_vpcc_camera_parameters_present_flag;
  fvv_atlas_camera_parameters_t *acp;

  fvv_bitstream_t               *data;

  fvv_ret_t (*pack)(struct fvv_aaps_vpcc_extension_t *self);
  fvv_ret_t (*copy_from)(struct fvv_aaps_vpcc_extension_t *self,
                         struct fvv_aaps_vpcc_extension_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_aaps_vpcc_extension_t, aaps_vpcc_camera_parameters_present_flag);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_aaps_vpcc_extension_t, acp, fvv_atlas_camera_parameters_t);
};

fvv_ret_t
fvv_aaps_vpcc_extension_init(fvv_aaps_vpcc_extension_t *self,
                             fvv_bitstream_t           *data);
fvv_ret_t
fvv_aaps_vpcc_extension_destroy(fvv_aaps_vpcc_extension_t *self);
fvv_ret_t
fvv_aaps_vpcc_extension_pack(fvv_aaps_vpcc_extension_t *self);
fvv_ret_t
fvv_aaps_vpcc_extension_copy_from(fvv_aaps_vpcc_extension_t *self,
                                  fvv_aaps_vpcc_extension_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_aaps_vpcc_extension_t, aaps_vpcc_camera_parameters_present_flag);
FVV_DECLARE_OBJ_SETTER(fvv_aaps_vpcc_extension_t, acp, fvv_atlas_camera_parameters_t);
#endif // FVV_SYNTAX_AAPS_VPCC_EXTENSION_H
