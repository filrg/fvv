#include <fvv/bitstream.h>
#include <fvv/syntax/scene_object_information.h>

// F.2.12.1 Scene object information SEI message syntax
fvv_ret_t fvv_scene_object_information_init(
    fvv_scene_object_information_t *self, fvv_bitstream_t *data)
{
  *self      = (fvv_scene_object_information_t){0};
  self->data = data;

  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_persistence_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_reset_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_num_object_updates);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_simple_objects_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_label_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_priority_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_hidden_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_dependency_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_visibility_cones_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_collision_shape_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_point_style_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_material_id_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_extension_present_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_scale_log2);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_log2_max_object_idx_updated_minus1);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_log2_max_object_dependency_idx);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_object_idx);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_cancel_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_label_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_label_idx);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_priority_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_priority_value);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_hidden_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_dependency_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_num_dependencies);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_object_dependency_idx);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_visibility_cones_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_direction_x);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_direction_y);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_direction_z);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_angle);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_x);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_y);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_z);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_size_x);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_size_y);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_size_z);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_collision_shape_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_collision_shape_id);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_point_style_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_point_shape_id);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_point_size);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t,
                     soi_material_id_update_flag);
  FVV_SET_SETTER_PTR(fvv_scene_object_information_t, soi_material_id);

  self->pack      = fvv_scene_object_information_pack;
  self->copy_from = fvv_scene_object_information_copy_from;
  return FVV_RET_SUCCESS;
}
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_persistence_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_reset_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_num_object_updates);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_simple_objects_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_object_label_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_priority_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_object_hidden_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_object_dependency_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_visibility_cones_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_collision_shape_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_point_style_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_material_id_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_extension_present_flag);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_scale_log2);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_log2_max_object_idx_updated_minus1);
FVV_DEFINE_SCALAR_SETTER(fvv_scene_object_information_t,
                         soi_log2_max_object_dependency_idx);

FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_idx);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_cancel_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_label_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_label_idx);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_priority_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_priority_value);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_hidden_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_dependency_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_num_dependencies);
FVV_DEFINE_2D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_object_dependency_idx);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_visibility_cones_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_direction_x);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_direction_y);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_direction_z);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t, soi_angle);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_x);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_y);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_z);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_size_x);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_size_y);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_3d_bounding_box_size_z);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_collision_shape_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_collision_shape_id);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_point_style_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_point_shape_id);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_point_size);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_material_id_update_flag);
FVV_DEFINE_1D_ARR_SETTER(fvv_scene_object_information_t,
                         soi_material_id);

