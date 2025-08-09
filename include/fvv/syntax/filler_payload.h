#ifndef FVV_SYNTAX_FILLER_PAYLOAD_H
#define FVV_SYNTAX_FILLER_PAYLOAD_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.2 Filler payload SEI message syntax
struct fvv_filler_payload_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_filler_payload_t, ff_byte);

  fvv_ret_t (*pack)(fvv_filler_payload_t *self, uint64_t payloadSize);
  fvv_ret_t (*copy_from)(fvv_filler_payload_t *self,
                         fvv_filler_payload_t *other);
};

fvv_ret_t fvv_filler_payload_init(fvv_filler_payload_t *self,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_filler_payload_destroy(fvv_filler_payload_t *self);
fvv_ret_t fvv_filler_payload_pack(fvv_filler_payload_t *self,
                                  uint64_t              payloadSize);
fvv_ret_t fvv_filler_payload_copy_from(fvv_filler_payload_t *self,
                                       fvv_filler_payload_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_filler_payload_t, ff_byte);

#endif // FVV_SYNTAX_FILLER_PAYLOAD_H