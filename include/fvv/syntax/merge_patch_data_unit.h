#ifndef FVV_SYNTAX_MERGE_PATCH_DATA_UNIT_H
#define FVV_SYNTAX_MERGE_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.5 Merge patch data unit syntax

struct fvv_merge_patch_data_unit_t
{
  uint64_t      **mpdu_ref_index;               // ue(v)
  uint64_t      **mpdu_override_2d_params_flag; // u(1)
  uint64_t      **mpdu_2d_pos_x;                // se(v)
  uint64_t      **mpdu_2d_pos_y;                // se(v)
  uint64_t      **mpdu_2d_delta_size_x;         // se(v)
  uint64_t      **mpdu_2d_delta_size_y;         // se(v)
  uint64_t      **mpdu_override_3d_params_flag; // u(1)
  uint64_t      **mpdu_3d_offset_u;             //  se(v)
  uint64_t      **mpdu_3d_offset_v;             // se(v)
  uint64_t      **mpdu_3d_offset_d;             // se(v)
  uint64_t      **mpdu_3d_range_d;              // se(v)
  uint64_t      **mpdu_override_plr_flag;       // u(1)
  fvv_plr_data_t *pd;

  uint64_t        mpdu_ref_index_size[2];
  uint64_t        mpdu_override_2d_params_flag_size[2];
  uint64_t        mpdu_2d_pos_x_size[2];
  uint64_t        mpdu_2d_pos_y_size[2];
  uint64_t        mpdu_2d_delta_size_x_size[2];
  uint64_t        mpdu_2d_delta_size_y_size[2];
  uint64_t        mpdu_override_3d_params_flag_size[2];
  uint64_t        mpdu_3d_offset_u_size[2];
  uint64_t        mpdu_3d_offset_v_size[2];
  uint64_t        mpdu_3d_offset_d_size[2];
  uint64_t        mpdu_3d_range_d_size[2];
  uint64_t        mpdu_override_plr_flag_size[2];

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_merge_patch_data_unit_t *self,
                    uint64_t                     tileID,
                    uint64_t                     patchIdx);
  fvv_ret_t (*copy_from)(fvv_merge_patch_data_unit_t *self,
                         fvv_merge_patch_data_unit_t *other);

  fvv_ret_t (*set_mpdu_ref_index)(fvv_merge_patch_data_unit_t *self,
                                  uint64_t mpdu_ref_index,
                                  uint64_t mpdu_ref_index_size[2]);
  fvv_ret_t (*set_mpdu_override_2d_params_flag)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_override_2d_params_flag,
      uint64_t mpdu_override_2d_params_flag_size[2]);
  fvv_ret_t (*set_mpdu_2d_pos_x)(fvv_merge_patch_data_unit_t *self,
                                 uint64_t mpdu_2d_pos_x,
                                 uint64_t mpdu_2d_pos_x_size[2]);
  fvv_ret_t (*set_mpdu_2d_pos_y)(fvv_merge_patch_data_unit_t *self,
                                 uint64_t mpdu_2d_pos_y,
                                 uint64_t mpdu_2d_pos_y_size[2]);
  fvv_ret_t (*set_mpdu_2d_delta_size_x)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_2d_delta_size_x,
      uint64_t                     mpdu_2d_delta_size_x_size[2]);
  fvv_ret_t (*set_mpdu_2d_delta_size_y)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_2d_delta_size_y,
      uint64_t                     mpdu_2d_delta_size_y_size[2]);
  fvv_ret_t (*set_mpdu_override_3d_params_flag)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_override_3d_params_flag,
      uint64_t mpdu_override_3d_params_flag_size[2]);
  fvv_ret_t (*set_mpdu_3d_offset_u)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_3d_offset_u,
      uint64_t                     mpdu_3d_offset_u_size[2]);
  fvv_ret_t (*set_mpdu_3d_offset_v)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_3d_offset_v,
      uint64_t                     mpdu_3d_offset_v_size[2]);
  fvv_ret_t (*set_mpdu_3d_offset_d)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_3d_offset_d,
      uint64_t                     mpdu_3d_offset_d_size[2]);
  fvv_ret_t (*set_mpdu_3d_range_d)(fvv_merge_patch_data_unit_t *self,
                                   uint64_t mpdu_3d_range_d,
                                   uint64_t mpdu_3d_range_d_size[2]);
  fvv_ret_t (*set_mpdu_override_plr_flag)(
      fvv_merge_patch_data_unit_t *self,
      uint64_t                     mpdu_override_plr_flag,
      uint64_t                     mpdu_override_plr_flag_size[2]);
  fvv_ret_t (*set_pd)(fvv_merge_patch_data_unit_t *self,
                      fvv_plr_data_t              *pd);
};

fvv_ret_t
fvv_merge_patch_data_unit_init(fvv_merge_patch_data_unit_t *self,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_merge_patch_data_unit_destroy(fvv_merge_patch_data_unit_t *self);
fvv_ret_t
fvv_merge_patch_data_unit_pack(fvv_merge_patch_data_unit_t *self,
                               uint64_t                     tileID,
                               uint64_t patchIdx);
fvv_ret_t fvv_merge_patch_data_unit_copy_from(
    fvv_merge_patch_data_unit_t *self,
    fvv_merge_patch_data_unit_t *other);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_ref_index(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_ref_index,
    uint64_t                     mpdu_ref_index_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_override_2d_params_flag(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_override_2d_params_flag,
    uint64_t mpdu_override_2d_params_flag_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_pos_x(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_2d_pos_x,
    uint64_t                     mpdu_2d_pos_x_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_pos_y(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_2d_pos_y,
    uint64_t                     mpdu_2d_pos_y_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_delta_size_x(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_2d_delta_size_x,
    uint64_t                     mpdu_2d_delta_size_x_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_2d_delta_size_y(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_2d_delta_size_y,
    uint64_t                     mpdu_2d_delta_size_y_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_override_3d_params_flag(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_override_3d_params_flag,
    uint64_t mpdu_override_3d_params_flag_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_offset_u(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_3d_offset_u,
    uint64_t                     mpdu_3d_offset_u_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_offset_v(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_3d_offset_v,
    uint64_t                     mpdu_3d_offset_v_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_offset_d(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_3d_offset_d,
    uint64_t                     mpdu_3d_offset_d_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_3d_range_d(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_3d_range_d,
    uint64_t                     mpdu_3d_range_d_size[2]);
fvv_ret_t fvv_merge_patch_data_unit_set_mpdu_override_plr_flag(
    fvv_merge_patch_data_unit_t *self,
    uint64_t                     mpdu_override_plr_flag,
    uint64_t                     mpdu_override_plr_flag_size[2]);
fvv_ret_t
fvv_merge_patch_data_unit_set_pd(fvv_merge_patch_data_unit_t *self,
                                 fvv_plr_data_t              *pd);

#endif // FVV_SYNTAX_MERGE_PATCH_DATA_UNIT_H
