#ifndef FVV_SYNTAX_H
#define FVV_SYNTAX_H

#include <fvv/bitstream.h>
#include <fvv/defs.h>
#include <fvv/semantic.h>

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
typedef struct fvv_v3c_parameter_set_t  fvv_v3c_parameter_set_t;
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
typedef struct fvv_rbsp_trailing_bits_t fvv_rbsp_trailing_bits_t;
typedef struct fvv_atlas_tile_header_t  fvv_atlas_tile_header_t;
typedef struct fvv_ref_list_struct_t    fvv_ref_list_struct_t;

// 8.3.2 V3C unit syntax
// 8.3.2.1 General V3C unit syntax
struct fvv_v3c_unit_t
{
  fvv_bitstream_t        *data;

  fvv_v3c_unit_header_t  *vuh;
  fvv_v3c_unit_payload_t *vup;

  fvv_ret_t (*pack)(fvv_v3c_unit_t *self,
                    uint64_t        numBytesInV3CUnit);

  fvv_ret_t (*copy_from)(fvv_v3c_unit_t *self,
                         fvv_v3c_unit_t *other);

  fvv_ret_t (*set_vuh)(fvv_v3c_unit_t        *self,
                       fvv_v3c_unit_header_t *vuh);
  fvv_ret_t (*set_vup)(fvv_v3c_unit_t         *self,
                       fvv_v3c_unit_payload_t *vup);
};

fvv_ret_t fvv_v3c_unit_init(fvv_v3c_unit_t  *self,
                            fvv_bitstream_t *data);
fvv_ret_t fvv_v3c_unit_destroy(fvv_v3c_unit_t *self);

fvv_ret_t fvv_v3c_unit_pack(fvv_v3c_unit_t *self,
                            uint64_t        numBytesInV3CUnit);

fvv_ret_t fvv_v3c_unit_copy_from(fvv_v3c_unit_t *self,
                                 fvv_v3c_unit_t *other);
fvv_ret_t fvv_v3c_unit_set_vuh(fvv_v3c_unit_t        *self,
                               fvv_v3c_unit_header_t *vuh);
fvv_ret_t fvv_v3c_unit_set_vup(fvv_v3c_unit_t         *self,
                               fvv_v3c_unit_payload_t *vup);

// 8.3.2.2 V3C unit header syntax
struct fvv_v3c_unit_header_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  uint64_t         vuh_unit_type;                 // u(5)
  uint64_t         vuh_v3c_parameter_set_id;      // u(4)
  uint64_t         vuh_atlas_id;                  // u(6)
  uint64_t         vuh_attribute_index;           // u(7)
  uint64_t         vuh_attribute_partition_index; // u(5)
  uint64_t         vuh_map_index;                 // u(4)
  uint64_t         vuh_auxiliary_video_flag;      // u(1)
  uint64_t         vuh_reserved_zero_12bits;      // u(12)
  uint64_t         vuh_reserved_zero_17bits;      // u(17)
  uint64_t         vuh_reserved_zero_27bits;      // u(27)

  fvv_ret_t (*pack)(fvv_v3c_unit_header_t *self);
  fvv_ret_t (*copy_from)(fvv_v3c_unit_header_t *self,
                         fvv_v3c_unit_header_t *other);

  fvv_ret_t (*set_vuh_unit_type)(fvv_v3c_unit_header_t *self,
                                 uint64_t vuh_unit_type);
  fvv_ret_t (*set_vuh_v3c_parameter_set_id)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_v3c_parameter_set_id);
  fvv_ret_t (*set_vuh_atlas_id)(fvv_v3c_unit_header_t *self,
                                uint64_t               vuh_atlas_id);
  fvv_ret_t (*set_vuh_attribute_index)(fvv_v3c_unit_header_t *self,
                                       uint64_t vuh_attribute_index);
  fvv_ret_t (*set_vuh_attribute_partition_index)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_attribute_partition_index);
  fvv_ret_t (*set_vuh_map_index)(fvv_v3c_unit_header_t *self,
                                 uint64_t vuh_map_index);
  fvv_ret_t (*set_vuh_auxiliary_video_flag)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_auxiliary_video_flag);
  fvv_ret_t (*set_vuh_reserved_zero_12bits)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_reserved_zero_12bits);
  fvv_ret_t (*set_vuh_reserved_zero_17bits)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_reserved_zero_17bits);
  fvv_ret_t (*set_vuh_reserved_zero_27bits)(
      fvv_v3c_unit_header_t *self,
      uint64_t               vuh_reserved_zero_27bits);
};

fvv_ret_t fvv_v3c_unit_header_init(fvv_v3c_unit_header_t *self,
                                   fvv_v3c_unit_t        *vu,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_v3c_unit_header_destroy(fvv_v3c_unit_header_t *self);

fvv_ret_t fvv_v3c_unit_header_pack(fvv_v3c_unit_header_t *self);
fvv_ret_t
fvv_v3c_unit_header_copy_from(fvv_v3c_unit_header_t *self,
                              fvv_v3c_unit_header_t *other);

fvv_ret_t
fvv_v3c_unit_header_set_vuh_unit_type(fvv_v3c_unit_header_t *self,
                                      uint64_t vuh_unit_type);
fvv_ret_t fvv_v3c_unit_header_set_vuh_v3c_parameter_set_id(
    fvv_v3c_unit_header_t *self, uint64_t vuh_v3c_parameter_set_id);
fvv_ret_t
fvv_v3c_unit_header_set_vuh_atlas_id(fvv_v3c_unit_header_t *self,
                                     uint64_t vuh_atlas_id);
fvv_ret_t fvv_v3c_unit_header_set_vuh_attribute_index(
    fvv_v3c_unit_header_t *self, uint64_t vuh_attribute_index);
fvv_ret_t fvv_v3c_unit_header_set_vuh_attribute_partition_index(
    fvv_v3c_unit_header_t *self,
    uint64_t               vuh_attribute_partition_index);
fvv_ret_t
fvv_v3c_unit_header_set_vuh_map_index(fvv_v3c_unit_header_t *self,
                                      uint64_t vuh_map_index);
fvv_ret_t fvv_v3c_unit_header_set_vuh_auxiliary_video_flag(
    fvv_v3c_unit_header_t *self, uint64_t vuh_auxiliary_video_flag);
fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_12bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_12bits);
fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_17bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_17bits);
fvv_ret_t fvv_v3c_unit_header_set_vuh_reserved_zero_27bits(
    fvv_v3c_unit_header_t *self, uint64_t vuh_reserved_zero_27bits);

// 8.3.2.3 V3C unit payload syntax
struct fvv_v3c_unit_payload_t
{
  fvv_v3c_unit_t            *vu;
  fvv_bitstream_t           *data;

  fvv_v3c_parameter_set_t   *vps;
  fvv_atlas_sub_bitstream_t *asb;
  fvv_video_sub_bitstream_t *vsb;

  fvv_ret_t (*pack)(fvv_v3c_unit_payload_t *self,
                    uint64_t                numBytesInV3CPayload);
  fvv_ret_t (*copy_from)(fvv_v3c_unit_payload_t *self,
                         fvv_v3c_unit_payload_t *other);
  fvv_ret_t (*set_vps)(fvv_v3c_unit_payload_t  *self,
                       fvv_v3c_parameter_set_t *vps);
  fvv_ret_t (*set_asb)(fvv_v3c_unit_payload_t    *self,
                       fvv_atlas_sub_bitstream_t *asb);
  fvv_ret_t (*set_vsb)(fvv_v3c_unit_payload_t    *self,
                       fvv_video_sub_bitstream_t *vsb);
};

fvv_ret_t fvv_v3c_unit_payload_init(fvv_v3c_unit_payload_t *self,
                                    fvv_v3c_unit_t         *vu,
                                    fvv_bitstream_t        *data);
fvv_ret_t fvv_v3c_unit_payload_destroy(fvv_v3c_unit_payload_t *self);