fvv_ret_t fvv_scene_object_information_destroy(
    fvv_scene_object_information_t *self)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_object_idx);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_object_cancel_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_object_label_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_object_label_idx);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_priority_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_priority_value);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_object_hidden_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_object_dependency_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_object_num_dependencies);
  FVV_DESTROY_2D_ARR(fvv_scene_object_information_t,
                     soi_object_dependency_idx);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_visibility_cones_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_direction_x);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_direction_y);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_direction_z);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_angle);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_x);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_y);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_z);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_size_x);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_size_y);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_3d_bounding_box_size_z);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_collision_shape_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_collision_shape_id);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_point_style_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_point_shape_id);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_point_size);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t,
                     soi_material_id_update_flag);
  FVV_DESTROY_1D_ARR(fvv_scene_object_information_t, soi_material_id);
  *self = (fvv_scene_object_information_t){0};

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_scene_object_information_pack(
    fvv_scene_object_information_t *self, uint64_t payloadSize)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  fvv_bitstream_t *buff = FVV_NULL;
  uint64_t         i    = 0;
  uint64_t         j    = 0;
  uint64_t         k    = 0;
  buff                  = self->data;

  buff->write_bits(buff,
                   self->soi_persistence_flag,
                   FVV_BIT_SOI_PERSISTENCE_FLAG,
                   FVV_DESCRIPTOR_SOI_PERSISTENCE_FLAG);
  buff->write_bits(buff,
                   self->soi_reset_flag,
                   FVV_BIT_SOI_RESET_FLAG,
                   FVV_DESCRIPTOR_SOI_RESET_FLAG);
  buff->write_bits(buff,
                   self->soi_num_object_updates,
                   FVV_BIT_SOI_NUM_OBJECT_UPDATES,
                   FVV_DESCRIPTOR_SOI_NUM_OBJECT_UPDATES);

  if (self->soi_num_object_updates > 0)
  {
    buff->write_bits(buff,
                     self->soi_simple_objects_flag,
                     FVV_BIT_SOI_SIMPLE_OBJECTS_FLAG,
                     FVV_DESCRIPTOR_SOI_SIMPLE_OBJECTS_FLAG);

    if (self->soi_simple_objects_flag == 0)
    {
      buff->write_bits(buff,
                       self->soi_object_label_present_flag,
                       FVV_BIT_SOI_OBJECT_LABEL_PRESENT_FLAG,
                       FVV_DESCRIPTOR_SOI_OBJECT_LABEL_PRESENT_FLAG);
      buff->write_bits(buff,
                       self->soi_priority_present_flag,
                       FVV_BIT_SOI_PRIORITY_PRESENT_FLAG,
                       FVV_DESCRIPTOR_SOI_PRIORITY_PRESENT_FLAG);
      buff->write_bits(buff,
                       self->soi_object_hidden_present_flag,
                       FVV_BIT_SOI_OBJECT_HIDDEN_PRESENT_FLAG,
                       FVV_DESCRIPTOR_SOI_OBJECT_HIDDEN_PRESENT_FLAG);
      buff->write_bits(
          buff,
          self->soi_object_dependency_present_flag,
          FVV_BIT_SOI_OBJECT_DEPENDENCY_PRESENT_FLAG,
          FVV_DESCRIPTOR_SOI_OBJECT_DEPENDENCY_PRESENT_FLAG);
      buff->write_bits(
          buff,
          self->soi_visibility_cones_present_flag,
          FVV_BIT_SOI_VISIBILITY_CONES_PRESENT_FLAG,
          FVV_DESCRIPTOR_SOI_VISIBILITY_CONES_PRESENT_FLAG);
      buff->write_bits(
          buff,
          self->soi_3d_bounding_box_present_flag,
          FVV_BIT_SOI_3D_BOUNDING_BOX_PRESENT_FLAG,
          FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_PRESENT_FLAG);
      buff->write_bits(
          buff,
          self->soi_collision_shape_present_flag,
          FVV_BIT_SOI_COLLISION_SHAPE_PRESENT_FLAG,
          FVV_DESCRIPTOR_SOI_COLLISION_SHAPE_PRESENT_FLAG);
      buff->write_bits(buff,
                       self->soi_point_style_present_flag,
                       FVV_BIT_SOI_POINT_STYLE_PRESENT_FLAG,
                       FVV_DESCRIPTOR_SOI_POINT_STYLE_PRESENT_FLAG);
      buff->write_bits(buff,
                       self->soi_material_id_present_flag,
                       FVV_BIT_SOI_MATERIAL_ID_PRESENT_FLAG,
                       FVV_DESCRIPTOR_SOI_MATERIAL_ID_PRESENT_FLAG);
      buff->write_bits(buff,
                       self->soi_extension_present_flag,
                       FVV_BIT_SOI_EXTENSION_PRESENT_FLAG,
                       FVV_DESCRIPTOR_SOI_EXTENSION_PRESENT_FLAG);
    }
    /* else: all present flags are implicitly set to 0 for simple
     * objects */

    if (self->soi_3d_bounding_box_present_flag)
    {
      buff->write_bits(buff,
                       self->soi_3d_bounding_box_scale_log2,
                       FVV_BIT_SOI_3D_BOUNDING_BOX_SCALE_LOG2,
                       FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SCALE_LOG2);
    }

    buff->write_bits(
        buff,
        self->soi_log2_max_object_idx_updated_minus1,
        FVV_BIT_SOI_LOG2_MAX_OBJECT_IDX_UPDATED_MINUS1,
        FVV_DESCRIPTOR_SOI_LOG2_MAX_OBJECT_IDX_UPDATED_MINUS1);

    if (self->soi_object_dependency_present_flag)
      buff->write_bits(
          buff,
          self->soi_log2_max_object_dependency_idx,
          FVV_BIT_SOI_LOG2_MAX_OBJECT_DEPENDENCY_IDX,
          FVV_DESCRIPTOR_SOI_LOG2_MAX_OBJECT_DEPENDENCY_IDX);

    for (i = 0; i < self->soi_num_object_updates; i++)
    {
      buff->write_bits(buff,
                       self->soi_object_idx[i],
                       self->soi_log2_max_object_idx_updated_minus1 +
                           1,
                       FVV_DESCRIPTOR_SOI_OBJECT_IDX);
      k = self->soi_object_idx[i];
      buff->write_bits(buff,
                       self->soi_object_cancel_flag[k],
                       FVV_BIT_SOI_OBJECT_CANCEL_FLAG,
                       FVV_DESCRIPTOR_SOI_OBJECT_CANCEL_FLAG);
      /* ObjectTracked[k] = !soi_object_cancel_flag[k] */

      if (!self->soi_object_cancel_flag[k])
      {
        if (self->soi_object_label_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_object_label_update_flag[k],
              FVV_BIT_SOI_OBJECT_LABEL_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_OBJECT_LABEL_UPDATE_FLAG);
          if (self->soi_object_label_update_flag[k])
            buff->write_bits(buff,
                             self->soi_object_label_idx[k],
                             FVV_BIT_SOI_OBJECT_LABEL_IDX,
                             FVV_DESCRIPTOR_SOI_OBJECT_LABEL_IDX);
        }

        if (self->soi_priority_present_flag)
        {
          buff->write_bits(buff,
                           self->soi_priority_update_flag[k],
                           FVV_BIT_SOI_PRIORITY_UPDATE_FLAG,
                           FVV_DESCRIPTOR_SOI_PRIORITY_UPDATE_FLAG);
          if (self->soi_priority_update_flag[k])
            buff->write_bits(buff,
                             self->soi_priority_value[k],
                             FVV_BIT_SOI_PRIORITY_VALUE,
                             FVV_DESCRIPTOR_SOI_PRIORITY_VALUE);
        }

        if (self->soi_object_hidden_present_flag)
          buff->write_bits(buff,
                           self->soi_object_hidden_flag[k],
                           FVV_BIT_SOI_OBJECT_HIDDEN_FLAG,
                           FVV_DESCRIPTOR_SOI_OBJECT_HIDDEN_FLAG);

        if (self->soi_object_dependency_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_object_dependency_update_flag[k],
              FVV_BIT_SOI_OBJECT_DEPENDENCY_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_OBJECT_DEPENDENCY_UPDATE_FLAG);
          if (self->soi_object_dependency_update_flag[k])
          {
            buff->write_bits(
                buff,
                self->soi_object_num_dependencies[k],
                FVV_BIT_SOI_OBJECT_NUM_DEPENDENCIES,
                FVV_DESCRIPTOR_SOI_OBJECT_NUM_DEPENDENCIES);
            for (j = 0; j < self->soi_object_num_dependencies[k]; j++)
              buff->write_bits(
                  buff,
                  self->soi_object_dependency_idx[k][j],
                  FVV_BIT_SOI_OBJECT_DEPENDENCY_IDX,
                  FVV_DESCRIPTOR_SOI_OBJECT_DEPENDENCY_IDX);
          }
        }

        if (self->soi_visibility_cones_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_visibility_cones_update_flag[k],
              FVV_BIT_SOI_VISIBILITY_CONES_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_VISIBILITY_CONES_UPDATE_FLAG);
          if (self->soi_visibility_cones_update_flag[k])
          {
            buff->write_bits(buff,
                             self->soi_direction_x[k],
                             FVV_BIT_SOI_DIRECTION_X,
                             FVV_DESCRIPTOR_SOI_DIRECTION_X);
            buff->write_bits(buff,
                             self->soi_direction_y[k],
                             FVV_BIT_SOI_DIRECTION_Y,
                             FVV_DESCRIPTOR_SOI_DIRECTION_Y);
            buff->write_bits(buff,
                             self->soi_direction_z[k],
                             FVV_BIT_SOI_DIRECTION_Z,
                             FVV_DESCRIPTOR_SOI_DIRECTION_Z);
            buff->write_bits(buff,
                             self->soi_angle[k],
                             FVV_BIT_SOI_ANGLE,
                             FVV_DESCRIPTOR_SOI_ANGLE);
          }
        }

        if (self->soi_3d_bounding_box_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_3d_bounding_box_update_flag[k],
              FVV_BIT_SOI_3D_BOUNDING_BOX_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_UPDATE_FLAG);
          if (self->soi_3d_bounding_box_update_flag[k])
          {
            buff->write_bits(buff,
                             self->soi_3d_bounding_box_x[k],
                             FVV_BIT_SOI_3D_BOUNDING_BOX_X,
                             FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_X);
            buff->write_bits(buff,
                             self->soi_3d_bounding_box_y[k],
                             FVV_BIT_SOI_3D_BOUNDING_BOX_Y,
                             FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_Y);
            buff->write_bits(buff,
                             self->soi_3d_bounding_box_z[k],
                             FVV_BIT_SOI_3D_BOUNDING_BOX_Z,
                             FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_Z);
            buff->write_bits(
                buff,
                self->soi_3d_bounding_box_size_x[k],
                FVV_BIT_SOI_3D_BOUNDING_BOX_SIZE_X,
                FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SIZE_X);
            buff->write_bits(
                buff,
                self->soi_3d_bounding_box_size_y[k],
                FVV_BIT_SOI_3D_BOUNDING_BOX_SIZE_Y,
                FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SIZE_Y);
            buff->write_bits(
                buff,
                self->soi_3d_bounding_box_size_z[k],
                FVV_BIT_SOI_3D_BOUNDING_BOX_SIZE_Z,
                FVV_DESCRIPTOR_SOI_3D_BOUNDING_BOX_SIZE_Z);
          }
        }

        if (self->soi_collision_shape_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_collision_shape_update_flag[k],
              FVV_BIT_SOI_COLLISION_SHAPE_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_COLLISION_SHAPE_UPDATE_FLAG);
          if (self->soi_collision_shape_update_flag[k])
            buff->write_bits(buff,
                             self->soi_collision_shape_id[k],
                             FVV_BIT_SOI_COLLISION_SHAPE_ID,
                             FVV_DESCRIPTOR_SOI_COLLISION_SHAPE_ID);
        }

        if (self->soi_point_style_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_point_style_update_flag[k],
              FVV_BIT_SOI_POINT_STYLE_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_POINT_STYLE_UPDATE_FLAG);
          if (self->soi_point_style_update_flag[k])
          {
            buff->write_bits(buff,
                             self->soi_point_shape_id[k],
                             FVV_BIT_SOI_POINT_SHAPE_ID,
                             FVV_DESCRIPTOR_SOI_POINT_SHAPE_ID);
            buff->write_bits(buff,
                             self->soi_point_size[k],
                             FVV_BIT_SOI_POINT_SIZE,
                             FVV_DESCRIPTOR_SOI_POINT_SIZE);
          }
        }

        if (self->soi_material_id_present_flag)
        {
          buff->write_bits(
              buff,
              self->soi_material_id_update_flag[k],
              FVV_BIT_SOI_MATERIAL_ID_UPDATE_FLAG,
              FVV_DESCRIPTOR_SOI_MATERIAL_ID_UPDATE_FLAG);
          if (self->soi_material_id_update_flag[k])
            buff->write_bits(buff,
                             self->soi_material_id[k],
                             FVV_BIT_SOI_MATERIAL_ID,
                             FVV_DESCRIPTOR_SOI_MATERIAL_ID);
        }
      }
    }
  }

  return FVV_RET_SUCCESS;
}

