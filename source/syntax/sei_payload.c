#include <fvv/bitstream.h>
#include <fvv/syntax/filler_payload.h>
#include <fvv/syntax/nal_unit_header.h>
#include <fvv/syntax/sei_payload.h>
// F.2.1 General SEI message syntax
fvv_ret_t fvv_sei_payload_init(fvv_sei_payload_t     *self,
                               fvv_nal_unit_header_t *nuh,
                               fvv_bitstream_t       *data)
{
  *self      = (fvv_sei_payload_t){0};
  self->data = data;
  self->nuh  = nuh;

  FVV_SET_SETTER_PTR(fvv_sei_payload_t,
                     sp_reserved_payload_extension_data);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, bp, fvv_buffering_period_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, aft, fvv_atlas_frame_timing_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, fp, fvv_filler_payload_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t,
                     udrit35,
                     fvv_user_data_registered_itu_t_t35_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, udu, fvv_user_data_unregistered_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, rp, fvv_recovery_point_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, nd, fvv_no_display_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, tc, fvv_time_code_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, sm, fvv_sei_manifest_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, spi, fvv_sei_prefix_indication_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, asb, fvv_active_sub_bitstreams_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, ccm, fvv_component_codec_mapping_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, soi, fvv_scene_object_information_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, oli, fvv_object_label_information_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, pi, fvv_patch_information_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, vri, fvv_volumetric_rectangle_information_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, aoa, fvv_atlas_object_association_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, vcp, fvv_viewport_camera_parameters_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, vp, fvv_viewport_position_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, atp, fvv_attribute_transformation_params_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, os, fvv_occupancy_synthesis_t);
  FVV_SET_SETTER_PTR(fvv_sei_payload_t, gs, fvv_geometry_smoothing_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, as, fvv_attribute_smoothing_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, dai, fvv_decoded_atlas_information_hash_t);
  FVV_SET_SETTER_PTR(
      fvv_sei_payload_t, rsm, fvv_reserved_sei_message_t);

  self->pack      = fvv_sei_payload_pack;
  self->copy_from = fvv_sei_payload_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_payload_destroy(fvv_sei_payload_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  FVV_DESTROY_OBJ(fvv_sei_payload_t, bp, fvv_buffering_period_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, aft, fvv_atlas_frame_timing_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, fp, fvv_filler_payload_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t,
                  udrit35,
                  fvv_user_data_registered_itu_t_t35_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, udu, fvv_user_data_unregistered_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, rp, fvv_recovery_point_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, nd, fvv_no_display_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, tc, fvv_time_code_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, sm, fvv_sei_manifest_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, spi, fvv_sei_prefix_indication_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, asb, fvv_active_sub_bitstreams_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, ccm, fvv_component_codec_mapping_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, soi, fvv_scene_object_information_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, oli, fvv_object_label_information_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, pi, fvv_patch_information_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, vri, fvv_volumetric_rectangle_information_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, aoa, fvv_atlas_object_association_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, vcp, fvv_viewport_camera_parameters_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, vp, fvv_viewport_position_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, atp, fvv_attribute_transformation_params_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, os, fvv_occupancy_synthesis_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, gs, fvv_geometry_smoothing_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, as, fvv_attribute_smoothing_t);
  FVV_DESTROY_OBJ(
      fvv_sei_payload_t, dai, fvv_decoded_atlas_information_hash_t);
  FVV_DESTROY_OBJ(fvv_sei_payload_t, rsm, fvv_reserved_sei_message_t);
  *self = (fvv_sei_payload_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_payload_pack(fvv_sei_payload_t *self,
                               uint64_t           payloadType,
                               uint64_t           payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  if ((self->nuh->nal_unit_type == FVV_NAL_PREFIX_NSEI) ||
      (self->nuh->nal_unit_type == FVV_NAL_PREFIX_ESEI))
  {
    if (payloadType == 0)
      self->bp->pack(self->bp, payloadSize);
    else if (payloadType == 1)
      self->aft->pack(self->aft, payloadSize);
    else if (payloadType == 2)
      self->fp->pack(self->fp, payloadSize);
    else if (payloadType == 3)
      self->udrit35->pack(self->udrit35, payloadSize);
    else if (payloadType == 4)
      self->udu->pack(self->udu, payloadSize);
    else if (payloadType == 5)
      self->rp->pack(self->rp, payloadSize);
    else if (payloadType == 6)
      self->nd->pack(self->nd, payloadSize);
    else if (payloadType == 7)
      self->tc->pack(self->tc, payloadSize);
    else if (payloadType == 8)
      self->sm->pack(self->sm, payloadSize);
    else if (payloadType == 9)
      self->spi->pack(self->spi, payloadSize);
    else if (payloadType == 10)
      self->asb->pack(self->asb, payloadSize);
    else if (payloadType == 11)
      self->ccm->pack(self->ccm, payloadSize);
    else if (payloadType == 12)
      self->soi->pack(self->soi, payloadSize);
    else if (payloadType == 13)
      self->oli->pack(self->oli, payloadSize);
    else if (payloadType == 14)
      self->pi->pack(self->pi, payloadSize);
    else if (payloadType == 15)
      self->vri->pack(self->vri, payloadSize);
    else if (payloadType == 16)
      self->aoa->pack(self->aoa, payloadSize);
    else if (payloadType == 17)
      self->vcp->pack(self->vcp, payloadSize);
    else if (payloadType == 18)
      self->vp->pack(self->vp, payloadSize);
    else if (payloadType == 64)
      self->atp->pack(self->atp,
                      payloadSize); /* Specified in Annex H */
    else if (payloadType == 65)
      self->os->pack(self->os,
                     payloadSize); /* Specified in Annex H */
    else if (payloadType == 66)
      self->gs->pack(self->gs,
                     payloadSize); /* Specified in Annex H */
    else if (payloadType == 67)
      self->as->pack(self->as,
                     payloadSize); /* Specified in Annex H */
    else
      self->rsm->pack(self->rsm, payloadSize);
  }
  else
  {
    /* (nal_unit_type == NAL_SUFFIX_NSEI) || (nal_unit_type ==
     * NAL_SUFFIX_ESEI) */
    if (payloadType == 2)
      self->fp->pack(self->fp, payloadSize);
    else if (payloadType == 3)
      self->udrit35->pack(self->udrit35, payloadSize);
    else if (payloadType == 4)
      self->udu->pack(self->udu, payloadSize);
    else if (payloadType == 19)
      self->dai->pack(self->dai, payloadSize);
    else
      self->rsm->pack(self->rsm, payloadSize);
  }

  if (more_data_in_payload())
  {
    if (payload_extension_present())
      buff->write_bits(
          buff,
          self->sp_reserved_payload_extension_data,
          FVV_BITS_PER_BYTE * payloadSize - nEarlierBits -
              nPayloadZeroBits - 1,
          FVV_DESCRIPTOR_SP_RESERVED_PAYLOAD_EXTENSION_DATA);
    byte_alignment();
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_sei_payload_copy_from(fvv_sei_payload_t *self,
                                    fvv_sei_payload_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_sp_reserved_payload_extension_data(
      self, other->sp_reserved_payload_extension_data);
  self->set_bp(self, other->bp);
  self->set_aft(self, other->aft);
  self->set_fp(self, other->fp);
  self->set_udrit35(self, other->udrit35);
  self->set_udu(self, other->udu);
  self->set_rp(self, other->rp);
  self->set_nd(self, other->nd);
  self->set_tc(self, other->tc);
  self->set_sm(self, other->sm);
  self->set_spi(self, other->spi);
  self->set_asb(self, other->asb);
  self->set_ccm(self, other->ccm);
  self->set_soi(self, other->soi);
  self->set_oli(self, other->oli);
  self->set_pi(self, other->pi);
  self->set_vri(self, other->vri);
  self->set_aoa(self, other->aoa);
  self->set_vcp(self, other->vcp);
  self->set_vp(self, other->vp);
  self->set_atp(self, other->atp);
  self->set_os(self, other->os);
  self->set_gs(self, other->gs);
  self->set_as(self, other->as);
  self->set_dai(self, other->dai);
  self->set_rsm(self, other->rsm);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_sei_payload_t,
                         sp_reserved_payload_extension_data);

FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, bp, fvv_buffering_period_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      aft,
                      fvv_atlas_frame_timing_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, fp, fvv_filler_payload_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      udrit35,
                      fvv_user_data_registered_itu_t_t35_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      udu,
                      fvv_user_data_unregistered_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, rp, fvv_recovery_point_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, nd, fvv_no_display_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, tc, fvv_time_code_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, sm, fvv_sei_manifest_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      spi,
                      fvv_sei_prefix_indication_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      asb,
                      fvv_active_sub_bitstreams_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      ccm,
                      fvv_component_codec_mapping_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      soi,
                      fvv_scene_object_information_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      oli,
                      fvv_object_label_information_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, pi, fvv_patch_information_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      vri,
                      fvv_volumetric_rectangle_information_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      aoa,
                      fvv_atlas_object_association_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      vcp,
                      fvv_viewport_camera_parameters_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t, vp, fvv_viewport_position_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      atp,
                      fvv_attribute_transformation_params_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      os,
                      fvv_occupancy_synthesis_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      gs,
                      fvv_geometry_smoothing_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      as,
                      fvv_attribute_smoothing_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      dai,
                      fvv_decoded_atlas_information_hash_t);
FVV_DEFINE_OBJ_SETTER(fvv_sei_payload_t,
                      rsm,
                      fvv_reserved_sei_message_t);