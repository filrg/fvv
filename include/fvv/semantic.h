#ifndef FVV_SEMANTIC_H
#define FVV_SEMANTIC_H

#define FVV_BIT_VUH_UNIT_TYPE                 5
#define FVV_BIT_VUH_V3C_PARAMETER_SET_ID      4
#define FVV_BIT_VUH_ATLAS_ID                  6
#define FVV_BIT_VUH_ATTRIBUTE_INDEX           7
#define FVV_BIT_VUH_ATTRIBUTE_PARTITION_INDEX 5
#define FVV_BIT_VUH_MAP_INDEX                 4
#define FVV_BIT_VUH_AUXILIARY_VIDEO_FLAG      1
#define FVV_BIT_VUH_RESERVED_ZERO_12BITS      12
#define FVV_BIT_VUH_RESERVED_ZERO_17BITS      17
#define FVV_BIT_VUH_RESERVED_ZERO_27BITS      27

#define FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ONE    1
#define FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ZERO   1

typedef enum
{
  FVV_V3C_VPS  = 0, // V3C parameter set
  FVV_V3C_AD   = 1, // Atlas data
  FVV_V3C_OVD  = 2, // Occupancy video data
  FVV_V3C_GVD  = 3, // Geometry video data
  FVV_V3C_AVD  = 4, // Attribute video data
  FVV_V3C_RSVD = 5  // Reserved, values 5..31
} fvv_vuh_unit_type_e;

#endif
