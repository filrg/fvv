#ifndef FVV_SYNTAX_ASPS_PLR_INFORMATION_H
#define FVV_SYNTAX_ASPS_PLR_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.1.2 Point local reconstruction information syntax
struct fvv_asps_plr_information_t
{
  fvv_atlas_sequence_parameter_set_rbsp_t *asps;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_asps_plr_information_t *self,
                    uint64_t                    mapCountMinus1);
  fvv_ret_t (*copy_from)(fvv_asps_plr_information_t *self,
                         fvv_asps_plr_information_t *other);

  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_interpolate_flag,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
      (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_filling_flag,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
      (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_minimum_depth,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
      (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
  FVV_DECLARE_2D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_neighbour_minus1,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
      (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);

  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_map_present_flag,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_number_of_modes_minus1,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
  FVV_DECLARE_1D_STATIC_ARR_SETTER_PTR(
      fvv_asps_plr_information_t,
      plri_block_threshold_per_patch_minus1,
      (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
};

fvv_ret_t fvv_asps_plr_information_init(fvv_asps_plr_information_t              *self,
                                        fvv_atlas_sequence_parameter_set_rbsp_t *asps,
                                        fvv_bitstream_t                         *data);
fvv_ret_t fvv_asps_plr_information_destroy(fvv_asps_plr_information_t *self);
fvv_ret_t fvv_asps_plr_information_pack(fvv_asps_plr_information_t *self,
                                        uint64_t                    mapCountMinus1);
fvv_ret_t fvv_asps_plr_information_copy_from(fvv_asps_plr_information_t *self,
                                             fvv_asps_plr_information_t *other);

FVV_DECLARE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_interpolate_flag,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
FVV_DECLARE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_filling_flag,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
FVV_DECLARE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_minimum_depth,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);
FVV_DECLARE_2D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_neighbour_minus1,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1,
    (0x1 << FVV_BIT_PLRI_NUMBER_OF_MODES_MINUS1) + 1);

FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_map_present_flag,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_number_of_modes_minus1,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);
FVV_DECLARE_1D_STATIC_ARR_SETTER(
    fvv_asps_plr_information_t,
    plri_block_threshold_per_patch_minus1,
    (0x1 << FVV_BIT_ASPS_MAP_COUNT_MINUS1) + 1);

#endif // FVV_SYNTAX_ASPS_PLR_INFORMATION_H