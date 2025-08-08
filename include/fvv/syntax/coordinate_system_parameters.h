#ifndef FVV_SYNTAX_COORDINATE_SYSTEM_PARAMETERS_H
#define FVV_SYNTAX_COORDINATE_SYSTEM_PARAMETERS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// G.2.5 Coordinate system parameters syntax
struct fvv_coordinate_system_parameters_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_coordinate_system_parameters_t,
                                csp_forward_axis);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_coordinate_system_parameters_t,
                                csp_delta_left_axis_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_coordinate_system_parameters_t,
                                csp_forward_sign);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_coordinate_system_parameters_t,
                                csp_left_sign);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_coordinate_system_parameters_t,
                                csp_up_sign);

  fvv_ret_t (*pack)(fvv_coordinate_system_parameters_t *self);
  fvv_ret_t (*copy_from)(fvv_coordinate_system_parameters_t *self,
                         fvv_coordinate_system_parameters_t *other);
};

fvv_ret_t fvv_coordinate_system_parameters_init(
    fvv_coordinate_system_parameters_t *self, fvv_bitstream_t *data);
fvv_ret_t fvv_coordinate_system_parameters_destroy(
    fvv_coordinate_system_parameters_t *self);
fvv_ret_t fvv_coordinate_system_parameters_pack(
    fvv_coordinate_system_parameters_t *self);
fvv_ret_t fvv_coordinate_system_parameters_copy_from(
    fvv_coordinate_system_parameters_t *self,
    fvv_coordinate_system_parameters_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                          csp_forward_axis);
FVV_DECLARE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                          csp_delta_left_axis_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                          csp_forward_sign);
FVV_DECLARE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                          csp_left_sign);
FVV_DECLARE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                          csp_up_sign);

#endif // FVV_SYNTAX_COORDINATE_SYSTEM_PARAMETERS_H