#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/ref_list_struct.h>

// 8.3.6.12 Reference list structure syntax
fvv_ret_t fvv_ref_list_struct_init(
    fvv_ref_list_struct_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_bitstream_t                         *data)
{
  *self       = (fvv_ref_list_struct_t){0};
  self->asps = asps;
  self->data  = data;

  FVV_SET_SETTER_PTR(fvv_ref_list_struct_t, num_ref_entries);
  FVV_SET_SETTER_PTR(fvv_ref_list_struct_t, st_ref_atlas_frame_flag);
  FVV_SET_SETTER_PTR(fvv_ref_list_struct_t, abs_delta_afoc_st);
  FVV_SET_SETTER_PTR(fvv_ref_list_struct_t, straf_entry_sign_flag);
  FVV_SET_SETTER_PTR(fvv_ref_list_struct_t, afoc_lsb_lt);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_ref_list_struct_destroy(fvv_ref_list_struct_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_ref_list_struct_t, num_ref_entries);
  FVV_DESTROY_2D_ARR(fvv_ref_list_struct_t, st_ref_atlas_frame_flag);
  FVV_DESTROY_2D_ARR(fvv_ref_list_struct_t, abs_delta_afoc_st);
  FVV_DESTROY_2D_ARR(fvv_ref_list_struct_t, straf_entry_sign_flag);
  FVV_DESTROY_2D_ARR(fvv_ref_list_struct_t, afoc_lsb_lt);
  *self = (fvv_ref_list_struct_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_ref_list_struct_pack(fvv_ref_list_struct_t *self,
                                   uint64_t               rlsIdx)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;
  buff->write_bits(buff,
                   self->num_ref_entries[rlsIdx],
                   FVV_BIT_NUM_REF_ENTRIES,
                   FVV_DESCRIPTOR_NUM_REF_ENTRIES);
  for (i = 0; i < num_ref_entries[rlsIdx]; i++)
  {
    if (self->asps->asps_long_term_ref_atlas_frames_flag)
      buff->write_bits(buff,
                       self->st_ref_atlas_frame_flag[rlsIdx][i],
                       FVV_BIT_ST_REF_ATLAS_FRAME_FLAG,
                       FVV_DESCRIPTOR_ST_REF_ATLAS_FRAME_FLAG);
    if (self->st_ref_atlas_frame_flag[rlsIdx][i])
    {
      buff->write_bits(buff,
                       self->abs_delta_afoc_st[rlsIdx][i],
                       FVV_BIT_ABS_DELTA_AFOC_ST,
                       FVV_DESCRIPTOR_ABS_DELTA_AFOC_ST);
      if (self->abs_delta_afoc_st[rlsIdx][i] > 0)
        buff->write_bits(buff,
                         self->straf_entry_sign_flag[rlsIdx][i],
                         FVV_BIT_STRAF_ENTRY_SIGN_FLAG,
                         FVV_DESCRIPTOR_STRAF_ENTRY_SIGN_FLAG);
    }
    else
      buff->write_bits(buff,
                       self->afoc_lsb_lt[rlsIdx][i],
                       FVV_BIT_AFOC_LSB_LT,
                       FVV_DESCRIPTOR_AFOC_LSB_LT);
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_ref_list_struct_copy_from(fvv_ref_list_struct_t *self,
                                        fvv_ref_list_struct_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_num_ref_entries(
      self, other->num_ref_entries, other->num_ref_entries_size);
  self->set_st_ref_atlas_frame_flag(
      self,
      other->st_ref_atlas_frame_flag,
      other->st_ref_atlas_frame_flag_size);
  self->set_abs_delta_afoc_st(
      self, other->abs_delta_afoc_st, other->abs_delta_afoc_st_size);
  self->set_straf_entry_sign_flag(self,
                                  other->straf_entry_sign_flag,
                                  other->straf_entry_sign_flag_size);
  self->set_afoc_lsb_lt(
      self, other->afoc_lsb_lt, other->afoc_lsb_lt_size);
  return FVV_RET_SUCCESS;
}
FVV_DECLARE_1D_ARR_SETTER(fvv_ref_list_struct_t, num_ref_entries);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t,
                          st_ref_atlas_frame_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t, abs_delta_afoc_st);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t,
                          straf_entry_sign_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t, afoc_lsb_lt);
