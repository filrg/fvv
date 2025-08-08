#include <fvv/bitstream.h>
#include <fvv/syntax/max_coded_video_resolution.h>

// G.2.4 Maximum coded video resolution syntax
fvv_ret_t fvv_max_coded_video_resolution_init(
    fvv_max_coded_video_resolution_t *self, fvv_bitstream_t *data)
{
  *self      = (fvv_max_coded_video_resolution_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_occupancy_resolution_present_flag);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_geometry_resolution_present_flag);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_attribute_resolution_present_flag);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_occupancy_width);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_occupancy_height);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_geometry_width);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_geometry_height);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_attribute_width);
  FVV_SET_SETTER_PTR(fvv_max_coded_video_resolution_t,
                     mcv_attribute_height);

  self->pack      = fvv_max_coded_video_resolution_pack;
  self->copy_from = fvv_max_coded_video_resolution_copy_from;

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_max_coded_video_resolution_destroy(
    fvv_max_coded_video_resolution_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_max_coded_video_resolution_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_max_coded_video_resolution_pack(
    fvv_max_coded_video_resolution_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  buff                  = self->data;

  buff->write_bits(
      buff,
      self->mcv_occupancy_resolution_present_flag,
      FVV_BIT_MCV_OCCUPANCY_RESOLUTION_PRESENT_FLAG,
      FVV_DESCRIPTOR_MCV_OCCUPANCY_RESOLUTION_PRESENT_FLAG);
  buff->write_bits(
      buff,
      self->mcv_geometry_resolution_present_flag,
      FVV_BIT_MCV_GEOMETRY_RESOLUTION_PRESENT_FLAG,
      FVV_DESCRIPTOR_MCV_GEOMETRY_RESOLUTION_PRESENT_FLAG);
  buff->write_bits(
      buff,
      self->mcv_attribute_resolution_present_flag,
      FVV_BIT_MCV_ATTRIBUTE_RESOLUTION_PRESENT_FLAG,
      FVV_DESCRIPTOR_MCV_ATTRIBUTE_RESOLUTION_PRESENT_FLAG);

  if (self->mcv_occupancy_resolution_present_flag)
  {
    buff->write_bits(buff,
                     self->mcv_occupancy_width,
                     FVV_BIT_MCV_OCCUPANCY_WIDTH,
                     FVV_DESCRIPTOR_MCV_OCCUPANCY_WIDTH);
    buff->write_bits(buff,
                     self->mcv_occupancy_height,
                     FVV_BIT_MCV_OCCUPANCY_HEIGHT,
                     FVV_DESCRIPTOR_MCV_OCCUPANCY_HEIGHT);
  }

  if (self->mcv_geometry_resolution_present_flag)
  {
    buff->write_bits(buff,
                     self->mcv_geometry_width,
                     FVV_BIT_MCV_GEOMETRY_WIDTH,
                     FVV_DESCRIPTOR_MCV_GEOMETRY_WIDTH);
    buff->write_bits(buff,
                     self->mcv_geometry_height,
                     FVV_BIT_MCV_GEOMETRY_HEIGHT,
                     FVV_DESCRIPTOR_MCV_GEOMETRY_HEIGHT);
  }

  if (self->mcv_attribute_resolution_present_flag)
  {
    buff->write_bits(buff,
                     self->mcv_attribute_width,
                     FVV_BIT_MCV_ATTRIBUTE_WIDTH,
                     FVV_DESCRIPTOR_MCV_ATTRIBUTE_WIDTH);
    buff->write_bits(buff,
                     self->mcv_attribute_height,
                     FVV_BIT_MCV_ATTRIBUTE_HEIGHT,
                     FVV_DESCRIPTOR_MCV_ATTRIBUTE_HEIGHT);
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_max_coded_video_resolution_copy_from(
    fvv_max_coded_video_resolution_t *self,
    fvv_max_coded_video_resolution_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_mcv_occupancy_resolution_present_flag(
      self, other->mcv_occupancy_resolution_present_flag);
  self->set_mcv_geometry_resolution_present_flag(
      self, other->mcv_geometry_resolution_present_flag);
  self->set_mcv_attribute_resolution_present_flag(
      self, other->mcv_attribute_resolution_present_flag);
  self->set_mcv_occupancy_width(self, other->mcv_occupancy_width);
  self->set_mcv_occupancy_height(self, other->mcv_occupancy_height);
  self->set_mcv_geometry_width(self, other->mcv_geometry_width);
  self->set_mcv_geometry_height(self, other->mcv_geometry_height);
  self->set_mcv_attribute_width(self, other->mcv_attribute_width);
  self->set_mcv_attribute_height(self, other->mcv_attribute_height);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_occupancy_resolution_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_geometry_resolution_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_attribute_resolution_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_occupancy_width);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_occupancy_height);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_geometry_width);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_geometry_height);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_attribute_width);
FVV_DEFINE_SCALAR_SETTER(fvv_max_coded_video_resolution_t,
                         mcv_attribute_height);