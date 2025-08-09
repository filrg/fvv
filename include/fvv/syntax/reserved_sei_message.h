#ifndef FVV_SYNTAX_RESERVED_SEI_MESSAGE_H
#define FVV_SYNTAX_RESERVED_SEI_MESSAGE_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.7 Reserved SEI message syntax
struct fvv_reserved_sei_message_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_reserved_sei_message_t,
                                reserved_sei_message_payload_byte);

  fvv_ret_t (*pack)(fvv_reserved_sei_message_t *self,
                    uint64_t                    payloadSize);
  fvv_ret_t (*copy_from)(fvv_reserved_sei_message_t *self,
                         fvv_reserved_sei_message_t *other);
};

fvv_ret_t
fvv_reserved_sei_message_init(fvv_reserved_sei_message_t *self,
                              fvv_bitstream_t            *data);
fvv_ret_t
fvv_reserved_sei_message_destroy(fvv_reserved_sei_message_t *self);
fvv_ret_t
fvv_reserved_sei_message_pack(fvv_reserved_sei_message_t *self,
                              uint64_t payloadSize);
fvv_ret_t
fvv_reserved_sei_message_copy_from(fvv_reserved_sei_message_t *self,
                                   fvv_reserved_sei_message_t *other);

FVV_DECLARE_1D_ARR_SETTER(fvv_reserved_sei_message_t,
                          reserved_sei_message_payload_byte);

#endif // FVV_SYNTAX_RESERVED_SEI_MESSAGE_H