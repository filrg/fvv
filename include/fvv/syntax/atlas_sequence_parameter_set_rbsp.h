#ifndef FVV_SYNTAX_ATLAS_SEQUENCE_PARAMETER_SET_RBSP_H
#define FVV_SYNTAX_ATLAS_SEQUENCE_PARAMETER_SET_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.1.1 General atlas sequence parameter set RBSP syntax
struct fvv_atlas_sequence_parameter_set_rbsp_t
{
  uint64_t asps_atlas_sequence_parameter_set_id;
  uint64_t asps_frame_width;
  uint64_t asps_frame_height;
  uint64_t asps_geometry_3d_bit_depth_minus1;
  uint64_t asps_geometry_2d_bit_depth_minus1;
  uint64_t asps_log2_max_atlas_frame_order_cnt_lsb_minus4;
  uint64_t asps_max_dec_atlas_frame_buffering_minus1;
  uint64_t asps_long_term_ref_atlas_frames_flag;
  uint64_t asps_num_ref_atlas_frame_lists_in_asps;
  uint64_t asps_use_eight_orientations_flag;
  uint64_t asps_extended_projection_enabled_flag;
  uint64_t asps_max_number_projections_minus1;
  uint64_t asps_normal_axis_limits_quantization_enabled_flag;
  uint64_t asps_normal_axis_max_delta_value_enabled_flag;
  uint64_t asps_patch_precedence_order_flag;
  uint64_t asps_log2_patch_packing_block_size;
  uint64_t asps_patch_size_quantizer_present_flag;
  uint64_t asps_map_count_minus1;
  uint64_t asps_pixel_deinterleaving_enabled_flag;
  uint64_t asps_raw_patch_enabled_flag;
  uint64_t asps_eom_patch_enabled_flag;
  uint64_t asps_eom_fix_bit_count_minus1;
  uint64_t asps_auxiliary_video_enabled_flag;
  uint64_t asps_plr_enabled_flag;
  uint64_t asps_vui_parameters_present_flag;
  uint64_t asps_extension_present_flag;
  uint64_t asps_vpcc_extension_present_flag;
  uint64_t asps_extension_7bits;
  uint64_t asps_extension_data_flag;
  uint64_t asps_map_pixel_deinterleaving_flag
      [0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1];

  fvv_ref_list_struct_t      *rls;
  fvv_asps_plr_information_t *api;
  fvv_vui_parameters_t       *vp;
  fvv_asps_vpcc_extension_t  *ave; /* Specified in Annex H*/
  fvv_rbsp_trailing_bits_t   *rtb;

  fvv_bitstream_t            *data;

