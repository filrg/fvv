#include <fvv/bitstream.h>
#include <fvv/syntax/filler_payload.h>

// F.2.2 Filler payload SEI message syntax
fvv_ret_t fvv_filler_payload_init(fvv_filler_payload_t *self,
                                  fvv_bitstream_t      *data)
{
  *self      = (fvv_filler_payload_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_filler_payload_t, ff_byte);

  self->pack      = fvv_filler_payload_pack;
  self->copy_from = fvv_filler_payload_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_filler_payload_destroy(fvv_filler_payload_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_filler_payload_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_filler_payload_pack(fvv_filler_payload_t *self,
                                  uint64_t              payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         k    = 0;
  buff                  = self->data;

  for (k = 0; k < payloadSize; k++)
  {
    buff->write_bits(buff,
                     self->ff_byte, /* equal to 0xFF */
                     FVV_BIT_FF_BYTE,
                     FVV_DESCRIPTOR_FF_BYTE);
  }
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_filler_payload_copy_from(fvv_filler_payload_t *self,
                                       fvv_filler_payload_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ff_byte(self, other->ff_byte);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_filler_payload_t, ff_byte);