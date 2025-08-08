#ifndef FVV_SYNTAX_EOM_PATCH_DATA_UNIT_H
#define FVV_SYNTAX_EOM_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.8 EOM patch data unit syntax
struct fvv_eom_patch_data_unit_t
{
  fvv_bitstream_t                      *data;
  fvv_atlas_frame_parameter_set_rbsp_t *afps;

  fvv_ret_t (*pack)(fvv_eom_patch_data_unit_t *self,
                    uint64_t                   tileID,
                    uint64_t                   patchIdx);
  fvv_ret_t (*copy_from)(fvv_eom_patch_data_unit_t *self,
                         fvv_eom_patch_data_unit_t *other);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_patch_in_auxiliary_video_flag);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_2d_pos_x);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_2d_pos_y);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_2d_size_x_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_2d_size_y_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_patch_count_minus1);
  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_associated_patch_idx);
  FVV_DECLARE_3D_ARR_SETTER_PTR(fvv_eom_patch_data_unit_t,
                                epdu_points);
};

fvv_ret_t fvv_eom_patch_data_unit_init(
    fvv_eom_patch_data_unit_t            *self,
    fvv_atlas_frame_parameter_set_rbsp_t *afps,
    fvv_bitstream_t                      *data);
fvv_ret_t
fvv_eom_patch_data_unit_destroy(fvv_eom_patch_data_unit_t *self);
fvv_ret_t
fvv_eom_patch_data_unit_pack(fvv_eom_patch_data_unit_t *self,
                             uint64_t                   tileID,
                             uint64_t                   patchIdx);
fvv_ret_t
fvv_eom_patch_data_unit_copy_from(fvv_eom_patch_data_unit_t *self,
                                  fvv_eom_patch_data_unit_t *other);
FVV_DECLARE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                          epdu_patch_in_auxiliary_video_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t, epdu_2d_pos_x);
FVV_DECLARE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t, epdu_2d_pos_y);
FVV_DECLARE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                          epdu_2d_size_x_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                          epdu_2d_size_y_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                          epdu_patch_count_minus1);
FVV_DECLARE_3D_ARR_SETTER(fvv_eom_patch_data_unit_t,
                          epdu_associated_patch_idx);
FVV_DECLARE_3D_ARR_SETTER(fvv_eom_patch_data_unit_t, epdu_points);

#endif // FVV_SYNTAX_EOM_PATCH_DATA_UNIT_H
