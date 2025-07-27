#ifndef FVV_SYNTAX_REF_LIST_STRUCT_H
#define FVV_SYNTAX_REF_LIST_STRUCT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.12 Reference list structure syntax
struct fvv_ref_list_struct_t
{
  uint64_t  *num_ref_entries;         // ue(v)
  uint64_t **st_ref_atlas_frame_flag; // u(1)
  uint64_t **abs_delta_afoc_st;       // ue(v)
  uint64_t **straf_entry_sign_flag;   // u(1)
  uint64_t **afoc_lsb_lt;             // u(v)

  uint64_t   num_ref_entries_size;
  uint64_t   st_ref_atlas_frame_flag_size[2];
  uint64_t   abs_delta_afoc_st_size[2];
  uint64_t   straf_entry_sign_flag[2];
  uint64_t   afoc_lsb_lt[2];

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_ref_list_struct_t *self, uint64_t rlsIdx);
};

// TODO: this really need a look
fvv_ret_t fvv_ref_list_struct_init(
    fvv_ref_list_struct_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_ref_list_struct_destroy(fvv_ref_list_struct_t *self);
fvv_ret_t fvv_ref_list_struct_pack(fvv_ref_list_struct_t *self,
                                   uint64_t               rlsIdx);
#endif // FVV_SYNTAX_REF_LIST_STRUCT_H