fvv_ret_t fvv_v3c_unit_payload_pack(fvv_v3c_unit_payload_t *self,
                                    uint64_t numBytesInV3CPayload);
fvv_ret_t
fvv_v3c_unit_payload_copy_from(fvv_v3c_unit_payload_t *self,
                               fvv_v3c_unit_payload_t *other);
fvv_ret_t fvv_v3c_unit_payload_set_vps(fvv_v3c_unit_payload_t  *self,
                                       fvv_v3c_parameter_set_t *vps);
fvv_ret_t
fvv_v3c_unit_payload_set_asb(fvv_v3c_unit_payload_t    *self,
                             fvv_atlas_sub_bitstream_t *asb);
fvv_ret_t
fvv_v3c_unit_payload_set_vsb(fvv_v3c_unit_payload_t    *self,
                             fvv_video_sub_bitstream_t *vsb);

// 8.3.2.4 Atlas sub-bitstream syntax
struct fvv_atlas_sub_bitstream_t
{
  fvv_v3c_unit_t                 *vu;
  fvv_bitstream_t                *data;

  fvv_sample_stream_nal_header_t *ssnh;
  fvv_sample_stream_nal_unit_t   *ssnu;

  fvv_ret_t (*pack)(fvv_atlas_sub_bitstream_t *self,
                    uint64_t                   numBytes);
  fvv_ret_t (*copy_from)(fvv_atlas_sub_bitstream_t *self,
                         fvv_atlas_sub_bitstream_t *other);
  fvv_ret_t (*set_ssnh)(fvv_atlas_sub_bitstream_t      *self,
                        fvv_sample_stream_nal_header_t *ssnh);
  fvv_ret_t (*set_ssnu)(fvv_atlas_sub_bitstream_t    *self,
                        fvv_sample_stream_nal_unit_t *ssnu);
};

fvv_ret_t
fvv_atlas_sub_bitstream_init(fvv_atlas_sub_bitstream_t *self,
                             fvv_v3c_unit_t            *vu,
                             fvv_bitstream_t           *data);
fvv_ret_t
fvv_atlas_sub_bitstream_destroy(fvv_atlas_sub_bitstream_t *self);

fvv_ret_t
fvv_atlas_sub_bitstream_pack(fvv_atlas_sub_bitstream_t *self,
                             uint64_t                   numBytes);

fvv_ret_t
fvv_atlas_sub_bitstream_copy_from(fvv_atlas_sub_bitstream_t *self,
                                  fvv_atlas_sub_bitstream_t *other);
fvv_ret_t fvv_atlas_sub_bitstream_set_ssnh(
    fvv_atlas_sub_bitstream_t      *self,
    fvv_sample_stream_nal_header_t *ssnh);
fvv_ret_t
fvv_atlas_sub_bitstream_set_ssnu(fvv_atlas_sub_bitstream_t    *self,
                                 fvv_sample_stream_nal_unit_t *ssnu);

// D.2 Sample stream NAL unit
// D.2.1 Sample stream NAL header syntax
struct fvv_sample_stream_nal_header_t
{
  fvv_bitstream_t *data;
  fvv_v3c_unit_t  *vu;

  uint64_t         ssnh_unit_size_precision_bytes_minus1; // u(3)
  uint64_t         ssnh_reserved_zero_5bits;              // u(5)

  fvv_ret_t (*pack)(fvv_sample_stream_nal_header_t *self);
  fvv_ret_t (*copy_from)(fvv_sample_stream_nal_header_t *self,
                         fvv_sample_stream_nal_header_t *other);
  fvv_ret_t (*set_ssnh_unit_size_precision_bytes_minus1)(
      fvv_sample_stream_nal_header_t *self,
      uint64_t ssnh_unit_size_precision_bytes_minus1);
  fvv_ret_t (*set_ssnh_reserved_zero_5bits)(
      fvv_sample_stream_nal_header_t *self,
      uint64_t                        ssnh_reserved_zero_5bits);
};
fvv_ret_t fvv_sample_stream_nal_header_init(
    fvv_sample_stream_nal_header_t *self,
    fvv_v3c_unit_t                 *vu,
    fvv_bitstream_t                *data);
fvv_ret_t fvv_sample_stream_nal_header_destroy(
    fvv_sample_stream_nal_header_t *self);

fvv_ret_t fvv_sample_stream_nal_header_pack(
    fvv_sample_stream_nal_header_t *self);
fvv_ret_t fvv_sample_stream_nal_header_copy_from(
    fvv_sample_stream_nal_header_t *self,
    fvv_sample_stream_nal_header_t *other);
fvv_ret_t
fvv_sample_stream_nal_header_set_ssnh_unit_size_precision_bytes_minus1(
    fvv_sample_stream_nal_header_t *self,
    uint64_t ssnh_unit_size_precision_bytes_minus1);
fvv_ret_t fvv_sample_stream_nal_header_set_ssnh_reserved_zero_5bits(
    fvv_sample_stream_nal_header_t *self,
    uint64_t                        ssnh_reserved_zero_5bits);

// D.2.2 Sample stream NAL unit syntax
struct fvv_sample_stream_nal_unit_t
{
  fvv_v3c_unit_t  *vu;
  fvv_bitstream_t *data;

  uint64_t         ssnu_nal_unit_size; // u(v)
  fvv_nal_unit_t  *nu;

  fvv_ret_t (*pack)(fvv_sample_stream_nal_unit_t *self);
  fvv_ret_t (*copy_from)(fvv_sample_stream_nal_unit_t *self,
                         fvv_sample_stream_nal_unit_t *other);
  fvv_ret_t (*set_ssnu_nal_unit_size)(
      fvv_sample_stream_nal_unit_t *self,
      uint64_t                      ssnu_nal_unit_size);
  fvv_ret_t (*set_nu)(fvv_sample_stream_nal_unit_t *self,
                      fvv_nal_unit_t               *nu);
};
fvv_ret_t
fvv_sample_stream_nal_unit_init(fvv_sample_stream_nal_unit_t *self,
                                fvv_v3c_unit_t               *vu,
                                fvv_bitstream_t              *data);
fvv_ret_t fvv_sample_stream_nal_unit_destroy(
    fvv_sample_stream_nal_unit_t *self);

fvv_ret_t
fvv_sample_stream_nal_unit_pack(fvv_sample_stream_nal_unit_t *self);
fvv_ret_t fvv_sample_stream_nal_unit_copy_from(
    fvv_sample_stream_nal_unit_t *self,
    fvv_sample_stream_nal_unit_t *other);
fvv_ret_t fvv_sample_stream_nal_unit_set_ssnu_nal_unit_size(
    fvv_sample_stream_nal_unit_t *self, uint64_t ssnu_nal_unit_size);
fvv_ret_t
fvv_sample_stream_nal_unit_set_nu(fvv_sample_stream_nal_unit_t *self,
                                  fvv_nal_unit_t               *nu);

// 8.3.3 Byte alignment syntax
struct fvv_byte_alignment_t
{
  fvv_bitstream_t *data;

  uint64_t         alignment_bit_equal_to_one;  // f(1)
  uint64_t         alignment_bit_equal_to_zero; // f(1)

  fvv_ret_t (*pack)(fvv_byte_alignment_t *self);
  fvv_ret_t (*copy_from)(fvv_byte_alignment_t *self,
                         fvv_byte_alignment_t *other);
  fvv_ret_t (*set_alignment_bit_equal_to_one)(
      fvv_byte_alignment_t *self,
      uint64_t              alignment_bit_equal_to_one);
  fvv_ret_t (*set_alignment_bit_equal_to_zero)(
      fvv_byte_alignment_t *self,
      uint64_t              alignment_bit_equal_to_zero);
};

fvv_ret_t fvv_byte_alignment_init(fvv_byte_alignment_t *self,
                                  fvv_bitstream_t      *data);
