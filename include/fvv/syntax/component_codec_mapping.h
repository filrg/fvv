#ifndef FVV_SYNTAX_COMPONENT_CODEC_MAPPING_H
#define FVV_SYNTAX_COMPONENT_CODEC_MAPPING_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.11 Component codec mapping SEI message syntax
struct fvv_component_codec_mapping_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_component_codec_mapping_t,
                                ccm_component_codec_cancel_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_component_codec_mapping_t,
                                ccm_codec_mappings_count_minus1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_component_codec_mapping_t,
      ccm_codec_id,
      (0x1 << FVV_BIT_CCM_CODEC_MAPPINGS_COUNT_MINUS1) + 1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_component_codec_mapping_t,
                                       ccm_codec_4cc,
                                       0x1 << FVV_BIT_CCM_CODEC_ID);

  fvv_ret_t (*pack)(fvv_component_codec_mapping_t *self,
                    uint64_t                       payloadSize);
  fvv_ret_t (*copy_from)(fvv_component_codec_mapping_t *self,
                         fvv_component_codec_mapping_t *other);
};

fvv_ret_t
fvv_component_codec_mapping_init(fvv_component_codec_mapping_t *self,
                                 fvv_bitstream_t               *data);
fvv_ret_t fvv_component_codec_mapping_destroy(
    fvv_component_codec_mapping_t *self);
fvv_ret_t
fvv_component_codec_mapping_pack(fvv_component_codec_mapping_t *self,
                                 uint64_t payloadSize);
fvv_ret_t fvv_component_codec_mapping_copy_from(
    fvv_component_codec_mapping_t *self,
    fvv_component_codec_mapping_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_component_codec_mapping_t,
                          ccm_component_codec_cancel_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_component_codec_mapping_t,
                          ccm_codec_mappings_count_minus1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_component_codec_mapping_t,
    ccm_codec_id,
    (0x1 << FVV_BIT_CCM_CODEC_MAPPINGS_COUNT_MINUS1) + 1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_component_codec_mapping_t,
                                 ccm_codec_4cc,
                                 0x1 << FVV_BIT_CCM_CODEC_ID);

#endif // FVV_SYNTAX_COMPONENT_CODEC_MAPPING_H