#ifndef FVV_DEFS_H
#define FVV_DEFS_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct fvv_bitstream_t           fvv_bitstream_t;
typedef struct fvv_process_t             fvv_process_t;
typedef struct fvv_semantic_t            fvv_semantic_t;
typedef struct fvv_uint128_t             fvv_uint128_t;
typedef uint16_t                         fvv_ret_t;

typedef struct fvv_v3c_unit_t            fvv_v3c_unit_t;
typedef struct fvv_v3c_unit_header_t     fvv_v3c_unit_header_t;
typedef struct fvv_v3c_unit_payload_t    fvv_v3c_unit_payload_t;
typedef struct fvv_v3c_parameter_set_t   fvv_v3c_parameter_set_t;
typedef struct fvv_atlas_sub_bitstream_t fvv_atlas_sub_bitstream_t;
typedef struct fvv_video_sub_bitstream_t fvv_video_sub_bitstream_t;
typedef struct fvv_sample_stream_nal_header_t
    fvv_sample_stream_nal_header_t;
typedef struct fvv_sample_stream_nal_unit_t
                                        fvv_sample_stream_nal_unit_t;
typedef struct fvv_byte_alignment_t     fvv_byte_alignment_t;
typedef struct fvv_profile_tier_level_t fvv_profile_tier_level_t;
typedef struct fvv_occupancy_information_t
                                          fvv_occupancy_information_t;
typedef struct fvv_geometry_information_t fvv_geometry_information_t;
typedef struct fvv_attribute_information_t
    fvv_attribute_information_t;
typedef struct fvv_profile_toolset_constraints_information_t
    fvv_profile_toolset_constraints_information_t;
typedef struct fvv_nal_unit_t        fvv_nal_unit_t;
typedef struct fvv_nal_unit_header_t fvv_nal_unit_header_t;
typedef struct fvv_atlas_sequence_parameter_set_rbsp_t
    fvv_atlas_sequence_parameter_set_rbsp_t;
typedef struct fvv_asps_plr_information_t fvv_asps_plr_information_t;
typedef struct fvv_atlas_frame_parameter_set_rbsp_t
    fvv_atlas_frame_parameter_set_rbsp_t;
typedef struct fvv_atlas_frame_tile_information_t
    fvv_atlas_frame_tile_information_t;
typedef struct fvv_atlas_adaptation_parameter_set_rbsp_t
    fvv_atlas_adaptation_parameter_set_rbsp_t;
typedef struct fvv_sei_rbsp_t fvv_sei_rbsp_t;
typedef struct fvv_access_unit_delimiter_rbsp_t
    fvv_access_unit_delimiter_rbsp_t;
typedef struct fvv_end_of_sequence_rbsp_t fvv_end_of_sequence_rbsp_t;
typedef struct fvv_end_of_atlas_sub_bitstream_rbsp_t
    fvv_end_of_atlas_sub_bitstream_rbsp_t;
typedef struct fvv_filler_data_rbsp_t fvv_filler_data_rbsp_t;
typedef struct fvv_atlas_tile_layer_rbsp_t
                                          fvv_atlas_tile_layer_rbsp_t;
typedef struct fvv_rbsp_trailing_bits_t   fvv_rbsp_trailing_bits_t;
typedef struct fvv_atlas_tile_header_t    fvv_atlas_tile_header_t;
typedef struct fvv_ref_list_struct_t      fvv_ref_list_struct_t;
typedef struct fvv_vui_parameters_t       fvv_vui_parameters_t;
typedef struct fvv_asps_vpcc_extension_t  fvv_asps_vpcc_extension_t;
typedef struct fvv_aaps_vpcc_extension_t  fvv_aaps_vpcc_extension_t;
typedef struct fvv_sei_message_t          fvv_sei_message_t;
typedef struct fvv_atlas_tile_data_unit_t fvv_atlas_tile_data_unit_t;
typedef struct fvv_aaps_vpcc_extension_t  fvv_aaps_vpcc_extension_t;
typedef struct fvv_atlas_camera_parameters_t
    fvv_atlas_camera_parameters_t;
typedef struct fvv_patch_information_data_t
                                     fvv_patch_information_data_t;
typedef struct fvv_patch_data_unit_t fvv_patch_data_unit_t;
typedef struct fvv_skip_patch_data_unit_t fvv_skip_patch_data_unit_t;
typedef struct fvv_merge_patch_data_unit_t
    fvv_merge_patch_data_unit_t;
typedef struct fvv_inter_patch_data_unit_t
                                         fvv_inter_patch_data_unit_t;
typedef struct fvv_raw_patch_data_unit_t fvv_raw_patch_data_unit_t;
typedef struct fvv_eom_patch_data_unit_t fvv_eom_patch_data_unit_t;
typedef struct fvv_plr_data_t            fvv_plr_data_t;
typedef struct fvv_sei_message_t         fvv_sei_message_t;
typedef struct fvv_sei_payload_t         fvv_sei_payload_t;
typedef struct fvv_hrd_parameters_t      fvv_hrd_parameters_t;
typedef struct fvv_max_coded_video_resolution_t
    fvv_max_coded_video_resolution_t;
typedef struct fvv_coordinate_system_parameters_t
    fvv_coordinate_system_parameters_t;
typedef struct fvv_hrd_sub_layer_parameters_t
                                      fvv_hrd_sub_layer_parameters_t;
typedef struct fvv_buffering_period_t fvv_buffering_period_t;
typedef struct fvv_atlas_frame_timing_t fvv_atlas_frame_timing_t;
typedef struct fvv_filler_payload_t     fvv_filler_payload_t;
typedef struct fvv_user_data_registered_itu_t_t35_t
    fvv_user_data_registered_itu_t_t35_t;
typedef struct fvv_user_data_unregistered_t
                                    fvv_user_data_unregistered_t;
typedef struct fvv_recovery_point_t fvv_recovery_point_t;
typedef struct fvv_no_display_t     fvv_no_display_t;
typedef struct fvv_time_code_t      fvv_time_code_t;
typedef struct fvv_sei_manifest_t   fvv_sei_manifest_t;
typedef struct fvv_sei_prefix_indication_t
    fvv_sei_prefix_indication_t;
typedef struct fvv_active_sub_bitstreams_t
    fvv_active_sub_bitstreams_t;
typedef struct fvv_component_codec_mapping_t
    fvv_component_codec_mapping_t;
typedef struct fvv_scene_object_information_t
    fvv_scene_object_information_t;
typedef struct fvv_object_label_information_t
                                       fvv_object_label_information_t;
typedef struct fvv_patch_information_t fvv_patch_information_t;
typedef struct fvv_volumetric_rectangle_information_t
    fvv_volumetric_rectangle_information_t;
typedef struct fvv_atlas_object_association_t
    fvv_atlas_object_association_t;
typedef struct fvv_viewport_camera_parameters_t
    fvv_viewport_camera_parameters_t;
typedef struct fvv_viewport_position_t fvv_viewport_position_t;
typedef struct fvv_attribute_transformation_params_t
    fvv_attribute_transformation_params_t;
typedef struct fvv_occupancy_synthesis_t fvv_occupancy_synthesis_t;
typedef struct fvv_geometry_smoothing_t  fvv_geometry_smoothing_t;
typedef struct fvv_attribute_smoothing_t fvv_attribute_smoothing_t;
typedef struct fvv_decoded_atlas_information_hash_t
    fvv_decoded_atlas_information_hash_t;
typedef struct fvv_reserved_sei_message_t fvv_reserved_sei_message_t;

// processes
typedef struct fvv_tile_partition_scanning_t
    fvv_tile_partition_scanning_t;

#define FVV_CONCAT(a, b)                    a##b
#define FVV_EXPAND_CONCAT(a, b)             FVV_CONCAT(a, b)

#define FVV_TYPE(TYPE)                      FVV_EXPAND_CONCAT(TYPE_NAME_, TYPE)
#define FVV_STRIP_T(TYPE)                   FVV_EXPAND_CONCAT(fvv_, FVV_TYPE(TYPE))

#define TYPE_NAME_fvv_bitstream_t           bitstream
#define TYPE_NAME_fvv_v3c_unit_t            v3c_unit
#define TYPE_NAME_fvv_v3c_unit_header_t     v3c_unit_header
#define TYPE_NAME_fvv_v3c_unit_payload_t    v3c_unit_payload
#define TYPE_NAME_fvv_v3c_parameter_set_t   v3c_parameter_set
#define TYPE_NAME_fvv_atlas_sub_bitstream_t atlas_sub_bitstream
#define TYPE_NAME_fvv_video_sub_bitstream_t video_sub_bitstream
#define TYPE_NAME_fvv_sample_stream_nal_header_t \
  sample_stream_nal_header
#define TYPE_NAME_fvv_sample_stream_nal_unit_t sample_stream_nal_unit
#define TYPE_NAME_fvv_byte_alignment_t         byte_alignment
#define TYPE_NAME_fvv_profile_tier_level_t     profile_tier_level
#define TYPE_NAME_fvv_occupancy_information_t  occupancy_information
#define TYPE_NAME_fvv_geometry_information_t   geometry_information
#define TYPE_NAME_fvv_attribute_information_t  attribute_information
#define TYPE_NAME_fvv_profile_toolset_constraints_information_t \
  profile_toolset_constraints_information
#define TYPE_NAME_fvv_nal_unit_t        nal_unit
#define TYPE_NAME_fvv_nal_unit_header_t nal_unit_header
#define TYPE_NAME_fvv_atlas_sequence_parameter_set_rbsp_t \
  atlas_sequence_parameter_set_rbsp
#define TYPE_NAME_fvv_asps_plr_information_t asps_plr_information
#define TYPE_NAME_fvv_atlas_frame_parameter_set_rbsp_t \
  atlas_frame_parameter_set_rbsp
#define TYPE_NAME_fvv_atlas_frame_tile_information_t \
  atlas_frame_tile_information
#define TYPE_NAME_fvv_atlas_adaptation_parameter_set_rbsp_t \
  atlas_adaptation_parameter_set_rbsp
#define TYPE_NAME_fvv_sei_rbsp_t sei_rbsp
#define TYPE_NAME_fvv_access_unit_delimiter_rbsp_t \
  access_unit_delimiter_rbsp
#define TYPE_NAME_fvv_end_of_sequence_rbsp_t end_of_sequence_rbsp
#define TYPE_NAME_fvv_end_of_atlas_sub_bitstream_rbsp_t \
  end_of_atlas_sub_bitstream_rbsp
