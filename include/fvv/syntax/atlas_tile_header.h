#ifndef FVV_SYNTAX_ATLAS_TILE_HEADER_H
#define FVV_SYNTAX_ATLAS_TILE_HEADER_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.11 Atlas tile header syntax
struct fvv_atlas_tile_header_t
{
  uint64_t  ath_no_output_of_prior_atlas_frames_flag; // u(1)
  uint64_t  ath_atlas_frame_parameter_set_id;         // ue(v)
  uint64_t  ath_atlas_adaptation_parameter_set_id;    // ue(v)
  uint64_t  ath_id;                                   // u(v)
  uint64_t  ath_type;                                 // ue(v)
  uint64_t  ath_atlas_output_flag;                    // u(1)
  uint64_t  ath_atlas_frm_order_cnt_lsb;              // u(v)
  uint64_t  ath_ref_atlas_frame_list_asps_flag;       // u(1)
  uint64_t  ath_ref_atlas_frame_list_idx;             // u(v)
  uint64_t *ath_additional_afoc_lsb_present_flag;     // u(1)
  uint64_t *ath_additional_afoc_lsb_val;              // u(v)
  uint64_t  ath_pos_min_d_quantizer;                  // u(5)
  uint64_t  ath_pos_delta_max_d_quantizer;            // u(5)
  uint64_t  ath_patch_size_x_info_quantizer;          // u(3)
  uint64_t  ath_patch_size_y_info_quantizer;          // u(3)
  uint64_t  ath_raw_3d_offset_axis_bit_count_minus1;  // u(v)
  uint64_t  ath_num_ref_idx_active_override_flag;     // u(1)
  uint64_t  ath_num_ref_idx_active_minus1;            // ue(v)
  fvv_ref_list_struct_t *rls;
  fvv_byte_alignment_t  *ba;

  uint64_t               ath_additional_afoc_lsb_present_flag_size;
  uint64_t               ath_additional_afoc_lsb_val_size;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_tile_header_t *self);
  fvv_ret_t (*copy_from)(fvv_atlas_tile_header_t *self,
                         fvv_atlas_tile_header_t *other);
  fvv_ret_t (*set_rls)(fvv_atlas_tile_header_t *self,
                       fvv_ref_list_struct_t   *rls);
  fvv_ret_t (*set_ba)(fvv_atlas_tile_header_t *self,
                      fvv_byte_alignment_t    *ba);
  fvv_ret_t (*set_ath_no_output_of_prior_atlas_frames_flag)(
      fvv_atlas_tile_header_t *self,
      uint64_t ath_no_output_of_prior_atlas_frames_flag);
  fvv_ret_t (*set_ath_atlas_frame_parameter_set_id)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_atlas_frame_parameter_set_id);
  fvv_ret_t (*set_ath_atlas_adaptation_parameter_set_id)(
      fvv_atlas_tile_header_t *self,
      uint64_t ath_atlas_adaptation_parameter_set_id);
  fvv_ret_t (*set_ath_id)(fvv_atlas_tile_header_t *self,
                          uint64_t                 ath_id);
  fvv_ret_t (*set_ath_type)(fvv_atlas_tile_header_t *self,
                            uint64_t                 ath_type);
  fvv_ret_t (*set_ath_atlas_output_flag)(
      fvv_atlas_tile_header_t *self, uint64_t ath_atlas_output_flag);
  fvv_ret_t (*set_ath_atlas_frm_order_cnt_lsb)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_atlas_frm_order_cnt_lsb);
  fvv_ret_t (*set_ath_ref_atlas_frame_list_asps_flag)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_ref_atlas_frame_list_asps_flag);
  fvv_ret_t (*set_ath_ref_atlas_frame_list_idx)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_ref_atlas_frame_list_idx);
  fvv_ret_t (*set_ath_pos_min_d_quantizer)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_pos_min_d_quantizer);
  fvv_ret_t (*set_ath_pos_delta_max_d_quantizer)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_pos_delta_max_d_quantizer);
  fvv_ret_t (*set_ath_patch_size_x_info_quantizer)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_patch_size_x_info_quantizer);
  fvv_ret_t (*set_ath_patch_size_y_info_quantizer)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_patch_size_y_info_quantizer);
  fvv_ret_t (*set_ath_raw_3d_offset_axis_bit_count_minus1)(
      fvv_atlas_tile_header_t *self,
      uint64_t ath_raw_3d_offset_axis_bit_count_minus1);
  fvv_ret_t (*set_ath_num_ref_idx_active_override_flag)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_num_ref_idx_active_override_flag);
  fvv_ret_t (*set_ath_num_ref_idx_active_minus1)(
      fvv_atlas_tile_header_t *self,
      uint64_t                 ath_num_ref_idx_active_minus1);
  fvv_ret_t (*set_ath_additional_afoc_lsb_present_flag)(
      *self,
      uint64_t *ath_additional_afoc_lsb_present_flag,
      uint64_t  ath_additional_afoc_lsb_present_flag_size);
  fvv_ret_t (*set_ath_additional_afoc_lsb_val)(
      *self,
      uint64_t *ath_additional_afoc_lsb_val,
      uint64_t  ath_additional_afoc_lsb_val_size);
};

