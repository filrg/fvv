#ifndef FVV_SYNTAX_ASPS_VPCC_EXTENSION_H
#define FVV_SYNTAX_ASPS_VPCC_EXTENSION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// H.8.3.6.1.3 ASPS V-PCC extension syntax
struct fvv_asps_vpcc_extension_t
{
  uint64_t                                 asps_vpcc_remove_duplicate_point_enabled_flag;
  uint64_t                                 asps_vpcc_surface_thickness_minus1;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(struct fvv_asps_vpcc_extension_t *self);
  fvv_ret_t (*copy_from)(struct fvv_asps_vpcc_extension_t *self,
                         struct fvv_asps_vpcc_extension_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_asps_vpcc_extension_t,
      asps_vpcc_remove_duplicate_point_enabled_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_asps_vpcc_extension_t,
                                  asps_vpcc_surface_thickness_minus1);
};
fvv_ret_t fvv_asps_vpcc_extension_init(
    fvv_asps_vpcc_extension_t               *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_asps_vpcc_extension_destroy(fvv_asps_vpcc_extension_t *self);
fvv_ret_t
fvv_asps_vpcc_extension_pack(fvv_asps_vpcc_extension_t *self);
fvv_ret_t
fvv_asps_vpcc_extension_copy_from(fvv_asps_vpcc_extension_t *self,
                                  fvv_asps_vpcc_extension_t *other);
FVV_DECLARE_SCALAR_SETTER(
    fvv_asps_vpcc_extension_t,
    asps_vpcc_remove_duplicate_point_enabled_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_asps_vpcc_extension_t,
                            asps_vpcc_surface_thickness_minus1);
#endif // FVV_SYNTAX_ASPS_VPCC_EXTENSION_H