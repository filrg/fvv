#include <fvv/bitstream.h>
#include <fvv/syntax/nal_unit.h>
#include <fvv/syntax/nal_unit_header.h>
#include <string.h>

// 8.3.5.1 General NAL unit syntax
// {
fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t  *self,
                            fvv_bitstream_t *data)
{
  *self           = (fvv_nal_unit_t){0};

  self->data      = data;

  self->pack      = fvv_nal_unit_pack;
  self->copy_from = fvv_nal_unit_copy_from;
  FVV_SET_SETTER_PTR(fvv_nal_unit_t, rbsp_byte);
  FVV_SET_SETTER_PTR(fvv_nal_unit_t, nuh, fvv_nal_unit_header_t);
  self->nuh =
      (fvv_nal_unit_header_t *)malloc(sizeof(fvv_nal_unit_header_t));
  fvv_nal_unit_header_init(self->nuh, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_nal_unit_destroy(fvv_nal_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_nal_unit_t, rbsp_byte);
  FVV_DESTROY_OBJ(fvv_nal_unit_t, nuh, fvv_nal_unit_header_t);
  *self = (fvv_nal_unit_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_nal_unit_pack(fvv_nal_unit_t *self,
                            uint64_t        NumBytesInNalUnit)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (!self->rbsp_byte)
  {
    return FVV_RET_FAIL;
  }
  fvv_bitstream_t *buff           = FVV_NULL;
  uint64_t         NumBytesInRbsp = 0;
  uint64_t         i              = 0;
  buff                            = self->data;

  self->nuh->pack(self->nuh);

  NumBytesInRbsp = 0;
  for (i = 2; i < NumBytesInNalUnit; i++)
  {
    buff->write_bits(buff, self->rbsp_byte[i], FVV_BIT_RBSP_BYTE);
    NumBytesInRbsp++;
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_nal_unit_copy_from(fvv_nal_unit_t *self,
                                 fvv_nal_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_rbsp_byte(self, other->rbsp_byte, other->rbsp_byte_size);
  self->set_nuh(self, other->nuh);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_1D_ARR_SETTER(fvv_nal_unit_t, rbsp_byte);
FVV_DEFINE_OBJ_SETTER(fvv_nal_unit_t, nuh, fvv_nal_unit_header_t);
// }
