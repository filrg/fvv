#ifndef FVV_DEFS_H
#define FVV_DEFS_H

#include <stdint.h>
#include <stdlib.h>

typedef struct fvv_bitstream_t                               fvv_bitstream_t;
typedef struct fvv_v3c_unit_t                                fvv_v3c_unit_t;
typedef struct fvv_v3c_unit_header_t                         fvv_v3c_unit_header_t;
typedef struct fvv_v3c_unit_payload_t                        fvv_v3c_unit_payload_t;
typedef struct fvv_v3c_parameter_set_t                       fvv_v3c_parameter_set_t;
typedef struct fvv_atlas_sub_bitstream_t                     fvv_atlas_sub_bitstream_t;
typedef struct fvv_video_sub_bitstream_t                     fvv_video_sub_bitstream_t;
typedef struct fvv_sample_stream_nal_header_t                fvv_sample_stream_nal_header_t;
typedef struct fvv_sample_stream_nal_unit_t                  fvv_sample_stream_nal_unit_t;
typedef struct fvv_byte_alignment_t                          fvv_byte_alignment_t;
typedef struct fvv_profile_tier_level_t                      fvv_profile_tier_level_t;
typedef struct fvv_occupancy_information_t                   fvv_occupancy_information_t;
typedef struct fvv_geometry_information_t                    fvv_geometry_information_t;
typedef struct fvv_attribute_information_t                   fvv_attribute_information_t;
typedef struct fvv_profile_toolset_constraints_information_t fvv_profile_toolset_constraints_information_t;
typedef struct fvv_nal_unit_t                                fvv_nal_unit_t;
typedef struct fvv_nal_unit_header_t                         fvv_nal_unit_header_t;
typedef struct fvv_atlas_sequence_parameter_set_rbsp_t       fvv_atlas_sequence_parameter_set_rbsp_t;
typedef struct fvv_asps_plr_information_t                    fvv_asps_plr_information_t;
typedef struct fvv_atlas_frame_parameter_set_rbsp_t          fvv_atlas_frame_parameter_set_rbsp_t;
typedef struct fvv_atlas_frame_tile_information_t            fvv_atlas_frame_tile_information_t;
typedef struct fvv_atlas_adaptation_parameter_set_rbsp_t     fvv_atlas_adaptation_parameter_set_rbsp_t;
typedef struct fvv_sei_rbsp_t                                fvv_sei_rbsp_t;
typedef struct fvv_access_unit_delimiter_rbsp_t              fvv_access_unit_delimiter_rbsp_t;
typedef struct fvv_end_of_sequence_rbsp_t                    fvv_end_of_sequence_rbsp_t;
typedef struct fvv_end_of_atlas_sub_bitstream_rbsp_t         fvv_end_of_atlas_sub_bitstream_rbsp_t;
typedef struct fvv_filler_data_rbsp_t                        fvv_filler_data_rbsp_t;
typedef struct fvv_atlas_tile_layer_rbsp_t                   fvv_atlas_tile_layer_rbsp_t;
typedef struct fvv_rbsp_trailing_bits_t                      fvv_rbsp_trailing_bits_t;
typedef struct fvv_atlas_tile_header_t                       fvv_atlas_tile_header_t;
typedef struct fvv_ref_list_struct_t                         fvv_ref_list_struct_t;
typedef struct fvv_vui_parameters_t                          fvv_vui_parameters_t;
typedef struct fvv_asps_vpcc_extension_t                     fvv_asps_vpcc_extension_t;
typedef struct fvv_aaps_vpcc_extension_t                     fvv_aaps_vpcc_extension_t;
typedef struct fvv_sei_message_t                             fvv_sei_message_t;
typedef struct fvv_atlas_tile_data_unit_t                    fvv_atlas_tile_data_unit_t;
typedef struct fvv_aaps_vpcc_extension_t                     fvv_aaps_vpcc_extension_t;
typedef struct fvv_atlas_camera_parameters_t                 fvv_atlas_camera_parameters_t;
typedef struct fvv_patch_information_data_t                  fvv_patch_information_data_t;
typedef struct fvv_patch_data_unit_t                         fvv_patch_data_unit_t;
typedef struct fvv_skip_patch_data_unit_t                    fvv_skip_patch_data_unit_t;
typedef struct fvv_merge_patch_data_unit_t                   fvv_merge_patch_data_unit_t;
typedef struct fvv_inter_patch_data_unit_t                   fvv_inter_patch_data_unit_t;
typedef struct fvv_raw_patch_data_unit_t                     fvv_raw_patch_data_unit_t;
typedef struct fvv_eom_patch_data_unit_t                     fvv_eom_patch_data_unit_t;
typedef struct fvv_plr_data_t                                fvv_plr_data_t;
typedef struct fvv_sei_message_t                             fvv_sei_message_t;
typedef struct fvv_sei_payload_t                             fvv_sei_payload_t;

