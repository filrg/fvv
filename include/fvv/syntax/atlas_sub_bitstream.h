#ifndef FVV_SYNTAX_ATLAS_SUB_BITSTREAM_H
#define FVV_SYNTAX_ATLAS_SUB_BITSTREAM_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.2.4 Atlas sub-bitstream syntax
struct fvv_atlas_sub_bitstream_t
{
  fvv_v3c_unit_t                 *vu;
  fvv_bitstream_t                *data;

  fvv_sample_stream_nal_header_t *ssnh;
  fvv_sample_stream_nal_unit_t  **ssnu;
  uint64_t                        ssnu_size;

  fvv_ret_t (*pack)(fvv_atlas_sub_bitstream_t *self,
                    uint64_t                   numBytes);
  fvv_ret_t (*copy_from)(fvv_atlas_sub_bitstream_t *self,
                         fvv_atlas_sub_bitstream_t *other);

  FVV_DECLARE_OBJ_SETTER_PTR(fvv_atlas_sub_bitstream_t, ssnh, fvv_sample_stream_nal_header_t);
  fvv_ret_t (*set_ssnu)(fvv_atlas_sub_bitstream_t     *self,
                        fvv_sample_stream_nal_unit_t **ssnu,
                        uint64_t                       ssnu_size);
};

fvv_ret_t
fvv_atlas_sub_bitstream_init(fvv_atlas_sub_bitstream_t *self,
                             fvv_v3c_unit_t            *vu,
                             fvv_bitstream_t           *data);
fvv_ret_t
fvv_atlas_sub_bitstream_destroy(fvv_atlas_sub_bitstream_t *self);

fvv_ret_t
fvv_atlas_sub_bitstream_pack(fvv_atlas_sub_bitstream_t *self,
                             uint64_t                   numBytes);

fvv_ret_t
fvv_atlas_sub_bitstream_copy_from(fvv_atlas_sub_bitstream_t *self,
                                  fvv_atlas_sub_bitstream_t *other);
FVV_DECLARE_OBJ_SETTER(fvv_atlas_sub_bitstream_t, ssnh, fvv_sample_stream_nal_header_t);
fvv_ret_t
fvv_atlas_sub_bitstream_set_ssnu(fvv_atlas_sub_bitstream_t     *self,
                                 fvv_sample_stream_nal_unit_t **ssnu,
                                 uint64_t                       ssnu_size);

#endif // FVV_SYNTAX_ATLAS_SUB_BITSTREAM_H