#include <fvv/bitstream.h>
#include <fvv/syntax/asps_plr_information.h>
#include <fvv/syntax/asps_vpcc_extension.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/rbsp_trailing_bits.h>
#include <fvv/syntax/ref_list_struct.h>
#include <string.h>

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
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_atlas_sequence_parameter_set_id);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_frame_width);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_frame_height);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_geometry_3d_bit_depth_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_geometry_2d_bit_depth_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_log2_max_atlas_frame_order_cnt_lsb_minus4);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_max_dec_atlas_frame_buffering_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_long_term_ref_atlas_frames_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_num_ref_atlas_frame_lists_in_asps);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_use_eight_orientations_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_extended_projection_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_max_number_projections_minus1);
  FVV_SET_SETTER_PTR(
      fvv_atlas_sequence_parameter_set_rbsp_t,
      asps_normal_axis_limits_quantization_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_normal_axis_max_delta_value_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_patch_precedence_order_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_log2_patch_packing_block_size);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_patch_size_quantizer_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_map_count_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_pixel_deinterleaving_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_raw_patch_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_eom_patch_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_eom_fix_bit_count_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_auxiliary_video_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_plr_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_vui_parameters_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_extension_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_vpcc_extension_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_extension_7bits);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_extension_data_flag);

  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     asps_map_pixel_deinterleaving_flag,
                     0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1);

  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     rls,
                     fvv_ref_list_struct_t);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     api,
                     fvv_asps_plr_information_t);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     vp,
                     fvv_vui_parameters_t);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     ave,
                     fvv_asps_vpcc_extension_t);
  FVV_SET_SETTER_PTR(fvv_atlas_sequence_parameter_set_rbsp_t,
                     rtb,
                     fvv_rbsp_trailing_bits_t);

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
  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_destroy(
    fvv_atlas_sequence_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_atlas_sequence_parameter_set_rbsp_t,
                  rls,
                  fvv_ref_list_struct_t);
  FVV_DESTROY_OBJ(fvv_atlas_sequence_parameter_set_rbsp_t,
                  api,
                  fvv_asps_plr_information_t);
  FVV_DESTROY_OBJ(fvv_atlas_sequence_parameter_set_rbsp_t,
                  vp,
                  fvv_vui_parameters_t);
  FVV_DESTROY_OBJ(fvv_atlas_sequence_parameter_set_rbsp_t,
                  ave,
                  fvv_asps_vpcc_extension_t);
  FVV_DESTROY_OBJ(fvv_atlas_sequence_parameter_set_rbsp_t,
                  rtb,
                  fvv_rbsp_trailing_bits_t);
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

  buff->write_bits(
      buff,
      self->asps_atlas_sequence_parameter_set_id,
      FVV_BIT_ASPS_ATLAS_SEQUENCE_PARAMETER_SET_ID,
      FVV_DESCRIPTOR_ASPS_ATLAS_SEQUENCE_PARAMETER_SET_ID);
  buff->write_bits(buff,
                   self->asps_frame_width,
                   FVV_BIT_ASPS_FRAME_WIDTH,
                   FVV_DESCRIPTOR_ASPS_FRAME_WIDTH);
  buff->write_bits(buff,
                   self->asps_frame_height,
                   FVV_BIT_ASPS_FRAME_HEIGHT,
                   FVV_DESCRIPTOR_ASPS_FRAME_HEIGHT);
  buff->write_bits(buff,
                   self->asps_geometry_3d_bit_depth_minus1,
                   FVV_BIT_ASPS_GEOMETRY_3D_BIT_DEPTH_MINUS1,
                   FVV_DESCRIPTOR_ASPS_GEOMETRY_3D_BIT_DEPTH_MINUS1);
  buff->write_bits(buff,
                   self->asps_geometry_2d_bit_depth_minus1,
                   FVV_BIT_ASPS_GEOMETRY_2D_BIT_DEPTH_MINUS1,
                   FVV_DESCRIPTOR_ASPS_GEOMETRY_2D_BIT_DEPTH_MINUS1);
  buff->write_bits(
      buff,
      self->asps_log2_max_atlas_frame_order_cnt_lsb_minus4,
      FVV_BIT_ASPS_LOG2_MAX_ATLAS_FRAME_ORDER_CNT_LSB_MINUS4,
      FVV_DESCRIPTOR_ASPS_LOG2_MAX_ATLAS_FRAME_ORDER_CNT_LSB_MINUS4);
  buff->write_bits(
      buff,
      self->asps_max_dec_atlas_frame_buffering_minus1,
      FVV_BIT_ASPS_MAX_DEC_ATLAS_FRAME_BUFFERING_MINUS1,
      FVV_DESCRIPTOR_ASPS_MAX_DEC_ATLAS_FRAME_BUFFERING_MINUS1);
  buff->write_bits(
      buff,
      self->asps_long_term_ref_atlas_frames_flag,
      FVV_BIT_ASPS_LONG_TERM_REF_ATLAS_FRAMES_FLAG,
      FVV_DESCRIPTOR_ASPS_LONG_TERM_REF_ATLAS_FRAMES_FLAG);
  buff->write_bits(
      buff,
      self->asps_num_ref_atlas_frame_lists_in_asps,
      FVV_BIT_ASPS_NUM_REF_ATLAS_FRAME_LISTS_IN_ASPS,
      FVV_DESCRIPTOR_ASPS_NUM_REF_ATLAS_FRAME_LISTS_IN_ASPS);

  for (i = 0; i < self->asps_num_ref_atlas_frame_lists_in_asps; i++)
  {
    self->rls->pack(self->rls, i);
  }

  buff->write_bits(buff,
                   self->asps_use_eight_orientations_flag,
                   FVV_BIT_ASPS_USE_EIGHT_ORIENTATIONS_FLAG,
                   FVV_DESCRIPTOR_ASPS_USE_EIGHT_ORIENTATIONS_FLAG);
  buff->write_bits(
      buff,
      self->asps_extended_projection_enabled_flag,
      FVV_BIT_ASPS_EXTENDED_PROJECTION_ENABLED_FLAG,
      FVV_DESCRIPTOR_ASPS_EXTENDED_PROJECTION_ENABLED_FLAG);
  if (self->asps_extended_projection_enabled_flag)
  {
    buff->write_bits(
        buff,
        self->asps_max_number_projections_minus1,
        FVV_BIT_ASPS_MAX_NUMBER_PROJECTIONS_MINUS1,
        FVV_DESCRIPTOR_ASPS_MAX_NUMBER_PROJECTIONS_MINUS1);
  }
  buff->write_bits(
      buff,
      self->asps_normal_axis_limits_quantization_enabled_flag,
      FVV_BIT_ASPS_NORMAL_AXIS_LIMITS_QUANTIZATION_ENABLED_FLAG,
      FVV_DESCRIPTOR_ASPS_NORMAL_AXIS_LIMITS_QUANTIZATION_ENABLED_FLAG);
  buff->write_bits(
      buff,
      self->asps_normal_axis_max_delta_value_enabled_flag,
      FVV_BIT_ASPS_NORMAL_AXIS_MAX_DELTA_VALUE_ENABLED_FLAG,
      FVV_DESCRIPTOR_ASPS_NORMAL_AXIS_MAX_DELTA_VALUE_ENABLED_FLAG);
  buff->write_bits(buff,
                   self->asps_patch_precedence_order_flag,
                   FVV_BIT_ASPS_PATCH_PRECEDENCE_ORDER_FLAG,
                   FVV_DESCRIPTOR_ASPS_PATCH_PRECEDENCE_ORDER_FLAG);
  buff->write_bits(buff,
                   self->asps_log2_patch_packing_block_size,
                   FVV_BIT_ASPS_LOG2_PATCH_PACKING_BLOCK_SIZE,
                   FVV_DESCRIPTOR_ASPS_LOG2_PATCH_PACKING_BLOCK_SIZE);
  buff->write_bits(
      buff,
      self->asps_patch_size_quantizer_present_flag,
      FVV_BIT_ASPS_PATCH_SIZE_QUANTIZER_PRESENT_FLAG,
      FVV_DESCRIPTOR_ASPS_PATCH_SIZE_QUANTIZER_PRESENT_FLAG);
  buff->write_bits(buff,
                   self->asps_map_count_minus1,
                   FVV_BIT_ASPS_MAP_COUNT_MINUS1,
                   FVV_DESCRIPTOR_ASPS_MAP_COUNT_MINUS1);
  buff->write_bits(
      buff,
      self->asps_pixel_deinterleaving_enabled_flag,
      FVV_BIT_ASPS_PIXEL_DEINTERLEAVING_ENABLED_FLAG,
      FVV_DESCRIPTOR_ASPS_PIXEL_DEINTERLEAVING_ENABLED_FLAG);

  if (self->asps_pixel_deinterleaving_enabled_flag)
  {
    for (j = 0; j <= self->asps_map_count_minus1; j++)
    {
      buff->write_bits(
          buff,
          self->asps_map_pixel_deinterleaving_flag[j],
          FVV_BIT_ASPS_MAP_PIXEL_DEINTERLEAVING_FLAG,
          FVV_DESCRIPTOR_ASPS_MAP_PIXEL_DEINTERLEAVING_FLAG);
    }
  }

  buff->write_bits(buff,
                   self->asps_raw_patch_enabled_flag,
                   FVV_BIT_ASPS_RAW_PATCH_ENABLED_FLAG,
                   FVV_DESCRIPTOR_ASPS_RAW_PATCH_ENABLED_FLAG);
  buff->write_bits(buff,
                   self->asps_eom_patch_enabled_flag,
                   FVV_BIT_ASPS_EOM_PATCH_ENABLED_FLAG,
                   FVV_DESCRIPTOR_ASPS_EOM_PATCH_ENABLED_FLAG);
  if (self->asps_eom_patch_enabled_flag &&
      self->asps_map_count_minus1 == 0)
  {
    buff->write_bits(buff,
                     self->asps_eom_fix_bit_count_minus1,
                     FVV_BIT_ASPS_EOM_FIX_BIT_COUNT_MINUS1,
                     FVV_DESCRIPTOR_ASPS_EOM_FIX_BIT_COUNT_MINUS1);
  }
  if (self->asps_raw_patch_enabled_flag ||
      self->asps_eom_patch_enabled_flag)
  {
    buff->write_bits(
        buff,
        self->asps_auxiliary_video_enabled_flag,
        FVV_BIT_ASPS_AUXILIARY_VIDEO_ENABLED_FLAG,
        FVV_DESCRIPTOR_ASPS_AUXILIARY_VIDEO_ENABLED_FLAG);
  }
  buff->write_bits(buff,
                   self->asps_plr_enabled_flag,
                   FVV_BIT_ASPS_PLR_ENABLED_FLAG,
                   FVV_DESCRIPTOR_ASPS_PLR_ENABLED_FLAG);

  if (self->asps_plr_enabled_flag)
  {
    self->api->pack(self->api, self->asps_map_count_minus1);
  }

  buff->write_bits(buff,
                   self->asps_vui_parameters_present_flag,
                   FVV_BIT_ASPS_VUI_PARAMETERS_PRESENT_FLAG,
                   FVV_DESCRIPTOR_ASPS_VUI_PARAMETERS_PRESENT_FLAG);

  if (self->asps_vui_parameters_present_flag)
  {
    self->vp->pack(self->vp);
  }

  buff->write_bits(buff,
                   self->asps_extension_present_flag,
                   FVV_BIT_ASPS_EXTENSION_PRESENT_FLAG,
                   FVV_DESCRIPTOR_ASPS_EXTENSION_PRESENT_FLAG);
  if (self->asps_extension_present_flag)
  {
    buff->write_bits(buff,
                     self->asps_vpcc_extension_present_flag,
                     FVV_BIT_ASPS_VPCC_EXTENSION_PRESENT_FLAG,
                     FVV_DESCRIPTOR_ASPS_VPCC_EXTENSION_PRESENT_FLAG);
    buff->write_bits(buff,
                     self->asps_extension_7bits,
                     FVV_BIT_ASPS_EXTENSION_7BITS,
                     FVV_DESCRIPTOR_ASPS_EXTENSION_7BITS);
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
      buff->write_bits(buff,
                       self->asps_extension_data_flag,
                       FVV_BIT_ASPS_EXTENSION_DATA_FLAG,
                       FVV_DESCRIPTOR_ASPS_EXTENSION_DATA_FLAG);

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
      self, other->asps_normal_axis_limits_quantization_enabled_flag);
  self->set_asps_normal_axis_max_delta_value_enabled_flag(
      self, other->asps_normal_axis_max_delta_value_enabled_flag);
  self->set_asps_patch_precedence_order_flag(
      self, other->asps_patch_precedence_order_flag);
  self->set_asps_log2_patch_packing_block_size(
      self, other->asps_log2_patch_packing_block_size);
  self->set_asps_patch_size_quantizer_present_flag(
      self, other->asps_patch_size_quantizer_present_flag);
  self->set_asps_map_count_minus1(self, other->asps_map_count_minus1);
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
  self->set_asps_plr_enabled_flag(self, other->asps_plr_enabled_flag);
  self->set_asps_vui_parameters_present_flag(
      self, other->asps_vui_parameters_present_flag);
  self->set_asps_extension_present_flag(
      self, other->asps_extension_present_flag);
  self->set_asps_vpcc_extension_present_flag(
      self, other->asps_vpcc_extension_present_flag);
  self->set_asps_extension_7bits(self, other->asps_extension_7bits);
  self->set_asps_extension_data_flag(self,
                                     other->asps_extension_data_flag);
  self->set_asps_map_pixel_deinterleaving_flag(
      self, other->asps_map_pixel_deinterleaving_flag);
  self->set_rls(self, other->rls);
  self->set_api(self, other->api);
  self->set_vp(self, other->vp);
  self->set_ave(self, other->ave);
  self->set_rtb(self, other->rtb);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_atlas_sequence_parameter_set_id);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_frame_width);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_frame_height);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_geometry_3d_bit_depth_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_geometry_2d_bit_depth_minus1);
