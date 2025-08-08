#ifndef FVV_SYNTAX_ATLAS_FRAME_PARAMETER_SET_RBSP_H
#define FVV_SYNTAX_ATLAS_FRAME_PARAMETER_SET_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>
// 8.3.6.2.1 General atlas frame parameter set RBSP syntax
struct fvv_atlas_frame_parameter_set_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *asps;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_frame_parameter_set_rbsp_t *self);
  fvv_ret_t (*copy_from)(
      fvv_atlas_frame_parameter_set_rbsp_t *self,
      fvv_atlas_frame_parameter_set_rbsp_t *other);

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_frame_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_sequence_parameter_set_id);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_output_flag_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_num_ref_idx_default_active_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_additional_lt_afoc_lsb_len);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_lod_mode_enabled_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_raw_3d_offset_bit_count_explicit_mode_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_8bits);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_data_flag);

  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afti, fvv_atlas_frame_tile_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
};
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_init(
    fvv_atlas_frame_parameter_set_rbsp_t    *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_destroy(
    fvv_atlas_frame_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_pack(
    fvv_atlas_frame_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_copy_from(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    fvv_atlas_frame_parameter_set_rbsp_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_frame_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_sequence_parameter_set_id);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_output_flag_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_num_ref_idx_default_active_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_additional_lt_afoc_lsb_len);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_lod_mode_enabled_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_raw_3d_offset_bit_count_explicit_mode_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_8bits);
FVV_DECLARE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_data_flag);

FVV_DECLARE_OBJ_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afti, fvv_atlas_frame_tile_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);
#endif // FVV_SYNTAX_ATLAS_FRAME_PARAMETER_SET_RBSP_H