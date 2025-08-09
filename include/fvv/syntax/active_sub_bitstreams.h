#ifndef FVV_SYNTAX_ACTIVE_SUB_BITSTREAMS_H
#define FVV_SYNTAX_ACTIVE_SUB_BITSTREAMS_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.10 Active sub-bitstreams SEI message syntax
struct fvv_active_sub_bitstreams_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_active_sub_bitstreams_t,
      asb_active_sub_bitstreams_cancel_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_active_sub_bitstreams_t,
                                asb_active_attributes_changes_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_active_sub_bitstreams_t,
                                asb_active_maps_changes_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_active_sub_bitstreams_t,
      asb_auxiliary_sub_bitstreams_active_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_active_sub_bitstreams_t,
                                asb_all_attributes_active_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_active_sub_bitstreams_t,
                                asb_active_attribute_count_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_active_sub_bitstreams_t,
                                asb_all_maps_active_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_active_sub_bitstreams_t,
                                asb_active_map_count_minus1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_active_sub_bitstreams_t,
      asb_active_attribute_idx,
      (0x1 << FVV_BIT_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1) + 1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_active_sub_bitstreams_t,
      asb_active_map_idx,
      (0x1 << FVV_BIT_ASB_ACTIVE_MAP_COUNT_MINUS1) + 1);

  fvv_ret_t (*pack)(fvv_active_sub_bitstreams_t *self,
                    uint64_t                     payloadSize);
  fvv_ret_t (*copy_from)(fvv_active_sub_bitstreams_t *self,
                         fvv_active_sub_bitstreams_t *other);
};

fvv_ret_t
fvv_active_sub_bitstreams_init(fvv_active_sub_bitstreams_t *self,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_active_sub_bitstreams_destroy(fvv_active_sub_bitstreams_t *self);
fvv_ret_t
fvv_active_sub_bitstreams_pack(fvv_active_sub_bitstreams_t *self,
                               uint64_t payloadSize);
fvv_ret_t fvv_active_sub_bitstreams_copy_from(
    fvv_active_sub_bitstreams_t *self,
    fvv_active_sub_bitstreams_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_active_sub_bitstreams_cancel_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_active_attributes_changes_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_active_maps_changes_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_auxiliary_sub_bitstreams_active_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_all_attributes_active_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_active_attribute_count_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_all_maps_active_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                          asb_active_map_count_minus1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_active_sub_bitstreams_t,
    asb_active_attribute_idx,
    (0x1 << FVV_BIT_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1) + 1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_active_sub_bitstreams_t,
    asb_active_map_idx,
    (0x1 << FVV_BIT_ASB_ACTIVE_MAP_COUNT_MINUS1) + 1);

#endif // FVV_SYNTAX_ACTIVE_SUB_BITSTREAMS_H