#include <fvv/bitstream.h>
#include <fvv/syntax/coordinate_system_parameters.h>

// G.2.5 Coordinate system parameters syntax
fvv_ret_t fvv_coordinate_system_parameters_init(
    fvv_coordinate_system_parameters_t *self, fvv_bitstream_t *data)
{
  *self      = (fvv_coordinate_system_parameters_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_coordinate_system_parameters_t,
                     csp_forward_axis);
  FVV_SET_SETTER_PTR(fvv_coordinate_system_parameters_t,
                     csp_delta_left_axis_minus1);
  FVV_SET_SETTER_PTR(fvv_coordinate_system_parameters_t,
                     csp_forward_sign);
  FVV_SET_SETTER_PTR(fvv_coordinate_system_parameters_t,
                     csp_left_sign);
  FVV_SET_SETTER_PTR(fvv_coordinate_system_parameters_t, csp_up_sign);

  self->pack      = fvv_coordinate_system_parameters_pack;
  self->copy_from = fvv_coordinate_system_parameters_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_coordinate_system_parameters_destroy(
    fvv_coordinate_system_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_coordinate_system_parameters_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_coordinate_system_parameters_pack(
    fvv_coordinate_system_parameters_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->csp_forward_axis,
                   FVV_BIT_CSP_FORWARD_AXIS,
                   FVV_DESCRIPTOR_CSP_FORWARD_AXIS);
  buff->write_bits(buff,
                   self->csp_delta_left_axis_minus1,
                   FVV_BIT_CSP_DELTA_LEFT_AXIS_MINUS1,
                   FVV_DESCRIPTOR_CSP_DELTA_LEFT_AXIS_MINUS1);
  buff->write_bits(buff,
                   self->csp_forward_sign,
                   FVV_BIT_CSP_FORWARD_SIGN,
                   FVV_DESCRIPTOR_CSP_FORWARD_SIGN);
  buff->write_bits(buff,
                   self->csp_left_sign,
                   FVV_BIT_CSP_LEFT_SIGN,
                   FVV_DESCRIPTOR_CSP_LEFT_SIGN);
  buff->write_bits(buff,
                   self->csp_up_sign,
                   FVV_BIT_CSP_UP_SIGN,
                   FVV_DESCRIPTOR_CSP_UP_SIGN);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_coordinate_system_parameters_copy_from(
    fvv_coordinate_system_parameters_t *self,
    fvv_coordinate_system_parameters_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_csp_forward_axis(self, other->csp_forward_axis);
  self->set_csp_delta_left_axis_minus1(
      self, other->csp_delta_left_axis_minus1);
  self->set_csp_forward_sign(self, other->csp_forward_sign);
  self->set_csp_left_sign(self, other->csp_left_sign);
  self->set_csp_up_sign(self, other->csp_up_sign);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                         csp_forward_axis);
FVV_DEFINE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                         csp_delta_left_axis_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                         csp_forward_sign);
FVV_DEFINE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                         csp_left_sign);
FVV_DEFINE_SCALAR_SETTER(fvv_coordinate_system_parameters_t,
                         csp_up_sign);