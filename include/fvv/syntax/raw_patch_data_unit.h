#ifndef FVV_SYNTAX_RAW_PATCH_DATA_UNIT_H
#define FVV_SYNTAX_RAW_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.7 Raw patch data unit syntax
struct fvv_raw_patch_data_unit_t
{
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_raw_patch_data_unit_t *self, uint64_t tileID, uint64_t patchIdx);
  fvv_ret_t (*copy_from)(fvv_raw_patch_data_unit_t *self, fvv_raw_patch_data_unit_t *other);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_patch_in_auxiliary_video_flag);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_2d_pos_x);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_2d_pos_y);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_2d_size_x_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_2d_size_y_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_u);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_v);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_3d_offset_d);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_raw_patch_data_unit_t, rpdu_points_minus1);
};

fvv_ret_t fvv_raw_patch_data_unit_init(fvv_raw_patch_data_unit_t *self, fvv_bitstream_t *data);
fvv_ret_t fvv_raw_patch_data_unit_destroy(fvv_raw_patch_data_unit_t *self);
fvv_ret_t fvv_raw_patch_data_unit_pack(fvv_raw_patch_data_unit_t *self, uint64_t tileID, uint64_t patchIdx);
fvv_ret_t fvv_raw_patch_data_unit_copy_from(fvv_raw_patch_data_unit_t *self, fvv_raw_patch_data_unit_t *other);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_patch_in_auxiliary_video_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_2d_pos_x);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_2d_pos_y);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_2d_size_x_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_2d_size_y_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_3d_offset_u);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_3d_offset_v);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_3d_offset_d);
FVV_DECLARE_2D_ARR_SETTER(fvv_raw_patch_data_unit_t, rpdu_points_minus1);

#endif // FVV_SYNTAX_RAW_PATCH_DATA_UNIT_H
