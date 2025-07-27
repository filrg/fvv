#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/bitstream.h>
#include <fvv/syntax/ref_list_struct.h>
#include <fvv/syntax/asps_plr_information.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
// 8.3.6.1.1 General atlas sequence parameter set RBSP syntax
// {

fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_init(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_atlas_sequence_parameter_set_rbsp_t){0};

  self->data      = data;
  self->pack      = fvv_atlas_sequence_parameter_set_rbsp_pack;
  self->copy_from = fvv_atlas_sequence_parameter_set_rbsp_copy_from;
  self->set_asps_atlas_sequence_parameter_set_id =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_atlas_sequence_parameter_set_id;
  self->set_asps_frame_width =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_frame_width;
  self->set_asps_frame_height =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_frame_height;
  self->set_asps_geometry_3d_bit_depth_minus1 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_geometry_3d_bit_depth_minus1;
  self->set_asps_geometry_2d_bit_depth_minus1 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_geometry_2d_bit_depth_minus1;
  self->set_asps_log2_max_atlas_frame_order_cnt_lsb_minus4 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_log2_max_atlas_frame_order_cnt_lsb_minus4;
  self->set_asps_max_dec_atlas_frame_buffering_minus1 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_max_dec_atlas_frame_buffering_minus1;
  self->set_asps_long_term_ref_atlas_frames_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_long_term_ref_atlas_frames_flag;
  self->set_asps_num_ref_atlas_frame_lists_in_asps =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_num_ref_atlas_frame_lists_in_asps;
  self->set_asps_use_eight_orientations_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_use_eight_orientations_flag;
  self->set_asps_extended_projection_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_extended_projection_enabled_flag;
  self->set_asps_max_number_projections_minus1 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_max_number_projections_minus1;
  self->set_asps_normal_axis_limits_quantization_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_normal_axis_limits_quantization_enabled_flag;
  self->set_asps_normal_axis_max_delta_value_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_normal_axis_max_delta_value_enabled_flag;
  self->set_asps_patch_precedence_order_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_patch_precedence_order_flag;
  self->set_asps_log2_patch_packing_block_size =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_log2_patch_packing_block_size;
  self->set_asps_patch_size_quantizer_present_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_patch_size_quantizer_present_flag;
  self->set_asps_map_count_minus1 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_map_count_minus1;
  self->set_asps_pixel_deinterleaving_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_pixel_deinterleaving_enabled_flag;
  self->set_asps_raw_patch_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_raw_patch_enabled_flag;
  self->set_asps_eom_patch_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_eom_patch_enabled_flag;
  self->set_asps_eom_fix_bit_count_minus1 =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_eom_fix_bit_count_minus1;
  self->set_asps_auxiliary_video_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_auxiliary_video_enabled_flag;
  self->set_asps_plr_enabled_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_plr_enabled_flag;
  self->set_asps_vui_parameters_present_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_vui_parameters_present_flag;
  self->set_asps_extension_present_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_present_flag;
  self->set_asps_vpcc_extension_present_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_vpcc_extension_present_flag;
  self->set_asps_extension_7bits =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_7bits;
  self->set_asps_extension_data_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_data_flag;
  self->set_asps_map_pixel_deinterleaving_flag =
      fvv_atlas_sequence_parameter_set_rbsp_set_asps_map_pixel_deinterleaving_flag;
  self->set_rls = fvv_atlas_sequence_parameter_set_rbsp_set_rls;
  self->set_api = fvv_atlas_sequence_parameter_set_rbsp_set_api;
  self->set_vp  = fvv_atlas_sequence_parameter_set_rbsp_set_vp;
  self->set_ave = fvv_atlas_sequence_parameter_set_rbsp_set_ave;
  self->set_rtb = fvv_atlas_sequence_parameter_set_rbsp_set_rtb;

  self->rls =
      (fvv_ref_list_struct_t *)malloc(sizeof(fvv_ref_list_struct_t));
  self->api = (fvv_asps_plr_information_t *)malloc(
      sizeof(fvv_asps_plr_information_t));
  self->vp =
      (fvv_vui_parameters_t *)malloc(sizeof(fvv_vui_parameters_t));
  self->ave = (fvv_asps_vpcc_extension_t *)malloc(
      sizeof(fvv_asps_vpcc_extension_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_ref_list_struct_init(self->rls, self, data);
  fvv_asps_plr_information_init(self->api, self, data);
  fvv_vui_parameters_init(self->vp, self, data);
  fvv_asps_vpcc_extension_init(self->ave, self, data);
  fvv_rbsp_trailing_bits_init(self->rtb, self, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_destroy(
    fvv_atlas_sequence_parameter_set_rbsp_t *self)
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
  if (self->api)
  {
    fvv_asps_plr_information_destroy(self->api);
    free(self->api);
  }
  if (self->vp)
  {
    fvv_vui_parameters_destroy(self->vp);
    free(self->vp);
  }
  if (self->ave)
  {
    fvv_asps_vpcc_extension_destroy(self->ave);
    free(self->ave);
  }
  if (self->rtb)
  {
    fvv_rbsp_trailing_bits_destroy(self->rtb);
    free(self->rtb);
  }

  *self = (fvv_atlas_sequence_parameter_set_rbsp_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_pack(
    fvv_atlas_sequence_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  uint64_t         j    = 0;
  fvv_bool_t       ret  = 0;
  buff                  = self->data;

  buff->pad(buff,
            self->asps_atlas_sequence_parameter_set_id,
            FVV_BIT_ASPS_ATLAS_SEQUENCE_PARAMETER_SET_ID);
  buff->pad(buff, self->asps_frame_width, FVV_BIT_ASPS_FRAME_WIDTH);
  buff->pad(
      buff, self->asps_frame_height, FVV_BIT_ASPS_FRAME_HEIGHT);
  buff->pad(buff,
            self->asps_geometry_3d_bit_depth_minus1,
            FVV_BIT_ASPS_GEOMETRY_3D_BIT_DEPTH_MINUS1);
  buff->pad(buff,
            self->asps_geometry_2d_bit_depth_minus1,
            FVV_BIT_ASPS_GEOMETRY_2D_BIT_DEPTH_MINUS1);
  buff->pad(buff,
            self->asps_log2_max_atlas_frame_order_cnt_lsb_minus4,
            FVV_BIT_ASPS_LOG2_MAX_ATLAS_FRAME_ORDER_CNT_LSB_MINUS4);
  buff->pad(buff,
            self->asps_max_dec_atlas_frame_buffering_minus1,
            FVV_BIT_ASPS_MAX_DEC_ATLAS_FRAME_BUFFERING_MINUS1);
  buff->pad(buff,
            self->asps_long_term_ref_atlas_frames_flag,
            FVV_BIT_ASPS_LONG_TERM_REF_ATLAS_FRAMES_FLAG);
  buff->pad(buff,
            self->asps_num_ref_atlas_frame_lists_in_asps,
            FVV_BIT_ASPS_NUM_REF_ATLAS_FRAME_LISTS_IN_ASPS);

  for (i = 0; i < self->asps_num_ref_atlas_frame_lists_in_asps; i++)
  {
    self->rls->pack(self->rls, i);
  }

  buff->pad(buff,
            self->asps_use_eight_orientations_flag,
            fvv_bit_asps_use_eight_orientations_flag);
  buff->pad(buff,
            self->asps_extended_projection_enabled_flag,
            fvv_bit_asps_extended_projection_enabled_flag);
  if (self->asps_extended_projection_enabled_flag)
  {
    buff->pad(buff,
              self->asps_max_number_projections_minus1,
              fvv_bit_asps_max_number_projections_minus1);
  }
  buff->pad(
      buff,
      self->asps_normal_axis_limits_quantization_enabled_flag,
      FVV_BIT_ASPS_NORMAL_AXIS_LIMITS_QUANTIZATION_ENABLED_FLAG);
  buff->pad(buff,
            self->asps_normal_axis_max_delta_value_enabled_flag,
            FVV_BIT_ASPS_NORMAL_AXIS_MAX_DELTA_VALUE_ENABLED_FLAG);
  buff->pad(buff,
            self->asps_patch_precedence_order_flag,
            FVV_BIT_ASPS_PATCH_PRECEDENCE_ORDER_FLAG);
  buff->pad(buff,
            self->asps_log2_patch_packing_block_size,
            FVV_BIT_ASPS_LOG2_PATCH_PACKING_BLOCK_SIZE);
  buff->pad(buff,
            self->asps_patch_size_quantizer_present_flag,
            FVV_BIT_ASPS_PATCH_SIZE_QUANTIZER_PRESENT_FLAG);
  buff->pad(buff,
            self->asps_map_count_minus1,
            FVV_BIT_ASPS_MAP_COUNT_MINUS1);
  buff->pad(buff,
            self->asps_pixel_deinterleaving_enabled_flag,
            FVV_BITASPS_PIXEL_DEINTERLEAVING_ENABLED_FLAG);

  if (self->asps_pixel_deinterleaving_enabled_flag)
  {
    for (j = 0; j <= self->asps_map_count_minus1; j++)
    {
      buff->pad(buff,
                self->asps_map_pixel_deinterleaving_flag[j],
                FVV_BIT_ASPS_MAP_PIXEL_DEINTERLEAVING_FLAG);
    }
  }

  buff->pad(buff,
            self->asps_raw_patch_enabled_flag,
            FVV_BIT_ASPS_RAW_PATCH_ENABLED_FLAG);
  buff->pad(buff,
            self->asps_eom_patch_enabled_flag,
            FVV_BIT_ASPS_EOM_PATCH_ENABLED_FLAG);
  if (self->asps_eom_patch_enabled_flag &&
      self->asps_map_count_minus1 == 0)
  {
    buff->pad(buff,
              self->asps_eom_fix_bit_count_minus1,
              FVV_BIT_ASPS_EOM_FIX_BIT_COUNT_MINUS1);
  }
  if (self->asps_raw_patch_enabled_flag ||
      self->asps_eom_patch_enabled_flag)
  {
    buff->pad(buff,
              self->asps_auxiliary_video_enabled_flag,
              FVV_BIT_ASPS_AUXILIARY_VIDEO_ENABLED_FLAG);
  }
  buff->pad(buff,
            self->asps_plr_enabled_flag,
            FVV_BIT_ASPS_PLR_ENABLED_FLAG);

  if (self->asps_plr_enabled_flag)
  {
    self->api->pack(self->api, self->asps_map_count_minus1);
  }

  buff->pad(buff,
            self->asps_vui_parameters_present_flag,
            FVV_BIT_ASPS_VUI_PARAMETERS_PRESENT_FLAG);

  if (self->asps_vui_parameters_present_flag)
  {
    self->vp->pack(self->vp);
  }

  buff->pad(buff,
            self->asps_extension_present_flag,
            FVV_BIT_ASPS_EXTENSION_PRESENT_FLAG);
  if (asps_extension_present_flag)
  {
    buff->pad(buff,
              self->asps_vpcc_extension_present_flag,
              FVV_BIT_ASPS_VPCC_EXTENSION_PRESENT_FLAG);
    buff->pad(buff,
              self->asps_extension_7bits,
              FVV_BIT_ASPS_EXTENSION_7BITS);
  }

  if (self->asps_vpcc_extension_present_flag)
  {
    self->ave->pack(self->ave);
  }
  if (self->asps_extension_7bits)
  {
    buff->more_rbsp_data(buff, &ret);
    while (ret)
    {
      buff->pad(buff,
                self->asps_extension_data_flag,
                FVV_BIT_ASPS_EXTENSION_DATA_FLAG);

      buff->more_rbsp_data(buff, &ret);
    }
  }
  self->rtb->pack(self->rtb);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_copy_from(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_asps_atlas_sequence_parameter_set_id(
      self, other->asps_atlas_sequence_parameter_set_id);
  self->set_asps_frame_width(self, other->asps_frame_width);
  self->set_asps_frame_height(self, other->asps_frame_height);
  self->set_asps_geometry_3d_bit_depth_minus1(
      self, other->asps_geometry_3d_bit_depth_minus1);
  self->set_asps_geometry_2d_bit_depth_minus1(
      self, other->asps_geometry_2d_bit_depth_minus1);
  self->set_asps_log2_max_atlas_frame_order_cnt_lsb_minus4(
      self, other->asps_log2_max_atlas_frame_order_cnt_lsb_minus4);
  self->set_asps_max_dec_atlas_frame_buffering_minus1(
      self, other->asps_max_dec_atlas_frame_buffering_minus1);
  self->set_asps_long_term_ref_atlas_frames_flag(
      self, other->asps_long_term_ref_atlas_frames_flag);
  self->set_asps_num_ref_atlas_frame_lists_in_asps(
      self, other->asps_num_ref_atlas_frame_lists_in_asps);
  self->set_asps_use_eight_orientations_flag(
      self, other->asps_use_eight_orientations_flag);
  self->set_asps_extended_projection_enabled_flag(
      self, other->asps_extended_projection_enabled_flag);
  self->set_asps_max_number_projections_minus1(
      self, other->asps_max_number_projections_minus1);
  self->set_asps_normal_axis_limits_quantization_enabled_flag(
      self,
      other->asps_normal_axis_limits_quantization_enabled_flag);
  self->set_asps_normal_axis_max_delta_value_enabled_flag(
      self, other->asps_normal_axis_max_delta_value_enabled_flag);
  self->set_asps_patch_precedence_order_flag(
      self, other->asps_patch_precedence_order_flag);
  self->set_asps_log2_patch_packing_block_size(
      self, other->asps_log2_patch_packing_block_size);
  self->set_asps_patch_size_quantizer_present_flag(
      self, other->asps_patch_size_quantizer_present_flag);
  self->set_asps_map_count_minus1(self,
                                  other->asps_map_count_minus1);
  self->set_asps_pixel_deinterleaving_enabled_flag(
      self, other->asps_pixel_deinterleaving_enabled_flag);
  self->set_asps_raw_patch_enabled_flag(
      self, other->asps_raw_patch_enabled_flag);
  self->set_asps_eom_patch_enabled_flag(
      self, other->asps_eom_patch_enabled_flag);
  self->set_asps_eom_fix_bit_count_minus1(
      self, other->asps_eom_fix_bit_count_minus1);
  self->set_asps_auxiliary_video_enabled_flag(
      self, other->asps_auxiliary_video_enabled_flag);
  self->set_asps_plr_enabled_flag(self,
                                  other->asps_plr_enabled_flag);
  self->set_asps_vui_parameters_present_flag(
      self, other->asps_vui_parameters_present_flag);
  self->set_asps_extension_present_flag(
      self, other->asps_extension_present_flag);
  self->set_asps_vpcc_extension_present_flag(
      self, other->asps_vpcc_extension_present_flag);
  self->set_asps_extension_7bits(self, other->asps_extension_7bits);
  self->set_asps_extension_data_flag(
      self, other->asps_extension_data_flag);
  self->set_asps_map_pixel_deinterleaving_flag(
      self, other->asps_map_pixel_deinterleaving_flag);
  self->set_rls(self, other->rls);
  self->set_api(self, other->api);
  self->set_vp(self, other->vp);
  self->set_ave(self, other->ave);
  self->set_rtb(self, other->rtb);
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_atlas_sequence_parameter_set_id(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_atlas_sequence_parameter_set_id)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_atlas_sequence_parameter_set_id =
      asps_atlas_sequence_parameter_set_id;
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_asps_frame_width(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_frame_width)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_frame_width = asps_frame_width;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_frame_height(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_frame_height)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_frame_height = asps_frame_height;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_geometry_3d_bit_depth_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_geometry_3d_bit_depth_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_geometry_3d_bit_depth_minus1 =
      asps_geometry_3d_bit_depth_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_geometry_2d_bit_depth_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_geometry_2d_bit_depth_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_geometry_2d_bit_depth_minus1 =
      asps_geometry_2d_bit_depth_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_log2_max_atlas_frame_order_cnt_lsb_minus4(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_log2_max_atlas_frame_order_cnt_lsb_minus4)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_log2_max_atlas_frame_order_cnt_lsb_minus4 =
      asps_log2_max_atlas_frame_order_cnt_lsb_minus4;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_max_dec_atlas_frame_buffering_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_max_dec_atlas_frame_buffering_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_max_dec_atlas_frame_buffering_minus1 =
      asps_max_dec_atlas_frame_buffering_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_long_term_ref_atlas_frames_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_long_term_ref_atlas_frames_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_long_term_ref_atlas_frames_flag =
      asps_long_term_ref_atlas_frames_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_num_ref_atlas_frame_lists_in_asps(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_num_ref_atlas_frame_lists_in_asps)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_num_ref_atlas_frame_lists_in_asps =
      asps_num_ref_atlas_frame_lists_in_asps;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_use_eight_orientations_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_use_eight_orientations_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_use_eight_orientations_flag =
      asps_use_eight_orientations_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extended_projection_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_extended_projection_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_extended_projection_enabled_flag =
      asps_extended_projection_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_max_number_projections_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_max_number_projections_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_max_number_projections_minus1 =
      asps_max_number_projections_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_normal_axis_limits_quantization_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_normal_axis_limits_quantization_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_normal_axis_limits_quantization_enabled_flag =
      asps_normal_axis_limits_quantization_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_normal_axis_max_delta_value_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_normal_axis_max_delta_value_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_normal_axis_max_delta_value_enabled_flag =
      asps_normal_axis_max_delta_value_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_patch_precedence_order_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_patch_precedence_order_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_patch_precedence_order_flag =
      asps_patch_precedence_order_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_log2_patch_packing_block_size(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_log2_patch_packing_block_size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_log2_patch_packing_block_size =
      asps_log2_patch_packing_block_size;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_patch_size_quantizer_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_patch_size_quantizer_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_patch_size_quantizer_present_flag =
      asps_patch_size_quantizer_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_map_count_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_map_count_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_map_count_minus1 = asps_map_count_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_pixel_deinterleaving_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_pixel_deinterleaving_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_pixel_deinterleaving_enabled_flag =
      asps_pixel_deinterleaving_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_raw_patch_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_raw_patch_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_raw_patch_enabled_flag = asps_raw_patch_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_eom_patch_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_eom_patch_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_eom_patch_enabled_flag = asps_eom_patch_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_eom_fix_bit_count_minus1(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_eom_fix_bit_count_minus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_eom_fix_bit_count_minus1 =
      asps_eom_fix_bit_count_minus1;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_auxiliary_video_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_auxiliary_video_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_auxiliary_video_enabled_flag =
      asps_auxiliary_video_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_plr_enabled_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_plr_enabled_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_plr_enabled_flag = asps_plr_enabled_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_vui_parameters_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_vui_parameters_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_vui_parameters_present_flag =
      asps_vui_parameters_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_extension_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_extension_present_flag = asps_extension_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_vpcc_extension_present_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_vpcc_extension_present_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_vpcc_extension_present_flag =
      asps_vpcc_extension_present_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_7bits(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t                                 asps_extension_7bits)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_extension_7bits = asps_extension_7bits;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_extension_data_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_extension_data_flag)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->asps_extension_data_flag = asps_extension_data_flag;
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sequence_parameter_set_rbsp_set_asps_map_pixel_deinterleaving_flag(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    uint64_t asps_map_pixel_deinterleaving_flag
        [0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1])
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  memcpy(self->asps_map_pixel_deinterleaving_flag,
         asps_map_pixel_deinterleaving_flag,
         sizeof(uint64_t) * (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1));
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_rls(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_ref_list_struct_t                   *rls)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rls->copy_from(self->rls, rls);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_api(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_asps_plr_information_t              *api)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->api->copy_from(self->api, api);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_vp(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_vui_parameters_t                    *vp)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->vp->copy_from(self->vp, vp);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_ave(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_asps_vpcc_extension_t               *ave)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ave->copy_from(self->ave, ave);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_set_rtb(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_rbsp_trailing_bits_t                *rtb)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rtb->copy_from(self->rtb, rtb);
  return FVV_RET_SUCCESS;
}

// }