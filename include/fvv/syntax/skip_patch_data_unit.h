#ifndef FVV_SYNTAX_SKIP_PATCH_DATA_UNIT_H
#define FVV_SYNTAX_SKIP_PATCH_DATA_UNIT_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.7.4 Skip patch data unit syntax
struct fvv_skip_patch_data_unit_t
{
  fvv_bitstream_t *data;

  fvv_ret_t (*pack)(fvv_skip_patch_data_unit_t *self);
  fvv_ret_t (*copy_from)(fvv_skip_patch_data_unit_t *self,
                         fvv_skip_patch_data_unit_t *other);
};

fvv_ret_t
fvv_skip_patch_data_unit_init(fvv_skip_patch_data_unit_t *self,
                              fvv_bitstream_t            *data);
fvv_ret_t
fvv_skip_patch_data_unit_destroy(fvv_skip_patch_data_unit_t *self);
fvv_ret_t
fvv_skip_patch_data_unit_pack(fvv_skip_patch_data_unit_t *self);
fvv_ret_t fvv_skip_patch_data_unit_copy_from(
    fvv_skip_patch_data_unit_t *self,
    fvv_skip_patch_data_unit_t *other);
#endif // FVV_SYNTAX_SKIP_PATCH_DATA_UNIT_H
