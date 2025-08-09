#include <fvv/bitstream.h>
#include <fvv/syntax/active_sub_bitstreams.h>

// F.2.10 Active sub-bitstreams SEI message syntax
fvv_ret_t
fvv_active_sub_bitstreams_init(fvv_active_sub_bitstreams_t *self,
                               fvv_bitstream_t             *data)
{
  *self      = (fvv_active_sub_bitstreams_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_active_sub_bitstreams_cancel_flag);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_active_attributes_changes_flag);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_active_maps_changes_flag);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_auxiliary_sub_bitstreams_active_flag);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_all_attributes_active_flag);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_active_attribute_count_minus1);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_all_maps_active_flag);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_active_map_count_minus1);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t,
                     asb_active_attribute_idx);
  FVV_SET_SETTER_PTR(fvv_active_sub_bitstreams_t, asb_active_map_idx);

  self->pack      = fvv_active_sub_bitstreams_pack;
  self->copy_from = fvv_active_sub_bitstreams_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_active_sub_bitstreams_destroy(fvv_active_sub_bitstreams_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_active_sub_bitstreams_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_active_sub_bitstreams_pack(fvv_active_sub_bitstreams_t *self,
                               uint64_t payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  buff->write_bits(
      buff,
      self->asb_active_sub_bitstreams_cancel_flag,
      FVV_BIT_ASB_ACTIVE_SUB_BITSTREAMS_CANCEL_FLAG,
      FVV_DESCRIPTOR_ASB_ACTIVE_SUB_BITSTREAMS_CANCEL_FLAG);

  if (!self->asb_active_sub_bitstreams_cancel_flag)
  {
    buff->write_bits(
        buff,
        self->asb_active_attributes_changes_flag,
        FVV_BIT_ASB_ACTIVE_ATTRIBUTES_CHANGES_FLAG,
        FVV_DESCRIPTOR_ASB_ACTIVE_ATTRIBUTES_CHANGES_FLAG);
    buff->write_bits(buff,
                     self->asb_active_maps_changes_flag,
                     FVV_BIT_ASB_ACTIVE_MAPS_CHANGES_FLAG,
                     FVV_DESCRIPTOR_ASB_ACTIVE_MAPS_CHANGES_FLAG);
    buff->write_bits(
        buff,
        self->asb_auxiliary_sub_bitstreams_active_flag,
        FVV_BIT_ASB_AUXILIARY_SUB_BITSTREAMS_ACTIVE_FLAG,
        FVV_DESCRIPTOR_ASB_AUXILIARY_SUB_BITSTREAMS_ACTIVE_FLAG);

    if (self->asb_active_attributes_changes_flag)
    {
      buff->write_bits(buff,
                       self->asb_all_attributes_active_flag,
                       FVV_BIT_ASB_ALL_ATTRIBUTES_ACTIVE_FLAG,
                       FVV_DESCRIPTOR_ASB_ALL_ATTRIBUTES_ACTIVE_FLAG);

      if (!self->asb_all_attributes_active_flag)
      {
        buff->write_bits(
            buff,
            self->asb_active_attribute_count_minus1,
            FVV_BIT_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1,
            FVV_DESCRIPTOR_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1);

        for (i = 0; i <= self->asb_active_attribute_count_minus1; i++)
        {
          buff->write_bits(buff,
                           self->asb_active_attribute_idx[i],
                           FVV_BIT_ASB_ACTIVE_ATTRIBUTE_IDX,
                           FVV_DESCRIPTOR_ASB_ACTIVE_ATTRIBUTE_IDX);
        }
      }
    }

    if (self->asb_active_maps_changes_flag)
    {
      buff->write_bits(buff,
                       self->asb_all_maps_active_flag,
                       FVV_BIT_ASB_ALL_MAPS_ACTIVE_FLAG,
                       FVV_DESCRIPTOR_ASB_ALL_MAPS_ACTIVE_FLAG);

      if (!self->asb_all_maps_active_flag)
      {
        buff->write_bits(buff,
                         self->asb_active_map_count_minus1,
                         FVV_BIT_ASB_ACTIVE_MAP_COUNT_MINUS1,
                         FVV_DESCRIPTOR_ASB_ACTIVE_MAP_COUNT_MINUS1);

        for (i = 0; i <= self->asb_active_map_count_minus1; i++)
        {
          buff->write_bits(buff,
                           self->asb_active_map_idx[i],
                           FVV_BIT_ASB_ACTIVE_MAP_IDX,
                           FVV_DESCRIPTOR_ASB_ACTIVE_MAP_IDX);
        }
      }
    }
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_active_sub_bitstreams_copy_from(
    fvv_active_sub_bitstreams_t *self,
    fvv_active_sub_bitstreams_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_asb_active_sub_bitstreams_cancel_flag(
      self, other->asb_active_sub_bitstreams_cancel_flag);
  self->set_asb_active_attributes_changes_flag(
      self, other->asb_active_attributes_changes_flag);
  self->set_asb_active_maps_changes_flag(
      self, other->asb_active_maps_changes_flag);
  self->set_asb_auxiliary_sub_bitstreams_active_flag(
      self, other->asb_auxiliary_sub_bitstreams_active_flag);
  self->set_asb_all_attributes_active_flag(
      self, other->asb_all_attributes_active_flag);
  self->set_asb_active_attribute_count_minus1(
      self, other->asb_active_attribute_count_minus1);
  self->set_asb_all_maps_active_flag(self,
                                     other->asb_all_maps_active_flag);
  self->set_asb_active_map_count_minus1(
      self, other->asb_active_map_count_minus1);
  self->set_asb_active_attribute_idx(self,
                                     other->asb_active_attribute_idx);
  self->set_asb_active_map_idx(self, other->asb_active_map_idx);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_active_sub_bitstreams_cancel_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_active_attributes_changes_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_active_maps_changes_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_auxiliary_sub_bitstreams_active_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_all_attributes_active_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_active_attribute_count_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_all_maps_active_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_active_sub_bitstreams_t,
                         asb_active_map_count_minus1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_active_sub_bitstreams_t,
    asb_active_attribute_idx,
    (0x1 << FVV_BIT_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1) + 1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_active_sub_bitstreams_t,
    asb_active_map_idx,
    (0x1 << FVV_BIT_ASB_ACTIVE_MAP_COUNT_MINUS1) + 1);