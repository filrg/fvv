#include <fvv/syntax.h>

int main()
{
    fvv_v3c_unit_header_t vuh = {0};
    fvv_v3c_unit_header_init(&vuh);

    vuh.vuh_unit_type = FVV_V3C_OVD;
    vuh.vuh_v3c_parameter_set_id = 14;
    vuh.vuh_atlas_id = 40;
    vuh.vuh_attribute_index = 69;
    vuh.vuh_attribute_partition_index = 23;
    vuh.vuh_map_index = 6;
    vuh.vuh_auxiliary_video_flag = 0;

    vuh.pack(&vuh);

    fvv_v3c_unit_header_destroy(&vuh);
}
