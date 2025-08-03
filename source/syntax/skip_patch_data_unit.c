#include <fvv/syntax/skip_patch_data_unit.h>

// 8.3.7.4 Skip patch data unit syntax
// {
fvv_ret_t
fvv_skip_patch_data_unit_init(fvv_skip_patch_data_unit_t *self,
                              fvv_bitstream_t            *data)
{
  *self           = (fvv_skip_patch_data_unit_t){0};
  self->data      = data;

  self->pack      = fvv_skip_patch_data_unit_pack;
  self->copy_from = fvv_skip_patch_data_unit_copy_from;

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_skip_patch_data_unit_destroy(fvv_skip_patch_data_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  *self = (fvv_skip_patch_data_unit_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_skip_patch_data_unit_pack(fvv_skip_patch_data_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_skip_patch_data_unit_copy_from(fvv_skip_patch_data_unit_t *self,
                                   fvv_skip_patch_data_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  return FVV_RET_SUCCESS;
}
// }