fvv_ret_t fvv_atlas_tile_header_init(
    fvv_atlas_tile_header_t                 *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_atlas_tile_header_destroy(fvv_atlas_tile_header_t *self);
fvv_ret_t fvv_atlas_tile_header_pack(fvv_atlas_tile_header_t *self);
fvv_ret_t
fvv_atlas_tile_header_copy_from(fvv_atlas_tile_header_t *self,
                                fvv_atlas_tile_header_t *other);
fvv_ret_t
fvv_atlas_tile_header_set_rls(fvv_atlas_tile_header_t *self,
                              fvv_ref_list_struct_t   *rls);
fvv_ret_t fvv_atlas_tile_header_set_ba(fvv_atlas_tile_header_t *self,
                                       fvv_byte_alignment_t    *ba);
fvv_ret_t
fvv_atlas_tile_header_set_ath_no_output_of_prior_atlas_frames_flag(
    fvv_atlas_tile_header_t *self,
    uint64_t ath_no_output_of_prior_atlas_frames_flag);
fvv_ret_t fvv_atlas_tile_header_set_ath_atlas_frame_parameter_set_id(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_atlas_frame_parameter_set_id);
fvv_ret_t
fvv_atlas_tile_header_set_ath_atlas_adaptation_parameter_set_id(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_atlas_adaptation_parameter_set_id);
fvv_ret_t
fvv_atlas_tile_header_set_ath_id(fvv_atlas_tile_header_t *self,
                                 uint64_t                 ath_id);
fvv_ret_t
fvv_atlas_tile_header_set_ath_type(fvv_atlas_tile_header_t *self,
                                   uint64_t ath_type);
fvv_ret_t fvv_atlas_tile_header_set_ath_atlas_output_flag(
    fvv_atlas_tile_header_t *self, uint64_t ath_atlas_output_flag);
fvv_ret_t fvv_atlas_tile_header_set_ath_atlas_frm_order_cnt_lsb(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_atlas_frm_order_cnt_lsb);
fvv_ret_t
fvv_atlas_tile_header_set_ath_ref_atlas_frame_list_asps_flag(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_ref_atlas_frame_list_asps_flag);
fvv_ret_t fvv_atlas_tile_header_set_ath_ref_atlas_frame_list_idx(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_ref_atlas_frame_list_idx);
fvv_ret_t fvv_atlas_tile_header_set_ath_pos_min_d_quantizer(
    fvv_atlas_tile_header_t *self, uint64_t ath_pos_min_d_quantizer);
fvv_ret_t fvv_atlas_tile_header_set_ath_pos_delta_max_d_quantizer(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_pos_delta_max_d_quantizer);
fvv_ret_t fvv_atlas_tile_header_set_ath_patch_size_x_info_quantizer(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_patch_size_x_info_quantizer);
fvv_ret_t fvv_atlas_tile_header_set_ath_patch_size_y_info_quantizer(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_patch_size_y_info_quantizer);
fvv_ret_t
fvv_atlas_tile_header_set_ath_raw_3d_offset_axis_bit_count_minus1(
    fvv_atlas_tile_header_t *self,
    uint64_t ath_raw_3d_offset_axis_bit_count_minus1);
fvv_ret_t
fvv_atlas_tile_header_set_ath_num_ref_idx_active_override_flag(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_num_ref_idx_active_override_flag);
fvv_ret_t fvv_atlas_tile_header_set_ath_num_ref_idx_active_minus1(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_num_ref_idx_active_minus1);
fvv_ret_t
fvv_atlas_tile_header_set_ath_additional_afoc_lsb_present_flag(
    *self,
    uint64_t *ath_additional_afoc_lsb_present_flag,
    uint64_t  ath_additional_afoc_lsb_present_flag_size);
fvv_ret_t fvv_atlas_tile_header_set_ath_additional_afoc_lsb_val(
    *self,
    uint64_t *ath_additional_afoc_lsb_val,
    uint64_t  ath_additional_afoc_lsb_val_size);

#endif // FVV_SYNTAX_ATLAS_TILE_HEADER_H
