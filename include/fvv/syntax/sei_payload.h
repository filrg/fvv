#ifndef FVV_SYNTAX_SEI_PAYLOAD_H
#define FVV_SYNTAX_SEI_PAYLOAD_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.1 General SEI message syntax
struct fvv_sei_payload_t
{
  fvv_nal_unit_header_t *nuh;
  fvv_bitstream_t       *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_sei_payload_t,
                                sp_reserved_payload_extension_data);

  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             bp,
                             fvv_buffering_period_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             aft,
                             fvv_atlas_frame_timing_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             fp,
                             fvv_filler_payload_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             udrit35,
                             fvv_user_data_registered_itu_t_t35_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             udu,
                             fvv_user_data_unregistered_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             rp,
                             fvv_recovery_point_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t, nd, fvv_no_display_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t, tc, fvv_time_code_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             sm,
                             fvv_sei_manifest_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             spi,
                             fvv_sei_prefix_indication_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             asb,
                             fvv_active_sub_bitstreams_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             ccm,
                             fvv_component_codec_mapping_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             soi,
                             fvv_scene_object_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             oli,
                             fvv_object_label_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             pi,
                             fvv_patch_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             vri,
                             fvv_volumetric_rectangle_information_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             aoa,
                             fvv_atlas_object_association_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             vcp,
                             fvv_viewport_camera_parameters_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             vp,
                             fvv_viewport_position_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             atp,
                             fvv_attribute_transformation_params_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             os,
                             fvv_occupancy_synthesis_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             gs,
                             fvv_geometry_smoothing_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             as,
                             fvv_attribute_smoothing_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             dai,
                             fvv_decoded_atlas_information_hash_t);
  FVV_DECLARE_OBJ_SETTER_PTR(fvv_sei_payload_t,
                             rsm,
                             fvv_reserved_sei_message_t);

  fvv_ret_t (*pack)(fvv_sei_payload_t *self,
                    uint64_t           payloadType,
                    uint64_t           payloadSize);
  fvv_ret_t (*copy_from)(fvv_sei_payload_t *self,
                         fvv_sei_payload_t *other);
};

fvv_ret_t fvv_sei_payload_init(fvv_sei_payload_t     *self,
                               fvv_nal_unit_header_t *nuh,
                               fvv_bitstream_t       *data);
fvv_ret_t fvv_sei_payload_destroy(fvv_sei_payload_t *self);
fvv_ret_t fvv_sei_payload_pack(fvv_sei_payload_t *self,
                               uint64_t           payloadType,
                               uint64_t           payloadSize);
fvv_ret_t fvv_sei_payload_copy_from(fvv_sei_payload_t *self,
                                    fvv_sei_payload_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_sei_payload_t,
                          sp_reserved_payload_extension_data);

FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t, bp, fvv_buffering_period_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       aft,
                       fvv_atlas_frame_timing_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t, fp, fvv_filler_payload_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       udrit35,
                       fvv_user_data_registered_itu_t_t35_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       udu,
                       fvv_user_data_unregistered_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t, rp, fvv_recovery_point_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t, nd, fvv_no_display_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t, tc, fvv_time_code_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t, sm, fvv_sei_manifest_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       spi,
                       fvv_sei_prefix_indication_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       asb,
                       fvv_active_sub_bitstreams_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       ccm,
                       fvv_component_codec_mapping_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       soi,
                       fvv_scene_object_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       oli,
                       fvv_object_label_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       pi,
                       fvv_patch_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       vri,
                       fvv_volumetric_rectangle_information_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       aoa,
                       fvv_atlas_object_association_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       vcp,
                       fvv_viewport_camera_parameters_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       vp,
                       fvv_viewport_position_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       atp,
                       fvv_attribute_transformation_params_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       os,
                       fvv_occupancy_synthesis_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       gs,
                       fvv_geometry_smoothing_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       as,
                       fvv_attribute_smoothing_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       dai,
                       fvv_decoded_atlas_information_hash_t);
FVV_DECLARE_OBJ_SETTER(fvv_sei_payload_t,
                       rsm,
                       fvv_reserved_sei_message_t);

#endif // FVV_SYNTAX_SEI_PAYLOAD_H