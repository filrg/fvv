#ifndef FVV_SYNTAX_OCCUPANCY_INFORMATION_H
#define FVV_SYNTAX_OCCUPANCY_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// typedef struct fvv_v3c_parameter_set_t fvv_v3c_parameter_set_t;
// typedef struct fvv_occupancy_information_t
//     fvv_occupancy_information_t;


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
#endif // FVV_SYNTAX_OCCUPANCY_INFORMATION_H