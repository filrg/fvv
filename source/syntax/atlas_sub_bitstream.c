#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_sub_bitstream.h>
#include <fvv/syntax/sample_stream_nal_header.h>
#include <fvv/syntax/sample_stream_nal_unit.h>
#include <fvv/syntax/v3c_unit.h>
#include <fvv/syntax/v3c_unit_payload.h>

// 8.3.2.4 Atlas sub-bitstream syntax
// {
fvv_ret_t
fvv_atlas_sub_bitstream_init(fvv_atlas_sub_bitstream_t *self,
                             fvv_v3c_unit_t            *vu,
                             fvv_bitstream_t           *data)
{
  *self      = (fvv_atlas_sub_bitstream_t){0};

  self->vu   = vu;
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_atlas_sub_bitstream_t, ssnh, fvv_sample_stream_nal_header_t);
  FVV_SET_SETTER_PTR(fvv_atlas_sub_bitstream_t, ssnu, fvv_sample_stream_nal_unit_t);

  self->ssnh = (fvv_sample_stream_nal_header_t *)malloc(
      sizeof(fvv_sample_stream_nal_header_t));

  fvv_sample_stream_nal_header_init(self->ssnh, self, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sub_bitstream_destroy(fvv_atlas_sub_bitstream_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_OBJ(fvv_atlas_sub_bitstream_t, ssnh, fvv_sample_stream_nal_header_t);
  if (self->ssnu)
  {
    for (uint64_t i = 0; i < self->ssnu_size; i++)
    {
      if (self->ssnu[i])
      {
        fvv_sample_stream_nal_unit_destroy(self->ssnu[i]);
        free(self->ssnu[i]);
      }
    }
    free(self->ssnu);
  }

  *self = (fvv_atlas_sub_bitstream_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t
fvv_atlas_sub_bitstream_pack(fvv_atlas_sub_bitstream_t *self,
                             uint64_t                   numBytes)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (!self->ssnu)
  {
    return FVV_RET_FAIL;
  }

  fvv_bitstream_t                *buff      = FVV_NULL;
  fvv_v3c_unit_t                 *vu        = FVV_NULL;
  fvv_sample_stream_nal_header_t *ssnh      = FVV_NULL;
  fvv_sample_stream_nal_unit_t  **ssnu_list = FVV_NULL;
  fvv_sample_stream_nal_unit_t   *ssnu      = FVV_NULL;
  uint64_t                        i         = 0;
  vu                                        = self->vu;
  buff                                      = self->data;
  ssnh                                      = vu->vup->asb->ssnh;
  ssnu_list                                 = vu->vup->asb->ssnu;
  ssnu                                      = *ssnu_list;

  ssnh->pack(ssnh);
  numBytes--;
  while (numBytes > 0)
  {
    ssnu[i].pack(&ssnu[i]);
    numBytes -= ssnu[i].ssnu_nal_unit_size +
                ssnh[i].ssnh_unit_size_precision_bytes_minus1 + 1;
    i++;
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_sub_bitstream_copy_from(fvv_atlas_sub_bitstream_t *self,
                                  fvv_atlas_sub_bitstream_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_ssnh(self, other->ssnh);
  self->set_ssnu(self, other->ssnu, other->ssnu_size);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_OBJ_SETTER(fvv_atlas_sub_bitstream_t, ssnh, fvv_sample_stream_nal_header_t);
fvv_ret_t
fvv_atlas_sub_bitstream_set_ssnu(fvv_atlas_sub_bitstream_t     *self,
                                 fvv_sample_stream_nal_unit_t **ssnu,
                                 uint64_t                       ssnu_size)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  if (self->ssnu)
  {
    for (uint64_t i = 0; i < self->ssnu_size; i++)
    {
      if (self->ssnu[i])
      {
        fvv_sample_stream_nal_unit_destroy(self->ssnu[i]);
        free(self->ssnu[i]);
      }
    }
    free(self->ssnu);
    self->ssnu      = FVV_NULL;
    self->ssnu_size = 0;
  }

  self->ssnu_size = ssnu_size;
  self->ssnu      = (fvv_sample_stream_nal_unit_t **)malloc(
      self->ssnu_size * sizeof(fvv_sample_stream_nal_unit_t *));

  for (uint64_t i = 0; i < self->ssnu_size; i++)
  {
    self->ssnu[i] = (fvv_sample_stream_nal_unit_t *)malloc(
        sizeof(fvv_sample_stream_nal_unit_t));
    fvv_sample_stream_nal_unit_init(self->ssnu[i], self, self->data);
    self->ssnu[i]->copy_from(self->ssnu[i], &(*ssnu)[i]);
  }

  return FVV_RET_SUCCESS;
}

// }