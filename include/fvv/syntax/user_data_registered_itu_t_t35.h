#ifndef FVV_SYNTAX_USER_DATA_REGISTERED_ITU_T_T35_H
#define FVV_SYNTAX_USER_DATA_REGISTERED_ITU_T_T35_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.3 User data registered by Recommendation ITU-T T.35 SEI message
// syntax
struct fvv_user_data_registered_itu_t_t35_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_user_data_registered_itu_t_t35_t,
                                itu_t_t35_country_code);
  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_user_data_registered_itu_t_t35_t,
      itu_t_t35_country_code_extension_byte);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_user_data_registered_itu_t_t35_t,
                                itu_t_t35_payload_byte);

  fvv_ret_t (*pack)(fvv_user_data_registered_itu_t_t35_t *self,
                    uint64_t payloadSize);
  fvv_ret_t (*copy_from)(fvv_user_data_registered_itu_t_t35_t *self,
                         fvv_user_data_registered_itu_t_t35_t *other);
};

fvv_ret_t fvv_user_data_registered_itu_t_t35_init(
    fvv_user_data_registered_itu_t_t35_t *self,
    fvv_bitstream_t                      *data);
fvv_ret_t fvv_user_data_registered_itu_t_t35_destroy(
    fvv_user_data_registered_itu_t_t35_t *self);
fvv_ret_t fvv_user_data_registered_itu_t_t35_pack(
    fvv_user_data_registered_itu_t_t35_t *self, uint64_t payloadSize);
fvv_ret_t fvv_user_data_registered_itu_t_t35_copy_from(
    fvv_user_data_registered_itu_t_t35_t *self,
    fvv_user_data_registered_itu_t_t35_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_user_data_registered_itu_t_t35_t,
                          itu_t_t35_country_code);
FVV_DECLARE_SCALAR_SETTER(fvv_user_data_registered_itu_t_t35_t,
                          itu_t_t35_country_code_extension_byte);
FVV_DECLARE_1D_ARR_SETTER(fvv_user_data_registered_itu_t_t35_t,
                          itu_t_t35_payload_byte);

#endif // FVV_SYNTAX_USER_DATA_REGISTERED_ITU_T_T35_H