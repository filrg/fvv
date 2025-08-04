#ifndef FVV_SYNTAX_REF_LIST_STRUCT_H
#define FVV_SYNTAX_REF_LIST_STRUCT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.12 Reference list structure syntax
struct fvv_ref_list_struct_t
{
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_ref_list_struct_t, num_ref_entries);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_ref_list_struct_t, st_ref_atlas_frame_flag);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_ref_list_struct_t, abs_delta_afoc_st);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_ref_list_struct_t, straf_entry_sign_flag);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_ref_list_struct_t, afoc_lsb_lt);

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_ref_list_struct_t *self, uint64_t rlsIdx);
  fvv_ret_t (*copy_from)(fvv_ref_list_struct_t *self, fvv_ref_list_struct_t *other);
};

fvv_ret_t fvv_ref_list_struct_init(
    fvv_ref_list_struct_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_ref_list_struct_destroy(fvv_ref_list_struct_t *self);
fvv_ret_t fvv_ref_list_struct_pack(fvv_ref_list_struct_t *self,
                                   uint64_t               rlsIdx);
fvv_ret_t fvv_ref_list_struct_copy_from(fvv_ref_list_struct_t *self, fvv_ref_list_struct_t *other);
FVV_DECLARE_1D_ARR_SETTER(fvv_ref_list_struct_t, num_ref_entries);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t, st_ref_atlas_frame_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t, abs_delta_afoc_st);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t, straf_entry_sign_flag);
FVV_DECLARE_2D_ARR_SETTER(fvv_ref_list_struct_t, afoc_lsb_lt);

#endif // FVV_SYNTAX_REF_LIST_STRUCT_H