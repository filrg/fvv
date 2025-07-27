#ifndef FVV_SYNTAX_ATLAS_FRAME_TILE_INFORMATION_H
#define FVV_SYNTAX_ATLAS_FRAME_TILE_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// 8.3.6.2.2 Atlas frame tile information syntax
struct fvv_atlas_frame_tile_information_t
{
  uint64_t  afti_single_tile_in_atlas_frame_flag;       // u(1)
  uint64_t  afti_uniform_partition_spacing_flag;        // u(1)
  uint64_t  afti_partition_cols_width_minus1;           // ue(v)
  uint64_t  afti_partition_rows_height_minus1;          // ue(v)
  uint64_t  afti_num_partition_columns_minus1;          // ue(v)
  uint64_t  afti_num_partition_rows_minus1;             // ue(v)
  uint64_t *afti_partition_column_width_minus1;         // ue(v)
  uint64_t *afti_partition_row_height_minus1;           // ue(v)
  uint64_t  afti_single_partition_per_tile_flag;        // u(1)
  uint64_t  afti_num_tiles_in_atlas_frame_minus1;       // ue(v)
  uint64_t *afti_top_left_partition_idx;                // u(v)
  uint64_t *afti_bottom_right_partition_column_offset;  // ue(v)
  uint64_t *afti_bottom_right_partition_row_offset;     // ue(v)
  uint64_t  afti_auxiliary_video_tile_row_width_minus1; // ue(v)
  uint64_t *afti_auxiliary_video_tile_row_height;       // ue(v)
  uint64_t  afti_signalled_tile_id_flag;                // u(1)
  uint64_t  afti_signalled_tile_id_length_minus1;       // ue(v)
  uint64_t *afti_tile_id;                               // u(v)

  uint64_t  afti_partition_column_width_minus1_size;
  uint64_t  afti_partition_column_height_minus1_size;
  uint64_t  afti_top_left_partition_idx_size;
  uint64_t  afti_bottom_right_partition_column_offset_size;
  uint64_t  afti_bottom_right_partition_row_offset_size;
  uint64_t  afti_auxiliary_video_tile_row_height_size;
  uint64_t  afti_tile_id_size;

  fvv_atlas_sequence_parameter_set_rbsp_t *aspsr;
  fvv_bitstream_t                         *data;

  fvv_ret_t (*pack)(fvv_atlas_frame_tile_information_t *self);
};
fvv_ret_t fvv_atlas_frame_tile_information_init(
    fvv_atlas_frame_tile_information_t      *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data);

fvv_ret_t fvv_atlas_frame_tile_information_destroy(
    fvv_atlas_frame_tile_information_t *self);
fvv_ret_t fvv_atlas_frame_tile_information_pack(
    fvv_atlas_frame_tile_information_t *self);

#endif // FVV_SYNTAX_ATLAS_FRAME_TILE_INFORMATION_H