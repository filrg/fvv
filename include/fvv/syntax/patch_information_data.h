#ifndef FVV_SYNTAX_PATCH_INFORMATION_DATA_H
#define FVV_SYNTAX_PATCH_INFORMATION_DATA_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.2 Patch information data syntax
typedef struct fvv_patch_information_data_t
{
  fvv_skip_patch_data_unit_t  *spdu;
  fvv_merge_patch_data_unit_t *mpdu;
  fvv_patch_data_unit_t       *pdu;
  fvv_inter_patch_data_unit_t *ipdu;
  fvv_raw_patch_data_unit_t   *rpdu;
  fvv_eom_patch_data_unit_t   *epdu;

  fvv_atlas_tile_header_t     *ath;

  fvv_bitstream_t             *data;

  void (*pack)(struct fvv_patch_information_data_t *self,
               uint64_t                             tileID,
               uint64_t                             patchIdx,
               uint64_t                             patchMode);
  void (*copy_from)(struct fvv_patch_information_data_t *self,
                    struct fvv_patch_information_data_t *other);

  fvv_ret_t (*set_spdu)(fvv_patch_information_data_t *self,
                        fvv_skip_patch_data_unit_t   *spdu);
  fvv_ret_t (*set_mpdu)(fvv_patch_information_data_t *self,
                        fvv_merge_patch_data_unit_t  *mpdu);
  fvv_ret_t (*set_pdu)(fvv_patch_information_data_t *self,
                       fvv_patch_data_unit_t        *pdu);
  fvv_ret_t (*set_ipdu)(fvv_patch_information_data_t *self,
                        fvv_inter_patch_data_unit_t  *ipdu);
  fvv_ret_t (*set_rpdu)(fvv_patch_information_data_t *self,
                        fvv_raw_patch_data_unit_t    *rpdu);
  fvv_ret_t (*set_epdu)(fvv_patch_information_data_t *self,
                        fvv_eom_patch_data_unit_t    *epdu);
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
fvv_ret_t fvv_patch_information_data_set_spdu(
    fvv_patch_information_data_t *self,
    fvv_skip_patch_data_unit_t   *spdu);
fvv_ret_t fvv_patch_information_data_set_mpdu(
    fvv_patch_information_data_t *self,
    fvv_merge_patch_data_unit_t  *mpdu);
fvv_ret_t fvv_patch_information_data_set_pdu(
    fvv_patch_information_data_t *self, fvv_patch_data_unit_t *pdu);
fvv_ret_t fvv_patch_information_data_set_ipdu(
    fvv_patch_information_data_t *self,
    fvv_inter_patch_data_unit_t  *ipdu);
fvv_ret_t fvv_patch_information_data_set_rpdu(
    fvv_patch_information_data_t *self,
    fvv_raw_patch_data_unit_t    *rpdu);
fvv_ret_t fvv_patch_information_data_set_epdu(
    fvv_patch_information_data_t *self,
    fvv_eom_patch_data_unit_t    *epdu);

#endif // FVV_SYNTAX_PATCH_INFORMATION_DATA_H