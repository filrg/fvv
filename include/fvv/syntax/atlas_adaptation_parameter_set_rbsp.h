#ifndef FVV_SYNTAX_ATLAS_ADAPTATION_PARAMETER_SET_RBSP_H
#define FVV_SYNTAX_ATLAS_ADAPTATION_PARAMETER_SET_RBSP_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.3 Atlas adaptation parameter set RBSP syntax
struct fvv_atlas_adaptation_parameter_set_rbsp_t
{
  uint64_t aaps_atlas_adaptation_parameter_set_id; // ue(v)
  uint64_t aaps_extension_present_flag;            // u(1)
  uint64_t aaps_vpcc_extension_present_flag;       // u(1)
  uint64_t aaps_extension_7bits;                   // u(7)
  uint64_t aaps_extension_data_flag;               // u(1)

  fvv_aaps_vpcc_extension_t *ave; /* Specified in Annex H*/
  fvv_rbsp_trailing_bits_t  *rtb;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_adaptation_parameter_set_rbsp_t *self);
  fvv_ret_t (*copy_from)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      fvv_atlas_adaptation_parameter_set_rbsp_t *other);
  fvv_ret_t (*set_aaps_atlas_adaptation_parameter_set_id)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      uint64_t aaps_atlas_adaptation_parameter_set_id);
  fvv_ret_t (*set_aaps_extension_present_flag)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      uint64_t aaps_extension_present_flag);
  fvv_ret_t (*set_aaps_vpcc_extension_present_flag)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      uint64_t aaps_vpcc_extension_present_flag);
  fvv_ret_t (*set_aaps_extension_7bits)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      uint64_t aaps_extension_7bits);
  fvv_ret_t (*set_aaps_extension_data_flag)(
      fvv_atlas_adaptation_parameter_set_rbsp_t *self,
      uint64_t aaps_extension_data_flag);

  fvv_ret_t (*set_ave)(*self, fvv_aaps_vpcc_extension_t *ave);
  fvv_ret_t (*set_rtb)(*self, fvv_rbsp_trailing_bits_t *rtb);
};

fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_init(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_atlas_sequence_parameter_set_rbsp_t   *aspsr,
    fvv_bitstream_t                           *data);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_destroy(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_pack(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_copy_from(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    fvv_atlas_adaptation_parameter_set_rbsp_t *other);

fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_atlas_adaptation_parameter_set_id(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_atlas_adaptation_parameter_set_id);
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_present_flag(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_extension_present_flag);
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_vpcc_extension_present_flag(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_vpcc_extension_present_flag);
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_7bits(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t                                   aaps_extension_7bits);
fvv_ret_t
fvv_atlas_adaptation_parameter_set_rbsp_set_aaps_extension_data_flag(
    fvv_atlas_adaptation_parameter_set_rbsp_t *self,
    uint64_t aaps_extension_data_flag);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_set_ave(
    *self, fvv_aaps_vpcc_extension_t *ave);
fvv_ret_t fvv_atlas_adaptation_parameter_set_rbsp_set_rtb(
    *self, fvv_rbsp_trailing_bits_t *rtb);

#endif // FVV_SYNTAX_ATLAS_ADAPTATION_PARAMETER_SET_RBSP_H