fvv_ret_t fvv_byte_alignment_destroy(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_pack(fvv_byte_alignment_t *self);

fvv_ret_t fvv_byte_alignment_copy_from(fvv_byte_alignment_t *self,
                                       fvv_byte_alignment_t *other);
fvv_ret_t fvv_byte_alignment_set_alignment_bit_equal_to_one(
    fvv_byte_alignment_t *self, uint64_t alignment_bit_equal_to_one);
fvv_ret_t fvv_byte_alignment_set_alignment_bit_equal_to_zero(
    fvv_byte_alignment_t *self,
    uint64_t              alignment_bit_equal_to_zero);

// 8.3.4 V3C parameter set syntax
// 8.3.4.1 General V3C parameter set syntax
struct fvv_v3c_parameter_set_t
{
  fvv_bitstream_t *data;

  uint64_t         vps_v3c_parameter_set_id; // u(4)
  uint64_t         vps_reserved_zero_8bits;  // u(8)
  uint64_t         vps_atlas_count_minus1;   // u(6)
  uint64_t vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) +
                        1];                               // u(6)
  uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID];  // ue(v)
  uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]; // ue(v)
  uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(4)
  uint64_t vps_multiple_map_streams_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_map_absolute_coding_enabled_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]; // u(1)
  uint64_t vps_map_predictor_index_diff
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]; // ue(v)
  uint64_t vps_auxiliary_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_occupancy_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_geometry_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t vps_attribute_video_present_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID];                        // u(1)
  uint64_t                     vps_extension_present_flag;  // u(1)
  uint64_t                     vps_extension_8bits;         // u(8)
  uint64_t                     vps_extension_length_minus1; // ue(v)
  uint64_t                     vps_extension_data_byte;     // u(8)

  fvv_profile_tier_level_t    *ptl;
  fvv_occupancy_information_t *oi;
  fvv_geometry_information_t  *gi;
  fvv_attribute_information_t *ai;
  fvv_byte_alignment_t        *ba;

  fvv_ret_t (*pack)(fvv_v3c_parameter_set_t *self);
  fvv_ret_t (*copy_from)(fvv_v3c_parameter_set_t *self,
                         fvv_v3c_parameter_set_t *other);
  fvv_ret_t (*set_vps_v3c_parameter_set_id)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_v3c_parameter_set_id);
  fvv_ret_t (*set_vps_reserved_zero_8bits)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_reserved_zero_8bits);
  fvv_ret_t (*set_vps_atlas_count_minus1)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_atlas_count_minus1);
  fvv_ret_t (*set_vps_atlas_id)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1]);
  fvv_ret_t (*set_vps_frame_width)(
      fvv_v3c_parameter_set_t *self,
      uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_frame_height)(
      fvv_v3c_parameter_set_t *self,
      uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_map_count_minus1)(
      fvv_v3c_parameter_set_t *self,
      uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_multiple_map_streams_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_multiple_map_streams_present_flag
          [0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_map_absolute_coding_enabled_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_map_absolute_coding_enabled_flag
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
  fvv_ret_t (*set_vps_map_predictor_index_diff)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_map_predictor_index_diff
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
  fvv_ret_t (*set_vps_auxiliary_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_auxiliary_video_present_flag[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_occupancy_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_occupancy_video_present_flag[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_geometry_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_geometry_video_present_flag[0x1
                                          << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_attribute_video_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t
          vps_attribute_video_present_flag[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_vps_extension_present_flag)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_extension_present_flag);
  fvv_ret_t (*set_vps_extension_8bits)(fvv_v3c_parameter_set_t *self,
                                       uint64_t vps_extension_8bits);
  fvv_ret_t (*set_vps_extension_length_minus1)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_extension_length_minus1);
  fvv_ret_t (*set_vps_extension_data_byte)(
      fvv_v3c_parameter_set_t *self,
      uint64_t                 vps_extension_data_byte);

  fvv_ret_t (*set_ptl)(fvv_v3c_parameter_set_t  *self,
                       fvv_profile_tier_level_t *ptl);
  fvv_ret_t (*set_oi)(fvv_v3c_parameter_set_t     *self,
                      fvv_occupancy_information_t *oi);
  fvv_ret_t (*set_gi)(fvv_v3c_parameter_set_t    *self,
                      fvv_geometry_information_t *gi);
  fvv_ret_t (*set_ai)(fvv_v3c_parameter_set_t     *self,
                      fvv_attribute_information_t *ai);
  fvv_ret_t (*set_ba)(fvv_v3c_parameter_set_t *self,
                      fvv_byte_alignment_t    *ba);
};

fvv_ret_t fvv_v3c_parameter_set_init(fvv_v3c_parameter_set_t *self,
                                     fvv_bitstream_t         *data);
fvv_ret_t
fvv_v3c_parameter_set_destroy(fvv_v3c_parameter_set_t *self);

fvv_ret_t fvv_v3c_parameter_set_pack(fvv_v3c_parameter_set_t *self);
fvv_ret_t
fvv_v3c_parameter_set_copy_from(fvv_v3c_parameter_set_t *self,
                                fvv_v3c_parameter_set_t *other);

fvv_ret_t fvv_v3c_parameter_set_set_vps_v3c_parameter_set_id(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_v3c_parameter_set_id);
fvv_ret_t fvv_v3c_parameter_set_set_vps_reserved_zero_8bits(
    fvv_v3c_parameter_set_t *self, uint64_t vps_reserved_zero_8bits);
fvv_ret_t fvv_v3c_parameter_set_set_vps_atlas_count_minus1(
    fvv_v3c_parameter_set_t *self, uint64_t vps_atlas_count_minus1);
fvv_ret_t fvv_v3c_parameter_set_set_vps_atlas_id(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_atlas_id[(0x1 << FVV_BIT_VPS_ATLAS_COUNT_MINUS1) + 1]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_frame_width(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_frame_width[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_frame_height(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_frame_height[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_map_count_minus1(
    fvv_v3c_parameter_set_t *self,
    uint64_t vps_map_count_minus1[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_v3c_parameter_set_set_vps_multiple_map_streams_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_multiple_map_streams_present_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_v3c_parameter_set_set_vps_map_absolute_coding_enabled_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_map_absolute_coding_enabled_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_map_predictor_index_diff(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_map_predictor_index_diff
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_VPS_MAP_COUNT_MINUS1]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_auxiliary_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_auxiliary_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_occupancy_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_occupancy_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_geometry_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_geometry_video_present_flag[0x1
                                        << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_attribute_video_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t
        vps_attribute_video_present_flag[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_present_flag(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_extension_present_flag);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_8bits(
    fvv_v3c_parameter_set_t *self, uint64_t vps_extension_8bits);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_length_minus1(
    fvv_v3c_parameter_set_t *self,
    uint64_t                 vps_extension_length_minus1);
fvv_ret_t fvv_v3c_parameter_set_set_vps_extension_data_byte(
    fvv_v3c_parameter_set_t *self, uint64_t vps_extension_data_byte);
fvv_ret_t
fvv_v3c_parameter_set_set_ptl(fvv_v3c_parameter_set_t  *self,
                              fvv_profile_tier_level_t *ptl);
fvv_ret_t
fvv_v3c_parameter_set_set_oi(fvv_v3c_parameter_set_t     *self,
                             fvv_occupancy_information_t *oi);
fvv_ret_t
fvv_v3c_parameter_set_set_gi(fvv_v3c_parameter_set_t    *self,
                             fvv_geometry_information_t *gi);
fvv_ret_t
          fvv_v3c_parameter_set_set_ai(fvv_v3c_parameter_set_t     *self,
                                       fvv_attribute_information_t *ai);
fvv_ret_t fvv_v3c_parameter_set_set_ba(fvv_v3c_parameter_set_t *self,
                                       fvv_byte_alignment_t    *ba);

// 8.3.4.2 Profile, tier, and level syntax
struct fvv_profile_tier_level_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint64_t                 ptl_tier_flag;                  // u(1)
  uint64_t                 ptl_profile_codec_group_idc;    // u(7)
  uint64_t                 ptl_profile_toolset_idc;        // u(8)
  uint64_t                 ptl_profile_reconstruction_idc; // u(8)
  uint64_t                 ptl_reserved_zero_16bits;       // u(16)
  uint64_t                 ptl_reserved_0xffff_16bits;     // u(16)
  uint64_t                 ptl_level_idc;                  // u(8)
  uint64_t                 ptl_num_sub_profiles;           // u(6)
  uint64_t                 ptl_extended_sub_profile_flag;  // u(1)
  uint64_t
           ptl_sub_profile_idc[0x1
                          << FVV_BIT_PTL_NUM_SUB_PROFILES]; // u(v)
  uint64_t ptl_tool_constraints_present_flag; // u(1)

  fvv_profile_toolset_constraints_information_t *ptci;

  fvv_ret_t (*pack)(fvv_profile_tier_level_t *self);
  fvv_ret_t (*copy_from)(fvv_profile_tier_level_t *self,
                         fvv_profile_tier_level_t *other);
  fvv_ret_t (*set_ptl_tier_flag)(fvv_profile_tier_level_t *self,
                                 uint64_t ptl_tier_flag);
  fvv_ret_t (*set_ptl_profile_codec_group_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_profile_codec_group_idc);
  fvv_ret_t (*set_ptl_profile_toolset_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_profile_toolset_idc);
  fvv_ret_t (*set_ptl_profile_reconstruction_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_profile_reconstruction_idc);
  fvv_ret_t (*set_ptl_reserved_zero_16bits)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_reserved_zero_16bits);
  fvv_ret_t (*set_ptl_reserved_0xffff_16bits)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_reserved_0xffff_16bits);
  fvv_ret_t (*set_ptl_level_idc)(fvv_profile_tier_level_t *self,
                                 uint64_t ptl_level_idc);
  fvv_ret_t (*set_ptl_num_sub_profiles)(
      fvv_profile_tier_level_t *self, uint64_t ptl_num_sub_profiles);
  fvv_ret_t (*set_ptl_extended_sub_profile_flag)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_extended_sub_profile_flag);
  fvv_ret_t (*set_ptl_sub_profile_idc)(
      fvv_profile_tier_level_t *self,
      uint64_t
          ptl_sub_profile_idc[0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES]);
  fvv_ret_t (*set_ptl_tool_constraints_present_flag)(
      fvv_profile_tier_level_t *self,
      uint64_t                  ptl_tool_constraints_present_flag);
  fvv_ret_t (*set_ptci)(
      fvv_profile_tier_level_t                      *self,
      fvv_profile_toolset_constraints_information_t *ptci);
};

fvv_ret_t fvv_profile_tier_level_init(fvv_profile_tier_level_t *self,
                                      fvv_v3c_parameter_set_t  *vps,
                                      fvv_bitstream_t *data);
fvv_ret_t
fvv_profile_tier_level_destroy(fvv_profile_tier_level_t *self);

fvv_ret_t
fvv_profile_tier_level_pack(fvv_profile_tier_level_t *self);
fvv_ret_t
fvv_profile_tier_level_copy_from(fvv_profile_tier_level_t *self,
                                 fvv_profile_tier_level_t *other);
fvv_ret_t fvv_profile_tier_level_set_ptl_tier_flag(
    fvv_profile_tier_level_t *self, uint64_t ptl_tier_flag);
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_codec_group_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_codec_group_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_toolset_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_toolset_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_profile_reconstruction_idc(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_profile_reconstruction_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_reserved_zero_16bits(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_reserved_zero_16bits);
fvv_ret_t fvv_profile_tier_level_set_ptl_reserved_0xffff_16bits(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_reserved_0xffff_16bits);
fvv_ret_t fvv_profile_tier_level_set_ptl_level_idc(
    fvv_profile_tier_level_t *self, uint64_t ptl_level_idc);
fvv_ret_t fvv_profile_tier_level_set_ptl_num_sub_profiles(
    fvv_profile_tier_level_t *self, uint64_t ptl_num_sub_profiles);
fvv_ret_t fvv_profile_tier_level_set_ptl_extended_sub_profile_flag(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_extended_sub_profile_flag);
fvv_ret_t fvv_profile_tier_level_set_ptl_sub_profile_idc(
    fvv_profile_tier_level_t *self,
    uint64_t
        ptl_sub_profile_idc[0x1 << FVV_BIT_PTL_NUM_SUB_PROFILES]);
fvv_ret_t
fvv_profile_tier_level_set_ptl_tool_constraints_present_flag(
    fvv_profile_tier_level_t *self,
    uint64_t                  ptl_tool_constraints_present_flag);
fvv_ret_t fvv_profile_tier_level_set_ptci(
    fvv_profile_tier_level_t                      *self,
    fvv_profile_toolset_constraints_information_t *ptci);

// 8.3.4.3 Occupancy information syntax
struct fvv_occupancy_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint64_t
      oi_occupancy_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)
  uint64_t oi_lossy_occupancy_compression_threshold
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)
  uint64_t oi_occupancy_2d_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(5)
  uint64_t
      oi_occupancy_MSB_align_flag[0x1
                                  << FVV_BIT_VPS_ATLAS_ID]; // u(1)

  fvv_ret_t (*pack)(fvv_occupancy_information_t *self,
                    uint64_t                     atlasID);
  fvv_ret_t (*copy_from)(fvv_occupancy_information_t *self,
                         fvv_occupancy_information_t *other);
  fvv_ret_t (*set_oi_occupancy_codec_id)(
      fvv_occupancy_information_t *self,
      uint64_t oi_occupancy_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_oi_lossy_occupancy_compression_threshold)(
      fvv_occupancy_information_t *self,
      uint64_t oi_lossy_occupancy_compression_threshold
          [0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_oi_occupancy_2d_bit_depth_minus1)(
      fvv_occupancy_information_t *self,
      uint64_t
          oi_occupancy_2d_bit_depth_minus1[0x1
                                           << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_oi_occupancy_MSB_align_flag)(
      fvv_occupancy_information_t *self,
      uint64_t
          oi_occupancy_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID]);
};
fvv_ret_t
fvv_occupancy_information_init(fvv_occupancy_information_t *self,
                               fvv_v3c_parameter_set_t     *vps,
                               fvv_bitstream_t             *data);
fvv_ret_t
fvv_occupancy_information_destroy(fvv_occupancy_information_t *self);
fvv_ret_t
fvv_occupancy_information_pack(fvv_occupancy_information_t *self,
                               uint64_t                     atlasID);
fvv_ret_t fvv_occupancy_information_copy_from(
    fvv_occupancy_information_t *self,
    fvv_occupancy_information_t *other);
fvv_ret_t fvv_occupancy_information_set_oi_occupancy_codec_id(
    fvv_occupancy_information_t *self,
    uint64_t oi_occupancy_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_occupancy_information_set_oi_lossy_occupancy_compression_threshold(
    fvv_occupancy_information_t *self,
    uint64_t oi_lossy_occupancy_compression_threshold
        [0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_occupancy_information_set_oi_occupancy_2d_bit_depth_minus1(
    fvv_occupancy_information_t *self,
    uint64_t
        oi_occupancy_2d_bit_depth_minus1[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_occupancy_information_set_oi_occupancy_MSB_align_flag(
    fvv_occupancy_information_t *self,
    uint64_t
        oi_occupancy_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID]);

// 8.3.4.4 Geometry information syntax
struct fvv_geometry_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint64_t gi_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)
  uint64_t gi_geometry_2d_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(5)
  uint64_t
           gi_geometry_MSB_align_flag[0x1
                                 << FVV_BIT_VPS_ATLAS_ID]; // u(1)
  uint64_t gi_geometry_3d_coordinates_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(5)
  uint64_t gi_auxiliary_geometry_codec_id
      [0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(8)

  fvv_ret_t (*pack)(fvv_geometry_information_t *self,
                    uint64_t                    atlasID);
  fvv_ret_t (*copy_from)(fvv_geometry_information_t *self,
                         fvv_geometry_information_t *other);
  fvv_ret_t (*set_gi_geometry_codec_id)(
      fvv_geometry_information_t *self,
      uint64_t gi_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_gi_geometry_2d_bit_depth_minus1)(
      fvv_geometry_information_t *self,
      uint64_t
          gi_geometry_2d_bit_depth_minus1[0x1
                                          << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_gi_geometry_MSB_align_flag)(
      fvv_geometry_information_t *self,
      uint64_t
          gi_geometry_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_gi_geometry_3d_coordinates_bit_depth_minus1)(
      fvv_geometry_information_t *self,
      uint64_t gi_geometry_3d_coordinates_bit_depth_minus1
          [0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_gi_auxiliary_geometry_codec_id)(
      fvv_geometry_information_t *self,
      uint64_t
          gi_auxiliary_geometry_codec_id[0x1
                                         << FVV_BIT_VPS_ATLAS_ID]);
};
fvv_ret_t
fvv_geometry_information_init(fvv_geometry_information_t *self,
                              fvv_v3c_parameter_set_t    *vps,
                              fvv_bitstream_t            *data);
fvv_ret_t
fvv_geometry_information_destroy(fvv_geometry_information_t *self);
fvv_ret_t
fvv_geometry_information_pack(fvv_geometry_information_t *self,
                              uint64_t                    atlasID);
fvv_ret_t fvv_geometry_information_copy_from(
    fvv_geometry_information_t *self,
    fvv_geometry_information_t *other);
fvv_ret_t fvv_geometry_information_set_gi_geometry_codec_id(
    fvv_geometry_information_t *self,
    uint64_t gi_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_geometry_information_set_gi_geometry_2d_bit_depth_minus1(
    fvv_geometry_information_t *self,
    uint64_t
        gi_geometry_2d_bit_depth_minus1[0x1
                                        << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_geometry_information_set_gi_geometry_MSB_align_flag(
    fvv_geometry_information_t *self,
    uint64_t
        gi_geometry_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_geometry_information_set_gi_geometry_3d_coordinates_bit_depth_minus1(
    fvv_geometry_information_t *self,
    uint64_t gi_geometry_3d_coordinates_bit_depth_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t
fvv_geometry_information_set_gi_auxiliary_geometry_codec_id(
    fvv_geometry_information_t *self,
    uint64_t
        gi_auxiliary_geometry_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]);

// 8.3.4.5 Attribute information syntax
struct fvv_attribute_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint64_t ai_attribute_count[0x1 << FVV_BIT_VPS_ATLAS_ID]; // u(7)
  uint64_t
      ai_attribute_type_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                          [0x1
                           << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(4)
  uint64_t
      ai_attribute_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                           [0x1
                            << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(8)
  uint64_t ai_auxiliary_attribute_codec_id
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(8)
  uint64_t ai_attribute_map_absolute_coding_persistence_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(1)
  uint64_t ai_attribute_dimension_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(6)
  uint64_t ai_attribute_dimension_partitions_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(6)
  uint64_t ai_attribute_partition_channels_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]
      [0x1
       << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1]; // ue(v)
  uint64_t ai_attribute_2d_bit_depth_minus1
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(5)
  uint64_t ai_attribute_MSB_align_flag
      [0x1 << FVV_BIT_VPS_ATLAS_ID]
      [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]; // u(1)

  fvv_ret_t (*pack)(fvv_attribute_information_t *self,
                    uint64_t                     atlasID);

  fvv_ret_t (*copy_from)(fvv_attribute_information_t *self,
                         fvv_attribute_information_t *other);

  fvv_ret_t (*set_ai_attribute_count)(
      fvv_attribute_information_t *self,
      uint64_t ai_attribute_count[0x1 << FVV_BIT_VPS_ATLAS_ID]);
  fvv_ret_t (*set_ai_attribute_type_id)(
      fvv_attribute_information_t *self,
      uint64_t
          ai_attribute_type_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                              [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_attribute_codec_id)(
      fvv_attribute_information_t *self,
      uint64_t
          ai_attribute_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                               [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_auxiliary_attribute_codec_id)(
      fvv_attribute_information_t *self,
      uint64_t                     ai_auxiliary_attribute_codec_id
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_attribute_map_absolute_coding_persistence_flag)(
      fvv_attribute_information_t *self,
      uint64_t ai_attribute_map_absolute_coding_persistence_flag
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_attribute_dimension_minus1)(
      fvv_attribute_information_t *self,
      uint64_t                     ai_attribute_dimension_minus1
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_attribute_dimension_partitions_minus1)(
      fvv_attribute_information_t *self,
      uint64_t ai_attribute_dimension_partitions_minus1
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_attribute_partition_channels_minus1)(
      fvv_attribute_information_t *self,
      uint64_t ai_attribute_partition_channels_minus1
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1]);
  fvv_ret_t (*set_ai_attribute_2d_bit_depth_minus1)(
      fvv_attribute_information_t *self,
      uint64_t                     ai_attribute_2d_bit_depth_minus1
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
  fvv_ret_t (*set_ai_attribute_MSB_align_flag)(
      fvv_attribute_information_t *self,
      uint64_t                     ai_attribute_MSB_align_flag
          [0x1 << FVV_BIT_VPS_ATLAS_ID]
          [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
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
    uint64_t ai_attribute_count[0x1 << FVV_BIT_VPS_ATLAS_ID]);
fvv_ret_t fvv_attribute_information_set_ai_attribute_type_id(
    fvv_attribute_information_t *self,
    uint64_t
        ai_attribute_type_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                            [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t fvv_attribute_information_set_ai_attribute_codec_id(
    fvv_attribute_information_t *self,
    uint64_t
        ai_attribute_codec_id[0x1 << FVV_BIT_VPS_ATLAS_ID]
                             [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t
fvv_attribute_information_set_ai_auxiliary_attribute_codec_id(
    fvv_attribute_information_t *self,
    uint64_t                     ai_auxiliary_attribute_codec_id
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t
fvv_attribute_information_set_ai_attribute_map_absolute_coding_persistence_flag(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_map_absolute_coding_persistence_flag
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t
fvv_attribute_information_set_ai_attribute_dimension_minus1(
    fvv_attribute_information_t *self,
    uint64_t                     ai_attribute_dimension_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t
fvv_attribute_information_set_ai_attribute_dimension_partitions_minus1(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_dimension_partitions_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t
fvv_attribute_information_set_ai_attribute_partition_channels_minus1(
    fvv_attribute_information_t *self,
    uint64_t ai_attribute_partition_channels_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_DIMENSION_PARTITIONS_MINUS1]);
fvv_ret_t
fvv_attribute_information_set_ai_attribute_2d_bit_depth_minus1(
    fvv_attribute_information_t *self,
    uint64_t                     ai_attribute_2d_bit_depth_minus1
        [0x1 << FVV_BIT_VPS_ATLAS_ID]
        [0x1 << FVV_BIT_AI_ATTRIBUTE_COUNT]);
fvv_ret_t fvv_attribute_information_set_ai_attribute_MSB_align_flag(
    fvv_attribute_information_t *self,
    uint64_t
        ai_attribute_MSB_align_flag[0x1 << FVV_BIT_VPS_ATLAS_ID]
                                   [0x1
                                    << FVV_BIT_AI_ATTRIBUTE_COUNT]);

// 8.3.4.6 Profile toolset constraints information syntax
struct fvv_profile_toolset_constraints_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  uint64_t                 ptc_one_v3c_frame_only_flag;      // u(1)
  uint64_t                 ptc_eom_constraint_flag;          // u(1)
  uint64_t                 ptc_max_map_count_minus1;         // u(4)
  uint64_t                 ptc_max_atlas_count_minus1;       // u(4)
  uint64_t ptc_multiple_map_streams_constraint_flag;         // u(1)
  uint64_t ptc_plr_constraint_flag;                          // u(1)
  uint64_t ptc_attribute_max_dimension_minus1;               // u(6)
  uint64_t ptc_attribute_max_dimension_partitions_minus1;    // u(6)
  uint64_t ptc_no_eight_orientations_constraint_flag;        // u(1)
  uint64_t ptc_no_45degree_projection_patch_constraint_flag; // u(1)
  uint64_t ptc_reserved_zero_6bits;                          // u(6)
  uint64_t ptc_num_reserved_constraint_bytes;                // u(8)
  uint64_t ptc_reserved_constraint_byte
      [0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES]; // u(8)

  fvv_ret_t (*pack)(
      fvv_profile_toolset_constraints_information_t *self);
  fvv_ret_t (*copy_from)(
      fvv_profile_toolset_constraints_information_t *self,
      fvv_profile_toolset_constraints_information_t *other);
  fvv_ret_t (*set_ptc_one_v3c_frame_only_flag)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_one_v3c_frame_only_flag);
  fvv_ret_t (*set_ptc_eom_constraint_flag)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_eom_constraint_flag);
  fvv_ret_t (*set_ptc_max_map_count_minus1)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_max_map_count_minus1);
  fvv_ret_t (*set_ptc_max_atlas_count_minus1)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_max_atlas_count_minus1);
  fvv_ret_t (*set_ptc_multiple_map_streams_constraint_flag)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_multiple_map_streams_constraint_flag);
  fvv_ret_t (*set_ptc_plr_constraint_flag)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_plr_constraint_flag);
  fvv_ret_t (*set_ptc_attribute_max_dimension_minus1)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_attribute_max_dimension_minus1);
  fvv_ret_t (*set_ptc_attribute_max_dimension_partitions_minus1)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_attribute_max_dimension_partitions_minus1);
  fvv_ret_t (*set_ptc_no_eight_orientations_constraint_flag)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_no_eight_orientations_constraint_flag);
  fvv_ret_t (*set_ptc_no_45degree_projection_patch_constraint_flag)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_no_45degree_projection_patch_constraint_flag);
  fvv_ret_t (*set_ptc_reserved_zero_6bits)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_reserved_zero_6bits);
  fvv_ret_t (*set_ptc_num_reserved_constraint_bytes)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_num_reserved_constraint_bytes);
  fvv_ret_t (*set_ptc_reserved_constraint_byte)(
      fvv_profile_toolset_constraints_information_t *self,
      uint64_t ptc_reserved_constraint_byte
          [0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES]);
};
fvv_ret_t fvv_profile_toolset_constraints_information_init(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_v3c_parameter_set_t                       *vps,
    fvv_bitstream_t                               *data);
fvv_ret_t fvv_profile_toolset_constraints_information_destroy(
    fvv_profile_toolset_constraints_information_t *self);
fvv_ret_t fvv_profile_toolset_constraints_information_pack(
    fvv_profile_toolset_constraints_information_t *self);
fvv_ret_t fvv_profile_toolset_constraints_information_copy_from(
    fvv_profile_toolset_constraints_information_t *self,
    fvv_profile_toolset_constraints_information_t *other);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_one_v3c_frame_only_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_one_v3c_frame_only_flag);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_eom_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_eom_constraint_flag);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_max_map_count_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_max_map_count_minus1);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_max_atlas_count_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_max_atlas_count_minus1);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_multiple_map_streams_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_multiple_map_streams_constraint_flag);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_plr_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_plr_constraint_flag);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_attribute_max_dimension_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_attribute_max_dimension_minus1);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_attribute_max_dimension_partitions_minus1(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_attribute_max_dimension_partitions_minus1);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_no_eight_orientations_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_no_eight_orientations_constraint_flag);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_no_45degree_projection_patch_constraint_flag(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_no_45degree_projection_patch_constraint_flag);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_reserved_zero_6bits(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_reserved_zero_6bits);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_num_reserved_constraint_bytes(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_num_reserved_constraint_bytes);
fvv_ret_t
fvv_profile_toolset_constraints_information_set_ptc_reserved_constraint_byte(
    fvv_profile_toolset_constraints_information_t *self,
    uint64_t ptc_reserved_constraint_byte
        [0x1 << FVV_BIT_PTC_NUM_RESERVED_CONSTRAINT_BYTES]);

// 8.3.5 NAL unit syntax
// 8.3.5.1 General NAL unit syntax
struct fvv_nal_unit_t
{
  uint64_t              *rbsp_byte;
  fvv_nal_unit_header_t *nuh;

  fvv_bitstream_t       *data;

  uint64_t               rbsp_byte_size;

  fvv_ret_t (*pack)(fvv_nal_unit_t *self,
                    uint64_t        NumBytesInNalUnit);
  fvv_ret_t (*copy_from)(fvv_nal_unit_t *self,
                         fvv_nal_unit_t *other);
  fvv_ret_t (*set_rbsp_byte)(fvv_nal_unit_t *self,
                             uint64_t       *rbsp_byte,
                             uint64_t        rbsp_byte_size);
  fvv_ret_t (*set_nal_unit_header)(fvv_nal_unit_t        *self,
                                   fvv_nal_unit_header_t *nuh);
};

fvv_ret_t fvv_nal_unit_init(fvv_nal_unit_t  *self,
                            fvv_bitstream_t *data);

fvv_ret_t fvv_nal_unit_destroy(fvv_nal_unit_t *self);

fvv_ret_t fvv_nal_unit_pack(fvv_nal_unit_t *self,
                            uint64_t        NumBytesInNalUnit);
fvv_ret_t fvv_nal_unit_copy_from(fvv_nal_unit_t *self,
                                 fvv_nal_unit_t *other);
fvv_ret_t fvv_nal_unit_set_rbsp_byte(fvv_nal_unit_t *self,
                                     uint64_t       *rbsp_byte,
                                     uint64_t        rbsp_byte_size);
fvv_ret_t
fvv_nal_unit_set_nal_unit_header(fvv_nal_unit_t        *self,
                                 fvv_nal_unit_header_t *nuh);
// 8.3.5.2 NAL unit header syntax
struct fvv_nal_unit_header_t
{
  uint64_t         nal_forbidden_zero_bit;
  uint64_t         nal_unit_type;
  uint64_t         nal_layer_id;
  uint64_t         nal_temporal_id_plus1;

  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_nal_unit_header_t *self);
  fvv_ret_t (*copy_from)(fvv_nal_unit_header_t *self,
                         fvv_nal_unit_header_t *other);
  fvv_ret_t (*set_nal_forbidden_zero_bit)(
      fvv_nal_unit_header_t *self, uint64_t nal_forbidden_zero_bit);
  fvv_ret_t (*set_nal_unit_type)(fvv_nal_unit_header_t *self,
                                 uint64_t nal_unit_type);
  fvv_ret_t (*set_nal_layer_id)(fvv_nal_unit_header_t *self,
                                uint64_t               nal_layer_id);
  fvv_ret_t (*set_nal_temporal_id_plus1)(
      fvv_nal_unit_header_t *self, uint64_t nal_temporal_id_plus1);
};

fvv_ret_t fvv_nal_unit_header_init(fvv_nal_unit_header_t *self,
                                   fvv_bitstream_t       *data);
fvv_ret_t fvv_nal_unit_header_destroy(fvv_nal_unit_header_t *self);
fvv_ret_t fvv_nal_unit_header_pack(fvv_nal_unit_header_t *self);
fvv_ret_t fvv_nal_unit_header_copy_from(
    fvv_nal_unit_header_t *self, fvv_nal_unit_header_t *other);
fvv_ret_t fvv_nal_unit_header_set_nal_forbidden_zero_bit(
    fvv_nal_unit_header_t *self, uint64_t nal_forbidden_zero_bit);
fvv_ret_t fvv_nal_unit_header_set_nal_unit_type(
    fvv_nal_unit_header_t *self, uint64_t nal_unit_type);
fvv_ret_t fvv_nal_unit_header_set_nal_layer_id(
    fvv_nal_unit_header_t *self, uint64_t nal_layer_id);
fvv_ret_t fvv_nal_unit_header_set_nal_temporal_id_plus1(
    fvv_nal_unit_header_t *self, uint64_t nal_temporal_id_plus1);

// 8.3.6 Raw byte sequence payloads, trailing bits, and byte
// alignment syntax
// 8.3.6.1 Atlas sequence parameter set RBSP syntax
// 8.3.6.1.1 General atlas sequence parameter set RBSP syntax
struct fvv_atlas_sequence_parameter_set_rbsp_t
{
  uint64_t asps_atlas_sequence_parameter_set_id;
  uint64_t asps_frame_width;
  uint64_t asps_frame_height;
  uint64_t asps_geometry_3d_bit_depth_minus1;
  uint64_t asps_geometry_2d_bit_depth_minus1;
  uint64_t asps_log2_max_atlas_frame_order_cnt_lsb_minus4;
  uint64_t asps_max_dec_atlas_frame_buffering_minus1;
  uint64_t asps_long_term_ref_atlas_frames_flag;
  uint64_t asps_num_ref_atlas_frame_lists_in_asps;
  uint64_t asps_use_eight_orientations_flag;
  uint64_t asps_extended_projection_enabled_flag;
  uint64_t asps_max_number_projections_minus1;
  uint64_t asps_normal_axis_limits_quantization_enabled_flag;
  uint64_t asps_normal_axis_max_delta_value_enabled_flag;
  uint64_t asps_patch_precedence_order_flag;
  uint64_t asps_log2_patch_packing_block_size;
  uint64_t asps_patch_size_quantizer_present_flag;
  uint64_t asps_map_count_minus1;
  uint64_t asps_pixel_deinterleaving_enabled_flag;
  uint64_t asps_raw_patch_enabled_flag;
  uint64_t asps_eom_patch_enabled_flag;
  uint64_t asps_eom_fix_bit_count_minus1;
  uint64_t asps_auxiliary_video_enabled_flag;
  uint64_t asps_plr_enabled_flag;
  uint64_t asps_vui_parameters_present_flag;
  uint64_t asps_extension_present_flag;
  uint64_t asps_vpcc_extension_present_flag;
  uint64_t asps_extension_7bits;
  uint64_t asps_extension_data_flag;
  uint64_t asps_map_pixel_deinterleaving_flag
      [0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1];

  fvv_ref_list_struct_t      *rls;
  fvv_asps_plr_information_t *api;
  fvv_vui_parameters_t       *vp;
  fvv_asps_vpcc_extension_t  *ave; /* Specified in Annex H*/
  fvv_rbsp_trailing_bits_t   *rtb;

  fvv_bitstream_t            *data;

  fvv_ret_t (*pack)(fvv_atlas_sequence_parameter_set_rbsp_t *self);
};
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_init(
    fvv_atlas_sequence_parameter_set_rbsp_t *self,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_destroy(
    fvv_atlas_sequence_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_sequence_parameter_set_rbsp_pack(
    fvv_atlas_sequence_parameter_set_rbsp_t *self);

// 8.3.6.1.2 Point local reconstruction information syntax
struct fvv_asps_plr_information_t
{
  uint64_t
      plri_map_present_flag[(0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) +
                            1];            // u(1)
  uint64_t plri_number_of_modes_minus1[i]; // u(4)
  uint64_t plri_interpolate_flag
      [(0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1]
      [(0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1]; // u(1)
  uint64_t plri_filling_flag
      [(0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1]
      [(0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1]; // u(1)
  uint64_t plri_minimum_depth
      [(0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1]
      [(0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1]; // u(2)
  uint64_t plri_neighbour_minus1
      [(0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1]
      [(0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1]; // u(2)
  uint64_t plri_block_threshold_per_patch_minus1
      [(0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1]; // u(6)

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_asps_plr_information_t *self,
                    uint64_t                    mapCountMinus1);
};

fvv_ret_t fvv_fvv_asps_plr_information_init(
    fvv_asps_plr_information_t              *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_fvv_asps_plr_information_destroy(
    fvv_asps_plr_information_t *self);
fvv_ret_t
fvv_fvv_asps_plr_information_pack(fvv_asps_plr_information_t *self,
                                  uint64_t mapCountMinus1);

// 8.3.6.2 Atlas frame parameter set RBSP syntax
// 8.3.6.2.1 General atlas frame parameter set RBSP syntax
struct fvv_atlas_frame_parameter_set_rbsp_t
{
  uint64_t afps_atlas_frame_parameter_set_id;               // ue(v)
  uint64_t afps_atlas_sequence_parameter_set_id;            // ue(v)
  uint64_t afps_output_flag_present_flag;                   // u(1)
  uint64_t afps_num_ref_idx_default_active_minus1;          // ue(v)
  uint64_t afps_additional_lt_afoc_lsb_len;                 // ue(v)
  uint64_t afps_lod_mode_enabled_flag;                      // u(1)
  uint64_t afps_raw_3d_offset_bit_count_explicit_mode_flag; // u(1)
  uint64_t afps_extension_present_flag;                     // u(1)
  uint64_t afps_extension_8bits;                            // u(8)
  uint64_t afps_extension_data_flag;                        // u(1)
  fvv_atlas_frame_tile_information_t      *afti;
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_frame_parameter_set_rbsp_t *self);
};
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_init(
    fvv_atlas_frame_parameter_set_rbsp_t    *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_destroy(
    fvv_atlas_frame_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_frame_parameter_set_rbsp_pack(
    fvv_atlas_frame_parameter_set_rbsp_t *self);
// 8.3.6.2.2 Atlas frame tile information syntax
struct fvv_atlas_frame_tile_information_t
{
  uint64_t  afti_single_tile_in_atlas_frame_flag;       // u(1)
  uint64_t  afti_uniform_partition_spacing_flag;        // u(1)
  uint64_t  afti_partition_cols_width_minus1;           // ue(v)
  uint64_t  afti_partition_rows_height_minus1;          // ue(v)
  uint64_t  afti_num_partition_columns_minus1;          // ue(v)
  uint64_t  afti_num_partition_rows_minus1;             // ue(v)
  uint64_t *afti_partition_column_width_minus1;         // ue(v)
  uint64_t *afti_partition_row_height_minus1;           // ue(v)
  uint64_t  afti_single_partition_per_tile_flag;        // u(1)
  uint64_t  afti_num_tiles_in_atlas_frame_minus1;       // ue(v)
  uint64_t *afti_top_left_partition_idx;                // u(v)
  uint64_t *afti_bottom_right_partition_column_offset;  // ue(v)
  uint64_t *afti_bottom_right_partition_row_offset;     // ue(v)
  uint64_t  afti_auxiliary_video_tile_row_width_minus1; // ue(v)
  uint64_t *afti_auxiliary_video_tile_row_height;       // ue(v)
  uint64_t  afti_signalled_tile_id_flag;                // u(1)
  uint64_t  afti_signalled_tile_id_length_minus1;       // ue(v)
  uint64_t *afti_tile_id;                               // u(v)

  uint64_t  afti_partition_column_width_minus1_size;
  uint64_t  afti_partition_column_height_minus1_size;
  uint64_t  afti_top_left_partition_idx_size;
  uint64_t  afti_bottom_right_partition_column_offset_size;
  uint64_t  afti_bottom_right_partition_row_offset_size;
  uint64_t  afti_auxiliary_video_tile_row_height_size;
  uint64_t  afti_tile_id_size;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_frame_tile_information_t *self);
};
fvv_ret_t fvv_atlas_frame_tile_information_init(
    fvv_atlas_frame_tile_information_t      *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);

fvv_ret_t fvv_atlas_frame_tile_information_destroy(
    fvv_atlas_frame_tile_information_t *self);
fvv_ret_t fvv_atlas_frame_tile_information_pack(
    fvv_atlas_frame_tile_information_t *self);

// 8.3.6.3 Atlas adaptation parameter set RBSP syntax
struct fvv_atlas_adaptation_parameter_set_rbsp_t
{
  uint64_t aaps_atlas_adaptation_parameter_set_id; // ue(v)
  uint64_t aaps_extension_present_flag;            // u(1)
  uint64_t aaps_vpcc_extension_present_flag;       // u(1)
  uint64_t aaps_extension_7bits;                   // u(7)
  uint64_t aaps_extension_data_flag;               // u(1)
  fvv_aaps_vpcc_extension_t *ave; /* Specified in Annex H*/
  fvv_rbsp_trailing_bits_t  *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_adaptation_parameter_set_rbsp_t *self);
};

fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_init(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_atlas_sequence_parameter_set_rbsp_t   *aspsr,
    fvv_bitstream_t                           *data);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_destroy(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_pack(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self);

// 8.3.6.4 Supplemental enhancement information RBSP syntax
struct fvv_sei_rbsp_t
{
  fvv_sei_message_t                       *se;
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_sei_rbsp_t *self);
};

fvv_ret_t
          fvv_sei_rbsp_init(fvv_sei_rbsp_t                          *self,
                            fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
                            fvv_bitstream_t                         *data);
fvv_ret_t fvv_sei_rbsp_destroy(fvv_sei_rbsp_t *self);
fvv_ret_t fvv_sei_rbsp_pack(fvv_sei_rbsp_t *self);

// 8.3.6.5 Access unit delimiter RBSP syntax
struct fvv_access_unit_delimiter_rbsp_t
{
  uint64_t                                 aframe_type; // u(3)
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_access_unit_delimiter_rbsp_t *self);
};
fvv_ret_t fvv_access_unit_delimiter_rbsp_init(
    fvv_access_unit_delimiter_rbsp_t        *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_access_unit_delimiter_rbsp_destroy(
    fvv_access_unit_delimiter_rbsp_t *self);
fvv_ret_t fvv_access_unit_delimiter_rbsp_pack(
    fvv_access_unit_delimiter_rbsp_t *self);

// 8.3.6.6 End of sequence RBSP syntax
struct fvv_end_of_sequence_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_end_of_sequence_rbsp_t *self);
};

fvv_ret_t fvv_end_of_sequence_rbsp_init(
    fvv_end_of_sequence_rbsp_t              *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_end_of_sequence_rbsp_destroy(fvv_end_of_sequence_rbsp_t *self);
fvv_ret_t
fvv_end_of_sequence_rbsp_pack(fvv_end_of_sequence_rbsp_t *self);

// 8.3.6.7 End of bitstream RBSP syntax
struct fvv_end_of_atlas_sub_bitstream_rbsp_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_end_of_atlas_sub_bitstream_rbsp_t *self);
};

fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_init(
    fvv_end_of_atlas_sub_bitstream_rbsp_t   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_destroy(
    fvv_end_of_atlas_sub_bitstream_rbsp_t *self);
fvv_ret_t fvv_end_of_atlas_sub_bitstream_rbsp_pack(
    fvv_end_of_atlas_sub_bitstream_rbsp_t *self);

// 8.3.6.8 Filler data RBSP syntax
struct fvv_filler_data_rbsp_t
{
  uint64_t                                 ff_byte; // f(8)
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_filler_data_rbsp_t *self);
};
fvv_ret_t fvv_filler_data_rbsp_init(
    fvv_filler_data_rbsp_t                  *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_filler_data_rbsp_destroy(fvv_filler_data_rbsp_t *self);
fvv_ret_t fvv_filler_data_rbsp_pack(fvv_filler_data_rbsp_t *self);

// 8.3.6.9 Atlas tile layer RBSP syntax
struct fvv_atlas_tile_layer_rbsp_t
{
  fvv_atlas_tile_header_t                 *ath;
  fvv_atlas_tile_data_unit_t              *atdu;
  fvv_rbsp_trailing_bits_t                *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_tile_layer_rbsp_t *self,
                    uint64_t                     tileID);
};

fvv_ret_t fvv_atlas_tile_layer_rbsp_init(
    fvv_atlas_tile_layer_rbsp_t             *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_destroy(fvv_atlas_tile_layer_rbsp_t *self);
fvv_ret_t
fvv_atlas_tile_layer_rbsp_pack(fvv_atlas_tile_layer_rbsp_t *self,
                               uint64_t                     tileID);

// 8.3.6.10 RBSP trailing bit syntax
struct fvv_rbsp_trailing_bits_t
{
  uint64_t rbsp_stop_one_bit;       // /* equal to 1 */ f(1)
  uint64_t rbsp_alignment_zero_bit; // /* equal to 0 */

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_rbsp_trailing_bits_t *self);
};

fvv_ret_t fvv_rbsp_trailing_bits_init(
    fvv_rbsp_trailing_bits_t                *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_rbsp_trailing_bits_destroy(fvv_rbsp_trailing_bits_t *self);
fvv_ret_t
fvv_rbsp_trailing_bits_pack(fvv_rbsp_trailing_bits_t *self);

// 8.3.6.11 Atlas tile header syntax
struct fvv_atlas_tile_header_t
{
  uint64_t  ath_no_output_of_prior_atlas_frames_flag; // u(1)
  uint64_t  ath_atlas_frame_parameter_set_id;         // ue(v)
  uint64_t  ath_atlas_adaptation_parameter_set_id;    // ue(v)
  uint64_t  ath_id;                                   // u(v)
  uint64_t  ath_type;                                 // ue(v)
  uint64_t  ath_atlas_output_flag;                    // u(1)
  uint64_t  ath_atlas_frm_order_cnt_lsb;              // u(v)
  uint64_t  ath_ref_atlas_frame_list_asps_flag;       // u(1)
  uint64_t  ath_ref_atlas_frame_list_idx;             // u(v)
  uint64_t *ath_additional_afoc_lsb_present_flag;     // u(1)
  uint64_t *ath_additional_afoc_lsb_val;              // u(v)
  uint64_t  ath_pos_min_d_quantizer;                  // u(5)
  uint64_t  ath_pos_delta_max_d_quantizer;            // u(5)
  uint64_t  ath_patch_size_x_info_quantizer;          // u(3)
  uint64_t  ath_patch_size_y_info_quantizer;          // u(3)
  uint64_t  ath_raw_3d_offset_axis_bit_count_minus1;  // u(v)
  uint64_t  ath_num_ref_idx_active_override_flag;     // u(1)
  uint64_t  ath_num_ref_idx_active_minus1;            // ue(v)
  fvv_ref_list_struct_t *rls;
  fvv_byte_alignment_t  *ba;

  uint64_t               ath_additional_afoc_lsb_present_flag_size;
  uint64_t               ath_additional_afoc_lsb_val_size;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_tile_header_t *self);
};

fvv_ret_t fvv_atlas_tile_header_init(
    fvv_atlas_tile_header_t                 *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t
fvv_atlas_tile_header_destroy(fvv_atlas_tile_header_t *self);
fvv_ret_t fvv_atlas_tile_header_pack(fvv_atlas_tile_header_t *self);

// 8.3.6.12 Reference list structure syntax
struct fvv_ref_list_struct_t
{
  uint64_t  *num_ref_entries;         // ue(v)
  uint64_t **st_ref_atlas_frame_flag; // u(1)
  uint64_t **abs_delta_afoc_st;       // ue(v)
  uint64_t **straf_entry_sign_flag;   // u(1)
  uint64_t **afoc_lsb_lt;             // u(v)

  uint64_t   num_ref_entries_size;
  uint64_t   st_ref_atlas_frame_flag_size[2];
  uint64_t   abs_delta_afoc_st_size[2];
  uint64_t   straf_entry_sign_flag[2];
  uint64_t   afoc_lsb_lt[2];

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_ref_list_struct_t *self, uint64_t rlsIdx);
};

// TODO: this really need a look
fvv_ret_t fvv_ref_list_struct_init(
    fvv_ref_list_struct_t                   *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);
fvv_ret_t fvv_ref_list_struct_destroy(fvv_ref_list_struct_t *self);
fvv_ret_t fvv_ref_list_struct_pack(fvv_ref_list_struct_t *self,
                                   uint64_t               rlsIdx);
#endif
