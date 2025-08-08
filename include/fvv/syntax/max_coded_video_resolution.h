#ifndef FVV_SYNTAX_MAX_CODED_VIDEO_RESOLUTION_H
#define FVV_SYNTAX_MAX_CODED_VIDEO_RESOLUTION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// G.2.4 Maximum coded video resolution syntax
struct fvv_max_coded_video_resolution_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_max_coded_video_resolution_t,
      mcv_occupancy_resolution_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_geometry_resolution_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(
      fvv_max_coded_video_resolution_t,
      mcv_attribute_resolution_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_occupancy_width);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_occupancy_height);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_geometry_width);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_geometry_height);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_attribute_width);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_max_coded_video_resolution_t,
                                mcv_attribute_height);

  fvv_ret_t (*pack)(fvv_max_coded_video_resolution_t *self);
  fvv_ret_t (*copy_from)(fvv_max_coded_video_resolution_t *self,
                         fvv_max_coded_video_resolution_t *other);
};

fvv_ret_t fvv_max_coded_video_resolution_init(
    fvv_max_coded_video_resolution_t *self, fvv_bitstream_t *data);
fvv_ret_t fvv_max_coded_video_resolution_destroy(
    fvv_max_coded_video_resolution_t *self);
fvv_ret_t fvv_max_coded_video_resolution_pack(
    fvv_max_coded_video_resolution_t *self);
fvv_ret_t fvv_max_coded_video_resolution_copy_from(
    fvv_max_coded_video_resolution_t *self,
    fvv_max_coded_video_resolution_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_occupancy_resolution_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_geometry_resolution_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_attribute_resolution_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_occupancy_width);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_occupancy_height);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_geometry_width);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_geometry_height);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_attribute_width);
FVV_DECLARE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                          mcv_attribute_height);

#endif // FVV_SYNTAX_MAX_CODED_VIDEO_RESOLUTION_H