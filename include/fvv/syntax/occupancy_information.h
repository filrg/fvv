#ifndef FVV_SYNTAX_OCCUPANCY_INFORMATION_H
#define FVV_SYNTAX_OCCUPANCY_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.4.3 Occupancy information syntax
struct fvv_occupancy_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;

  fvv_ret_t (*pack)(fvv_occupancy_information_t *self,
                    uint64_t                     atlasID);
  fvv_ret_t (*copy_from)(fvv_occupancy_information_t *self,
                         fvv_occupancy_information_t *other);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_occupancy_information_t, oi_occupancy_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_occupancy_information_t, oi_lossy_occupancy_compression_threshold, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_occupancy_information_t, oi_occupancy_2d_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_occupancy_information_t, oi_occupancy_MSB_align_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
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
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_occupancy_information_t, oi_occupancy_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_occupancy_information_t, oi_lossy_occupancy_compression_threshold, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_occupancy_information_t, oi_occupancy_2d_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_occupancy_information_t, oi_occupancy_MSB_align_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);

#endif // FVV_SYNTAX_OCCUPANCY_INFORMATION_H