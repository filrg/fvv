#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_tile_header.h>
#include <fvv/syntax/patch_information_data.h>
// 8.3.7.2 Patch information data syntax
// {
fvv_ret_t
fvv_patch_information_data_init(fvv_patch_information_data_t *self,
                                fvv_atlas_tile_header_t      *ath,
                                fvv_bitstream_t              *data)
{
  *self           = (fvv_patch_information_data_t){0};
  self->ath       = ath;
  self->data      = data;

  self->pack      = fvv_patch_information_data_pack;
  self->copy_from = fvv_patch_information_data_copy_from;
  self->set_spdu  = fvv_patch_information_data_set_spdu;
  self->set_mpdu  = fvv_patch_information_data_set_mpdu;
  self->set_pdu   = fvv_patch_information_data_set_pdu;
  self->set_ipdu  = fvv_patch_information_data_set_ipdu;
  self->set_rpdu  = fvv_patch_information_data_set_rpdu;
  self->set_epdu  = fvv_patch_information_data_set_epdu;

  self->spdu      = (fvv_skip_patch_data_unit_t *)malloc(
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
  fvv_patch_data_unit_init(self->pdu, data);
  fvv_inter_patch_data_unit_init(self->ipdu, data);
  fvv_raw_patch_data_unit_init(self->rpdu, data);
  fvv_eom_patch_data_unit_init(self->epdu, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_destroy(
    fvv_patch_information_data_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  if (self->spdu)
  {
    fvv_skip_patch_data_unit_destroy(self->spdu);
    free(self->spdu);
  }
  if (self->mpdu)
  {
    fvv_merge_patch_data_unit_destroy(self->mpdu);
    free(self->mpdu);
  }
  if (self->pdu)
  {
    fvv_patch_data_unit_destroy(self->pdu);
    free(self->pdu);
  }
  if (self->ipdu)
  {
    fvv_inter_patch_data_unit_destroy(self->ipdu);
    free(self->ipdu);
  }
  if (self->rpdu)
  {
    fvv_raw_patch_data_unit_destroy(self->rpdu);
    free(self->rpdu);
  }
  if (self->epdu)
  {
    fvv_eom_patch_data_unit_destroy(self->epdu);
    free(self->epdu);
  }
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
fvv_ret_t fvv_patch_information_data_set_spdu(
    fvv_patch_information_data_t *self,
    fvv_skip_patch_data_unit_t   *spdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->spdu->copy_from(self->spdu, spdu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_set_mpdu(
    fvv_patch_information_data_t *self,
    fvv_merge_patch_data_unit_t  *mpdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->mpdu->copy_from(self->mpdu, mpdu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_set_pdu(
    fvv_patch_information_data_t *self, fvv_patch_data_unit_t *pdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->pdu->copy_from(self->pdu, pdu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_set_ipdu(
    fvv_patch_information_data_t *self,
    fvv_inter_patch_data_unit_t  *ipdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->ipdu->copy_from(self->ipdu, ipdu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_set_rpdu(
    fvv_patch_information_data_t *self,
    fvv_raw_patch_data_unit_t    *rpdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->rpdu->copy_from(self->rpdu, rpdu);
  return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_patch_information_data_set_epdu(
    fvv_patch_information_data_t *self,
    fvv_eom_patch_data_unit_t    *epdu)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->epdu->copy_from(self->epdu, epdu);
  return FVV_RET_SUCCESS;
}
// }