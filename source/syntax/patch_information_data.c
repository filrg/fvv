#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_tile_header.h>
#include <fvv/syntax/eom_patch_data_unit.h>
#include <fvv/syntax/inter_patch_data_unit.h>
#include <fvv/syntax/merge_patch_data_unit.h>
#include <fvv/syntax/patch_data_unit.h>
#include <fvv/syntax/patch_information_data.h>
#include <fvv/syntax/raw_patch_data_unit.h>
#include <fvv/syntax/skip_patch_data_unit.h>
// 8.3.7.2 Patch information data syntax
// {
fvv_ret_t fvv_patch_information_data_init(
    fvv_patch_information_data_t            *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_atlas_frame_parameter_set_rbsp_t    *afpsr,
    fvv_atlas_tile_header_t                 *ath,
    fvv_bitstream_t                         *data)
{
  *self       = (fvv_patch_information_data_t){0};
  self->aspsr = aspsr;
  self->afpsr = afpsr;
  self->ath   = ath;
  self->data  = data;

  FVV_SET_SETTER_PTR(
      fvv_patch_information_data_t, spdu, fvv_skip_patch_data_unit_t);
  FVV_SET_SETTER_PTR(fvv_patch_information_data_t,
                     mpdu,
                     fvv_merge_patch_data_unit_t);
  FVV_SET_SETTER_PTR(
      fvv_patch_information_data_t, pdu, fvv_patch_data_unit_t);
  FVV_SET_SETTER_PTR(fvv_patch_information_data_t,
                     ipdu,
                     fvv_inter_patch_data_unit_t);
  FVV_SET_SETTER_PTR(
      fvv_patch_information_data_t, rpdu, fvv_raw_patch_data_unit_t);
  FVV_SET_SETTER_PTR(
      fvv_patch_information_data_t, epdu, fvv_eom_patch_data_unit_t);

  self->spdu = (fvv_skip_patch_data_unit_t *)malloc(
      sizeof(fvv_skip_patch_data_unit_t));
  self->mpdu = (fvv_merge_patch_data_unit_t *)malloc(
      sizeof(fvv_merge_patch_data_unit_t));
  self->pdu =
      (fvv_patch_data_unit_t *)malloc(sizeof(fvv_patch_data_unit_t));
  self->ipdu = (fvv_inter_patch_data_unit_t *)malloc(
      sizeof(fvv_inter_patch_data_unit_t));
  self->rpdu = (fvv_raw_patch_data_unit_t *)malloc(
      sizeof(fvv_raw_patch_data_unit_t));
  self->epdu = (fvv_eom_patch_data_unit_t *)malloc(
      sizeof(fvv_eom_patch_data_unit_t));

  fvv_skip_patch_data_unit_init(self->spdu, data);
  fvv_merge_patch_data_unit_init(self->mpdu, data);
  fvv_patch_data_unit_init(
      self->pdu, self->aspsr, self->afpsr, self->ath, data);
  fvv_inter_patch_data_unit_init(self->ipdu, self->aspsr, data);
  fvv_raw_patch_data_unit_init(self->rpdu, data);
  fvv_eom_patch_data_unit_init(self->epdu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_patch_information_data_destroy(fvv_patch_information_data_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(
      fvv_patch_information_data_t, spdu, fvv_skip_patch_data_unit_t);
  FVV_DESTROY_OBJ(fvv_patch_information_data_t,
                  mpdu,
                  fvv_merge_patch_data_unit_t);
  FVV_DESTROY_OBJ(
      fvv_patch_information_data_t, pdu, fvv_patch_data_unit_t);
  FVV_DESTROY_OBJ(fvv_patch_information_data_t,
                  ipdu,
                  fvv_inter_patch_data_unit_t);
  FVV_DESTROY_OBJ(
      fvv_patch_information_data_t, rpdu, fvv_raw_patch_data_unit_t);
  FVV_DESTROY_OBJ(
      fvv_patch_information_data_t, epdu, fvv_eom_patch_data_unit_t);
  *self = (fvv_patch_information_data_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_patch_information_data_pack(fvv_patch_information_data_t *self,
                                uint64_t                      tileID,
                                uint64_t patchIdx,
                                uint64_t patchMode)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  if (self->ath->ath_type == FVV_P_TILE)
  {
    if (patchMode == FVV_P_SKIP)
      self->spdu->pack(self->spdu);
    else if (patchMode == FVV_P_MERGE)
      self->mpdu->pack(self->mpdu, tileID, patchIdx);
    else if (patchMode == FVV_P_INTRA)
      self->pdu->pack(self->pdu, tileID, patchIdx);
    else if (patchMode == FVV_P_INTER)
      self->ipdu->pack(self->ipdu, tileID, patchIdx);
    else if (patchMode == FVV_P_RAW)
      self->rpdu->pack(self->rpdu, tileID, patchIdx);
    else if (patchMode == FVV_P_EOM)
      self->epdu->pack(self->epdu, tileID, patchIdx);
  }
  else if (self->ath->ath_type == FVV_I_TILE)
  {
    if (patchMode == FVV_I_INTRA)
      self->pdu->pack(self->pdu, tileID, patchIdx);
    else if (patchMode == FVV_I_RAW)
      self->rpdu->pack(self->rpdu, tileID, patchIdx);
    else if (patchMode == FVV_I_EOM)
      self->epdu->pack(self->epdu, tileID, patchIdx);
  }

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_copy_from(
    fvv_patch_information_data_t *self,
    fvv_patch_information_data_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_spdu(self, other->spdu);
  self->set_mpdu(self, other->mpdu);
  self->set_pdu(self, other->pdu);
  self->set_ipdu(self, other->ipdu);
  self->set_rpdu(self, other->rpdu);
  self->set_epdu(self, other->epdu);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_OBJ_SETTER(fvv_patch_information_data_t,
                      spdu,
                      fvv_skip_patch_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_patch_information_data_t,
                      mpdu,
                      fvv_merge_patch_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_patch_information_data_t,
                      pdu,
                      fvv_patch_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_patch_information_data_t,
                      ipdu,
                      fvv_inter_patch_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_patch_information_data_t,
                      rpdu,
                      fvv_raw_patch_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_patch_information_data_t,
                      epdu,
                      fvv_eom_patch_data_unit_t);
// }