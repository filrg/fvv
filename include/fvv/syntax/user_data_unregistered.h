#ifndef FVV_SYNTAX_USER_DATA_UNREGISTERED_H
#define FVV_SYNTAX_USER_DATA_UNREGISTERED_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.4 User data unregistered SEI message syntax
struct fvv_user_data_unregistered_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_user_data_unregistered_t,
                                       uuid_iso_iec_11578,
                                       2);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_user_data_unregistered_t,
                                user_data_payload_byte);

  fvv_ret_t (*pack)(fvv_user_data_unregistered_t *self,
                    uint64_t                      payloadSize);
  fvv_ret_t (*copy_from)(fvv_user_data_unregistered_t *self,
                         fvv_user_data_unregistered_t *other);
};

fvv_ret_t
fvv_user_data_unregistered_init(fvv_user_data_unregistered_t *self,
                                fvv_bitstream_t              *data);
fvv_ret_t fvv_user_data_unregistered_destroy(
    fvv_user_data_unregistered_t *self);
fvv_ret_t
fvv_user_data_unregistered_pack(fvv_user_data_unregistered_t *self,
                                uint64_t payloadSize);
fvv_ret_t fvv_user_data_unregistered_copy_from(
    fvv_user_data_unregistered_t *self,
    fvv_user_data_unregistered_t *other);

FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_user_data_unregistered_t,
                                 uuid_iso_iec_11578,
                                 2);
FVV_DECLARE_1D_ARR_SETTER(fvv_user_data_unregistered_t,
                          user_data_payload_byte);

#endif // FVV_SYNTAX_USER_DATA_UNREGISTERED_H