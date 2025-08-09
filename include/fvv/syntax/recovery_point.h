#ifndef FVV_SYNTAX_RECOVERY_POINT_H
#define FVV_SYNTAX_RECOVERY_POINT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.5 Recovery point SEI message syntax
struct fvv_recovery_point_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_recovery_point_t,
                                recovery_afoc_cnt);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_recovery_point_t,
                                exact_match_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_recovery_point_t,
                                broken_link_flag);

  fvv_ret_t (*pack)(fvv_recovery_point_t *self, uint64_t payloadSize);
  fvv_ret_t (*copy_from)(fvv_recovery_point_t *self,
                         fvv_recovery_point_t *other);
};

fvv_ret_t fvv_recovery_point_init(fvv_recovery_point_t *self,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_recovery_point_destroy(fvv_recovery_point_t *self);
fvv_ret_t fvv_recovery_point_pack(fvv_recovery_point_t *self,
                                  uint64_t              payloadSize);
fvv_ret_t fvv_recovery_point_copy_from(fvv_recovery_point_t *self,
                                       fvv_recovery_point_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_recovery_point_t, recovery_afoc_cnt);
FVV_DECLARE_SCALAR_SETTER(fvv_recovery_point_t, exact_match_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_recovery_point_t, broken_link_flag);

#endif // FVV_SYNTAX_RECOVERY_POINT_H