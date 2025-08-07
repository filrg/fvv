#include <fvv/bitstream.h>
#include <fvv/syntax/asps_vpcc_extension.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
// H.8.3.6.1.3 ASPS V-PCC extension syntax
// {
fvv_ret_t fvv_asps_vpcc_extension_init(
    fvv_asps_vpcc_extension_t               *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self           = (fvv_asps_vpcc_extension_t){0};
  self->data      = data;
  self->aspsr     = aspsr;
  self->pack      = fvv_asps_vpcc_extension_pack;
  self->copy_from = fvv_asps_vpcc_extension_copy_from;
  FVV_SET_SETTER_PTR(fvv_asps_vpcc_extension_t,
                     asps_vpcc_remove_duplicate_point_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_asps_vpcc_extension_t,
                     asps_vpcc_surface_thickness_minus1);
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_asps_vpcc_extension_destroy(fvv_asps_vpcc_extension_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_asps_vpcc_extension_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_asps_vpcc_extension_pack(fvv_asps_vpcc_extension_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->write_bits(buff,
            self->asps_vpcc_remove_duplicate_point_enabled_flag,
            FVV_BIT_ASPS_VPCC_REMOVE_DUPLICATE_POINT_ENABLED_FLAG);

  if (self->aspsr->asps_pixel_deinterleaving_enabled_flag ||
      self->aspsr->asps_plr_enabled_flag)
  {
    buff->write_bits(buff,
              self->asps_vpcc_surface_thickness_minus1,
              FVV_BIT_ASPS_VPCC_SURFACE_THICKNESS_MINUS1);
  }

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_asps_vpcc_extension_copy_from(fvv_asps_vpcc_extension_t *self,
                                  fvv_asps_vpcc_extension_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_asps_vpcc_remove_duplicate_point_enabled_flag(
      self, other->asps_vpcc_remove_duplicate_point_enabled_flag);
  self->set_asps_vpcc_surface_thickness_minus1(
      self, other->asps_vpcc_surface_thickness_minus1);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(
    fvv_asps_vpcc_extension_t,
    asps_vpcc_remove_duplicate_point_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_asps_vpcc_extension_t,
                           asps_vpcc_surface_thickness_minus1);
// }