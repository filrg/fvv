#include <fvv/syntax/v3c_unit.h>
#include <fvv/syntax/v3c_unit_header.h>
#include <fvv/syntax/v3c_unit_payload.h>

// 8.3.2.1 General V3C unit syntax
// {
fvv_ret_t fvv_v3c_unit_init(fvv_v3c_unit_t  *self,
                            fvv_bitstream_t *data)
{
  *self           = (fvv_v3c_unit_t){0};

  self->pack      = fvv_v3c_unit_pack;
  self->copy_from = fvv_v3c_unit_copy_from;
  FVV_SET_SETTER_PTR(fvv_v3c_unit_t, vuh, fvv_v3c_unit_header_t);
  FVV_SET_SETTER_PTR(fvv_v3c_unit_t, vup, fvv_v3c_unit_payload_t);

  self->data = data;

  self->vuh =
      (fvv_v3c_unit_header_t *)malloc(sizeof(fvv_v3c_unit_header_t));
  self->vup = (fvv_v3c_unit_payload_t *)malloc(
      sizeof(fvv_v3c_unit_payload_t));

  fvv_v3c_unit_header_init(self->vuh, self, data);
  fvv_v3c_unit_payload_init(self->vup, self, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_unit_destroy(fvv_v3c_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_v3c_unit_t, vuh, fvv_v3c_unit_header_t);
  FVV_DESTROY_OBJ(fvv_v3c_unit_t, vup, fvv_v3c_unit_payload_t);

  *self = (fvv_v3c_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_pack(fvv_v3c_unit_t *self,
                            uint64_t        numBytesInV3CUnit)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_v3c_unit_header_t  *vuh = FVV_NULL;
  fvv_v3c_unit_payload_t *vup = FVV_NULL;

  vuh                         = self->vuh;
  vup                         = self->vup;

  vuh->pack(vuh);
  vup->pack(vup, numBytesInV3CUnit - 4);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_v3c_unit_copy_from(fvv_v3c_unit_t *self,
                                 fvv_v3c_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_vuh(self, other->vuh);
  self->set_vup(self, other->vup);

  return FVV_RET_SUCCESS;
}
FVV_DEFINE_OBJ_SETTER(fvv_v3c_unit_t, vuh, fvv_v3c_unit_header_t);
FVV_DEFINE_OBJ_SETTER(fvv_v3c_unit_t, vup, fvv_v3c_unit_payload_t);

// }