#define TYPE_NAME_fvv_filler_data_rbsp_t      filler_data_rbsp
#define TYPE_NAME_fvv_atlas_tile_layer_rbsp_t atlas_tile_layer_rbsp
#define TYPE_NAME_fvv_rbsp_trailing_bits_t    rbsp_trailing_bits
#define TYPE_NAME_fvv_atlas_tile_header_t     atlas_tile_header
#define TYPE_NAME_fvv_ref_list_struct_t       ref_list_struct
#define TYPE_NAME_fvv_vui_parameters_t        vui_parameters
#define TYPE_NAME_fvv_asps_vpcc_extension_t   asps_vpcc_extension
#define TYPE_NAME_fvv_aaps_vpcc_extension_t   aaps_vpcc_extension
#define TYPE_NAME_fvv_sei_message_t           sei_message
#define TYPE_NAME_fvv_atlas_tile_data_unit_t  atlas_tile_data_unit
#define TYPE_NAME_fvv_atlas_camera_parameters_t \
  atlas_camera_parameters
#define TYPE_NAME_fvv_patch_information_data_t patch_information_data
#define TYPE_NAME_fvv_patch_data_unit_t        patch_data_unit
#define TYPE_NAME_fvv_skip_patch_data_unit_t   skip_patch_data_unit
#define TYPE_NAME_fvv_merge_patch_data_unit_t  merge_patch_data_unit
#define TYPE_NAME_fvv_inter_patch_data_unit_t  inter_patch_data_unit
#define TYPE_NAME_fvv_raw_patch_data_unit_t    raw_patch_data_unit
#define TYPE_NAME_fvv_eom_patch_data_unit_t    eom_patch_data_unit
#define TYPE_NAME_fvv_plr_data_t               plr_data
#define TYPE_NAME_fvv_sei_message_t            sei_message
#define TYPE_NAME_fvv_sei_payload_t            sei_payload
#define TYPE_NAME_fvv_hrd_parameters_t         hrd_parameters
#define TYPE_NAME_fvv_max_coded_video_resolution_t \
  max_coded_video_resolution
#define TYPE_NAME_fvv_coordinate_system_parameters_t \
  coordinate_system_parameters
#define TYPE_NAME_fvv_hrd_sub_layer_parameters_t \
  hrd_sub_layer_parameters
#define TYPE_NAME_fvv_buffering_period_t   buffering_period
#define TYPE_NAME_fvv_atlas_frame_timing_t atlas_frame_timing
#define TYPE_NAME_fvv_filler_payload_t     filler_payload
#define TYPE_NAME_fvv_user_data_registered_itu_t_t35_t \
  user_data_registered_itu_t_t35
#define TYPE_NAME_fvv_user_data_unregistered_t user_data_unregistered
#define TYPE_NAME_fvv_recovery_point_t         recovery_point
#define TYPE_NAME_fvv_no_display_t             no_display
#define TYPE_NAME_fvv_time_code_t              time_code
#define TYPE_NAME_fvv_sei_manifest_t           sei_manifest
#define TYPE_NAME_fvv_sei_prefix_indication_t  sei_prefix_indication
#define TYPE_NAME_fvv_active_sub_bitstreams_t  active_sub_bitstreams
#define TYPE_NAME_fvv_component_codec_mapping_t \
  component_codec_mapping
#define TYPE_NAME_fvv_scene_object_information_t \
  scene_object_information
#define TYPE_NAME_fvv_object_label_information_t \
  object_label_information
#define TYPE_NAME_fvv_patch_information_t patch_information
#define TYPE_NAME_fvv_volumetric_rectangle_information_t \
  volumetric_rectangle_information
#define TYPE_NAME_fvv_atlas_object_association_t \
  atlas_object_association
#define TYPE_NAME_fvv_viewport_camera_parameters_t \
  viewport_camera_parameters
#define TYPE_NAME_fvv_viewport_position_t viewport_position
#define TYPE_NAME_fvv_attribute_transformation_params_t \
  attribute_transformation_params
#define TYPE_NAME_fvv_occupancy_synthesis_t occupancy_synthesis
#define TYPE_NAME_fvv_geometry_smoothing_t  geometry_smoothing
#define TYPE_NAME_fvv_attribute_smoothing_t attribute_smoothing
#define TYPE_NAME_fvv_decoded_atlas_information_hash_t \
  decoded_atlas_information_hash
#define TYPE_NAME_fvv_reserved_sei_message_t reserved_sei_message
// processes
#define TYPE_NAME_fvv_tile_partition_scanning_t \
  tile_partition_scanning

#define FVV_RET_SUCCESS               0x0000
#define FVV_RET_FAIL                  0x0001
#define FVV_RET_UNINITIALIZED         0x0002
#define FVV_RET_UNSUPPORT             0x0003
#define FVV_RET_ILLEGAL_MEMORY_ACCESS 0x0004

#define FVV_FAILED(x)                 ((x) != FVV_RET_SUCCESS)
#define FVV_SUCCEEDED(x)              ((x) == FVV_RET_SUCCESS)

typedef uint8_t fvv_bool_t;

#define FVV_FALSE         0x00
#define FVV_TRUE          0x01

#define FVV_NULL          ((void *)0)

#define FVV_BITS_PER_BYTE 0x08

#define FVV_SET_SETTER_PTR(STRUCT, ATTRIB, ...) \
  self->set_##ATTRIB =                          \
      FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)