fvv_ret_t fvv_scene_object_information_copy_from(
    fvv_scene_object_information_t *self,
    fvv_scene_object_information_t *other)
{
  if (!self)
  {
    return FVV_RET_UNINITIALIZED;
  }

  self->set_soi_persistence_flag(self, other->soi_persistence_flag);
  self->set_soi_reset_flag(self, other->soi_reset_flag);
  self->set_soi_num_object_updates(self,
                                   other->soi_num_object_updates);
  self->set_soi_simple_objects_flag(self,
                                    other->soi_simple_objects_flag);
  self->set_soi_object_label_present_flag(
      self, other->soi_object_label_present_flag);
  self->set_soi_priority_present_flag(
      self, other->soi_priority_present_flag);
  self->set_soi_object_hidden_present_flag(
      self, other->soi_object_hidden_present_flag);
  self->set_soi_object_dependency_present_flag(
      self, other->soi_object_dependency_present_flag);
  self->set_soi_visibility_cones_present_flag(
      self, other->soi_visibility_cones_present_flag);
  self->set_soi_3d_bounding_box_present_flag(
      self, other->soi_3d_bounding_box_present_flag);
  self->set_soi_collision_shape_present_flag(
      self, other->soi_collision_shape_present_flag);
  self->set_soi_point_style_present_flag(
      self, other->soi_point_style_present_flag);
  self->set_soi_material_id_present_flag(
      self, other->soi_material_id_present_flag);
  self->set_soi_extension_present_flag(
      self, other->soi_extension_present_flag);
  self->set_soi_3d_bounding_box_scale_log2(
      self, other->soi_3d_bounding_box_scale_log2);
  self->set_soi_log2_max_object_idx_updated_minus1(
      self, other->soi_log2_max_object_idx_updated_minus1);
  self->set_soi_log2_max_object_dependency_idx(
      self, other->soi_log2_max_object_dependency_idx);
  self->set_soi_object_idx(
      self, other->soi_object_idx, other->soi_object_idx_size);
  self->set_soi_object_cancel_flag(
      self,
      other->soi_object_cancel_flag,
      other->soi_object_cancel_flag_size);
  self->set_soi_object_label_update_flag(
      self,
      other->soi_object_label_update_flag,
      other->soi_object_label_update_flag_size);
  self->set_soi_object_label_idx(self,
                                 other->soi_object_label_idx,
                                 other->soi_object_label_idx_size);
  self->set_soi_priority_update_flag(
      self,
      other->soi_priority_update_flag,
      other->soi_priority_update_flag_size);
  self->set_soi_priority_value(self,
                               other->soi_priority_value,
                               other->soi_priority_value_size);
  self->set_soi_object_hidden_flag(
      self,
      other->soi_object_hidden_flag,
      other->soi_object_hidden_flag_size);
  self->set_soi_object_dependency_update_flag(
      self,
      other->soi_object_dependency_update_flag,
      other->soi_object_dependency_update_flag_size);
  self->set_soi_object_num_dependencies(
      self,
      other->soi_object_num_dependencies,
      other->soi_object_num_dependencies_size);
  self->set_soi_object_dependency_idx(
      self,
      other->soi_object_dependency_idx,
      other->soi_object_dependency_idx_size);
  self->set_soi_visibility_cones_update_flag(
      self,
      other->soi_visibility_cones_update_flag,
      other->soi_visibility_cones_update_flag_size);
  self->set_soi_direction_x(
      self, other->soi_direction_x, other->soi_direction_x_size);
  self->set_soi_direction_y(
      self, other->soi_direction_y, other->soi_direction_y_size);
  self->set_soi_direction_z(
      self, other->soi_direction_z, other->soi_direction_z_size);
  self->set_soi_angle(self, other->soi_angle, other->soi_angle_size);
  self->set_soi_3d_bounding_box_update_flag(
      self,
      other->soi_3d_bounding_box_update_flag,
      other->soi_3d_bounding_box_update_flag_size);
  self->set_soi_3d_bounding_box_x(self,
                                  other->soi_3d_bounding_box_x,
                                  other->soi_3d_bounding_box_x_size);
  self->set_soi_3d_bounding_box_y(self,
                                  other->soi_3d_bounding_box_y,
                                  other->soi_3d_bounding_box_y_size);
  self->set_soi_3d_bounding_box_z(self,
                                  other->soi_3d_bounding_box_z,
                                  other->soi_3d_bounding_box_z_size);
  self->set_soi_3d_bounding_box_size_x(
      self,
      other->soi_3d_bounding_box_size_x,
      other->soi_3d_bounding_box_size_x_size);
  self->set_soi_3d_bounding_box_size_y(
      self,
      other->soi_3d_bounding_box_size_y,
      other->soi_3d_bounding_box_size_y_size);
  self->set_soi_3d_bounding_box_size_z(
      self,
      other->soi_3d_bounding_box_size_z,
      other->soi_3d_bounding_box_size_z_size);
  self->set_soi_collision_shape_update_flag(
      self,
      other->soi_collision_shape_update_flag,
      other->soi_collision_shape_update_flag_size);
  self->set_soi_collision_shape_id(
      self,
      other->soi_collision_shape_id,
      other->soi_collision_shape_id_size);
  self->set_soi_point_style_update_flag(
      self,
      other->soi_point_style_update_flag,
      other->soi_point_style_update_flag_size);
  self->set_soi_point_shape_id(self,
                               other->soi_point_shape_id,
                               other->soi_point_shape_id_size);
  self->set_soi_point_size(
      self, other->soi_point_size, other->soi_point_size_size);
  self->set_soi_material_id_update_flag(
      self,
      other->soi_material_id_update_flag,
      other->soi_material_id_update_flag_size);
  self->set_soi_material_id(
      self, other->soi_material_id, other->soi_material_id_size);

  return FVV_RET_SUCCESS;
}