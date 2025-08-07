#ifndef FVV_SYNTAX_PATCH_INFORMATION_DATA_H
#define FVV_SYNTAX_PATCH_INFORMATION_DATA_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.2 Patch information data syntax
typedef struct fvv_patch_information_data_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_atlas_frame_parameter_set_rbsp_t    *afpsr;
  fvv_atlas_tile_header_t                 *ath;
  fvv_bitstream_t                         *data;

  void (*pack)(struct fvv_patch_information_data_t *self,
               uint64_t                             tileID,
               uint64_t                             patchIdx,
               uint64_t                             patchMode);
  void (*copy_from)(struct fvv_patch_information_data_t *self,
                    struct fvv_patch_information_data_t *other);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_information_data_t,
                             spdu,
                             fvv_skip_patch_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_information_data_t,
                             mpdu,
                             fvv_merge_patch_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_information_data_t,
                             pdu,
                             fvv_patch_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_information_data_t,
                             ipdu,
                             fvv_inter_patch_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_information_data_t,
                             rpdu,
                             fvv_raw_patch_data_unit_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_patch_information_data_t,
                             epdu,
                             fvv_eom_patch_data_unit_t);
} fvv_patch_information_data_t;

fvv_ret_t
fvv_patch_information_data_init(fvv_patch_information_data_t *self,
                                fvv_atlas_tile_header_t      *ath,
                                fvv_bitstream_t              *data);
fvv_ret_t fvv_patch_information_data_destroy(
    fvv_patch_information_data_t *self);
fvv_ret_t
fvv_patch_information_data_pack(fvv_patch_information_data_t *self,
                                uint64_t                      tileID,
                                uint64_t patchIdx,
                                uint64_t patchMode);
fvv_ret_t fvv_patch_information_data_copy_from(
    fvv_patch_information_data_t *self,
    fvv_patch_information_data_t *other);
FVV_DECLARE_OBJ_SETTER(fvv_patch_information_data_t,
                       spdu,
                       fvv_skip_patch_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_patch_information_data_t,
                       mpdu,
                       fvv_merge_patch_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_patch_information_data_t,
                       pdu,
                       fvv_patch_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_patch_information_data_t,
                       ipdu,
                       fvv_inter_patch_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_patch_information_data_t,
                       rpdu,
                       fvv_raw_patch_data_unit_t);
FVV_DECLARE_OBJ_SETTER(fvv_patch_information_data_t,
                       epdu,
                       fvv_eom_patch_data_unit_t);

#endif // FVV_SYNTAX_PATCH_INFORMATION_DATA_H