FVV_DEFINE_SCALAR_SETTER(
    fvv_atlas_sequence_parameter_set_rbsp_t,
    asps_log2_max_atlas_frame_order_cnt_lsb_minus4);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_max_dec_atlas_frame_buffering_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_long_term_ref_atlas_frames_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_num_ref_atlas_frame_lists_in_asps);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_use_eight_orientations_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_extended_projection_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_max_number_projections_minus1);
FVV_DEFINE_SCALAR_SETTER(
    fvv_atlas_sequence_parameter_set_rbsp_t,
    asps_normal_axis_limits_quantization_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(
    fvv_atlas_sequence_parameter_set_rbsp_t,
    asps_normal_axis_max_delta_value_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_patch_precedence_order_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_log2_patch_packing_block_size);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_patch_size_quantizer_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_map_count_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_pixel_deinterleaving_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_raw_patch_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_eom_patch_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_eom_fix_bit_count_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_auxiliary_video_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_plr_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_vui_parameters_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_extension_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_vpcc_extension_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_extension_7bits);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                         asps_extension_data_flag);

FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_atlas_sequence_parameter_set_rbsp_t,
    asps_map_pixel_deinterleaving_flag,
    0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1);

FVV_DEFINE_OBJ_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                      rls,
                      fvv_ref_list_struct_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                      api,
                      fvv_asps_plr_information_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                      vp,
                      fvv_vui_parameters_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                      ave,
                      fvv_asps_vpcc_extension_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_sequence_parameter_set_rbsp_t,
                      rtb,
                      fvv_rbsp_trailing_bits_t);

// }