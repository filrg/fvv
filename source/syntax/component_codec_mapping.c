#include <fvv/bitstream.h>
#include <fvv/syntax/component_codec_mapping.h>

// F.2.11 Component codec mapping SEI message syntax
fvv_ret_t
fvv_component_codec_mapping_init(fvv_component_codec_mapping_t *self,
                                 fvv_bitstream_t               *data)
{
  *self      = (fvv_component_codec_mapping_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_component_codec_mapping_t,
                     ccm_component_codec_cancel_flag);
  FVV_SET_SETTER_PTR(fvv_component_codec_mapping_t,
                     ccm_codec_mappings_count_minus1);
  FVV_SET_SETTER_PTR(fvv_component_codec_mapping_t, ccm_codec_id);
  FVV_SET_SETTER_PTR(fvv_component_codec_mapping_t, ccm_codec_4cc);

  self->pack      = fvv_component_codec_mapping_pack;
  self->copy_from = fvv_component_codec_mapping_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_component_codec_mapping_destroy(
    fvv_component_codec_mapping_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_component_codec_mapping_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_component_codec_mapping_pack(fvv_component_codec_mapping_t *self,
                                 uint64_t payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->ccm_component_codec_cancel_flag,
                   FVV_BIT_CCM_COMPONENT_CODEC_CANCEL_FLAG,
                   FVV_DESCRIPTOR_CCM_COMPONENT_CODEC_CANCEL_FLAG);

  if (!self->ccm_component_codec_cancel_flag)
  {
    buff->write_bits(buff,
                     self->ccm_codec_mappings_count_minus1,
                     FVV_BIT_CCM_CODEC_MAPPINGS_COUNT_MINUS1,
                     FVV_DESCRIPTOR_CCM_CODEC_MAPPINGS_COUNT_MINUS1);

    for (i = 0; i <= self->ccm_codec_mappings_count_minus1; i++)
    {
      buff->write_bits(buff,
                       self->ccm_codec_id[i],
                       FVV_BIT_CCM_CODEC_ID,
                       FVV_DESCRIPTOR_CCM_CODEC_ID);
      buff->write_bits(buff,
                       self->ccm_codec_4cc[self->ccm_codec_id[i]],
                       FVV_BIT_CCM_CODEC_4CC,
                       FVV_DESCRIPTOR_CCM_CODEC_4CC);
    }
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_component_codec_mapping_copy_from(
    fvv_component_codec_mapping_t *self,
    fvv_component_codec_mapping_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_ccm_component_codec_cancel_flag(
      self, other->ccm_component_codec_cancel_flag);
  self->set_ccm_codec_mappings_count_minus1(
      self, other->ccm_codec_mappings_count_minus1);
  self->set_ccm_codec_id(self, other->ccm_codec_id);
  self->set_ccm_codec_4cc(self, other->ccm_codec_4cc);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_component_codec_mapping_t,
                         ccm_component_codec_cancel_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_component_codec_mapping_t,
                         ccm_codec_mappings_count_minus1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(
    fvv_component_codec_mapping_t,
    ccm_codec_id,
    (0x1 << FVV_BIT_CCM_CODEC_MAPPINGS_COUNT_MINUS1) + 1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_component_codec_mapping_t,
                                ccm_codec_4cc,
                                0x1 << FVV_BIT_CCM_CODEC_ID);