typedef uint16_t                                             fvv_ret_t;

#define FVV_CONCAT(a, b)                                        a##b
#define FVV_EXPAND_CONCAT(a, b)                                 FVV_CONCAT(a, b)

#define FVV_TYPE(TYPE)                                          FVV_EXPAND_CONCAT(TYPE_NAME_, TYPE)
#define FVV_STRIP_T(TYPE)                                       FVV_EXPAND_CONCAT(fvv_, FVV_TYPE(TYPE))

#define TYPE_NAME_fvv_bitstream_t                               bitstream
#define TYPE_NAME_fvv_v3c_unit_t                                v3c_unit
#define TYPE_NAME_fvv_v3c_unit_header_t                         v3c_unit_header
#define TYPE_NAME_fvv_v3c_unit_payload_t                        v3c_unit_payload
#define TYPE_NAME_fvv_v3c_parameter_set_t                       v3c_parameter_set
#define TYPE_NAME_fvv_atlas_sub_bitstream_t                     atlas_sub_bitstream
#define TYPE_NAME_fvv_video_sub_bitstream_t                     video_sub_bitstream
#define TYPE_NAME_fvv_sample_stream_nal_header_t                sample_stream_nal_header
#define TYPE_NAME_fvv_sample_stream_nal_unit_t                  sample_stream_nal_unit
#define TYPE_NAME_fvv_byte_alignment_t                          byte_alignment
#define TYPE_NAME_fvv_profile_tier_level_t                      profile_tier_level
#define TYPE_NAME_fvv_occupancy_information_t                   occupancy_information
#define TYPE_NAME_fvv_geometry_information_t                    geometry_information
#define TYPE_NAME_fvv_attribute_information_t                   attribute_information
#define TYPE_NAME_fvv_profile_toolset_constraints_information_t profile_toolset_constraints_information
#define TYPE_NAME_fvv_nal_unit_t                                nal_unit
#define TYPE_NAME_fvv_nal_unit_header_t                         nal_unit_header
#define TYPE_NAME_fvv_atlas_sequence_parameter_set_rbsp_t       atlas_sequence_parameter_set_rbsp
#define TYPE_NAME_fvv_asps_plr_information_t                    asps_plr_information
#define TYPE_NAME_fvv_atlas_frame_parameter_set_rbsp_t          atlas_frame_parameter_set_rbsp
#define TYPE_NAME_fvv_atlas_frame_tile_information_t            atlas_frame_tile_information
#define TYPE_NAME_fvv_atlas_adaptation_parameter_set_rbsp_t     atlas_adaptation_parameter_set_rbsp
#define TYPE_NAME_fvv_sei_rbsp_t                                sei_rbsp
#define TYPE_NAME_fvv_access_unit_delimiter_rbsp_t              access_unit_delimiter_rbsp
#define TYPE_NAME_fvv_end_of_sequence_rbsp_t                    end_of_sequence_rbsp
#define TYPE_NAME_fvv_end_of_atlas_sub_bitstream_rbsp_t         end_of_atlas_sub_bitstream_rbsp
#define TYPE_NAME_fvv_filler_data_rbsp_t                        filler_data_rbsp
#define TYPE_NAME_fvv_atlas_tile_layer_rbsp_t                   atlas_tile_layer_rbsp
#define TYPE_NAME_fvv_rbsp_trailing_bits_t                      rbsp_trailing_bits
#define TYPE_NAME_fvv_atlas_tile_header_t                       atlas_tile_header
#define TYPE_NAME_fvv_ref_list_struct_t                         ref_list_struct
#define TYPE_NAME_fvv_vui_parameters_t                          vui_parameters
#define TYPE_NAME_fvv_asps_vpcc_extension_t                     asps_vpcc_extension
#define TYPE_NAME_fvv_aaps_vpcc_extension_t                     aaps_vpcc_extension
#define TYPE_NAME_fvv_sei_message_t                             sei_message
#define TYPE_NAME_fvv_atlas_tile_data_unit_t                    atlas_tile_data_unit
#define TYPE_NAME_fvv_atlas_camera_parameters_t                 atlas_camera_parameters
#define TYPE_NAME_fvv_patch_information_data_t                  patch_information_data
#define TYPE_NAME_fvv_patch_data_unit_t                         patch_data_unit
#define TYPE_NAME_fvv_skip_patch_data_unit_t                    skip_patch_data_unit
#define TYPE_NAME_fvv_merge_patch_data_unit_t                   merge_patch_data_unit
#define TYPE_NAME_fvv_inter_patch_data_unit_t                   inter_patch_data_unit
#define TYPE_NAME_fvv_raw_patch_data_unit_t                     raw_patch_data_unit
#define TYPE_NAME_fvv_eom_patch_data_unit_t                     eom_patch_data_unit
#define TYPE_NAME_fvv_plr_data_t                                plr_data
#define TYPE_NAME_fvv_sei_message_t                             sei_message
#define TYPE_NAME_fvv_sei_payload_t                             sei_payload

