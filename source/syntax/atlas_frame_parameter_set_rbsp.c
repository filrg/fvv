#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_frame_parameter_set_rbsp.h>
#include <fvv/syntax/atlas_frame_tile_information.h>
#include <fvv/syntax/rbsp_trailing_bits.h>

// 8.3.6.2.1 General atlas frame parameter set RBSP syntax
// {
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_init(
    fvv_atlas_frame_parameter_set_rbsp_t    *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_atlas_frame_parameter_set_rbsp_t){0};

  self->data      = data;
  self->aspsr     = aspsr;
  self->pack      = fvv_atlas_frame_parameter_set_rbsp_pack;
  self->copy_from = fvv_atlas_frame_parameter_set_rbsp_copy_from;

  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_frame_parameter_set_id);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_sequence_parameter_set_id);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_output_flag_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_num_ref_idx_default_active_minus1);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_additional_lt_afoc_lsb_len);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_lod_mode_enabled_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_raw_3d_offset_bit_count_explicit_mode_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_present_flag);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_8bits);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_data_flag);

  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, afti, fvv_atlas_frame_tile_information_t);
  FVV_SET_SETTER_PTR(fvv_atlas_frame_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

  self->afti = (fvv_atlas_frame_tile_information_t *)malloc(
      sizeof(fvv_atlas_frame_tile_information_t));
  self->rtb = (fvv_rbsp_trailing_bits_t *)malloc(
      sizeof(fvv_rbsp_trailing_bits_t));

  fvv_atlas_frame_tile_information_init(self->afti, self->aspsr, data);
  fvv_rbsp_trailing_bits_init(self->rtb, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_destroy(
    fvv_atlas_frame_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_atlas_frame_parameter_set_rbsp_t, afti, fvv_atlas_frame_tile_information_t);
  FVV_DESTROY_OBJ(fvv_atlas_frame_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

  *self = (fvv_atlas_frame_parameter_set_rbsp_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_pack(
    fvv_atlas_frame_parameter_set_rbsp_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff           = FVV_NULL;
  fvv_bool_t       more_rbsp_data = 0;
  buff                            = self->data;

  buff->pad(buff,
            self->afps_atlas_frame_parameter_set_id,
            FVV_BIT_AFPS_ATLAS_FRAME_PARAMETER_SET_ID);
  buff->pad(buff,
            self->afps_atlas_sequence_parameter_set_id,
            FVV_BIT_AFPS_ATLAS_SEQUENCE_PARAMETER_SET_ID);

  self->afti->pack(self->afti);

  buff->pad(buff,
            self->afps_output_flag_present_flag,
            FVV_BIT_AFPS_OUTPUT_FLAG_PRESENT_FLAG);
  buff->pad(buff,
            self->afps_num_ref_idx_default_active_minus1,
            FVV_BIT_AFPS_NUM_REF_IDX_DEFAULT_ACTIVE_MINUS1);
  buff->pad(buff,
            self->afps_additional_lt_afoc_lsb_len,
            FVV_BIT_AFPS_ADDITIONAL_LT_AFOC_LSB_LEN);
  buff->pad(buff,
            self->afps_lod_mode_enabled_flag,
            FVV_BIT_AFPS_LOD_MODE_ENABLED_FLAG);
  buff->pad(buff,
            self->afps_raw_3d_offset_bit_count_explicit_mode_flag,
            FVV_BIT_AFPS_RAW_3D_OFFSET_BIT_COUNT_EXPLICIT_MODE_FLAG);
  buff->pad(buff,
            self->afps_extension_present_flag,
            FVV_BIT_AFPS_EXTENSION_PRESENT_FLAG);

  if (self->afps_extension_present_flag)
  {
    buff->pad(buff,
              self->afps_extension_8bits,
              FVV_BIT_AFPS_EXTENSION_8BITS);
  }
  if (self->afps_extension_8bits)
  {

    buff->more_rbsp_data(buff, &more_rbsp_data);
    while (more_rbsp_data)
    {
      buff->pad(buff,
                self->afps_extension_data_flag,
                FVV_BIT_AFPS_EXTENSION_DATA_FLAG);

      buff->more_rbsp_data(buff, &more_rbsp_data);
    }
  }
  self->rtb->pack(self->rtb);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_copy_from(
    fvv_atlas_frame_parameter_set_rbsp_t *self,
    fvv_atlas_frame_parameter_set_rbsp_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_afps_atlas_frame_parameter_set_id(
      self, other->afps_atlas_frame_parameter_set_id);
  self->set_afps_atlas_sequence_parameter_set_id(
      self, other->afps_atlas_sequence_parameter_set_id);
  self->set_afps_output_flag_present_flag(
      self, other->afps_output_flag_present_flag);
  self->set_afps_num_ref_idx_default_active_minus1(
      self, other->afps_num_ref_idx_default_active_minus1);
  self->set_afps_additional_lt_afoc_lsb_len(
      self, other->afps_additional_lt_afoc_lsb_len);
  self->set_afps_lod_mode_enabled_flag(
      self, other->afps_lod_mode_enabled_flag);
  self->set_afps_raw_3d_offset_bit_count_explicit_mode_flag(
      self, other->afps_raw_3d_offset_bit_count_explicit_mode_flag);
  self->set_afps_extension_present_flag(
      self, other->afps_extension_present_flag);
  self->set_afps_extension_8bits(self, other->afps_extension_8bits);
  self->set_afps_extension_data_flag(
      self, other->afps_extension_data_flag);

  self->set_afti(self, other->afti);
  self->set_rtb(self, other->rtb);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_frame_parameter_set_id);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_atlas_sequence_parameter_set_id);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_output_flag_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_num_ref_idx_default_active_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_additional_lt_afoc_lsb_len);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_lod_mode_enabled_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_raw_3d_offset_bit_count_explicit_mode_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_8bits);
FVV_DEFINE_SCALAR_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afps_extension_data_flag);

FVV_DEFINE_OBJ_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, afti, fvv_atlas_frame_tile_information_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_frame_parameter_set_rbsp_t, rtb, fvv_rbsp_trailing_bits_t);

// }