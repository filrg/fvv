#ifndef FVV_SYNTAX_SEI_MESSAGE_H
#define FVV_SYNTAX_SEI_MESSAGE_H

#include <fvv/semantic.h>
#include <fvv/defs.h>

// 8.3.8 SEI message syntax
struct fvv_sei_message_t
{
  fvv_bitstream_t   *data;

  fvv_ret_t (*pack)(fvv_sei_message_t *self);
  fvv_ret_t (*copy_from)(fvv_sei_message_t *self, fvv_sei_message_t *other);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_message_t, sm_payload_type_byte);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_message_t, sm_payload_size_byte);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_message_t, sp, fvv_sei_payload_t);
};

fvv_ret_t fvv_sei_message_init(fvv_sei_message_t *self, fvv_bitstream_t *data);
fvv_ret_t fvv_sei_message_destroy(fvv_sei_message_t *self);
fvv_ret_t fvv_sei_message_pack(fvv_sei_message_t *self);
fvv_ret_t fvv_sei_message_copy_from(fvv_sei_message_t *self, fvv_sei_message_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_sei_message_t, sm_payload_type_byte);
FVV_DECLARE_SCALAR_SETTER(fvv_sei_message_t, sm_payload_size_byte);
FVV_DECLARE_OBJ_SETTER(fvv_sei_message_t, sp, fvv_sei_payload_t);

#endif // FVV_SYNTAX_SEI_MESSAGE_H
