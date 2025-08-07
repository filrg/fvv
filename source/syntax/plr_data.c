#include <fvv/bitstream.h>
#include <fvv/syntax/asps_plr_information.h>
#include <fvv/syntax/atlas_sequence_parameter_set_rbsp.h>
#include <fvv/syntax/plr_data.h>
// 8.3.7.9 Point local reconstruction data syntax
// {
fvv_ret_t
fvv_plr_data_init(fvv_plr_data_t                          *self,
                  fvv_bitstream_t                         *data,
                  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
                  fvv_asps_plr_information_t              *plri)
{
  *self           = (fvv_plr_data_t){0};
  self->data      = data;
  self->aspsr     = aspsr;
  self->plri      = plri;

  self->pack      = fvv_plr_data_pack;
  self->copy_from = fvv_plr_data_copy_from;

  FVV_SET_SETTER_PTR(fvv_plr_data_t, plrd_level);
  FVV_SET_SETTER_PTR(fvv_plr_data_t, plrd_present_block_flag);
  FVV_SET_SETTER_PTR(fvv_plr_data_t, plrd_block_mode_minus1);
  FVV_SET_SETTER_PTR(fvv_plr_data_t, plrd_present_flag);
  FVV_SET_SETTER_PTR(fvv_plr_data_t, plrd_mode_minus1);

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_plr_data_destroy(fvv_plr_data_t *self)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  FVV_DESTROY_3D_ARR(fvv_plr_data_t, plrd_level);
  FVV_DESTROY_4D_ARR(fvv_plr_data_t, plrd_present_block_flag);
  FVV_DESTROY_4D_ARR(fvv_plr_data_t, plrd_block_mode_minus1);
  FVV_DESTROY_3D_ARR(fvv_plr_data_t, plrd_present_flag);
  FVV_DESTROY_3D_ARR(fvv_plr_data_t, plrd_mode_minus1);

  *self = (fvv_plr_data_t){0};
  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_plr_data_pack(fvv_plr_data_t *self,
                            uint64_t        tileID,
                            uint64_t        patchIdx)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  fvv_bitstream_t *buff = self->data;
  uint32_t blockCnt     = BlockCnt(TilePatch2dSizeX[tileID][patchIdx],
                               TilePatch2dSizeY[tileID][patchIdx]);

  for (uint64_t i = 0; i <= self->aspsr->asps_map_count_minus1; ++i)
  {
    if (self->plri->plri_map_present_flag[i])
    {
      if (blockCnt >
          self->plri->plri_block_threshold_per_patch_minus1[i] + 1)
      {
        buff->write_bits(buff,
                         self->plrd_level[tileID][patchIdx][i],
                         FVV_BIT_PLRD_LEVEL,
                         FVV_DESCRIPTOR_PLRD_LEVEL);
      }
      else
      {
        self->plrd_level[tileID][patchIdx][i] = 1;
      }

      if (self->plrd_level[tileID][patchIdx][i] == 0)
      {
        for (uint64_t j = 0; j < blockCnt; ++j)
        {
          buff->write_bits(
              buff,
              self->plrd_present_block_flag[tileID][patchIdx][i][j],
              FVV_BIT_PLRD_PRESENT_BLOCK_FLAG,
              FVV_DESCRIPTOR_PLRD_PRESENT_BLOCK_FLAG);
          if (self->plrd_present_block_flag[tileID][patchIdx][i][j])
          {
            buff->write_bits(
                buff,
                self->plrd_block_mode_minus1[tileID][patchIdx][i][j],
                FVV_BIT_PLRD_BLOCK_MODE_MINUS1,
                FVV_DESCRIPTOR_PLRD_BLOCK_MODE_MINUS1);
          }
        }
      }
      else
      {
        buff->write_bits(buff,
                         self->plrd_present_flag[tileID][patchIdx][i],
                         FVV_BIT_PLRD_PRESENT_FLAG,
                         FVV_DESCRIPTOR_PLRD_PRESENT_FLAG);
        if (self->plrd_present_flag[tileID][patchIdx][i])
        {
          buff->write_bits(
              buff,
              self->plrd_mode_minus1[tileID][patchIdx][i],
              FVV_BIT_PLRD_MODE_MINUS1,
              FVV_DESCRIPTOR_PLRD_MODE_MINUS1);
        }
      }
    }
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_plr_data_copy_from(fvv_plr_data_t *self,
                                 fvv_plr_data_t *other)
{
  if (!self)
    return FVV_RET_UNINITIALIZED;

  self->set_plrd_level(
      self, other->plrd_level, other->plrd_level_size);
  self->set_plrd_present_block_flag(
      self,
      other->plrd_present_block_flag,
      other->plrd_present_block_flag_size);
  self->set_plrd_block_mode_minus1(
      self,
      other->plrd_block_mode_minus1,
      other->plrd_block_mode_minus1_size);
  self->set_plrd_present_flag(
      self, other->plrd_present_flag, other->plrd_present_flag_size);
  self->set_plrd_mode_minus1(
      self, other->plrd_mode_minus1, other->plrd_mode_minus1_size);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_3D_ARR_SETTER(fvv_plr_data_t, plrd_level);
FVV_DEFINE_4D_ARR_SETTER(fvv_plr_data_t, plrd_present_block_flag);
FVV_DEFINE_4D_ARR_SETTER(fvv_plr_data_t, plrd_block_mode_minus1);
FVV_DEFINE_3D_ARR_SETTER(fvv_plr_data_t, plrd_present_flag);
FVV_DEFINE_3D_ARR_SETTER(fvv_plr_data_t, plrd_mode_minus1);
// }