#define FVV_RET_SUCCESS                                         0x0000
#define FVV_RET_FAIL                                            0x0001
#define FVV_RET_UNINITIALIZED                                   0x0002
#define FVV_RET_UNSUPPORT                                       0x0003
#define FVV_RET_ILLEGAL_MEMORY_ACCESS                           0x0004

#define FVV_FAILED(x)                                           ((x) != FVV_RET_SUCCESS)
#define FVV_SUCCEEDED(x)                                        ((x) == FVV_RET_SUCCESS)

typedef uint8_t fvv_bool_t;

#define FVV_FALSE                               0x00
#define FVV_TRUE                                0x01

#define FVV_NULL                                ((void *)0)

#define FVV_BITS_PER_BYTE                       0x08

#define FVV_SET_SETTER_PTR(STRUCT, ATTRIB, ...) self->set_##ATTRIB = FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)

#define FVV_DECLARE_4D_ARR_SETTER_PTR(STRUCT, ATTRIB) \
  uint64_t ****ATTRIB;                                \
  uint64_t     ATTRIB##_size[4];                      \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,            \
                            uint64_t ****ATTRIB,      \
                            uint64_t     ATTRIB##_size[4])
#define FVV_DECLARE_4D_ARR_SETTER(STRUCT, ATTRIB)                                      \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,       \
                                                                  uint64_t ****ATTRIB, \
                                                                  uint64_t     ATTRIB##_size[4])
