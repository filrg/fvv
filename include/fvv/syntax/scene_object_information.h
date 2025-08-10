#ifndef FVV_SYNTAX_SCENE_OBJECT_INFORMATION_H
#define FVV_SYNTAX_SCENE_OBJECT_INFORMATION_H

#include <fvv/defs.h>
#include <fvv/semantic.h>

// F.2.12.1 Scene object information SEI message syntax
struct fvv_scene_object_information_t
{
  fvv_bitstream_t *data;

  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_persistence_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_reset_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_num_object_updates);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_simple_objects_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_object_label_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_priority_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_object_hidden_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_object_dependency_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_visibility_cones_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_3d_bounding_box_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_collision_shape_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_point_style_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_material_id_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_extension_present_flag);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_3d_bounding_box_scale_log2);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_log2_max_object_idx_updated_minus1);
  FVV_DECLARE_SCALAR_SETTER_PTR(fvv_scene_object_information_t,
                                soi_log2_max_object_dependency_idx);

  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_idx);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_cancel_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_label_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_label_idx);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_priority_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_priority_value);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_hidden_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_dependency_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_num_dependencies);
  FVV_DECLARE_2D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_object_dependency_idx);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_visibility_cones_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_direction_x);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_direction_y);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_direction_z);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_angle);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_x);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_y);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_z);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_size_x);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_size_y);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_3d_bounding_box_size_z);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_collision_shape_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_collision_shape_id);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_point_style_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_point_shape_id);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_point_size);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_material_id_update_flag);
  FVV_DECLARE_1D_ARR_SETTER_PTR(fvv_scene_object_information_t,
                                        soi_material_id);

  fvv_ret_t (*pack)(fvv_scene_object_information_t *self,
                    uint64_t payloadSize);
  fvv_ret_t (*copy_from)(fvv_scene_object_information_t *self,
                         fvv_scene_object_information_t *other);
};

fvv_ret_t fvv_scene_object_information_init(fvv_scene_object_information_t *self,
                                            fvv_bitstream_t *data);
fvv_ret_t fvv_scene_object_information_destroy(fvv_scene_object_information_t *self);
fvv_ret_t fvv_scene_object_information_pack(fvv_scene_object_information_t *self,
                                            uint64_t payloadSize);
fvv_ret_t fvv_scene_object_information_copy_from(fvv_scene_object_information_t *self,
                                                 fvv_scene_object_information_t *other);

FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_persistence_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_reset_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_num_object_updates);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_simple_objects_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_object_label_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_priority_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_object_hidden_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_object_dependency_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_visibility_cones_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_3d_bounding_box_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_collision_shape_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_point_style_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_material_id_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_extension_present_flag);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_3d_bounding_box_scale_log2);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_log2_max_object_idx_updated_minus1);
FVV_DECLARE_SCALAR_SETTER(fvv_scene_object_information_t,
                          soi_log2_max_object_dependency_idx);

FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_idx);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_cancel_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_label_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_label_idx);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_priority_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_priority_value);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_hidden_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_dependency_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_num_dependencies);
FVV_DECLARE_2D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_object_dependency_idx);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_visibility_cones_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_direction_x);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_direction_y);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_direction_z);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_angle);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_x);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_y);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_z);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_size_x);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_size_y);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_3d_bounding_box_size_z);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_collision_shape_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_collision_shape_id);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_point_style_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_point_shape_id);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_point_size);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_material_id_update_flag);
FVV_DECLARE_1D_ARR_SETTER(fvv_scene_object_information_t,
                                  soi_material_id);

#endif // FVV_SYNTAX_SCENE_OBJECT_INFORMATION_H