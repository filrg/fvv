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
  self->set_vuh   = fvv_v3c_unit_set_vuh;
  self->set_vup   = fvv_v3c_unit_set_vup;

  self->data      = data;

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
  if (self->vuh)
  {
    fvv_v3c_unit_header_destroy(self->vuh);
    free(self->vuh);
  }
  if (self->vup)
  {
    fvv_v3c_unit_payload_destroy(self->vup);
    free(self->vup);
  }

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
fvv_ret_t fvv_v3c_unit_set_vuh(fvv_v3c_unit_t        *self,
                               fvv_v3c_unit_header_t *vuh)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vuh->copy_from(self->vuh, vuh);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_v3c_unit_set_vup(fvv_v3c_unit_t         *self,
                               fvv_v3c_unit_payload_t *vup)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vup->copy_from(self->vup, vup);
  return FVV_RET_SUCCESS;
}

// }