#define FVV_DEFINE_4D_ARR_SETTER(STRUCT, ATTRIB)                                                 \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,                 \
                                                                  uint64_t ****ATTRIB,           \
                                                                  uint64_t     ATTRIB##_size[4]) \
  {                                                                                              \
    if (!self)                                                                                   \
    {                                                                                            \
      return FVV_RET_UNINITIALIZED;                                                              \
    }                                                                                            \
    if (self->ATTRIB)                                                                            \
    {                                                                                            \
      for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)                                      \
      {                                                                                          \
        for (uint64_t j = 0; j < self->ATTRIB##_size[1]; j++)                                    \
        {                                                                                        \
          for (uint64_t k = 0; k < self->ATTRIB##_size[2]; k++)                                  \
          {                                                                                      \
            free(self->ATTRIB[i][j][k]);                                                         \
          }                                                                                      \
          free(self->ATTRIB[i][j]);                                                              \
        }                                                                                        \
        free(self->ATTRIB[i]);                                                                   \
      }                                                                                          \
      free(self->ATTRIB);                                                                        \
      self->ATTRIB##_size[0] = 0;                                                                \
      self->ATTRIB##_size[1] = 0;                                                                \
      self->ATTRIB##_size[2] = 0;                                                                \
      self->ATTRIB##_size[3] = 0;                                                                \
    }                                                                                            \
    self->ATTRIB =                                                                               \
        (uint64_t ****)malloc(sizeof(uint64_t ***) * ATTRIB##_size[0]);                          \
    for (uint64_t i = 0; i < ATTRIB##_size[0]; i++)                                              \
    {                                                                                            \
      self->ATTRIB[i] = (uint64_t ***)malloc(sizeof(uint64_t **) * ATTRIB##_size[1]);            \
      for (uint64_t j = 0; j < ATTRIB##_size[1]; j++)                                            \
      {                                                                                          \
        self->ATTRIB[i][j] = (uint64_t **)malloc(sizeof(uint64_t *) * ATTRIB##_size[2]);         \
        for (uint64_t k = 0; k < ATTRIB##_size[2]; k++)                                          \
        {                                                                                        \
          self->ATTRIB[i][j][k] = (uint64_t *)malloc(sizeof(uint64_t) * ATTRIB##_size[3]);       \
          memcpy(self->ATTRIB[i][j][k], ATTRIB[i][j][k], sizeof(uint64_t) * ATTRIB##_size[3]);   \
        }                                                                                        \
      }                                                                                          \
    }                                                                                            \
    self->ATTRIB##_size[0] = ATTRIB##_size[0];                                                   \
    self->ATTRIB##_size[1] = ATTRIB##_size[1];                                                   \
    self->ATTRIB##_size[2] = ATTRIB##_size[2];                                                   \
    self->ATTRIB##_size[3] = ATTRIB##_size[3];                                                   \
    return FVV_RET_SUCCESS;                                                                      \
  }
#define FVV_DESTROY_4D_ARR(STRUCT, ATTRIB)                    \
  if (self->ATTRIB)                                           \
  {                                                           \
    for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)     \
    {                                                         \
      for (uint64_t j = 0; j < self->ATTRIB##_size[1]; j++)   \
      {                                                       \
        for (uint64_t k = 0; k < self->ATTRIB##_size[2]; k++) \
        {                                                     \
          free(self->ATTRIB[i][j][k]);                        \
        }                                                     \
        free(self->ATTRIB[i][j]);                             \
      }                                                       \
      free(self->ATTRIB[i]);                                  \
    }                                                         \
    free(self->ATTRIB);                                       \
    self->ATTRIB           = FVV_NULL;                        \
    self->ATTRIB##_size[0] = 0;                               \
    self->ATTRIB##_size[1] = 0;                               \
    self->ATTRIB##_size[2] = 0;                               \
    self->ATTRIB##_size[3] = 0;                               \
  }

#define FVV_DECLARE_3D_ARR_SETTER_PTR(STRUCT, ATTRIB) \
  uint64_t ***ATTRIB;                                 \
  uint64_t    ATTRIB##_size[3];                       \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,            \
                            uint64_t ***ATTRIB,       \
                            uint64_t    ATTRIB##_size[3])
#define FVV_DECLARE_3D_ARR_SETTER(STRUCT, ATTRIB)                                     \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,      \
                                                                  uint64_t ***ATTRIB, \
                                                                  uint64_t    ATTRIB##_size[3])
#define FVV_DEFINE_3D_ARR_SETTER(STRUCT, ATTRIB)                                                \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,                \
                                                                  uint64_t ***ATTRIB,           \
                                                                  uint64_t    ATTRIB##_size[3]) \
  {                                                                                             \
    if (!self)                                                                                  \
    {                                                                                           \
      return FVV_RET_UNINITIALIZED;                                                             \
    }                                                                                           \
    if (self->ATTRIB)                                                                           \
    {                                                                                           \
      for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)                                     \
      {                                                                                         \
        for (uint64_t j = 0; j < self->ATTRIB##_size[1]; j++)                                   \
        {                                                                                       \
          free(self->ATTRIB[i][j]);                                                             \
        }                                                                                       \
        free(self->ATTRIB[i]);                                                                  \
      }                                                                                         \
      free(self->ATTRIB);                                                                       \
      self->ATTRIB##_size[0] = 0;                                                               \
      self->ATTRIB##_size[1] = 0;                                                               \
      self->ATTRIB##_size[2] = 0;                                                               \
    }                                                                                           \
    self->ATTRIB =                                                                              \
        (uint64_t ***)malloc(sizeof(uint64_t **) * ATTRIB##_size[0]);                           \
    for (uint64_t i = 0; i < ATTRIB##_size[0]; i++)                                             \
    {                                                                                           \
      self->ATTRIB[i] =                                                                         \
          (uint64_t **)malloc(sizeof(uint64_t *) * ATTRIB##_size[1]);                           \
      for (uint64_t j = 0; j < ATTRIB##_size[1]; j++)                                           \
      {                                                                                         \
        self->ATTRIB[i][j] =                                                                    \
            (uint64_t *)malloc(sizeof(uint64_t) * ATTRIB##_size[2]);                            \
        memcpy(self->ATTRIB[i][j], ATTRIB[i][j], sizeof(uint64_t) * ATTRIB##_size[2]);          \
      }                                                                                         \
    }                                                                                           \
    self->ATTRIB##_size[0] = ATTRIB##_size[0];                                                  \
    self->ATTRIB##_size[1] = ATTRIB##_size[1];                                                  \
    self->ATTRIB##_size[2] = ATTRIB##_size[2];                                                  \
    return FVV_RET_SUCCESS;                                                                     \
  }
#define FVV_DESTROY_3D_ARR(STRUCT, ATTRIB)                  \
  if (self->ATTRIB)                                         \
  {                                                         \
    for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)   \
    {                                                       \
      for (uint64_t j = 0; j < self->ATTRIB##_size[1]; j++) \
      {                                                     \
        free(self->ATTRIB[i][j]);                           \
      }                                                     \
      free(self->ATTRIB[i]);                                \
    }                                                       \
    free(self->ATTRIB);                                     \
    self->ATTRIB           = FVV_NULL;                      \
    self->ATTRIB##_size[0] = 0;                             \
    self->ATTRIB##_size[1] = 0;                             \
    self->ATTRIB##_size[2] = 0;                             \
  }

#define FVV_DECLARE_2D_ARR_SETTER_PTR(STRUCT, ATTRIB) \
  uint64_t **ATTRIB;                                  \
  uint64_t   ATTRIB##_size[2];                        \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,            \
                            uint64_t **ATTRIB,        \
                            uint64_t   ATTRIB##_size[2])
#define FVV_DECLARE_2D_ARR_SETTER(STRUCT, ATTRIB)                                    \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,     \
                                                                  uint64_t **ATTRIB, \
                                                                  uint64_t   ATTRIB##_size[2])
#define FVV_DEFINE_2D_ARR_SETTER(STRUCT, ATTRIB)                                               \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,               \
                                                                  uint64_t **ATTRIB,           \
                                                                  uint64_t   ATTRIB##_size[2]) \
  {                                                                                            \
    if (!self)                                                                                 \
    {                                                                                          \
      return FVV_RET_UNINITIALIZED;                                                            \
    }                                                                                          \
    if (self->ATTRIB)                                                                          \
    {                                                                                          \
      for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)                                    \
      {                                                                                        \
        free(self->ATTRIB[i]);                                                                 \
      }                                                                                        \
      free(self->ATTRIB);                                                                      \
      self->ATTRIB##_size[0] = 0;                                                              \
      self->ATTRIB##_size[1] = 0;                                                              \
    }                                                                                          \
    self->ATTRIB =                                                                             \
        (uint64_t **)malloc(sizeof(uint64_t *) * ATTRIB##_size[0]);                            \
    for (uint64_t i = 0; i < ATTRIB##_size[0]; i++)                                            \
    {                                                                                          \
      memcpy(self->ATTRIB[i],                                                                  \
             ATTRIB[i],                                                                        \
             sizeof(uint64_t) * ATTRIB##_size[1]);                                             \
    }                                                                                          \
    self->ATTRIB##_size[0] = ATTRIB##_size[0];                                                 \
    self->ATTRIB##_size[1] = ATTRIB##_size[1];                                                 \
    return FVV_RET_SUCCESS;                                                                    \
  }
#define FVV_DESTROY_2D_ARR(STRUCT, ATTRIB)                \
  if (self->ATTRIB)                                       \
  {                                                       \
    for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++) \
    {                                                     \
      free(self->ATTRIB[i]);                              \
    }                                                     \
    free(self->ATTRIB);                                   \
    self->ATTRIB           = FVV_NULL;                    \
    self->ATTRIB##_size[0] = 0;                           \
    self->ATTRIB##_size[1] = 0;                           \
  }

#define FVV_DECLARE_1D_ARR_SETTER_PTR(STRUCT, ATTRIB) \
  uint64_t *ATTRIB;                                   \
  uint64_t  ATTRIB##_size;                            \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,            \
                            uint64_t *ATTRIB,         \
                            uint64_t  ATTRIB##_size)
#define FVV_DECLARE_1D_ARR_SETTER(STRUCT, ATTRIB)                                   \
  uint64_t *ATTRIB;                                                                 \
  uint64_t  ATTRIB##_size;                                                          \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,    \
                                                                  uint64_t *ATTRIB, \
                                                                  uint64_t  ATTRIB##_size)
#define FVV_DEFINE_1D_ARR_SETTER(STRUCT, ATTRIB)                                           \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,           \
                                                                  uint64_t *ATTRIB,        \
                                                                  uint64_t  ATTRIB##_size) \
  {                                                                                        \
    if (!self)                                                                             \
    {                                                                                      \
      return FVV_RET_UNINITIALIZED;                                                        \
    }                                                                                      \
    if (self->ATTRIB)                                                                      \
    {                                                                                      \
      free(self->ATTRIB);                                                                  \
      self->ATTRIB##_size = 0;                                                             \
    }                                                                                      \
    self->ATTRIB =                                                                         \
        (uint64_t *)malloc(sizeof(uint64_t) * ATTRIB##_size);                              \
    memcpy(self->ATTRIB, ATTRIB, sizeof(uint64_t) * ATTRIB##_size);                        \
    self->ATTRIB##_size = ATTRIB##_size;                                                   \
    return FVV_RET_SUCCESS;                                                                \
  }
#define FVV_DESTROY_1D_ARR(STRUCT, ATTRIB) \
  if (self->ATTRIB)                        \
  {                                        \
    free(self->ATTRIB);                    \
    self->ATTRIB        = FVV_NULL;        \
    self->ATTRIB##_size = 0;               \
  }

#define FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(STRUCT, ATTRIB, SIZE) \
  uint64_t ATTRIB[(SIZE)];                                         \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self, uint64_t ATTRIB[(SIZE)])
#define FVV_DECLARE_1D_STATIC_ARR_SETTER(STRUCT, ATTRIB, SIZE)                   \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self, \
                                                                  uint64_t ATTRIB[(SIZE)])
#define FVV_DEFINE_1D_STATIC_ARR_SETTER(STRUCT, ATTRIB, SIZE)                              \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,           \
                                                                  uint64_t ATTRIB[(SIZE)]) \
  {                                                                                        \
    if (!self)                                                                             \
      return FVV_RET_UNINITIALIZED;                                                        \
    memcpy(self->ATTRIB, ATTRIB, sizeof(self->ATTRIB));                                    \
    return FVV_RET_SUCCESS;                                                                \
  }

#define FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR( \
    STRUCT, ATTRIB, SIZE1, SIZE2)             \
  uint64_t ATTRIB[(SIZE1)][(SIZE2)];          \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,    \
                            uint64_t ATTRIB[(SIZE1)][(SIZE2)])
#define FVV_DECLARE_2D_STATIC_ARR_SETTER(                          \
    STRUCT, ATTRIB, SIZE1, SIZE2)                                  \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB[(SIZE1)][(SIZE2)])
#define FVV_DEFINE_2D_STATIC_ARR_SETTER(                           \
    STRUCT, ATTRIB, SIZE1, SIZE2)                                  \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB[(SIZE1)][(SIZE2)])            \
  {                                                                \
    if (!self)                                                     \
      return FVV_RET_UNINITIALIZED;                                \
    memcpy(self->ATTRIB, ATTRIB, sizeof(self->ATTRIB));            \
    return FVV_RET_SUCCESS;                                        \
  }

#define FVV_DECLARE_3D_STATIC_ARR_SETTER_PTR( \
    STRUCT, ATTRIB, SIZE1, SIZE2, SIZE3)      \
  uint64_t ATTRIB[(SIZE1)][(SIZE2)][(SIZE3)]; \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,    \
                            uint64_t ATTRIB[(SIZE1)][(SIZE2)][(SIZE3)])
#define FVV_DECLARE_3D_STATIC_ARR_SETTER(                          \
    STRUCT, ATTRIB, SIZE1, SIZE2, SIZE3)                           \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB[(SIZE1)][(SIZE2)][(SIZE3)])
#define FVV_DEFINE_3D_STATIC_ARR_SETTER(                           \
    STRUCT, ATTRIB, SIZE1, SIZE2, SIZE3)                           \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB[(SIZE1)][(SIZE2)][(SIZE3)])   \
  {                                                                \
    if (!self)                                                     \
      return FVV_RET_UNINITIALIZED;                                \
    memcpy(self->ATTRIB, ATTRIB, sizeof(self->ATTRIB));            \
    return FVV_RET_SUCCESS;                                        \
  }

#define FVV_DECLARE_SCALAR_SETTER_PTR(STRUCT, ATTRIB) \
  uint64_t ATTRIB;                                    \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,            \
                            uint64_t ATTRIB)
#define FVV_DECLARE_SCALAR_SETTER(STRUCT, ATTRIB)                                \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self, \
                                                                  uint64_t ATTRIB)
#define FVV_DEFINE_SCALAR_SETTER(STRUCT, ATTRIB)                                   \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self,   \
                                                                  uint64_t ATTRIB) \
  {                                                                                \
    if (!self)                                                                     \
    {                                                                              \
      return FVV_RET_UNINITIALIZED;                                                \
    }                                                                              \
    self->ATTRIB = ATTRIB;                                                         \
    return FVV_RET_SUCCESS;                                                        \
  }

#define FVV_DECLARE_OBJ_SETTER_PTR(STRUCT, ATTRIB, TYPE) \
  TYPE *ATTRIB;                                          \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self,               \
                            TYPE * ATTRIB)
#define FVV_DECLARE_OBJ_SETTER(STRUCT, ATTRIB, TYPE)                             \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self, \
                                                                  TYPE * ATTRIB)
#define FVV_DEFINE_OBJ_SETTER(STRUCT, ATTRIB, TYPE)                              \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(STRUCT * self, \
                                                                  TYPE * ATTRIB) \
  {                                                                              \
    if (!self)                                                                   \
    {                                                                            \
      return FVV_RET_UNINITIALIZED;                                              \
    }                                                                            \
    self->ATTRIB->copy_from(self->ATTRIB, ATTRIB);                               \
    return FVV_RET_SUCCESS;                                                      \
  }
#define FVV_DESTROY_OBJ(STRUCT, ATTRIB, TYPE)                     \
  if (self->ATTRIB)                                               \
  {                                                               \
    FVV_EXPAND_CONCAT(FVV_STRIP_T(TYPE), _destroy)(self->ATTRIB); \
    free(self->ATTRIB);                                           \
  }

#endif