  fvv_ret_t (*pack)(fvv_atlas_sequence_parameter_set_rbsp_t *self);
  fvv_ret_t (*copy_from)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      fvv_atlas_sequence_parameter_set_rbsp_t *other);
  fvv_ret_t (*set_asps_atlas_sequence_parameter_set_id)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_atlas_sequence_parameter_set_id);
  fvv_ret_t (*set_asps_frame_width)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t                                 asps_frame_width);
  fvv_ret_t (*set_asps_frame_height)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t                                 asps_frame_height);
  fvv_ret_t (*set_asps_geometry_3d_bit_depth_minus1)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_geometry_3d_bit_depth_minus1);
  fvv_ret_t (*set_asps_geometry_2d_bit_depth_minus1)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_geometry_2d_bit_depth_minus1);
  fvv_ret_t (*set_asps_log2_max_atlas_frame_order_cnt_lsb_minus4)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_log2_max_atlas_frame_order_cnt_lsb_minus4);
  fvv_ret_t (*set_asps_max_dec_atlas_frame_buffering_minus1)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_max_dec_atlas_frame_buffering_minus1);
  fvv_ret_t (*set_asps_long_term_ref_atlas_frames_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_long_term_ref_atlas_frames_flag);
  fvv_ret_t (*set_asps_num_ref_atlas_frame_lists_in_asps)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_num_ref_atlas_frame_lists_in_asps);
  fvv_ret_t (*set_asps_use_eight_orientations_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_use_eight_orientations_flag);
  fvv_ret_t (*set_asps_extended_projection_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_extended_projection_enabled_flag);
  fvv_ret_t (*set_asps_max_number_projections_minus1)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_max_number_projections_minus1);
  fvv_ret_t (*set_asps_normal_axis_limits_quantization_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_normal_axis_limits_quantization_enabled_flag);
  fvv_ret_t (*set_asps_normal_axis_max_delta_value_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_normal_axis_max_delta_value_enabled_flag);
  fvv_ret_t (*set_asps_patch_precedence_order_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_patch_precedence_order_flag);
  fvv_ret_t (*set_asps_log2_patch_packing_block_size)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_log2_patch_packing_block_size);
  fvv_ret_t (*set_asps_patch_size_quantizer_present_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_patch_size_quantizer_present_flag);
  fvv_ret_t (*set_asps_map_count_minus1)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_map_count_minus1);
  fvv_ret_t (*set_asps_pixel_deinterleaving_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_pixel_deinterleaving_enabled_flag);
  fvv_ret_t (*set_asps_raw_patch_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_raw_patch_enabled_flag);
  fvv_ret_t (*set_asps_eom_patch_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_eom_patch_enabled_flag);
  fvv_ret_t (*set_asps_eom_fix_bit_count_minus1)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_eom_fix_bit_count_minus1);
  fvv_ret_t (*set_asps_auxiliary_video_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_auxiliary_video_enabled_flag);
  fvv_ret_t (*set_asps_plr_enabled_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_plr_enabled_flag);
  fvv_ret_t (*set_asps_vui_parameters_present_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_vui_parameters_present_flag);
  fvv_ret_t (*set_asps_extension_present_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_extension_present_flag);
  fvv_ret_t (*set_asps_vpcc_extension_present_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_vpcc_extension_present_flag);
  fvv_ret_t (*set_asps_extension_7bits)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t                                 asps_extension_7bits);
  fvv_ret_t (*set_asps_extension_data_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_extension_data_flag);
  fvv_ret_t (*set_asps_map_pixel_deinterleaving_flag)(
      fvv_atlas_sequence_parameter_set_rbsp_t *self,
      uint64_t asps_map_pixel_deinterleaving_flag
          [0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1]);
  fvv_ret_t (*set_rls)(fvv_atlas_sequence_parameter_set_rbsp_t *self,
                       fvv_ref_list_struct_t                   *rls);
  fvv_ret_t (*set_api)(fvv_atlas_sequence_parameter_set_rbsp_t *self,
                       fvv_asps_plr_information_t              *api);
  fvv_ret_t (*set_vp)(fvv_atlas_sequence_parameter_set_rbsp_t *self,
                      fvv_vui_parameters_t                    *vp);
  fvv_ret_t (*set_ave)(fvv_atlas_sequence_parameter_set_rbsp_t *self,
                       fvv_asps_vpcc_extension_t               *ave);
  fvv_ret_t (*set_rtb)(fvv_atlas_sequence_parameter_set_rbsp_t *self,
                       fvv_rbsp_trailing_bits_t                *rtb);
};
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_init(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_destroy(
    fvv_atlas_sequence_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_pack(
    fvv_atlas_sequence_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_copy_from(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *other);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_atlas_sequence_parameter_set_id(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_atlas_sequence_parameter_set_id);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_asps_frame_width(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_frame_width);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_frame_height(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_frame_height);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_geometry_3d_bit_depth_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_geometry_3d_bit_depth_minus1);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_geometry_2d_bit_depth_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_geometry_2d_bit_depth_minus1);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_log2_max_atlas_frame_order_cnt_lsb_minus4(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_log2_max_atlas_frame_order_cnt_lsb_minus4);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_max_dec_atlas_frame_buffering_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_max_dec_atlas_frame_buffering_minus1);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_long_term_ref_atlas_frames_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_long_term_ref_atlas_frames_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_num_ref_atlas_frame_lists_in_asps(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_num_ref_atlas_frame_lists_in_asps);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_use_eight_orientations_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_use_eight_orientations_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extended_projection_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_extended_projection_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_max_number_projections_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_max_number_projections_minus1);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_normal_axis_limits_quantization_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_normal_axis_limits_quantization_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_normal_axis_max_delta_value_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_normal_axis_max_delta_value_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_patch_precedence_order_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_patch_precedence_order_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_log2_patch_packing_block_size(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_log2_patch_packing_block_size);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_patch_size_quantizer_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_patch_size_quantizer_present_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_map_count_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_map_count_minus1);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_pixel_deinterleaving_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_pixel_deinterleaving_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_raw_patch_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_raw_patch_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_eom_patch_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_eom_patch_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_eom_fix_bit_count_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_eom_fix_bit_count_minus1);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_auxiliary_video_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_auxiliary_video_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_plr_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_plr_enabled_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_vui_parameters_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_vui_parameters_present_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_extension_present_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_vpcc_extension_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_vpcc_extension_present_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_7bits(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_extension_7bits);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_data_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_extension_data_flag);
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_map_pixel_deinterleaving_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_map_pixel_deinterleaving_flag
        [0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1]);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_rls(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_ref_list_struct_t                   *rls);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_api(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_asps_plr_information_t              *api);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_vp(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_vui_parameters_t                    *vp);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_ave(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_asps_vpcc_extension_t               *ave);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_rtb(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_rbsp_trailing_bits_t                *rtb);
    #endif // FVV_SYNTAX_ATLAS_SEQUENCE_PARAMETER_SET_RBSP_H