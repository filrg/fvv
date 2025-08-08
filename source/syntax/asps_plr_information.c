#include <fvv/bitstream.h>
#include <fvv/syntax/asps_plr_information.h>
#include <string.h>

// 8.3.6.1.2 Point local reconstruction information syntax
// {

fvv_ret_t fvv_asps_plr_information_init(
    fvv_asps_plr_information_t              *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *asps,
    fvv_bitstream_t                         *data)
{
  *self           = (fvv_asps_plr_information_t){0};

  self->asps     = asps;
  self->data      = data;

  self->pack      = fvv_asps_plr_information_pack;
  self->copy_from = fvv_asps_plr_information_copy_from;

  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_interpolate_flag,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
                     (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) +
                         1);
  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_filling_flag,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
                     (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) +
                         1);
  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_minimum_depth,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
                     (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) +
                         1);
  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_neighbour_minus1,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
                     (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) +
                         1);
  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_map_present_flag,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_number_of_modes_minus1,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
  FVV_SET_SETTER_PTR(fvv_asps_plr_information_t,
                     plri_block_threshold_per_patch_minus1,
                     (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_asps_plr_information_destroy(fvv_asps_plr_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  *self = (fvv_asps_plr_information_t){0};
  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_asps_plr_information_pack(fvv_asps_plr_information_t *self,
                              uint64_t mapCountMinus1)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  uint64_t         j    = 0;

  buff                  = self->data;

  for (i = 0; i < mapCountMinus1 + 1; i++)
  {
    buff->write_bits(buff,
                     self->plri_map_present_flag[i],
                     FVV_BIT_PLRI_MAP_PRESENT_FLAG,
                     FVV_DESCRIPTOR_PLRI_MAP_PRESENT_FLAG);
    if (self->plri_map_present_flag[i])
    {
      buff->write_bits(buff,
                       self->plri_number_of_modes_minus1[i],
                       FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1,
                       FVV_DESCRIPTOR_PLRI_NUMBER_OF_MODES_MINUS1);
      for (j = 0; j < self->plri_number_of_modes_minus1[i] + 1; j++)
      {
        buff->write_bits(buff,
                         self->plri_interpolate_flag[i][j],
                         FVV_BIT_PLRI_INTERPOLATE_FLAG,
                         FVV_DESCRIPTOR_PLRI_INTERPOLATE_FLAG);
        buff->write_bits(buff,
                         self->plri_filling_flag[i][j],
                         FVV_BIT_PLRI_FILLING_FLAG,
                         FVV_DESCRIPTOR_PLRI_FILLING_FLAG);
        buff->write_bits(buff,
                         self->plri_minimum_depth[i][j],
                         FVV_BIT_PLRI_MINIMUM_DEPTH,
                         FVV_DESCRIPTOR_PLRI_MINIMUM_DEPTH);
        buff->write_bits(buff,
                         self->plri_neighbour_minus1[i][j],
                         FVV_BIT_PLRI_NEIGHBOUR_MINUS1,
                         FVV_DESCRIPTOR_PLRI_NEIGHBOUR_MINUS1);
      }
      buff->write_bits(
          buff,
          self->plri_block_threshold_per_patch_minus1[i],
          FVV_BIT_PLRI_BLOCK_THRESHOLD_PER_PATCH_MINUS1,
          FVV_DESCRIPTOR_PLRI_BLOCK_THRESHOLD_PER_PATCH_MINUS1);
    }
  }

  return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_asps_plr_information_copy_from(fvv_asps_plr_information_t *self,
                                   fvv_asps_plr_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  self->set_plri_map_present_flag(self, other->plri_map_present_flag);
  self->set_plri_number_of_modes_minus1(
      self, other->plri_number_of_modes_minus1);
  self->set_plri_interpolate_flag(self, other->plri_interpolate_flag);
  self->set_plri_filling_flag(self, other->plri_filling_flag);
  self->set_plri_minimum_depth(self, other->plri_minimum_depth);
  self->set_plri_neighbour_minus1(self, other->plri_neighbour_minus1);
  self->set_plri_block_threshold_per_patch_minus1(
      self, other->plri_block_threshold_per_patch_minus1);

  return FVV_RET_SUCCESS;
}

FVV_DEFINE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_interpolate_flag,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
FVV_DEFINE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_filling_flag,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
FVV_DEFINE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_minimum_depth,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
FVV_DEFINE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_neighbour_minus1,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);

FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_asps_plr_information_t,
                                plri_map_present_flag,
                                (0x1
                                 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) +
                                    1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_asps_plr_information_t,
                                plri_number_of_modes_minus1,
                                (0x1
                                 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) +
                                    1);
FVV_DEFINE_1D_STATIC_ARR_SETTER(fvv_asps_plr_information_t,
                                plri_block_threshold_per_patch_minus1,
                                (0x1
                                 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) +
                                    1);

// }