#define FVV_DECLARE_4D_ARR_SETTER_PTR(STRUCT, ATTRIB) \
  uint64_t ****ATTRIB;                                \
  uint64_t     ATTRIB##_size[4];                      \
  fvv_ret_t (*set_##ATTRIB)(                          \
      STRUCT * self, uint64_t ****ATTRIB, uint64_t ATTRIB##_size[4])
#define FVV_DECLARE_4D_ARR_SETTER(STRUCT, ATTRIB)                  \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ****ATTRIB, uint64_t ATTRIB##_size[4])
#define FVV_DEFINE_4D_ARR_SETTER(STRUCT, ATTRIB)                     \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(   \
      STRUCT * self, uint64_t ****ATTRIB, uint64_t ATTRIB##_size[4]) \
  {                                                                  \
    if (!self)                                                       \
    {                                                                \
      return FVV_RET_UNINITIALIZED;                                  \
    }                                                                \
    if (self->ATTRIB)                                                \
    {                                                                \
      for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)          \
      {                                                              \
        for (uint64_t j = 0; j < self->ATTRIB##_size[1]; j++)        \
        {                                                            \
          for (uint64_t k = 0; k < self->ATTRIB##_size[2]; k++)      \
          {                                                          \
            free(self->ATTRIB[i][j][k]);                             \
          }                                                          \
          free(self->ATTRIB[i][j]);                                  \
        }                                                            \
        free(self->ATTRIB[i]);                                       \
      }                                                              \
      free(self->ATTRIB);                                            \
      self->ATTRIB##_size[0] = 0;                                    \
      self->ATTRIB##_size[1] = 0;                                    \
      self->ATTRIB##_size[2] = 0;                                    \
      self->ATTRIB##_size[3] = 0;                                    \
    }                                                                \
    self->ATTRIB = (uint64_t ****)malloc(sizeof(uint64_t ***) *      \
                                         ATTRIB##_size[0]);          \
    for (uint64_t i = 0; i < ATTRIB##_size[0]; i++)                  \
    {                                                                \
      self->ATTRIB[i] = (uint64_t ***)malloc(sizeof(uint64_t **) *   \
                                             ATTRIB##_size[1]);      \
      for (uint64_t j = 0; j < ATTRIB##_size[1]; j++)                \
      {                                                              \
        self->ATTRIB[i][j] = (uint64_t **)malloc(                    \
            sizeof(uint64_t *) * ATTRIB##_size[2]);                  \
        for (uint64_t k = 0; k < ATTRIB##_size[2]; k++)              \
        {                                                            \
          self->ATTRIB[i][j][k] = (uint64_t *)malloc(                \
              sizeof(uint64_t) * ATTRIB##_size[3]);                  \
          memcpy(self->ATTRIB[i][j][k],                              \
                 ATTRIB[i][j][k],                                    \
                 sizeof(uint64_t) * ATTRIB##_size[3]);               \
        }                                                            \
      }                                                              \
    }                                                                \
    self->ATTRIB##_size[0] = ATTRIB##_size[0];                       \
    self->ATTRIB##_size[1] = ATTRIB##_size[1];                       \
    self->ATTRIB##_size[2] = ATTRIB##_size[2];                       \
    self->ATTRIB##_size[3] = ATTRIB##_size[3];                       \
    return FVV_RET_SUCCESS;                                          \
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
  fvv_ret_t (*set_##ATTRIB)(                          \
      STRUCT * self, uint64_t ***ATTRIB, uint64_t ATTRIB##_size[3])
#define FVV_DECLARE_3D_ARR_SETTER(STRUCT, ATTRIB)                  \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ***ATTRIB, uint64_t ATTRIB##_size[3])
#define FVV_DEFINE_3D_ARR_SETTER(STRUCT, ATTRIB)                     \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(   \
      STRUCT * self, uint64_t ***ATTRIB, uint64_t ATTRIB##_size[3])  \
  {                                                                  \
    if (!self)                                                       \
    {                                                                \
      return FVV_RET_UNINITIALIZED;                                  \
    }                                                                \
    if (self->ATTRIB)                                                \
    {                                                                \
      for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)          \
      {                                                              \
        for (uint64_t j = 0; j < self->ATTRIB##_size[1]; j++)        \
        {                                                            \
          free(self->ATTRIB[i][j]);                                  \
        }                                                            \
        free(self->ATTRIB[i]);                                       \
      }                                                              \
      free(self->ATTRIB);                                            \
      self->ATTRIB##_size[0] = 0;                                    \
      self->ATTRIB##_size[1] = 0;                                    \
      self->ATTRIB##_size[2] = 0;                                    \
    }                                                                \
    self->ATTRIB = (uint64_t ***)malloc(sizeof(uint64_t **) *        \
                                        ATTRIB##_size[0]);           \
    for (uint64_t i = 0; i < ATTRIB##_size[0]; i++)                  \
    {                                                                \
      self->ATTRIB[i] = (uint64_t **)malloc(sizeof(uint64_t *) *     \
                                            ATTRIB##_size[1]);       \
      for (uint64_t j = 0; j < ATTRIB##_size[1]; j++)                \
      {                                                              \
        self->ATTRIB[i][j] =                                         \
            (uint64_t *)malloc(sizeof(uint64_t) * ATTRIB##_size[2]); \
        memcpy(self->ATTRIB[i][j],                                   \
               ATTRIB[i][j],                                         \
               sizeof(uint64_t) * ATTRIB##_size[2]);                 \
      }                                                              \
    }                                                                \
    self->ATTRIB##_size[0] = ATTRIB##_size[0];                       \
    self->ATTRIB##_size[1] = ATTRIB##_size[1];                       \
    self->ATTRIB##_size[2] = ATTRIB##_size[2];                       \
    return FVV_RET_SUCCESS;                                          \
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
  fvv_ret_t (*set_##ATTRIB)(                          \
      STRUCT * self, uint64_t **ATTRIB, uint64_t ATTRIB##_size[2])
#define FVV_DECLARE_2D_ARR_SETTER(STRUCT, ATTRIB)                  \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t **ATTRIB, uint64_t ATTRIB##_size[2])
#define FVV_DEFINE_2D_ARR_SETTER(STRUCT, ATTRIB)                    \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(  \
      STRUCT * self, uint64_t **ATTRIB, uint64_t ATTRIB##_size[2])  \
  {                                                                 \
    if (!self)                                                      \
    {                                                               \
      return FVV_RET_UNINITIALIZED;                                 \
    }                                                               \
    if (self->ATTRIB)                                               \
    {                                                               \
      for (uint64_t i = 0; i < self->ATTRIB##_size[0]; i++)         \
      {                                                             \
        free(self->ATTRIB[i]);                                      \
      }                                                             \
      free(self->ATTRIB);                                           \
      self->ATTRIB##_size[0] = 0;                                   \
      self->ATTRIB##_size[1] = 0;                                   \
    }                                                               \
    self->ATTRIB =                                                  \
        (uint64_t **)malloc(sizeof(uint64_t *) * ATTRIB##_size[0]); \
    for (uint64_t i = 0; i < ATTRIB##_size[0]; i++)                 \
    {                                                               \
      memcpy(self->ATTRIB[i],                                       \
             ATTRIB[i],                                             \
             sizeof(uint64_t) * ATTRIB##_size[1]);                  \
    }                                                               \
    self->ATTRIB##_size[0] = ATTRIB##_size[0];                      \
    self->ATTRIB##_size[1] = ATTRIB##_size[1];                      \
    return FVV_RET_SUCCESS;                                         \
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
  fvv_ret_t (*set_##ATTRIB)(                          \
      STRUCT * self, uint64_t *ATTRIB, uint64_t ATTRIB##_size)
#define FVV_DECLARE_1D_ARR_SETTER(STRUCT, ATTRIB)                  \
  uint64_t *ATTRIB;                                                \
  uint64_t  ATTRIB##_size;                                         \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t *ATTRIB, uint64_t ATTRIB##_size)
#define FVV_DEFINE_1D_ARR_SETTER(STRUCT, ATTRIB)                    \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)(  \
      STRUCT * self, uint64_t *ATTRIB, uint64_t ATTRIB##_size)      \
  {                                                                 \
    if (!self)                                                      \
    {                                                               \
      return FVV_RET_UNINITIALIZED;                                 \
    }                                                               \
    if (self->ATTRIB)                                               \
    {                                                               \
      free(self->ATTRIB);                                           \
      self->ATTRIB##_size = 0;                                      \
    }                                                               \
    self->ATTRIB =                                                  \
        (uint64_t *)malloc(sizeof(uint64_t) * ATTRIB##_size);       \
    memcpy(self->ATTRIB, ATTRIB, sizeof(uint64_t) * ATTRIB##_size); \
    self->ATTRIB##_size = ATTRIB##_size;                            \
    return FVV_RET_SUCCESS;                                         \
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
#define FVV_DECLARE_1D_STATIC_ARR_SETTER(STRUCT, ATTRIB, SIZE)     \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB[(SIZE)])
#define FVV_DEFINE_1D_STATIC_ARR_SETTER(STRUCT, ATTRIB, SIZE)      \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB[(SIZE)])                      \
  {                                                                \
    if (!self)                                                     \
      return FVV_RET_UNINITIALIZED;                                \
    memcpy(self->ATTRIB, ATTRIB, sizeof(self->ATTRIB));            \
    return FVV_RET_SUCCESS;                                        \
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
  fvv_ret_t (*set_##ATTRIB)(                  \
      STRUCT * self, uint64_t ATTRIB[(SIZE1)][(SIZE2)][(SIZE3)])
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
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self, uint64_t ATTRIB)
#define FVV_DECLARE_SCALAR_SETTER(STRUCT, ATTRIB)                  \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB)
#define FVV_DEFINE_SCALAR_SETTER(STRUCT, ATTRIB)                   \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, uint64_t ATTRIB)                              \
  {                                                                \
    if (!self)                                                     \
    {                                                              \
      return FVV_RET_UNINITIALIZED;                                \
    }                                                              \
    self->ATTRIB = ATTRIB;                                         \
    return FVV_RET_SUCCESS;                                        \
  }

#define FVV_DECLARE_OBJ_SETTER_PTR(STRUCT, ATTRIB, TYPE) \
  TYPE *ATTRIB;                                          \
  fvv_ret_t (*set_##ATTRIB)(STRUCT * self, TYPE * ATTRIB)
#define FVV_DECLARE_OBJ_SETTER(STRUCT, ATTRIB, TYPE)               \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, TYPE * ATTRIB)
#define FVV_DEFINE_OBJ_SETTER(STRUCT, ATTRIB, TYPE)                \
  fvv_ret_t FVV_EXPAND_CONCAT(FVV_STRIP_T(STRUCT), _set_##ATTRIB)( \
      STRUCT * self, TYPE * ATTRIB)                                \
  {                                                                \
    if (!self)                                                     \
    {                                                              \
      return FVV_RET_UNINITIALIZED;                                \
    }                                                              \
    self->ATTRIB->copy_from(self->ATTRIB, ATTRIB);                 \
    return FVV_RET_SUCCESS;                                        \
  }
#define FVV_DESTROY_OBJ(STRUCT, ATTRIB, TYPE)                     \
  if (self->ATTRIB)                                               \
  {                                                               \
    FVV_EXPAND_CONCAT(FVV_STRIP_T(TYPE), _destroy)(self->ATTRIB); \
    free(self->ATTRIB);                                           \
  }

// Bit size type
#define FVV_BIT_VARIABLE                                          0x00

// Descriptors type
#define FVV_DESCRIPTOR_B                                          0x00
#define FVV_DESCRIPTOR_F                                          0x01
#define FVV_DESCRIPTOR_FL                                         0x02
#define FVV_DESCRIPTOR_I                                          0x03
#define FVV_DESCRIPTOR_SE                                         0x04
#define FVV_DESCRIPTOR_ST                                         0x05
#define FVV_DESCRIPTOR_U                                          0x06
#define FVV_DESCRIPTOR_UE                                         0x07

// Bit size
#define FVV_BIT_TRAILING_ZERO_8BITS                               8
#define FVV_BIT_VUH_UNIT_TYPE                                     5
#define FVV_BIT_VUH_V3C_PARAMETER_SET_ID                          4
#define FVV_BIT_VUH_ATLAS_ID                                      6
#define FVV_BIT_VUH_ATTRIBUTE_INDEX                               7
#define FVV_BIT_VUH_ATTRIBUTE_PARTITION_INDEX                     5
#define FVV_BIT_VUH_MAP_INDEX                                     4
#define FVV_BIT_VUH_AUXILIARY_VIDEO_FLAG                          1
#define FVV_BIT_VUH_RESERVED_ZERO_12BITS                          12
#define FVV_BIT_VUH_RESERVED_ZERO_17BITS                          17
#define FVV_BIT_VUH_RESERVED_ZERO_27BITS                          27
#define FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ONE                        1
#define FVV_BIT_ALIGNMENT_BIT_EQUAL_TO_ZERO                       1
#define FVV_BIT_VPS_V3C_PARAMETER_SET_ID                          4
#define FVV_BIT_VPS_RESERVED_ZERO_8BITS                           8
#define FVV_BIT_VPS_ATLAS_COUNT_MINUS1                            6
#define FVV_BIT_VPS_ATLAS_ID                                      6
#define FVV_BIT_VPS_FRAME_WIDTH                                   FVV_BIT_VARIABLE
#define FVV_BIT_VPS_FRAME_HEIGHT                                  FVV_BIT_VARIABLE
#define FVV_BIT_VPS_MAP_COUNT_MINUS1                              4
#define FVV_BIT_VPS_MULTIPLE_MAP_STREAMS_PRESENT_FLAG             1
#define FVV_BIT_VPS_MAP_ABSOLUTE_CODING_ENABLED_FLAG              1
#define FVV_BIT_VPS_MAP_PREDICTOR_INDEX_DIFF                      FVV_BIT_VARIABLE
#define FVV_BIT_VPS_AUXILIARY_VIDEO_PRESENT_FLAG                  1
#define FVV_BIT_VPS_OCCUPANCY_VIDEO_PRESENT_FLAG                  1
#define FVV_BIT_VPS_GEOMETRY_VIDEO_PRESENT_FLAG                   1
#define FVV_BIT_VPS_ATTRIBUTE_VIDEO_PRESENT_FLAG                  1
#define FVV_BIT_VPS_EXTENSION_PRESENT_FLAG                        1
#define FVV_BIT_VPS_EXTENSION_8BITS                               8
#define FVV_BIT_VPS_EXTENSION_LENGTH_MINUS1                       FVV_BIT_VARIABLE
#define FVV_BIT_VPS_EXTENSION_DATA_BYTE                           8
#define FVV_BIT_PTL_TIER_FLAG                                     1
#define FVV_BIT_PTL_PROFILE_CODEC_GROUP_IDC                       7
#define FVV_BIT_PTL_PROFILE_TOOLSET_IDC                           8
#define FVV_BIT_PTL_PROFILE_RECONSTRUCTION_IDC                    8
#define FVV_BIT_PTL_RESERVED_ZERO_16BITS                          16
#define FVV_BIT_PTL_RESERVED_0XFFFF_16BITS                        16
#define FVV_BIT_PTL_LEVEL_IDC                                     8
#define FVV_BIT_PTL_NUM_SUB_PROFILES                              6
#define FVV_BIT_PTL_EXTENDED_SUB_PROFILE_FLAG                     1
#define FVV_BIT_PTL_SUB_PROFILE_IDC                               FVV_BIT_VARIABLE
#define FVV_BIT_PTL_TOOL_CONSTRAINTS_PRESENT_FLAG                 1
#define FVV_BIT_SSNH_UNIT_SIZE_PRECISION_BYTES_MINUS1             3
#define FVV_BIT_SSNH_RESERVED_ZERO_5BITS                          5
#define FVV_BIT_SSNU_NAL_UNIT_SIZE                                FVV_BIT_VARIABLE
#define FVV_BIT_OI_OCCUPANCY_CODEC_ID                             8
#define FVV_BIT_OI_LOSSY_OCCUPANCY_COMPRESSION_THRESHOLD          8
#define FVV_BIT_OI_OCCUPANCY_2D_BIT_DEPTH_MINUS1                  5
#define FVV_BIT_OI_OCCUPANCY_MSB_ALIGN_FLAG                       1
#define FVV_BIT_GI_GEOMETRY_CODEC_ID                              8
#define FVV_BIT_GI_GEOMETRY_2D_BIT_DEPTH_MINUS1                   5
#define FVV_BIT_GI_GEOMETRY_MSB_ALIGN_FLAG                        1
#define FVV_BIT_GI_GEOMETRY_3D_COORDINATES_BIT_DEPTH_MINUS1       5
#define FVV_BIT_GI_AUXILIARY_GEOMETRY_CODEC_ID                    8
#define FVV_BIT_AI_ATTRIBUTE_COUNT                                7
#define FVV_BIT_AI_ATTRIBUTE_TYPE_ID                              4
#define FVV_BIT_AI_ATTRIBUTE_CODEC_ID                             8
#define FVV_BIT_AI_AUXILIARY_ATTRIBUTE_CODEC_ID                   8
#define FVV_BIT_AI_ATTRIBUTE_MAP_ABSOLUTE_CODING_PERSISTENCE_FLAG 1
#define FVV_BIT_AI_ATTRIBUTE_DIMENSION_MINUS1                     6
#define FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1          6
#define FVV_BIT_AI_ATTRIBUTE_PARTITION_CHANNELS_MINUS1 \
  FVV_BIT_VARIABLE
#define FVV_BIT_AI_ATTRIBUTE_2D_BIT_DEPTH_MINUS1                 5
#define FVV_BIT_AI_ATTRIBUTE_MSB_ALIGN_FLAG                      1
#define FVV_BIT_PTC_ONE_V3C_FRAME_ONLY_FLAG                      1
#define FVV_BIT_PTC_EOM_CONSTRAINT_FLAG                          1
#define FVV_BIT_PTC_MAX_MAP_COUNT_MINUS1                         4
#define FVV_BIT_PTC_MAX_ATLAS_COUNT_MINUS1                       4
#define FVV_BIT_PTC_MULTIPLE_MAP_STREAMS_CONSTRAINT_FLAG         1
#define FVV_BIT_PTC_PLR_CONSTRAINT_FLAG                          1
#define FVV_BIT_PTC_ATTRIBUTE_MAX_DIMENSION_MINUS1               6
#define FVV_BIT_PTC_ATTRIBUTE_MAX_DIMENSION_PARTITIONS_MINUS1    6
#define FVV_BIT_PTC_NO_EIGHT_ORIENTATIONS_CONSTRAINT_FLAG        1
#define FVV_BIT_PTC_NO_45DEGREE_PROJECTION_PATCH_CONSTRAINT_FLAG 1
#define FVV_BIT_PTC_RESERVED_ZERO_6BITS                          6
#define FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES                8
#define FVV_BIT_PTC_RESERVED_CONSTRAINT_BYTE                     8
#define FVV_BIT_RBSP_BYTE                                        8
#define FVV_BIT_NAL_FORBIDDEN_ZERO_BIT                           1
#define FVV_BIT_NAL_UNIT_TYPE                                    6
#define FVV_BIT_NAL_LAYER_ID                                     6
#define FVV_BIT_NAL_TEMPORAL_ID_PLUS1                            3
#define FVV_BIT_ASPS_ATLAS_SEQUENCE_PARAMETER_SET_ID             FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_FRAME_WIDTH                                 FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_FRAME_HEIGHT                                FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_GEOMETRY_3D_BIT_DEPTH_MINUS1                5
#define FVV_BIT_ASPS_GEOMETRY_2D_BIT_DEPTH_MINUS1                5
#define FVV_BIT_ASPS_LOG2_MAX_ATLAS_FRAME_ORDER_CNT_LSB_MINUS4 \
  FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_MAX_DEC_ATLAS_FRAME_BUFFERING_MINUS1 \
  FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_LONG_TERM_REF_ATLAS_FRAMES_FLAG 1
#define FVV_BIT_ASPS_NUM_REF_ATLAS_FRAME_LISTS_IN_ASPS \
  FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_USE_EIGHT_ORIENTATIONS_FLAG                  1
#define FVV_BIT_ASPS_EXTENDED_PROJECTION_ENABLED_FLAG             1
#define FVV_BIT_ASPS_MAX_NUMBER_PROJECTIONS_MINUS1                FVV_BIT_VARIABLE
#define FVV_BIT_ASPS_NORMAL_AXIS_LIMITS_QUANTIZATION_ENABLED_FLAG 1
#define FVV_BIT_ASPS_NORMAL_AXIS_MAX_DELTA_VALUE_ENABLED_FLAG     1
#define FVV_BIT_ASPS_PATCH_PRECEDENCE_ORDER_FLAG                  1
#define FVV_BIT_ASPS_LOG2_PATCH_PACKING_BLOCK_SIZE                3
#define FVV_BIT_ASPS_PATCH_SIZE_QUANTIZER_PRESENT_FLAG            1
#define FVV_BIT_ASPS_MAP_COUNT_MINUS1                             4
#define FVV_BIT_ASPS_PIXEL_DEINTERLEAVING_ENABLED_FLAG            1
#define FVV_BIT_ASPS_MAP_PIXEL_DEINTERLEAVING_FLAG                1
#define FVV_BIT_ASPS_RAW_PATCH_ENABLED_FLAG                       1
#define FVV_BIT_ASPS_EOM_PATCH_ENABLED_FLAG                       1
#define FVV_BIT_ASPS_EOM_FIX_BIT_COUNT_MINUS1                     4
#define FVV_BIT_ASPS_AUXILIARY_VIDEO_ENABLED_FLAG                 1
#define FVV_BIT_ASPS_PLR_ENABLED_FLAG                             1
#define FVV_BIT_ASPS_VUI_PARAMETERS_PRESENT_FLAG                  1
#define FVV_BIT_ASPS_EXTENSION_PRESENT_FLAG                       1
#define FVV_BIT_ASPS_VPCC_EXTENSION_PRESENT_FLAG                  1
#define FVV_BIT_ASPS_EXTENSION_7BITS                              7
#define FVV_BIT_ASPS_EXTENSION_DATA_FLAG                          1
#define FVV_BIT_PLRI_MAP_PRESENT_FLAG                             1
#define FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1                       4
#define FVV_BIT_PLRI_INTERPOLATE_FLAG                             1
#define FVV_BIT_PLRI_FILLING_FLAG                                 1
#define FVV_BIT_PLRI_MINIMUM_DEPTH                                2
#define FVV_BIT_PLRI_NEIGHBOUR_MINUS1                             2
#define FVV_BIT_PLRI_BLOCK_THRESHOLD_PER_PATCH_MINUS1             6
#define FVV_BIT_AFPS_ATLAS_FRAME_PARAMETER_SET_ID                 FVV_BIT_VARIABLE
#define FVV_BIT_AFPS_ATLAS_SEQUENCE_PARAMETER_SET_ID              FVV_BIT_VARIABLE
#define FVV_BIT_AFPS_OUTPUT_FLAG_PRESENT_FLAG                     1
#define FVV_BIT_AFPS_NUM_REF_IDX_DEFAULT_ACTIVE_MINUS1 \
  FVV_BIT_VARIABLE
#define FVV_BIT_AFPS_ADDITIONAL_LT_AFOC_LSB_LEN                 FVV_BIT_VARIABLE
#define FVV_BIT_AFPS_LOD_MODE_ENABLED_FLAG                      1
#define FVV_BIT_AFPS_RAW_3D_OFFSET_BIT_COUNT_EXPLICIT_MODE_FLAG 1
#define FVV_BIT_AFPS_EXTENSION_PRESENT_FLAG                     1
#define FVV_BIT_AFPS_EXTENSION_8BITS                            8
#define FVV_BIT_AFPS_EXTENSION_DATA_FLAG                        1
#define FVV_BIT_AFTI_SINGLE_TILE_IN_ATLAS_FRAME_FLAG            1
#define FVV_BIT_AFTI_UNIFORM_PARTITION_SPACING_FLAG             1
#define FVV_BIT_AFTI_PARTITION_COLS_WIDTH_MINUS1                FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_PARTITION_ROWS_HEIGHT_MINUS1               FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_NUM_PARTITION_COLUMNS_MINUS1               FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_NUM_PARTITION_ROWS_MINUS1                  FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_PARTITION_COLUMN_WIDTH_MINUS1              FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_PARTITION_ROW_HEIGHT_MINUS1                FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_SINGLE_PARTITION_PER_TILE_FLAG             1
#define FVV_BIT_AFTI_NUM_TILES_IN_ATLAS_FRAME_MINUS1            FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_TOP_LEFT_PARTITION_IDX                     FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_BOTTOM_RIGHT_PARTITION_COLUMN_OFFSET \
  FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_BOTTOM_RIGHT_PARTITION_ROW_OFFSET \
  FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_AUXILIARY_VIDEO_TILE_ROW_WIDTH_MINUS1 \
  FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_AUXILIARY_VIDEO_TILE_ROW_HEIGHT FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_SIGNALLED_TILE_ID_FLAG          1
#define FVV_BIT_AFTI_SIGNALLED_TILE_ID_LENGTH_MINUS1 FVV_BIT_VARIABLE
#define FVV_BIT_AFTI_TILE_ID                         FVV_BIT_VARIABLE
#define FVV_BIT_AAPS_ATLAS_ADAPTATION_PARAMETER_SET_ID \
  FVV_BIT_VARIABLE
#define FVV_BIT_AAPS_EXTENSION_PRESENT_FLAG              1
#define FVV_BIT_AAPS_VPCC_EXTENSION_PRESENT_FLAG         1
#define FVV_BIT_AAPS_EXTENSION_7BITS                     7
#define FVV_BIT_AAPS_EXTENSION_DATA_FLAG                 1
#define FVV_BIT_AFRAME_TYPE                              3
#define FVV_BIT_FF_BYTE                                  8
#define FVV_BIT_RBSP_STOP_ONE_BIT                        1
#define FVV_BIT_RBSP_ALIGNMENT_ZERO_BIT                  1
#define FVV_BIT_ATH_NO_OUTPUT_OF_PRIOR_ATLAS_FRAMES_FLAG 1
#define FVV_BIT_ATH_ATLAS_FRAME_PARAMETER_SET_ID         FVV_BIT_VARIABLE
#define FVV_BIT_ATH_ATLAS_ADAPTATION_PARAMETER_SET_ID    FVV_BIT_VARIABLE
#define FVV_BIT_ATH_ID                                   FVV_BIT_VARIABLE
#define FVV_BIT_ATH_TYPE                                 FVV_BIT_VARIABLE
#define FVV_BIT_ATH_ATLAS_OUTPUT_FLAG                    1
#define FVV_BIT_ATH_ATLAS_FRM_ORDER_CNT_LSB              FVV_BIT_VARIABLE
#define FVV_BIT_ATH_REF_ATLAS_FRAME_LIST_ASPS_FLAG       1
#define FVV_BIT_ATH_REF_ATLAS_FRAME_LIST_IDX             FVV_BIT_VARIABLE
#define FVV_BIT_ATH_ADDITIONAL_AFOC_LSB_PRESENT_FLAG     1
#define FVV_BIT_ATH_ADDITIONAL_AFOC_LSB_VAL              FVV_BIT_VARIABLE
#define FVV_BIT_ATH_POS_MIN_D_QUANTIZER                  5
#define FVV_BIT_ATH_POS_DELTA_MAX_D_QUANTIZER            5
#define FVV_BIT_ATH_PATCH_SIZE_X_INFO_QUANTIZER          3
#define FVV_BIT_ATH_PATCH_SIZE_Y_INFO_QUANTIZER          3
#define FVV_BIT_ATH_RAW_3D_OFFSET_AXIS_BIT_COUNT_MINUS1 \
  FVV_BIT_VARIABLE
#define FVV_BIT_ATH_NUM_REF_IDX_ACTIVE_OVERRIDE_FLAG          1
#define FVV_BIT_ATH_NUM_REF_IDX_ACTIVE_MINUS1                 FVV_BIT_VARIABLE
#define FVV_BIT_NUM_REF_ENTRIES                               FVV_BIT_VARIABLE
#define FVV_BIT_ST_REF_ATLAS_FRAME_FLAG                       1
#define FVV_BIT_ABS_DELTA_AFOC_ST                             FVV_BIT_VARIABLE
#define FVV_BIT_STRAF_ENTRY_SIGN_FLAG                         1
#define FVV_BIT_AFOC_LSB_LT                                   FVV_BIT_VARIABLE
#define FVV_BIT_AAPS_VPCC_CAMERA_PARAMETERS_PRESENT_FLAG      1
#define FVV_BIT_ACP_CAMERA_MODEL                              8
#define FVV_BIT_ACP_SCALE_ENABLED_FLAG                        1
#define FVV_BIT_ACP_OFFSET_ENABLED_FLAG                       1
#define FVV_BIT_ACP_ROTATION_ENABLED_FLAG                     1
#define FVV_BIT_ACP_SCALE_ON_AXIS                             32
#define FVV_BIT_ACP_OFFSET_ON_AXIS                            32
#define FVV_BIT_ACP_ROTATION_QX                               16
#define FVV_BIT_ACP_ROTATION_QY                               16
#define FVV_BIT_ACP_ROTATION_QZ                               16
#define FVV_BIT_ASPS_VPCC_REMOVE_DUPLICATE_POINT_ENABLED_FLAG 1
#define FVV_BIT_ASPS_VPCC_SURFACE_THICKNESS_MINUS1            FVV_BIT_VARIABLE
#define FVV_BIT_ATDU_PATCH_MODE                               FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_REF_INDEX                                FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_OVERRIDE_2D_PARAMS_FLAG                  1
#define FVV_BIT_MPDU_2D_POS_X                                 FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_2D_POS_Y                                 FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_2D_DELTA_SIZE_X                          FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_2D_DELTA_SIZE_Y                          FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_OVERRIDE_3D_PARAMS_FLAG                  1
#define FVV_BIT_MPDU_3D_OFFSET_U                              FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_3D_OFFSET_V                              FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_3D_OFFSET_D                              FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_3D_RANGE_D                               FVV_BIT_VARIABLE
#define FVV_BIT_MPDU_OVERRIDE_PLR_FLAG                        1
#define FVV_BIT_EPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG            1
#define FVV_BIT_EPDU_2D_POS_X                                 FVV_BIT_VARIABLE
#define FVV_BIT_EPDU_2D_POS_Y                                 FVV_BIT_VARIABLE
#define FVV_BIT_EPDU_2D_SIZE_X_MINUS1                         FVV_BIT_VARIABLE
#define FVV_BIT_EPDU_2D_SIZE_Y_MINUS1                         FVV_BIT_VARIABLE
#define FVV_BIT_EPDU_PATCH_COUNT_MINUS1                       FVV_BIT_VARIABLE
#define FVV_BIT_EPDU_ASSOCIATED_PATCH_IDX                     FVV_BIT_VARIABLE
#define FVV_BIT_EPDU_POINTS                                   FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_REF_INDEX                                FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_PATCH_INDEX                              FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_2D_POS_X                                 FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_2D_POS_Y                                 FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_2D_DELTA_SIZE_X                          FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_2D_DELTA_SIZE_Y                          FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_3D_OFFSET_U                              FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_3D_OFFSET_V                              FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_3D_OFFSET_D                              FVV_BIT_VARIABLE
#define FVV_BIT_IPDU_3D_RANGE_D                               FVV_BIT_VARIABLE
#define FVV_BIT_PDU_2D_POS_X                                  FVV_BIT_VARIABLE
#define FVV_BIT_PDU_2D_POS_Y                                  FVV_BIT_VARIABLE
#define FVV_BIT_PDU_2D_SIZE_X_MINUS1                          FVV_BIT_VARIABLE
#define FVV_BIT_PDU_2D_SIZE_Y_MINUS1                          FVV_BIT_VARIABLE
#define FVV_BIT_PDU_LOD_ENABLED_FLAG                          1
#define FVV_BIT_PDU_LOD_SCALE_X_MINUS1                        FVV_BIT_VARIABLE
#define FVV_BIT_PDU_LOD_SCALE_Y_IDC                           FVV_BIT_VARIABLE
#define FVV_BIT_PLRD_LEVEL                                    1
#define FVV_BIT_PLRD_PRESENT_BLOCK_FLAG                       1
#define FVV_BIT_PLRD_PRESENT_FLAG                             1
// TODO: FVV_BIT_PLRD_BLOCK_MODE_MINUS1 is not specified in Draft
#define FVV_BIT_PLRD_BLOCK_MODE_MINUS1                        4
// TODO: FVV_BIT_PLRD_MODE_MINUS1 is not specified in Draft
#define FVV_BIT_PLRD_MODE_MINUS1                              4
#define FVV_BIT_RPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG            1
#define FVV_BIT_RPDU_2D_POS_X                                 FVV_BIT_VARIABLE
#define FVV_BIT_RPDU_2D_POS_Y                                 FVV_BIT_VARIABLE
#define FVV_BIT_RPDU_2D_SIZE_X_MINUS1                         FVV_BIT_VARIABLE
#define FVV_BIT_RPDU_2D_SIZE_Y_MINUS1                         FVV_BIT_VARIABLE
#define FVV_BIT_RPDU_POINTS_MINUS1                            FVV_BIT_VARIABLE
#define FVV_BIT_SM_PAYLOAD_TYPE_BYTE                          8
#define FVV_BIT_SM_PAYLOAD_SIZE_BYTE                          8
#define FVV_BIT_VUI_TIMING_INFO_PRESENT_FLAG                  1
#define FVV_BIT_VUI_NUM_UNITS_IN_TICK                         32
#define FVV_BIT_VUI_TIME_SCALE                                32
#define FVV_BIT_VUI_POC_PROPORTIONAL_TO_TIMING_FLAG           1
#define FVV_BIT_VUI_NUM_TICKS_POC_DIFF_ONE_MINUS1             FVV_BIT_VARIABLE
#define FVV_BIT_VUI_HRD_PARAMETERS_PRESENT_FLAG               1
#define FVV_BIT_VUI_TILE_RESTRICTIONS_PRESENT_FLAG            1
#define FVV_BIT_VUI_FIXED_ATLAS_TILE_STRUCTURE_FLAG           1
#define FVV_BIT_VUI_FIXED_VIDEO_TILE_STRUCTURE_FLAG           1
#define FVV_BIT_VUI_CONSTRAINED_TILES_ACROSS_V3C_COMPONENTS_IDC \
  FVV_BIT_VARIABLE
#define FVV_BIT_VUI_MAX_NUM_TILES_PER_ATLAS_MINUS1            FVV_BIT_VARIABLE
#define FVV_BIT_VUI_MAX_CODED_VIDEO_RESOLUTION_PRESENT_FLAG   1
#define FVV_BIT_VUI_COORDINATE_SYSTEM_PARAMETERS_PRESENT_FLAG 1
#define FVV_BIT_VUI_UNIT_IN_METRES_FLAG                       1
#define FVV_BIT_VUI_DISPLAY_BOX_INFO_PRESENT_FLAG             1
#define FVV_BIT_VUI_ANCHOR_POINT_PRESENT_FLAG                 1
#define FVV_BIT_MCV_OCCUPANCY_RESOLUTION_PRESENT_FLAG         1
#define FVV_BIT_MCV_GEOMETRY_RESOLUTION_PRESENT_FLAG          1
#define FVV_BIT_MCV_ATTRIBUTE_RESOLUTION_PRESENT_FLAG         1
#define FVV_BIT_MCV_OCCUPANCY_WIDTH                           FVV_BIT_VARIABLE
#define FVV_BIT_MCV_OCCUPANCY_HEIGHT                          FVV_BIT_VARIABLE
#define FVV_BIT_MCV_GEOMETRY_WIDTH                            FVV_BIT_VARIABLE
#define FVV_BIT_MCV_GEOMETRY_HEIGHT                           FVV_BIT_VARIABLE
#define FVV_BIT_MCV_ATTRIBUTE_WIDTH                           FVV_BIT_VARIABLE
#define FVV_BIT_MCV_ATTRIBUTE_HEIGHT                          FVV_BIT_VARIABLE
#define FVV_BIT_HRD_CAB_SIZE_VALUE_MINUS1                     FVV_BIT_VARIABLE
#define FVV_BIT_HRD_BIT_RATE_VALUE_MINUS1                     FVV_BIT_VARIABLE
#define FVV_BIT_HRD_CBR_FLAG                                  1
#define FVV_BIT_HRD_NAL_PARAMETERS_PRESENT_FLAG               1
#define FVV_BIT_HRD_ACL_PARAMETERS_PRESENT_FLAG               1
#define FVV_BIT_HRD_BIT_RATE_SCALE                            4
#define FVV_BIT_HRD_CAB_SIZE_SCALE                            4
#define FVV_BIT_HRD_FIXED_ATLAS_RATE_GENERAL_FLAG             1
#define FVV_BIT_HRD_FIXED_ATLAS_RATE_WITHIN_CAS_FLAG          1
#define FVV_BIT_HRD_ELEMENTAL_DURATION_IN_TC_MINUS1           FVV_BIT_VARIABLE
#define FVV_BIT_HRD_LOW_DELAY_FLAG                            1
#define FVV_BIT_HRD_CAB_CNT_MINUS1                            FVV_BIT_VARIABLE
#define FVV_BIT_CSP_FORWARD_AXIS                              2
#define FVV_BIT_CSP_DELTA_LEFT_AXIS_MINUS1                    1
#define FVV_BIT_CSP_FORWARD_SIGN                              1
#define FVV_BIT_CSP_LEFT_SIGN                                 1
#define FVV_BIT_CSP_UP_SIGN                                   1
#define FVV_BIT_ITU_T_T35_COUNTRY_CODE                        8
#define FVV_BIT_ITU_T_T35_COUNTRY_CODE_EXTENSION_BYTE         8
#define FVV_BIT_ITU_T_T35_PAYLOAD_BYTE                        8
#define FVV_BIT_UUID_ISO_IEC_11578                            128
#define FVV_BIT_USER_DATA_PAYLOAD_BYTE                        8
#define FVV_BIT_RECOVERY_AFOC_CNT                             FVV_BIT_VARIABLE
#define FVV_BIT_EXACT_MATCH_FLAG                              1
#define FVV_BIT_BROKEN_LINK_FLAG                              1
#define FVV_BIT_RESERVED_SEI_MESSAGE_PAYLOAD_BYTE             8
#define FVV_BIT_MANIFEST_NUM_SEI_MSG_TYPES                    16
#define FVV_BIT_MANIFEST_SEI_PAYLOAD_TYPE                     16
#define FVV_BIT_MANIFEST_SEI_DESCRIPTION                      8
#define FVV_BIT_PREFIX_SEI_PAYLOAD_TYPE                       16
#define FVV_BIT_NUM_SEI_PREFIX_INDICATIONS_MINUS1             8
#define FVV_BIT_NUM_BITS_IN_PREFIX_INDICATION_MINUS1          16
#define FVV_BIT_SEI_PREFIX_DATA_BIT                           1
#define FVV_BIT_BYTE_ALIGNMENT_BIT_EQUAL_TO_ONE               1
#define FVV_BIT_ASB_ACTIVE_SUB_BITSTREAMS_CANCEL_FLAG         1
#define FVV_BIT_ASB_ACTIVE_ATTRIBUTES_CHANGES_FLAG            1
#define FVV_BIT_ASB_ACTIVE_MAPS_CHANGES_FLAG                  1
#define FVV_BIT_ASB_AUXILIARY_SUB_BITSTREAMS_ACTIVE_FLAG      1
#define FVV_BIT_ASB_ALL_ATTRIBUTES_ACTIVE_FLAG                1
#define FVV_BIT_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1             7
#define FVV_BIT_ASB_ACTIVE_ATTRIBUTE_IDX                      7
#define FVV_BIT_ASB_ALL_MAPS_ACTIVE_FLAG                      1
#define FVV_BIT_ASB_ACTIVE_MAP_COUNT_MINUS1                   4
#define FVV_BIT_ASB_ACTIVE_MAP_IDX                            4
#define FVV_BIT_CCM_COMPONENT_CODEC_CANCEL_FLAG               1
#define FVV_BIT_CCM_CODEC_MAPPINGS_COUNT_MINUS1               8
#define FVV_BIT_CCM_CODEC_ID                                  8
#define FVV_BIT_CCM_CODEC_4CC                                 FVV_BIT_VARIABLE
#define FVV_BIT_SOI_PERSISTENCE_FLAG                          1
#define FVV_BIT_SOI_RESET_FLAG                                1
#define FVV_BIT_SOI_NUM_OBJECT_UPDATES                        FVV_BIT_VARIABLE
#define FVV_BIT_SOI_SIMPLE_OBJECTS_FLAG                       1
#define FVV_BIT_SOI_OBJECT_LABEL_PRESENT_FLAG                 1
#define FVV_BIT_SOI_PRIORITY_PRESENT_FLAG                     1
#define FVV_BIT_SOI_OBJECT_HIDDEN_PRESENT_FLAG                1
#define FVV_BIT_SOI_OBJECT_DEPENDENCY_PRESENT_FLAG            1
#define FVV_BIT_SOI_VISIBILITY_CONES_PRESENT_FLAG             1
#define FVV_BIT_SOI_3D_BOUNDING_BOX_PRESENT_FLAG              1
#define FVV_BIT_SOI_COLLISION_SHAPE_PRESENT_FLAG              1
#define FVV_BIT_SOI_POINT_STYLE_PRESENT_FLAG                  1
#define FVV_BIT_SOI_MATERIAL_ID_PRESENT_FLAG                  1
#define FVV_BIT_SOI_EXTENSION_PRESENT_FLAG                    1
#define FVV_BIT_SOI_3D_BOUNDING_BOX_SCALE_LOG2                5
#define FVV_BIT_SOI_LOG2_MAX_OBJECT_IDX_UPDATED_MINUS1        5
#define FVV_BIT_SOI_LOG2_MAX_OBJECT_DEPENDENCY_IDX            5
#define FVV_BIT_SOI_OBJECT_CANCEL_FLAG                        1
#define FVV_BIT_SOI_OBJECT_LABEL_UPDATE_FLAG                  1
#define FVV_BIT_SOI_OBJECT_LABEL_IDX                          FVV_BIT_VARIABLE
#define FVV_BIT_SOI_PRIORITY_UPDATE_FLAG                      1
#define FVV_BIT_SOI_PRIORITY_VALUE                            4
#define FVV_BIT_SOI_OBJECT_HIDDEN_FLAG                        1
#define FVV_BIT_SOI_OBJECT_DEPENDENCY_UPDATE_FLAG             1
#define FVV_BIT_SOI_OBJECT_NUM_DEPENDENCIES                   4
#define FVV_BIT_SOI_VISIBILITY_CONES_UPDATE_FLAG              1
#define FVV_BIT_SOI_DIRECTION_X                               16
#define FVV_BIT_SOI_DIRECTION_Y                               16
#define FVV_BIT_SOI_DIRECTION_Z                               16
#define FVV_BIT_SOI_ANGLE                                     16
#define FVV_BIT_SOI_3D_BOUNDING_BOX_UPDATE_FLAG               1
#define FVV_BIT_SOI_3D_BOUNDING_BOX_X                         FVV_BIT_VARIABLE
#define FVV_BIT_SOI_3D_BOUNDING_BOX_Y                         FVV_BIT_VARIABLE
#define FVV_BIT_SOI_3D_BOUNDING_BOX_Z                         FVV_BIT_VARIABLE
#define FVV_BIT_SOI_3D_BOUNDING_BOX_SIZE_X                    FVV_BIT_VARIABLE
#define FVV_BIT_SOI_3D_BOUNDING_BOX_SIZE_Y                    FVV_BIT_VARIABLE
#define FVV_BIT_SOI_3D_BOUNDING_BOX_SIZE_Z                    FVV_BIT_VARIABLE
#define FVV_BIT_SOI_COLLISION_SHAPE_UPDATE_FLAG               1
#define FVV_BIT_SOI_COLLISION_SHAPE_ID                        16
#define FVV_BIT_SOI_POINT_STYLE_UPDATE_FLAG                   1
#define FVV_BIT_SOI_POINT_SHAPE_ID                            8
#define FVV_BIT_SOI_POINT_SIZE                                16
#define FVV_BIT_SOI_MATERIAL_ID_UPDATE_FLAG                   1
#define FVV_BIT_SOI_MATERIAL_ID                               16
// Descriptors

#define FVV_DESCRIPTOR_VUH_UNIT_TYPE                          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_V3C_PARAMETER_SET_ID               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_ATLAS_ID                           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_ATTRIBUTE_INDEX                    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_ATTRIBUTE_PARTITION_INDEX          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_MAP_INDEX                          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_AUXILIARY_VIDEO_FLAG               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_RESERVED_ZERO_12BITS               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_RESERVED_ZERO_17BITS               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUH_RESERVED_ZERO_27BITS               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ALIGNMENT_BIT_EQUAL_TO_ONE             FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_ALIGNMENT_BIT_EQUAL_TO_ZERO            FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_VPS_V3C_PARAMETER_SET_ID               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_RESERVED_ZERO_8BITS                FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_ATLAS_COUNT_MINUS1                 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_ATLAS_ID                           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_FRAME_WIDTH                        FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VPS_FRAME_HEIGHT                       FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VPS_MAP_COUNT_MINUS1                   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_MULTIPLE_MAP_STREAMS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_MAP_ABSOLUTE_CODING_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_MAP_PREDICTOR_INDEX_DIFF FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VPS_AUXILIARY_VIDEO_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_OCCUPANCY_VIDEO_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_GEOMETRY_VIDEO_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_ATTRIBUTE_VIDEO_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_EXTENSION_PRESENT_FLAG     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_EXTENSION_8BITS            FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VPS_EXTENSION_LENGTH_MINUS1    FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VPS_EXTENSION_DATA_BYTE        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_TIER_FLAG                  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_PROFILE_CODEC_GROUP_IDC    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_PROFILE_TOOLSET_IDC        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_PROFILE_RECONSTRUCTION_IDC FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_RESERVED_ZERO_16BITS       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_RESERVED_0XFFFF_16BITS     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_LEVEL_IDC                  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_NUM_SUB_PROFILES           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_EXTENDED_SUB_PROFILE_FLAG  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_SUB_PROFILE_IDC            FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTL_TOOL_CONSTRAINTS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SSNH_UNIT_SIZE_PRECISION_BYTES_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SSNH_RESERVED_ZERO_5BITS FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SSNU_NAL_UNIT_SIZE       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_OI_LOSSY_OCCUPANCY_COMPRESSION_THRESHOLD \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_OI_OCCUPANCY_CODEC_ID FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_OI_OCCUPANCY_2D_BIT_DEPTH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_OI_OCCUPANCY_MSB_ALIGN_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_GI_GEOMETRY_CODEC_ID        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_GI_GEOMETRY_2D_BIT_DEPTH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_GI_GEOMETRY_MSB_ALIGN_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_GI_GEOMETRY_3D_COORDINATES_BIT_DEPTH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_GI_AUXILIARY_GEOMETRY_CODEC_ID FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_COUNT             FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_TYPE_ID           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_CODEC_ID          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_AUXILIARY_ATTRIBUTE_CODEC_ID \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_MAP_ABSOLUTE_CODING_PERSISTENCE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_DIMENSION_MINUS1 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_PARTITION_CHANNELS_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_2D_BIT_DEPTH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AI_ATTRIBUTE_MSB_ALIGN_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_ONE_V3C_FRAME_ONLY_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_EOM_CONSTRAINT_FLAG     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_MAX_MAP_COUNT_MINUS1    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_MAX_ATLAS_COUNT_MINUS1  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_MULTIPLE_MAP_STREAMS_CONSTRAINT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_PLR_CONSTRAINT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_ATTRIBUTE_MAX_DIMENSION_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_ATTRIBUTE_MAX_DIMENSION_PARTITIONS_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_NO_EIGHT_ORIENTATIONS_CONSTRAINT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_NO_45DEGREE_PROJECTION_PATCH_CONSTRAINT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_RESERVED_ZERO_6BITS FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_NUM_RESERVED_CONSTRAINT_BYTES \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PTC_RESERVED_CONSTRAINT_BYTE FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RBSP_BYTE                    FVV_DESCRIPTOR_B
#define FVV_DESCRIPTOR_NAL_FORBIDDEN_ZERO_BIT       FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_NAL_UNIT_TYPE                FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_NAL_LAYER_ID                 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_NAL_TEMPORAL_ID_PLUS1        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_ATLAS_SEQUENCE_PARAMETER_SET_ID \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_FRAME_WIDTH  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_FRAME_HEIGHT FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_GEOMETRY_3D_BIT_DEPTH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_GEOMETRY_2D_BIT_DEPTH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_LOG2_MAX_ATLAS_FRAME_ORDER_CNT_LSB_MINUS4 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_MAX_DEC_ATLAS_FRAME_BUFFERING_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_LONG_TERM_REF_ATLAS_FRAMES_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_NUM_REF_ATLAS_FRAME_LISTS_IN_ASPS \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_USE_EIGHT_ORIENTATIONS_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_EXTENDED_PROJECTION_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_MAX_NUMBER_PROJECTIONS_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ASPS_NORMAL_AXIS_LIMITS_QUANTIZATION_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_NORMAL_AXIS_MAX_DELTA_VALUE_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_PATCH_PRECEDENCE_ORDER_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_LOG2_PATCH_PACKING_BLOCK_SIZE \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_PATCH_SIZE_QUANTIZER_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_MAP_COUNT_MINUS1 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_PIXEL_DEINTERLEAVING_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_MAP_PIXEL_DEINTERLEAVING_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_RAW_PATCH_ENABLED_FLAG   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_EOM_PATCH_ENABLED_FLAG   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_EOM_FIX_BIT_COUNT_MINUS1 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_AUXILIARY_VIDEO_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_PLR_ENABLED_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_VUI_PARAMETERS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_EXTENSION_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_VPCC_EXTENSION_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_EXTENSION_7BITS        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_EXTENSION_DATA_FLAG    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_MAP_PRESENT_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_NUMBER_OF_MODES_MINUS1 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_INTERPOLATE_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_FILLING_FLAG           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_MINIMUM_DEPTH          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_NEIGHBOUR_MINUS1       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRI_BLOCK_THRESHOLD_PER_PATCH_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFPS_ATLAS_FRAME_PARAMETER_SET_ID \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFPS_ATLAS_SEQUENCE_PARAMETER_SET_ID \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFPS_OUTPUT_FLAG_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFPS_NUM_REF_IDX_DEFAULT_ACTIVE_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFPS_ADDITIONAL_LT_AFOC_LSB_LEN \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFPS_LOD_MODE_ENABLED_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFPS_RAW_3D_OFFSET_BIT_COUNT_EXPLICIT_MODE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFPS_EXTENSION_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFPS_EXTENSION_8BITS        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFPS_EXTENSION_DATA_FLAG    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFTI_SINGLE_TILE_IN_ATLAS_FRAME_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFTI_UNIFORM_PARTITION_SPACING_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFTI_PARTITION_COLS_WIDTH_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_PARTITION_ROWS_HEIGHT_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_NUM_PARTITION_COLUMNS_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_NUM_PARTITION_ROWS_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_PARTITION_COLUMN_WIDTH_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_PARTITION_ROW_HEIGHT_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_SINGLE_PARTITION_PER_TILE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFTI_NUM_TILES_IN_ATLAS_FRAME_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_TOP_LEFT_PARTITION_IDX FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFTI_BOTTOM_RIGHT_PARTITION_COLUMN_OFFSET \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_BOTTOM_RIGHT_PARTITION_ROW_OFFSET \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_AUXILIARY_VIDEO_TILE_ROW_WIDTH_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_AUXILIARY_VIDEO_TILE_ROW_HEIGHT \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_SIGNALLED_TILE_ID_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFTI_SIGNALLED_TILE_ID_LENGTH_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AFTI_TILE_ID FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AAPS_ATLAS_ADAPTATION_PARAMETER_SET_ID \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_AAPS_EXTENSION_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AAPS_VPCC_EXTENSION_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AAPS_EXTENSION_7BITS     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AAPS_EXTENSION_DATA_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFRAME_TYPE              FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_FF_BYTE                  FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_RBSP_STOP_ONE_BIT        FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_RBSP_ALIGNMENT_ZERO_BIT  FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_ATH_NO_OUTPUT_OF_PRIOR_ATLAS_FRAMES_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_ATLAS_FRAME_PARAMETER_SET_ID \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ATH_ATLAS_ADAPTATION_PARAMETER_SET_ID \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ATH_ID                      FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_TYPE                    FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ATH_ATLAS_OUTPUT_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_ATLAS_FRM_ORDER_CNT_LSB FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_REF_ATLAS_FRAME_LIST_ASPS_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_REF_ATLAS_FRAME_LIST_IDX FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_ADDITIONAL_AFOC_LSB_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_ADDITIONAL_AFOC_LSB_VAL   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_POS_MIN_D_QUANTIZER       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_POS_DELTA_MAX_D_QUANTIZER FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_PATCH_SIZE_X_INFO_QUANTIZER \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_PATCH_SIZE_Y_INFO_QUANTIZER \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_RAW_3D_OFFSET_AXIS_BIT_COUNT_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_NUM_REF_IDX_ACTIVE_OVERRIDE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ATH_NUM_REF_IDX_ACTIVE_MINUS1 FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_NUM_REF_ENTRIES               FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ST_REF_ATLAS_FRAME_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ABS_DELTA_AFOC_ST             FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_STRAF_ENTRY_SIGN_FLAG         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AFOC_LSB_LT                   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_AAPS_VPCC_CAMERA_PARAMETERS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ACP_CAMERA_MODEL          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ACP_SCALE_ENABLED_FLAG    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ACP_OFFSET_ENABLED_FLAG   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ACP_ROTATION_ENABLED_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ACP_SCALE_ON_AXIS         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ACP_OFFSET_ON_AXIS        FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_ACP_ROTATION_QX           FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_ACP_ROTATION_QY           FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_ACP_ROTATION_QZ           FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_ASPS_VPCC_REMOVE_DUPLICATE_POINT_ENABLED_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASPS_VPCC_SURFACE_THICKNESS_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_ATDU_PATCH_MODE              FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MPDU_REF_INDEX               FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MPDU_OVERRIDE_2D_PARAMS_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MPDU_2D_POS_X                FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_2D_POS_Y                FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_2D_DELTA_SIZE_X         FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_2D_DELTA_SIZE_Y         FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_OVERRIDE_3D_PARAMS_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MPDU_3D_OFFSET_U             FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_3D_OFFSET_V             FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_3D_OFFSET_D             FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_3D_RANGE_D              FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_MPDU_OVERRIDE_PLR_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_EPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_EPDU_2D_POS_X             FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_EPDU_2D_POS_Y             FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_EPDU_2D_SIZE_X_MINUS1     FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_EPDU_2D_SIZE_Y_MINUS1     FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_EPDU_PATCH_COUNT_MINUS1   FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_EPDU_ASSOCIATED_PATCH_IDX FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_EPDU_POINTS               FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_IPDU_REF_INDEX            FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_IPDU_PATCH_INDEX          FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_2D_POS_X             FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_2D_POS_Y             FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_2D_DELTA_SIZE_X      FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_2D_DELTA_SIZE_Y      FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_3D_OFFSET_U          FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_3D_OFFSET_V          FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_3D_OFFSET_D          FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_IPDU_3D_RANGE_D           FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_PDU_2D_POS_X              FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_PDU_2D_POS_Y              FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_PDU_2D_SIZE_X_MINUS1      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_PDU_2D_SIZE_Y_MINUS1      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_PDU_3D_OFFSET_U           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_3D_OFFSET_V           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_3D_OFFSET_D           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_3D_RANGE_D            FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_PROJECTION_ID         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_ORIENTATION_INDEX     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_LOD_ENABLED_FLAG      FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PDU_LOD_SCALE_X_MINUS1    FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_PDU_LOD_SCALE_Y_IDC       FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_PLRD_LEVEL                FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRD_PRESENT_BLOCK_FLAG   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRD_PRESENT_FLAG         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRD_BLOCK_MODE_MINUS1    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PLRD_MODE_MINUS1          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RPDU_PATCH_IN_AUXILIARY_VIDEO_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RPDU_2D_POS_X                FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_RPDU_2D_POS_Y                FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_RPDU_2D_SIZE_X_MINUS1        FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_RPDU_2D_SIZE_Y_MINUS1        FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_RPDU_3D_OFFSET_U             FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RPDU_3D_OFFSET_V             FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RPDU_3D_OFFSET_D             FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RPDU_POINTS_MINUS1           FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SM_PAYLOAD_TYPE_BYTE         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SM_PAYLOAD_SIZE_BYTE         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_TIMING_INFO_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_NUM_UNITS_IN_TICK        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_TIME_SCALE               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_POC_PROPORTIONAL_TO_TIMING_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_NUM_TICKS_POC_DIFF_ONE_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VUI_HRD_PARAMETERS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_TILE_RESTRICTIONS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_FIXED_ATLAS_TILE_STRUCTURE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_FIXED_VIDEO_TILE_STRUCTURE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_CONSTRAINED_TILES_ACROSS_V3C_COMPONENTS_IDC \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VUI_MAX_NUM_TILES_PER_ATLAS_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_VUI_MAX_CODED_VIDEO_RESOLUTION_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_COORDINATE_SYSTEM_PARAMETERS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_UNIT_IN_METRES_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_DISPLAY_BOX_INFO_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_DISPLAY_BOX_ORIGIN        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_DISPLAY_BOX_SIZE          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_ANCHOR_POINT_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_VUI_ANCHOR_POINT              FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MCV_OCCUPANCY_RESOLUTION_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MCV_GEOMETRY_RESOLUTION_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MCV_ATTRIBUTE_RESOLUTION_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MCV_OCCUPANCY_WIDTH       FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MCV_OCCUPANCY_HEIGHT      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MCV_GEOMETRY_WIDTH        FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MCV_GEOMETRY_HEIGHT       FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MCV_ATTRIBUTE_WIDTH       FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_MCV_ATTRIBUTE_HEIGHT      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_HRD_BIT_RATE_VALUE_MINUS1 FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_HRD_CAB_SIZE_VALUE_MINUS1 FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_HRD_CBR_FLAG              FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_NAL_PARAMETERS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_ACL_PARAMETERS_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_BIT_RATE_SCALE FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_CAB_SIZE_SCALE FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_FIXED_ATLAS_RATE_GENERAL_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_FIXED_ATLAS_RATE_WITHIN_CAS_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_ELEMENTAL_DURATION_IN_TC_MINUS1 \
  FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_HRD_LOW_DELAY_FLAG         FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_HRD_CAB_CNT_MINUS1         FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_CSP_FORWARD_AXIS           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CSP_DELTA_LEFT_AXIS_MINUS1 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CSP_FORWARD_SIGN           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CSP_LEFT_SIGN              FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CSP_UP_SIGN                FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SP_RESERVED_PAYLOAD_EXTENSION_DATA \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ITU_T_T35_COUNTRY_CODE FVV_DESCRIPTOR_B
#define FVV_DESCRIPTOR_ITU_T_T35_COUNTRY_CODE_EXTENSION_BYTE \
  FVV_DESCRIPTOR_B
#define FVV_DESCRIPTOR_ITU_T_T35_PAYLOAD_BYTE FVV_DESCRIPTOR_B
#define FVV_DESCRIPTOR_UUID_ISO_IEC_11578     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_USER_DATA_PAYLOAD_BYTE FVV_DESCRIPTOR_B
#define FVV_DESCRIPTOR_RECOVERY_AFOC_CNT      FVV_DESCRIPTOR_SE
#define FVV_DESCRIPTOR_EXACT_MATCH_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_BROKEN_LINK_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_RESERVED_SEI_MESSAGE_PAYLOAD_BYTE \
  FVV_DESCRIPTOR_B

#define FVV_DESCRIPTOR_MANIFEST_NUM_SEI_MSG_TYPES FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MANIFEST_SEI_PAYLOAD_TYPE  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_MANIFEST_SEI_DESCRIPTION   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_PREFIX_SEI_PAYLOAD_TYPE    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_NUM_SEI_PREFIX_INDICATIONS_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_NUM_BITS_IN_PREFIX_INDICATION_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SEI_PREFIX_DATA_BIT FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_BYTE_ALIGNMENT_BIT_EQUAL_TO_ONE \
  FVV_DESCRIPTOR_F
#define FVV_DESCRIPTOR_ASB_ACTIVE_SUB_BITSTREAMS_CANCEL_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ACTIVE_ATTRIBUTES_CHANGES_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ACTIVE_MAPS_CHANGES_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_AUXILIARY_SUB_BITSTREAMS_ACTIVE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ALL_ATTRIBUTES_ACTIVE_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ACTIVE_ATTRIBUTE_COUNT_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ACTIVE_ATTRIBUTE_IDX    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ALL_MAPS_ACTIVE_FLAG    FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ACTIVE_MAP_COUNT_MINUS1 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_ASB_ACTIVE_MAP_IDX          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CCM_COMPONENT_CODEC_CANCEL_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CCM_CODEC_MAPPINGS_COUNT_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CCM_CODEC_ID                   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_CCM_CODEC_4CC                  FVV_DESCRIPTOR_ST
#define FVV_DESCRIPTOR_SOI_PERSISTENCE_FLAG           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_RESET_FLAG                 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_NUM_OBJECT_UPDATES         FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_SIMPLE_OBJECTS_FLAG        FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_LABEL_PRESENT_FLAG  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_PRIORITY_PRESENT_FLAG      FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_HIDDEN_PRESENT_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_DEPENDENCY_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_VISIBILITY_CONES_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_COLLISION_SHAPE_PRESENT_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_POINT_STYLE_PRESENT_FLAG   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_MATERIAL_ID_PRESENT_FLAG   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_EXTENSION_PRESENT_FLAG     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SCALE_LOG2 FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_LOG2_MAX_OBJECT_IDX_UPDATED_MINUS1 \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_LOG2_MAX_OBJECT_DEPENDENCY_IDX \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_IDX               FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_CANCEL_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_LABEL_UPDATE_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_LABEL_IDX         FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_PRIORITY_UPDATE_FLAG     FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_PRIORITY_VALUE           FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_HIDDEN_FLAG       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_DEPENDENCY_UPDATE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_NUM_DEPENDENCIES FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_OBJECT_DEPENDENCY_IDX   FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_VISIBILITY_CONES_UPDATE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_DIRECTION_X FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_SOI_DIRECTION_Y FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_SOI_DIRECTION_Z FVV_DESCRIPTOR_I
#define FVV_DESCRIPTOR_SOI_ANGLE       FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_UPDATE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_X      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_Y      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_Z      FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SIZE_X FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SIZE_Y FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SIZE_Z FVV_DESCRIPTOR_UE
#define FVV_DESCRIPTOR_SOI_COLLISION_SHAPE_UPDATE_FLAG \
  FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_COLLISION_SHAPE_ID      FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_POINT_STYLE_UPDATE_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_POINT_SHAPE_ID          FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_POINT_SIZE              FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_MATERIAL_ID_UPDATE_FLAG FVV_DESCRIPTOR_U
#define FVV_DESCRIPTOR_SOI_MATERIAL_ID             FVV_DESCRIPTOR_U

typedef enum
{
  FVV_V3C_VPS  = 0, // V3C parameter set
  FVV_V3C_AD   = 1, // Atlas data
  FVV_V3C_OVD  = 2, // Occupancy video data
  FVV_V3C_GVD  = 3, // Geometry video data
  FVV_V3C_AVD  = 4, // Attribute video data
  FVV_V3C_RSVD = 5  // Reserved, values 5..31
} fvv_vuh_unit_type_e;

typedef enum
{
  FVV_ATTR_TEXTURE      = 0, // Texture
  FVV_ATTR_MATERIAL_ID  = 1, // Material ID
  FVV_ATTR_TRANSPARENCY = 2, // Transparency
  FVV_ATTR_REFLECTANCE  = 3, // Reflectance
  FVV_ATTR_NORMAL       = 4, // Normals
  ATTR_RESERVED         = 5, // Reserved, value 5..14
  ATTR_UNSPECIFIED      = 15 // Unspecified
} fvv_ai_attribute_type_id_e;

typedef enum
{
  // Trailing atlas frame tiles
  FVV_NAL_TRAIL_N         = 0,
  FVV_NAL_TRAIL_R         = 1,
  FVV_NAL_TSA_N           = 2,
  FVV_NAL_TSA_R           = 3,
  FVV_NAL_STSA_N          = 4,
  FVV_NAL_STSA_R          = 5,
  FVV_NAL_RADL_N          = 6,
  FVV_NAL_RADL_R          = 7,
  FVV_NAL_RASL_N          = 8,
  FVV_NAL_RASL_R          = 9,

  // Skipped frames
  FVV_NAL_SKIP_N          = 10,
  FVV_NAL_SKIP_R          = 11,

  // Reserved ACL (non-IRAP)
  FVV_NAL_RSV_ACL_N12     = 12,
  FVV_NAL_RSV_ACL_R13     = 13,
  FVV_NAL_RSV_ACL_N14     = 14,
  FVV_NAL_RSV_ACL_R15     = 15,

  // BLA frames
  FVV_NAL_BLA_W_LP        = 16,
  FVV_NAL_BLA_W_RADL      = 17,
  FVV_NAL_BLA_N_LP        = 18,

  // GBLA frames
  FVV_NAL_GBLA_W_LP       = 19,
  FVV_NAL_GBLA_W_RADL     = 20,
  FVV_NAL_GBLA_N_LP       = 21,

  // IDR & GIDR frames
  FVV_NAL_IDR_W_RADL      = 22,
  FVV_NAL_IDR_N_LP        = 23,
  FVV_NAL_GIDR_W_RADL     = 24,
  FVV_NAL_GIDR_N_LP       = 25,

  // CRA & GCRA frames
  FVV_NAL_CRA             = 26,
  FVV_NAL_GCRA            = 27,

  // Reserved IRAP ACL
  FVV_NAL_RSV_IRAP_ACL_28 = 28,
  FVV_NAL_RSV_IRAP_ACL_29 = 29,

  // Reserved non-IRAP ACL
  FVV_NAL_RSV_ACL_30      = 30,
  FVV_NAL_RSV_ACL_31      = 31,
  FVV_NAL_RSV_ACL_32      = 32,
  FVV_NAL_RSV_ACL_33      = 33,
  FVV_NAL_RSV_ACL_34      = 34,
  FVV_NAL_RSV_ACL_35      = 35,

  // Non-ACL NAL unit types
  FVV_NAL_ASPS            = 36,
  FVV_NAL_AFPS            = 37,
  FVV_NAL_AUD             = 38,
  FVV_NAL_V3C_AUD         = 39,
  FVV_NAL_EOS             = 40,
  FVV_NAL_EOB             = 41,
  FVV_NAL_FD              = 42,
  FVV_NAL_PREFIX_NSEI     = 43,
  FVV_NAL_SUFFIX_NSEI     = 44,
  FVV_NAL_PREFIX_ESEI     = 45,
  FVV_NAL_SUFFIX_ESEI     = 46,
  FVV_NAL_AAPS            = 47,

  // Reserved non-ACL
  FVV_NAL_RSV_NACL_48     = 48,
  FVV_NAL_RSV_NACL_49     = 49,
  FVV_NAL_RSV_NACL_50     = 50,
  FVV_NAL_RSV_NACL_51     = 51,
  FVV_NAL_RSV_NACL_52     = 52,

  // Unspecified
  FVV_NAL_UNSPEC_53       = 53,
  FVV_NAL_UNSPEC_54       = 54,
  FVV_NAL_UNSPEC_55       = 55,
  FVV_NAL_UNSPEC_56       = 56,
  FVV_NAL_UNSPEC_57       = 57,
  FVV_NAL_UNSPEC_58       = 58,
  FVV_NAL_UNSPEC_59       = 59,
  FVV_NAL_UNSPEC_60       = 60,
  FVV_NAL_UNSPEC_61       = 61,
  FVV_NAL_UNSPEC_62       = 62,
  FVV_NAL_UNSPEC_63       = 63
} fvv_nal_unit_type_e;

typedef enum
{
  FVV_P_TILE    = 0,
  FVV_I_TILE    = 1,
  FVV_SKIP_TILE = 2,
  FVV_RESERVED  = 3, // Reserved, values 3..7
} fvv_ath_type_e;

typedef enum
{
  FVV_I_INTRA    = 0, // Non-predicted patch mode
  FVV_I_RAW      = 1, // RAW Point Patch mode
  FVV_I_EOM      = 2, // EOM Point Patch mode
  FVV_I_RESERVED = 3, // Reserved modes for future use by ISO/IEC
  FVV_I_END      = 14 // Patch termination mode
} fvv_atdu_patch_mode_i_tile_e;

typedef enum
{
  FVV_P_SKIP     = 0, // Patch Skip mode
  FVV_P_MERGE    = 1, // Patch Merge mode
  FVV_P_INTER    = 2, // Inter predicted Patch mode
  FVV_P_INTRA    = 3, // Non-predicted Patch mode
  FVV_P_RAW      = 4, // RAW Point Patch mode
  FVV_P_EOM      = 5, // EOM Point Patch mode
  FVV_P_RESERVED = 6, // Reserved modes for future use by ISO/IEC
  FVV_P_END      = 14 // Patch termination mode
} fvv_atdu_patch_mode_p_tile_e;

#endif
