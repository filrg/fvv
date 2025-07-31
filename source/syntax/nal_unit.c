#include <fvv/bitstream.h>
#include <fvv/syntax/nal_unit.h>
#include <fvv/syntax/nal_unit_header.h>
// 8.3.5.1 General NAL unit syntax
// {
fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t            *self,
                            fvv_atlas_sub_bitstream_t *asb,
                            fvv_bitstream_t           *data)
{
  *self                     = (fvv_nal_unit_t){0};

  self->asb                 = asb;
  self->data                = data;

  self->pack                = fvv_nal_unit_pack;
  self->copy_from           = fvv_nal_unit_copy_from;
  self->set_rbsp_byte       = fvv_nal_unit_set_rbsp_byte;
  self->set_nal_unit_header = fvv_nal_unit_set_nal_unit_header;

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
  if (self->rbsp_byte)
  {
    free(self->rbsp_byte);
  }
  if (self->nuh)
  {
    fvv_nal_unit_header_destroy(self->nuh);
    free(self->nuh);
  }
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
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->pad(buff,
            self->nuh->nal_forbidden_zero_bit,
            FVV_BIT_NAL_FORBIDDEN_ZERO_BIT);
  buff->pad(buff, self->nuh->nal_unit_type, FVV_BIT_NAL_UNIT_TYPE);
  buff->pad(buff, self->nuh->nal_layer_id, FVV_BIT_NAL_LAYER_ID);
  buff->pad(buff,
            self->nuh->nal_temporal_id_plus1,
            FVV_BIT_NAL_TEMPORAL_ID_PLUS1);

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
  self->set_nal_unit_header(self, other->nuh);
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_nal_unit_set_rbsp_byte(fvv_nal_unit_t *self,
                                     const uint64_t *rbsp_byte,
                                     uint64_t        rbsp_byte_size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->rbsp_byte)
  {
    free(self->rbsp_byte);
    self->rbsp_byte      = FVV_NULL;
    self->rbsp_byte_size = 0;
  }

  self->rbsp_byte =
      (uint64_t *)malloc(rbsp_byte_size * sizeof(uint64_t));
  memcpy(
      self->rbsp_byte, rbsp_byte, rbsp_byte_size * sizeof(uint64_t));
  self->rbsp_byte_size = rbsp_byte_size;

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_nal_unit_set_nal_unit_header(fvv_nal_unit_t        *self,
                                 fvv_nal_unit_header_t *nuh)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->nuh->copy_from(self->nuh, nuh);
  return FVV_RET_SUCCESS;
}
// }
