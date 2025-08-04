#ifndef FVV_SYNTAX_ATTRIBUTE_INFORMATION_H
#define FVV_SYNTAX_ATTRIBUTE_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// typedef struct fvv_v3c_parameter_set_t   fvv_v3c_parameter_set_t;

// 8.3.4.5 Attribute information syntax
struct fvv_attribute_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  fvv_ret_t (*pack)(fvv_attribute_information_t *self,
                    uint64_t                     atlasID);
  fvv_ret_t (*copy_from)(fvv_attribute_information_t *self,
                         fvv_attribute_information_t *other);

  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_count, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_type_id, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_auxiliary_attribute_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_map_absolute_coding_persistence_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_dimension_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_dimension_partitions_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_2d_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_MSB_align_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
  FVV_DECLARE_3D_STATIC_ARR_SETTER_PTR(fvv_attribute_information_t, ai_attribute_partition_channels_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT, 0x1 << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1);
};
fvv_ret_t
fvv_attribute_information_init(fvv_attribute_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_attribute_information_destroy(fvv_attribute_information_t *self);

fvv_ret_t
          fvv_attribute_information_pack(fvv_attribute_information_t *self,
                                         uint64_t                     atlasID);
fvv_ret_t fvv_attribute_information_copy_from(
    fvv_attribute_information_t *self,
    fvv_attribute_information_t *other);
fvv_ret_t fvv_attribute_information_set_ai_attribute_count(
    fvv_attribute_information_t *self,
    uint64_t                     ai_attribute_count[0x1 << FVV_BIT_VPS_ATLAS_ID]);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_count, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_type_id, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_auxiliary_attribute_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_map_absolute_coding_persistence_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_dimension_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_dimension_partitions_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_2d_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_2D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_MSB_align_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT);
FVV_DECLARE_3D_STATIC_ARR_SETTER(fvv_attribute_information_t, ai_attribute_partition_channels_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID, 0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT, 0x1 << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1);
#endif // FVV_SYNTAX_ATTRIBUTE_INFORMATION_H