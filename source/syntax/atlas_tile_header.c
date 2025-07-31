#include <fvv/syntax/atlas_tile_header.h>
#include <fvv/syntax/bitstream.h>
// 8.3.6.11 Atlas tile header syntax
// {
fvv_ret_t fvv_atlas_tile_header_init(
    fvv_atlas_tile_header_t                 *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_atlas_tile_header_t){0};
  self->aspsr     = aspsr;
  self->data      = data;

  self->pack      = fvv_atlas_tile_header_pack;
  self->copy_from = fvv_atlas_tile_header_copy_from;

  self->set_rls   = fvv_atlas_tile_header_set_rls;
  self->set_ba    = fvv_atlas_tile_header_set_ba;
  self->set_ath_no_output_of_prior_atlas_frames_flag =
      fvv_atlas_tile_header__set_ath_no_output_of_prior_atlas_frames_flag;
  self->set_ath_atlas_frame_parameter_set_id =
      fvv_atlas_tile_header__set_ath_atlas_frame_parameter_set_id;
  self->set_ath_atlas_adaptation_parameter_set_id =
      fvv_atlas_tile_header__set_ath_atlas_adaptation_parameter_set_id;
  self->set_ath_id   = fvv_atlas_tile_header__set_ath_id;
  self->set_ath_type = fvv_atlas_tile_header__set_ath_type;
  self->set_ath_atlas_output_flag =
      fvv_atlas_tile_header__set_ath_atlas_output_flag;
  self->set_ath_atlas_frm_order_cnt_lsb =
      fvv_atlas_tile_header__set_ath_atlas_frm_order_cnt_lsb;
  self->set_ath_ref_atlas_frame_list_asps_flag =
      fvv_atlas_tile_header__set_ath_ref_atlas_frame_list_asps_flag;
  self->set_ath_ref_atlas_frame_list_idx =
      fvv_atlas_tile_header__set_ath_ref_atlas_frame_list_idx;
  self->set_ath_pos_min_d_quantizer =
      fvv_atlas_tile_header__set_ath_pos_min_d_quantizer;
  self->set_ath_pos_delta_max_d_quantizer =
      fvv_atlas_tile_header__set_ath_pos_delta_max_d_quantizer;
  self->set_ath_patch_size_x_info_quantizer =
      fvv_atlas_tile_header__set_ath_patch_size_x_info_quantizer;
  self->set_ath_patch_size_y_info_quantizer =
      fvv_atlas_tile_header__set_ath_patch_size_y_info_quantizer;
  self->set_ath_raw_3d_offset_axis_bit_count_minus1 =
      fvv_atlas_tile_header__set_ath_raw_3d_offset_axis_bit_count_minus1;
  self->set_ath_num_ref_idx_active_override_flag =
      fvv_atlas_tile_header__set_ath_num_ref_idx_active_override_flag;
  self->set_ath_num_ref_idx_active_minus1 =
      fvv_atlas_tile_header__set_ath_num_ref_idx_active_minus1;
  self->set_ath_additional_afoc_lsb_present_flag =
      fvv_atlas_tile_header_set_ath_additional_afoc_lsb_present_flag;
  self->set_ath_additional_afoc_lsb_val =
      fvv_atlas_tile_header_set_ath_additional_afoc_lsb_val;

  self->rls =
      (fvv_ref_list_struct_t *)malloc(sizeof(fvv_ref_list_struct_t));
  self->ba =
      (fvv_byte_alignment_t *)malloc(sizeof(fvv_byte_alignment_t));

  fvv_ref_list_struct_init(self->rls, aspsr, data);
  fvv_byte_alignment_init(self->ba, aspsr->vu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_destroy(fvv_atlas_tile_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->rls)
  {
    fvv_ref_list_struct_destroy(self->rls);
    free(self->rls);
  }
  if (self->ba)
  {
    fvv_byte_alignment_destroy(self->ba);
    free(self->ba);
  }
  *self = (fvv_atlas_tile_header_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_pack(fvv_atlas_tile_header_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff          = FVV_NULL;
  fvv_v3c_unit_t  *vu            = FVV_NULL;
  uint64_t         nal_unit_type = 0;

  buff                           = self->data;
  vu                             = self->aspsr->vu;
  nal_unit_type = vu->vup->asb->ssnu->nu->nuh->nal_unit_type;

  if (nal_unit_type >= NAL_BLA_W_LP &&
      nal_unit_type <= NAL_RSV_IRAP_ACL_29)
    buff->pad(buff,
              self->ath_no_output_of_prior_atlas_frames_flag,
              FVV_BIT_ATH_NO_OUTPUT_OF_PRIOR_ATLAS_FRAMES_FLAG);
  buff->pad(buff,
            self->ath_atlas_frame_parameter_set_id,
            FVV_BIT_ATH_ATLAS_FRAME_PARAMETER_SET_ID);
  buff->pad(buff,
            self->ath_atlas_adaptation_parameter_set_id,
            FVV_BIT_ATH_ATLAS_ADAPTATION_PARAMETER_SET_ID);
  buff->pad(buff, self->ath_id, fvv_bit_ath_id);
  tileID = ath_id;
  buff->pad(buff, self->ath_type, FVV_BIT_ATH_TYPE);
  if (afps_output_flag_present_flag){
    buff->pad(buff,
              self->ath_atlas_output_flag,
              FVV_BIT_ATH_ATLAS_OUTPUT_FLAG);
  }
  buff->pad(buff,
            self->ath_atlas_frm_order_cnt_lsb,
            fvv_bit_ath_atlas_frm_order_cnt_lsb);
  if (asps_num_ref_atlas_frame_lists_in_asps > 0)
    buff->pad(buff,
              self->ath_ref_atlas_frame_list_asps_flag,
              fvv_bit_ath_ref_atlas_frame_list_asps_flag);
  if (ath_ref_atlas_frame_list_asps_flag == 0)
    ref_list_struct(asps_num_ref_atlas_frame_lists_in_asps) else if (
        asps_num_ref_atlas_frame_lists_in_asps > 1)
        buff->pad(buff,
                  self->ath_ref_atlas_frame_list_idx,
                  fvv_bit_ath_ref_atlas_frame_list_idx);
  for (j = 0; j < NumLtrAtlasFrmEntries; j++)
  {
    buff->pad(buff,
              self->ath_additional_afoc_lsb_present_flag[j],
              fvv_bit_ath_additional_afoc_lsb_present_flag[j]);
    if (ath_additional_afoc_lsb_present_flag[j])
      buff->pad(buff,
                self->ath_additional_afoc_lsb_val[j],
                fvv_bit_ath_additional_afoc_lsb_val[j]);
  }
  if (ath_type != SKIP_TILE)
  {
    if (asps_normal_axis_limits_quantization_enabled_flag)
    {
      buff->pad(buff,
                self->ath_pos_min_d_quantizer,
                fvv_bit_ath_pos_min_d_quantizer);
      if (asps_normal_axis_max_delta_value_enabled_flag)
        buff->pad(buff,
                  self->ath_pos_delta_max_d_quantizer,
                  fvv_bit_ath_pos_delta_max_d_quantizer);
    }
    if (asps_patch_size_quantizer_present_flag)
    {
      buff->pad(buff,
                self->ath_patch_size_x_info_quantizer,
                fvv_bit_ath_patch_size_x_info_quantizer);
      buff->pad(buff,
                self->ath_patch_size_y_info_quantizer,
                fvv_bit_ath_patch_size_y_info_quantizer);
    }
    if (afps_raw_3d_offset_bit_count_explicit_mode_flag)
      buff->pad(buff,
                self->ath_raw_3d_offset_axis_bit_count_minus1,
                fvv_bit_ath_raw_3d_offset_axis_bit_count_minus1);
    if (ath_type == P_TILE && num_ref_entries[RlsIdx] > 1)
    {
      buff->pad(buff,
                self->ath_num_ref_idx_active_override_flag,
                fvv_bit_ath_num_ref_idx_active_override_flag);
      if (ath_num_ref_idx_active_override_flag)
        buff->pad(buff,
                  self->ath_num_ref_idx_active_minus1,
                  fvv_bit_ath_num_ref_idx_active_minus1);
    }
  }
  self - ba->pack(self->ba);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_copy_from(fvv_atlas_tile_header_t *self,
                                fvv_atlas_tile_header_t *other);

fvv_ret_t
fvv_atlas_tile_header_set_ath_no_output_of_prior_atlas_frames_flag(
    fvv_atlas_tile_header_t *self,
    uint64_t ath_no_output_of_prior_atlas_frames_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_no_output_of_prior_atlas_frames_flag =
      ath_no_output_of_prior_atlas_frames_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_atlas_frame_parameter_set_id(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_atlas_frame_parameter_set_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_atlas_frame_parameter_set_id =
      ath_atlas_frame_parameter_set_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_ath_atlas_adaptation_parameter_set_id(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_atlas_adaptation_parameter_set_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_atlas_adaptation_parameter_set_id =
      ath_atlas_adaptation_parameter_set_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_ath_id(fvv_atlas_tile_header_t *self,
                                 uint64_t                 ath_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_id = ath_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_ath_type(fvv_atlas_tile_header_t *self,
                                   uint64_t                 ath_type)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_type = ath_type;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_atlas_output_flag(
    fvv_atlas_tile_header_t *self, uint64_t ath_atlas_output_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_atlas_output_flag = ath_atlas_output_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_atlas_frm_order_cnt_lsb(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_atlas_frm_order_cnt_lsb)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_atlas_frm_order_cnt_lsb = ath_atlas_frm_order_cnt_lsb;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_ath_ref_atlas_frame_list_asps_flag(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_ref_atlas_frame_list_asps_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_ref_atlas_frame_list_asps_flag =
      ath_ref_atlas_frame_list_asps_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_ref_atlas_frame_list_idx(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_ref_atlas_frame_list_idx)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_ref_atlas_frame_list_idx = ath_ref_atlas_frame_list_idx;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_pos_min_d_quantizer(
    fvv_atlas_tile_header_t *self, uint64_t ath_pos_min_d_quantizer)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_pos_min_d_quantizer = ath_pos_min_d_quantizer;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_pos_delta_max_d_quantizer(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_pos_delta_max_d_quantizer)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_pos_delta_max_d_quantizer =
      ath_pos_delta_max_d_quantizer;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_patch_size_x_info_quantizer(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_patch_size_x_info_quantizer)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_patch_size_x_info_quantizer =
      ath_patch_size_x_info_quantizer;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_patch_size_y_info_quantizer(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_patch_size_y_info_quantizer)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_patch_size_y_info_quantizer =
      ath_patch_size_y_info_quantizer;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_ath_raw_3d_offset_axis_bit_count_minus1(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_raw_3d_offset_axis_bit_count_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_raw_3d_offset_axis_bit_count_minus1 =
      ath_raw_3d_offset_axis_bit_count_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_ath_num_ref_idx_active_override_flag(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_num_ref_idx_active_override_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_num_ref_idx_active_override_flag =
      ath_num_ref_idx_active_override_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_num_ref_idx_active_minus1(
    fvv_atlas_tile_header_t *self,
    uint64_t                 ath_num_ref_idx_active_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ath_num_ref_idx_active_minus1 =
      ath_num_ref_idx_active_minus1;
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_tile_header_set_ath_additional_afoc_lsb_present_flag(
    *self,
    uint64_t *ath_additional_afoc_lsb_present_flag,
    uint64_t  ath_additional_afoc_lsb_present_flag_size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ath_additional_afoc_lsb_present_flag)
  {
    free(self->ath_additional_afoc_lsb_present_flag);
    self->ath_additional_afoc_lsb_present_flag      = FVV_NULL;
    self->ath_additional_afoc_lsb_present_flag_size = 0;
  }
  self->ath_additional_afoc_lsb_present_flag = (uint64_t *)malloc(
      sizeof(uint64_t) * ath_additional_afoc_lsb_present_flag_size);
  memcpy(self->ath_additional_afoc_lsb_present_flag,
         ath_additional_afoc_lsb_present_flag,
         ath_additional_afoc_lsb_present_flag_size);
  self->ath_additional_afoc_lsb_present_flag_size =
      ath_additional_afoc_lsb_present_flag_size;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ath_additional_afoc_lsb_val(
    *self,
    uint64_t *ath_additional_afoc_lsb_val,
    uint64_t  ath_additional_afoc_lsb_val_size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ath_additional_afoc_lsb_val)
  {
    free(self->ath_additional_afoc_lsb_val);
    self->ath_additional_afoc_lsb_val      = FVV_NULL;
    self->ath_additional_afoc_lsb_val_size = 0;
  }
  self->ath_additional_afoc_lsb_val = (uint64_t *)malloc(
      sizeof(uint64_t) * ath_additional_afoc_lsb_val_size);
  memcpy(self->ath_additional_afoc_lsb_val,
         ath_additional_afoc_lsb_val,
         ath_additional_afoc_lsb_val_size);
  self->ath_additional_afoc_lsb_val_size =
      ath_additional_afoc_lsb_val_size;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_header_set_rls(fvv_atlas_tile_header_t *self,
                              fvv_ref_list_struct_t   *rls)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rls->copy_from(self->rls, rls);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_tile_header_set_ba(fvv_atlas_tile_header_t *self,
                                       fvv_byte_alignment_t    *ba)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ba->copy_from(self->ba, ba);
  return FVV_RET_SUCCESS;
}
// }
