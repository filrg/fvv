#include <fvv/bitstream.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
#include <fvv/syntax/sei_message.h>
#include <fvv/syntax/sei_rbsp.h>

// 8.3.6.4 Supplemental enhancement information RBSP syntax
// {
fvv_ret_t fvv_sei_rbsp_init(fvv_sei_rbsp_t        *self,
                            fvv_nal_unit_header_t *nuh,
                            fvv_bitstream_t       *data)
{
  *self           = (fvv_sei_rbsp_t){0};
  self->nuh       = nuh;
  self->data      = data;

  self->pack      = fvv_sei_rbsp_pack;
  self->copy_from = fvv_sei_rbsp_copy_from;

  FVV_SET_SETTER_PTR(fvv_sei_rbsp_t, sm, fvv_sei_message_t);
  FVV_SET_SETTER_PTR(fvv_sei_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

  self->sm  = (fvv_sei_message_t *)malloc(sizeof(fvv_sei_message_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_sei_message_init(self->sm, self->nuh, data);
  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sei_rbsp_destroy(fvv_sei_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_sei_rbsp_t, sm, fvv_sei_message_t);
  FVV_DESTROY_OBJ(fvv_sei_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sei_rbsp_pack(fvv_sei_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bool_t       more_rbsp_data = 0;
  fvv_bitstream_t *buff           = FVV_NULL;
  buff                            = self->data;

  do
  {
    self->sm->pack(self->sm);
    buff->more_rbsp_data(buff, &more_rbsp_data);
  } while (more_rbsp_data);
  self->rtb->pack(self->rtb);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_sei_rbsp_copy_from(fvv_sei_rbsp_t *self,
                                 fvv_sei_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->sm->copy_from(self->sm, other->sm);
  self->rtb->copy_from(self->rtb, other->rtb);
  return FVV_RET_SUCCESS;
}

FVV_DEFINE_OBJ_SETTER(fvv_sei_rbsp_t, sm, fvv_sei_message_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

// }
