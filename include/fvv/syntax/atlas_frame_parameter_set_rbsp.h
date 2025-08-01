#ifndef FVV_SYNTAX_ATLAS_FRAME_PARAMETER_SET_RBSP_H
#define FVV_SYNTAX_ATLAS_FRAME_PARAMETER_SET_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>
// 8.3.6.2.1 General atlas frame parameter set RBSP syntax
struct fvv_atlas_frame_parameter_set_rbsp_t
{
  uint64_t afps_atlas_frame_parameter_set_id;               // ue(v)
  uint64_t afps_atlas_sequence_parameter_set_id;            // ue(v)
  uint64_t afps_output_flag_present_flag;                   // u(1)
  uint64_t afps_num_ref_idx_default_active_minus1;          // ue(v)
  uint64_t afps_additional_lt_afoc_lsb_len;                 // ue(v)
  uint64_t afps_lod_mode_enabled_flag;                      // u(1)
  uint64_t afps_raw_3d_offset_bit_count_explicit_mode_flag; // u(1)
  uint64_t afps_extension_present_flag;                     // u(1)
  uint64_t afps_extension_8bits;                            // u(8)
  uint64_t afps_extension_data_flag;                        // u(1)
  fvv_atlas_frame_tile_information_t      *afti;
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_frame_parameter_set_rbsp_t *self);
  fvv_ret_t (*copy_from)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      fvv_atlas_frame_parameter_set_rbsp_t *other);
  fvv_ret_t (*set_afps_atlas_frame_parameter_set_id)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_atlas_frame_parameter_set_id);
  fvv_ret_t (*set_afps_atlas_sequence_parameter_set_id)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_atlas_sequence_parameter_set_id);
  fvv_ret_t (*set_afps_output_flag_present_flag)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_output_flag_present_flag);
  fvv_ret_t (*set_afps_num_ref_idx_default_active_minus1)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_num_ref_idx_default_active_minus1);
  fvv_ret_t (*set_afps_additional_lt_afoc_lsb_len)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_additional_lt_afoc_lsb_len);
  fvv_ret_t (*set_afps_lod_mode_enabled_flag)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_lod_mode_enabled_flag);
  fvv_ret_t (*set_afps_raw_3d_offset_bit_count_explicit_mode_flag)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_raw_3d_offset_bit_count_explicit_mode_flag);
  fvv_ret_t (*set_afps_extension_present_flag)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_extension_present_flag);
  fvv_ret_t (*set_afps_extension_8bits)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t                              afps_extension_8bits);
  fvv_ret_t (*set_afps_extension_data_flag)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      uint64_t afps_extension_data_flag);
  fvv_ret_t (*set_afti)(fvv_atlas_frame_parameter_set_rbsp_t *self,
                        fvv_atlas_frame_tile_information_t   *afti);
  fvv_ret_t (*set_rtb)(fvv_atlas_frame_parameter_set_rbsp_t *self,
                       fvv_rbsp_trailing_bits_t             *rtb);
};
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_init(
    fvv_atlas_frame_parameter_set_rbsp_t    *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_destroy(
    fvv_atlas_frame_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_pack(
    fvv_atlas_frame_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_copy_from(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    fvv_atlas_frame_parameter_set_rbsp_t *other);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_atlas_frame_parameter_set_id(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_atlas_frame_parameter_set_id);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_atlas_sequence_parameter_set_id(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_atlas_sequence_parameter_set_id);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_output_flag_present_flag(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_output_flag_present_flag);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_num_ref_idx_default_active_minus1(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_num_ref_idx_default_active_minus1);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_additional_lt_afoc_lsb_len(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_additional_lt_afoc_lsb_len);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_lod_mode_enabled_flag(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_lod_mode_enabled_flag);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_raw_3d_offset_bit_count_explicit_mode_flag(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_raw_3d_offset_bit_count_explicit_mode_flag);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_extension_present_flag(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t afps_extension_present_flag);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_extension_8bits(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t                              afps_extension_8bits);
fvv_ret_t
fvv_atlas_frame_parameter_set_rbsp_set_afps_extension_data_flag(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    uint64_t                              afps_extension_data_flag);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_set_afti(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    fvv_atlas_frame_tile_information_t   *afti);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_set_rtb(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    fvv_rbsp_trailing_bits_t             *rtb);
#endif // FVV_SYNTAX_ATLAS_FRAME_PARAMETER_SET_RBSP_H