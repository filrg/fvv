#include <fvv/bitstream.h>
#include <fvv/syntax/recovery_point.h>

// F.2.5 Recovery point SEI message syntax
fvv_ret_t fvv_recovery_point_init(fvv_recovery_point_t *self,
                                  fvv_bitstream_t      *data)
{
  *self      = (fvv_recovery_point_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_recovery_point_t, recovery_afoc_cnt);
  FVV_SET_SETTER_PTR(fvv_recovery_point_t, exact_match_flag);
  FVV_SET_SETTER_PTR(fvv_recovery_point_t, broken_link_flag);

  self->pack      = fvv_recovery_point_pack;
  self->copy_from = fvv_recovery_point_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_recovery_point_destroy(fvv_recovery_point_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_recovery_point_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_recovery_point_pack(fvv_recovery_point_t *self,
                                  uint64_t              payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->recovery_afoc_cnt,
                   FVV_BIT_RECOVERY_AFOC_CNT,
                   FVV_DESCRIPTOR_RECOVERY_AFOC_CNT);
  buff->write_bits(buff,
                   self->exact_match_flag,
                   FVV_BIT_EXACT_MATCH_FLAG,
                   FVV_DESCRIPTOR_EXACT_MATCH_FLAG);
  buff->write_bits(buff,
                   self->broken_link_flag,
                   FVV_BIT_BROKEN_LINK_FLAG,
                   FVV_DESCRIPTOR_BROKEN_LINK_FLAG);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_recovery_point_copy_from(fvv_recovery_point_t *self,
                                       fvv_recovery_point_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_recovery_afoc_cnt(self, other->recovery_afoc_cnt);
  self->set_exact_match_flag(self, other->exact_match_flag);
  self->set_broken_link_flag(self, other->broken_link_flag);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_recovery_point_t, recovery_afoc_cnt);
FVV_DEFINE_SCALAR_SETTER(fvv_recovery_point_t, exact_match_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_recovery_point_t, broken_link_flag);