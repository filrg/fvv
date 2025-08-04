#include <fvv/bitstream.h>
#include <fvv/syntax/atlas_tile_data_unit.h>
#include <fvv/syntax/atlas_tile_header.h>

// 8.3.7.1 General atlas tile data unit syntax
// {
fvv_ret_t
fvv_atlas_tile_data_unit_init(fvv_atlas_tile_data_unit_t *self,
                              fvv_atlas_tile_header_t    *ath,
                              fvv_bitstream_t            *data)
{
  *self           = (fvv_atlas_tile_data_unit_t){0};
  self->data      = data;
  self->ath       = ath;

  self->pack      = fvv_atlas_tile_data_unit_pack;
  self->copy_from = fvv_atlas_tile_data_unit_copy_from;

  FVV_SET_SETTER_PTR(fvv_atlas_tile_data_unit_t, atdu_patch_mode);
  FVV_SET_SETTER_PTR(fvv_atlas_tile_data_unit_t, spdu, fvv_skip_patch_data_unit_t);
  FVV_SET_SETTER_PTR(fvv_atlas_tile_data_unit_t, pid, fvv_patch_information_data_t);

  self->spdu = (fvv_skip_patch_data_unit_t *)malloc(sizeof(fvv_skip_patch_data_unit_t));
  self->pid  = (fvv_patch_information_data_t *)malloc(sizeof(fvv_patch_information_data_t));

  fvv_skip_patch_data_unit_init(self->spdu, data);
  fvv_patch_information_data_init(self->pid, data);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_data_unit_destroy(fvv_atlas_tile_data_unit_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_2D_ARR(fvv_atlas_tile_data_unit_t, atdu_patch_mode);
  FVV_DESTROY_OBJ(fvv_atlas_tile_data_unit_t, spdu, fvv_skip_patch_data_unit_t);
  FVV_DESTROY_OBJ(fvv_atlas_tile_data_unit_t, pid, fvv_patch_information_data_t);

  *self = (fvv_atlas_tile_data_unit_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_data_unit_pack(fvv_atlas_tile_data_unit_t *self,
                              uint64_t                    tileID)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  fvv_bitstream_t *buff  = FVV_NULL;
  uint64_t         p     = 0;
  fvv_bool_t       isEnd = 0;
  buff                   = self->data;

  if (self->ath->ath_type == FVV_SKIP_TILE)
  {
    for (p = 0; p < RefAtduTotalNumPatches[tileID]; p++)
      self->spdu->pack(self->spdu);
  }
  else
  {
    p = 0;
    do
    {
      buff->pad(buff,
                self->atdu_patch_mode[tileID][p],
                FVV_BIT_ATDU_PATCH_MODE);
      isEnd = (self->ath->ath_type == FVV_P_TILE &&
               self->atdu_patch_mode[tileID][p] == FVV_P_END) ||
              (self->ath->ath_type == FVV_I_TILE &&
               self->atdu_patch_mode[tileID][p] == FVV_I_END);
      if (!isEnd)
      {
        self->pid->pack(
            self->pid, tileID, p, self->atdu_patch_mode[tileID][p]);
        p++;
      }
    } while (!isEnd)
  }
  AtduTotalNumPatches[tileID] = p;

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_atlas_tile_data_unit_copy_from(fvv_atlas_tile_data_unit_t *self,
                                   fvv_atlas_tile_data_unit_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_atdu_patch_mode(self, other->atdu_patch_mode);
  self->set_spdu(self, other->spdu);
  self->set_pid(self, other->pid);
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_2D_ARR_SETTER(fvv_atlas_tile_data_unit_t, atdu_patch_mode);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_tile_data_unit_t, spdu, fvv_skip_patch_data_unit_t);
FVV_DEFINE_OBJ_SETTER(fvv_atlas_tile_data_unit_t, pid, fvv_patch_information_data_t);
// }
