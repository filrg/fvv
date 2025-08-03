#ifndef FVV_PATCH_DATA_UNIT_H
#define FVV_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>
// 8.3.7.3 Patch data unit syntax

struct fvv_patch_data_unit_t
{
  uint64_t      **pdu_2d_pos_x;           // ue(v)
  uint64_t      **pdu_2d_pos_y;           // ue(v)
  uint64_t      **pdu_2d_size_x_minus1;   // ue(v)
  uint64_t      **pdu_2d_size_y_minus1;   // ue(v)
  uint64_t      **pdu_3d_offset_u;        // u(v)
  uint64_t      **pdu_3d_offset_v;        // u(v)
  uint64_t      **pdu_3d_offset_d;        // u(v)
  uint64_t      **pdu_3d_range_d;         // u(v)
  uint64_t      **pdu_projection_id;      // u(v)
  uint64_t      **pdu_orientation_index;  // u(v)
  uint64_t      **pdu_lod_enabled_flag;   // u(1)
  uint64_t      **pdu_lod_scale_x_minus1; // ue(v)
  uint64_t      **pdu_lod_scale_y_idc;    // ue(v)
  fvv_plr_data_t *pd;

  uint64_t        pdu_2d_pos_x_size[2];
  uint64_t        pdu_2d_pos_y_size[2];
  uint64_t        pdu_2d_size_x_minus1_size[2];
  uint64_t        pdu_2d_size_y_minus1_size[2];
  uint64_t        pdu_3d_offset_u_size[2];
  uint64_t        pdu_3d_offset_v_size[2];
  uint64_t        pdu_3d_offset_d_size[2];
  uint64_t        pdu_3d_range_d_size[2];
  uint64_t        pdu_projection_id_size[2];
  uint64_t        pdu_orientation_index_size[2];
  uint64_t        pdu_lod_enabled_flag_size[2];
  uint64_t        pdu_lod_scale_x_minus1_size[2];
  uint64_t        pdu_lod_scale_y_idc_size[2];

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_atlas_frame_parameter_set_rbsp_t    *afpsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_patch_data_unit_t *self,
                    uint64_t               tileID,
                    uint64_t               patchIdx,
                    uint64_t               patchMode);
  fvv_ret_t (*copy_from)(fvv_patch_data_unit_t *self,
                         fvv_patch_data_unit_t *other);
  fvv_ret_t (*set_pd)(fvv_patch_data_unit_t *self,
                      fvv_plr_data_t        *pd);
  fvv_ret_t (*set_pdu_2d_pos_x)(fvv_patch_data_unit_t *self,
                                uint64_t             **pdu_2d_pos_x,
                                uint64_t pdu_2d_pos_x_size[2]);
  fvv_ret_t (*set_pdu_2d_pos_y)(fvv_patch_data_unit_t *self,
                                uint64_t             **pdu_2d_pos_y,
                                uint64_t pdu_2d_pos_y_size[2]);
  fvv_ret_t (*set_pdu_2d_size_x_minus1)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_2d_size_x_minus1,
      uint64_t               pdu_2d_size_x_minus1_size[2]);
  fvv_ret_t (*set_pdu_2d_size_y_minus1)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_2d_size_y_minus1,
      uint64_t               pdu_2d_size_y_minus1_size[2]);
  fvv_ret_t (*set_pdu_3d_offset_u)(fvv_patch_data_unit_t *self,
                                   uint64_t **pdu_3d_offset_u,
                                   uint64_t pdu_3d_offset_u_size[2]);
  fvv_ret_t (*set_pdu_3d_offset_v)(fvv_patch_data_unit_t *self,
                                   uint64_t **pdu_3d_offset_v,
                                   uint64_t pdu_3d_offset_v_size[2]);
  fvv_ret_t (*set_pdu_3d_offset_d)(fvv_patch_data_unit_t *self,
                                   uint64_t **pdu_3d_offset_d,
                                   uint64_t pdu_3d_offset_d_size[2]);
  fvv_ret_t (*set_pdu_3d_range_d)(fvv_patch_data_unit_t *self,
                                  uint64_t **pdu_3d_range_d,
                                  uint64_t   pdu_3d_range_d_size[2]);
  fvv_ret_t (*set_pdu_projection_id)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_projection_id,
      uint64_t               pdu_projection_id_size[2]);
  fvv_ret_t (*set_pdu_orientation_index)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_orientation_index,
      uint64_t               pdu_orientation_index_size[2]);
  fvv_ret_t (*set_pdu_lod_enabled_flag)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_lod_enabled_flag,
      uint64_t               pdu_lod_enabled_flag_size[2]);
  fvv_ret_t (*set_pdu_lod_scale_x_minus1)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_lod_scale_x_minus1,
      uint64_t               pdu_lod_scale_x_minus1_size[2]);
  fvv_ret_t (*set_pdu_lod_scale_y_idc)(
      fvv_patch_data_unit_t *self,
      uint64_t             **pdu_lod_scale_y_idc,
      uint64_t               pdu_lod_scale_y_idc_size[2]);
};
fvv_ret_t fvv_patch_data_unit_init(
    fvv_patch_data_unit_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_atlas_frame_parameter_set_rbsp_t    *afpsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_patch_data_unit_destroy(fvv_patch_data_unit_t *self);
fvv_ret_t fvv_patch_data_unit_pack(fvv_patch_data_unit_t *self,
                                   uint64_t               tileID,
                                   uint64_t               patchIdx);
fvv_ret_t
          fvv_patch_data_unit_copy_from(fvv_patch_data_unit_t *self,
                                        fvv_patch_data_unit_t *other);
fvv_ret_t fvv_patch_data_unit_set_pd(fvv_patch_data_unit_t *self,
                                     fvv_plr_data_t        *pd);
fvv_ret_t
fvv_patch_data_unit_set_pdu_2d_pos_x(fvv_patch_data_unit_t *self,
                                     uint64_t **pdu_2d_pos_x,
                                     uint64_t pdu_2d_pos_x_size[2]);
fvv_ret_t
fvv_patch_data_unit_set_pdu_2d_pos_y(fvv_patch_data_unit_t *self,
                                     uint64_t **pdu_2d_pos_y,
                                     uint64_t pdu_2d_pos_y_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_2d_size_x_minus1(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_2d_size_x_minus1,
    uint64_t               pdu_2d_size_x_minus1_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_2d_size_y_minus1(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_2d_size_y_minus1,
    uint64_t               pdu_2d_size_y_minus1_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_offset_u(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_offset_u,
    uint64_t               pdu_3d_offset_u_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_offset_v(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_offset_v,
    uint64_t               pdu_3d_offset_v_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_offset_d(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_offset_d,
    uint64_t               pdu_3d_offset_d_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_3d_range_d(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_3d_range_d,
    uint64_t               pdu_3d_range_d_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_projection_id(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_projection_id,
    uint64_t               pdu_projection_id_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_orientation_index(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_orientation_index,
    uint64_t               pdu_orientation_index_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_lod_enabled_flag(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_lod_enabled_flag,
    uint64_t               pdu_lod_enabled_flag_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_lod_scale_x_minus1(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_lod_scale_x_minus1,
    uint64_t               pdu_lod_scale_x_minus1_size[2]);
fvv_ret_t fvv_patch_data_unit_set_pdu_lod_scale_y_idc(
    fvv_patch_data_unit_t *self,
    uint64_t             **pdu_lod_scale_y_idc,
    uint64_t               pdu_lod_scale_y_idc_size[2]);

#endif // FVV_PATCH_DATA_UNIT_H