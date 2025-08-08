#ifndef FVV_SYNTAX_PLR_DATA_H
#define FVV_SYNTAX_PLR_DATA_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.9 Point local reconstruction data syntax
struct fvv_plr_data_t
{
  fvv_bitstream_t                         *data;
  fvv_atlas_sequence_parameter_set_rbsp_t *asps;

  fvv_ret_t (*pack)(fvv_plr_data_t *self,
                    uint64_t        tileID,
                    uint64_t        patchIdx);
  fvv_ret_t (*copy_from)(fvv_plr_data_t *self, fvv_plr_data_t *other);

  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_plr_data_t, plrd_level);
  FVV_DECLARE_4D_ARR_SETTER_PTR(fvv_plr_data_t,
                                plrd_present_block_flag);
  FVV_DECLARE_4D_ARR_SETTER_PTR(fvv_plr_data_t,
                                plrd_block_mode_minus1);
  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_plr_data_t, plrd_present_flag);
  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_plr_data_t, plrd_mode_minus1);
};

fvv_ret_t
          fvv_plr_data_init(fvv_plr_data_t                          *self,
                            fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                            fvv_bitstream_t                         *data);
fvv_ret_t fvv_plr_data_destroy(fvv_plr_data_t *self);
fvv_ret_t fvv_plr_data_pack(fvv_plr_data_t *self,
                            uint64_t        tileID,
                            uint64_t        patchIdx);
fvv_ret_t fvv_plr_data_copy_from(fvv_plr_data_t *self,
                                 fvv_plr_data_t *other);

FVV_DECLARE_3D_ARR_SETTER(fvv_plr_data_t, plrd_level);
FVV_DECLARE_4D_ARR_SETTER(fvv_plr_data_t, plrd_present_block_flag);
FVV_DECLARE_4D_ARR_SETTER(fvv_plr_data_t, plrd_block_mode_minus1);
FVV_DECLARE_3D_ARR_SETTER(fvv_plr_data_t, plrd_present_flag);
FVV_DECLARE_3D_ARR_SETTER(fvv_plr_data_t, plrd_mode_minus1);

#endif // FVV_SYNTAX_PLR_DATA_H
