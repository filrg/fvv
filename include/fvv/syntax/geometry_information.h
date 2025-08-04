#ifndef FVV_SYNTAX_GEOMETRY_INFORMATION_H
#define FVV_SYNTAX_GEOMETRY_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.4.4 Geometry information syntax
struct fvv_geometry_information_t
{
  fvv_v3c_parameter_set_t *vps;
  fvv_bitstream_t         *data;
  fvv_ret_t (*pack)(fvv_geometry_information_t *self,
                    uint64_t                    atlasID);
  fvv_ret_t (*copy_from)(fvv_geometry_information_t *self,
                         fvv_geometry_information_t *other);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_geometry_information_t, gi_geometry_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_geometry_information_t, gi_geometry_2d_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_geometry_information_t, gi_geometry_MSB_align_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_geometry_information_t, gi_geometry_3d_coordinates_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(fvv_geometry_information_t, gi_auxiliary_geometry_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID);
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
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_geometry_information_t, gi_geometry_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_geometry_information_t, gi_geometry_2d_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_geometry_information_t, gi_geometry_MSB_align_flag, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_geometry_information_t, gi_geometry_3d_coordinates_bit_depth_minus1, 0x1 << FVV_BIT_VPS_ATLAS_ID);
FVV_DECLARE_1D_STATIC_ARR_SETTER(fvv_geometry_information_t, gi_auxiliary_geometry_codec_id, 0x1 << FVV_BIT_VPS_ATLAS_ID);
#endif // FVV_SYNTAX_GEOMETRY_INFORMATION_H