#ifndef FVV_PATCH_DATA_UNIT_H
#define FVV_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>
// 8.3.7.3 Patch data unit syntax

struct fvv_patch_data_unit_t
{

  fvv_atlas_sequence_parameter_set_rbsp_t *asps;
  fvv_atlas_frame_parameter_set_rbsp_t    *afps;
  fvv_atlas_tile_header_t                 *ath;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_patch_data_unit_t *self,
                    uint64_t               tileID,
                    uint64_t               patchIdx);
  fvv_ret_t (*copy_from)(fvv_patch_data_unit_t *self,
                         fvv_patch_data_unit_t *other);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t, pdu_2d_pos_x);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t, pdu_2d_pos_y);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_2d_size_x_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_2d_size_y_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_3d_offset_u);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_3d_offset_v);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_3d_offset_d);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_3d_range_d);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_projection_id);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_orientation_index);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_lod_enabled_flag);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_lod_scale_x_minus1);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_patch_data_unit_t,
                                pdu_lod_scale_y_idc);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_data_unit_t,
                             pd,
                             fvv_plr_data_t);
};
fvv_ret_t fvv_patch_data_unit_init(
    fvv_patch_data_unit_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_atlas_frame_parameter_set_rbsp_t    *afps,
    fvv_atlas_tile_header_t                 *ath,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_patch_data_unit_destroy(fvv_patch_data_unit_t *self);
fvv_ret_t fvv_patch_data_unit_pack(fvv_patch_data_unit_t *self,
                                   uint64_t               tileID,
                                   uint64_t               patchIdx);
fvv_ret_t fvv_patch_data_unit_copy_from(fvv_patch_data_unit_t *self,
                                        fvv_patch_data_unit_t *other);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_2d_pos_x);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_2d_pos_y);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t,
                          pdu_2d_size_x_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t,
                          pdu_2d_size_y_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_offset_u);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_offset_v);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_offset_d);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_3d_range_d);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_projection_id);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t,
                          pdu_orientation_index);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t,
                          pdu_lod_enabled_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t,
                          pdu_lod_scale_x_minus1);
FVV_DECLARE_2D_ARR_SETTER(fvv_patch_data_unit_t, pdu_lod_scale_y_idc);
FVV_DECLARE_OBJ_SETTER(fvv_patch_data_unit_t, pd, fvv_plr_data_t);

#endif // FVV_PATCH_DATA_UNIT_H