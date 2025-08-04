#ifndef FVV_SYNTAX_ATLAS_TILE_HEADER_H
#define FVV_SYNTAX_ATLAS_TILE_HEADER_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.11 Atlas tile header syntax
struct fvv_atlas_tile_header_t
{
  uint64_t                                 ath_no_output_of_prior_atlas_frames_flag; // u(1)
  uint64_t                                 ath_atlas_frame_parameter_set_id;         // ue(v)
  uint64_t                                 ath_atlas_adaptation_parameter_set_id;    // ue(v)
  uint64_t                                 ath_id;                                   // u(v)
  uint64_t                                 ath_type;                                 // ue(v)
  uint64_t                                 ath_atlas_output_flag;                    // u(1)
  uint64_t                                 ath_atlas_frm_order_cnt_lsb;              // u(v)
  uint64_t                                 ath_ref_atlas_frame_list_asps_flag;       // u(1)
  uint64_t                                 ath_ref_atlas_frame_list_idx;             // u(v)
  uint64_t                                 ath_pos_min_d_quantizer;                  // u(5)
  uint64_t                                 ath_pos_delta_max_d_quantizer;            // u(5)
  uint64_t                                 ath_patch_size_x_info_quantizer;          // u(3)
  uint64_t                                 ath_patch_size_y_info_quantizer;          // u(3)
  uint64_t                                 ath_raw_3d_offset_axis_bit_count_minus1;  // u(v)
  uint64_t                                 ath_num_ref_idx_active_override_flag;     // u(1)
  uint64_t                                 ath_num_ref_idx_active_minus1;            // ue(v)

  uint64_t                                *ath_additional_afoc_lsb_present_flag; // u(1)
  uint64_t                                *ath_additional_afoc_lsb_val;          // u(v)

  fvv_ref_list_struct_t                   *rls;
  fvv_byte_alignment_t                    *ba;

  uint64_t                                 ath_additional_afoc_lsb_present_flag_size;
  uint64_t                                 ath_additional_afoc_lsb_val_size;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_atlas_frame_parameter_set_rbsp_t    *afpsr;
  fvv_nal_unit_header_t                   *nuh;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_tile_header_t *self);
  fvv_ret_t (*copy_from)(fvv_atlas_tile_header_t *self,
                         fvv_atlas_tile_header_t *other);

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_no_output_of_prior_atlas_frames_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_atlas_frame_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_atlas_adaptation_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_type);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_atlas_output_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_atlas_frm_order_cnt_lsb);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_ref_atlas_frame_list_asps_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_ref_atlas_frame_list_idx);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_pos_min_d_quantizer);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_pos_delta_max_d_quantizer);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_patch_size_x_info_quantizer);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_patch_size_y_info_quantizer);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_raw_3d_offset_axis_bit_count_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_num_ref_idx_active_override_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_tile_header_t, ath_num_ref_idx_active_minus1);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_atlas_tile_header_t, ath_additional_afoc_lsb_present_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_atlas_tile_header_t, ath_additional_afoc_lsb_val);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_header_t, rls, fvv_ref_list_struct_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_tile_header_t, ba, fvv_byte_alignment_t);
};

fvv_ret_t fvv_atlas_tile_header_init(
    fvv_atlas_tile_header_t                 *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_atlas_frame_parameter_set_rbsp_t    *afpsr,
    fvv_nal_unit_header_t                   *nuh,
    fvv_bitstream_t                         *data);
fvv_ret_t
          fvv_atlas_tile_header_destroy(fvv_atlas_tile_header_t *self);
fvv_ret_t fvv_atlas_tile_header_pack(fvv_atlas_tile_header_t *self);
fvv_ret_t
fvv_atlas_tile_header_copy_from(fvv_atlas_tile_header_t *self,
                                fvv_atlas_tile_header_t *other);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_no_output_of_prior_atlas_frames_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_atlas_frame_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_atlas_adaptation_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_id);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_type);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_atlas_output_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_atlas_frm_order_cnt_lsb);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_ref_atlas_frame_list_asps_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_ref_atlas_frame_list_idx);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_pos_min_d_quantizer);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_pos_delta_max_d_quantizer);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_patch_size_x_info_quantizer);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_patch_size_y_info_quantizer);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_raw_3d_offset_axis_bit_count_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_num_ref_idx_active_override_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_tile_header_t, ath_num_ref_idx_active_minus1);
FVV_DECLARE_1D_ARR_SETTER(fvv_atlas_tile_header_t, ath_additional_afoc_lsb_present_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_atlas_tile_header_t, ath_additional_afoc_lsb_val);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_header_t, rls, fvv_ref_list_struct_t);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_tile_header_t, ba, fvv_byte_alignment_t);
#endif // FVV_SYNTAX_ATLAS_TILE_HEADER_H
