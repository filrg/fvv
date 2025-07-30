fvv_ret_t fvv_end_of_sequence_rbsp_init(
    fvv_end_of_sequence_rbsp_t              *self,
    fvv_atlas_sequence_parameter_set_rbsp_t *aspsr,
    fvv_bitstream_t                         *data)
{
    *self = (fvv_end_of_sequence_rbsp_t){0};
    self->aspsr = aspsr;
    self->data = data;

    self->pack = fvv_end_of_sequence_rbsp_pack;
    self->copy_from = fvv_end_of_sequence_rbsp_copy_from;

    return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_end_of_sequence_rbsp_destroy(fvv_end_of_sequence_rbsp_t *self)
{
    if(!self)
    {
        return FVV_RET_UNINITIALIZED;
    }

    *self = (fvv_end_of_sequence_rbsp_t){0};
    return FVV_RET_SUCCESS;
}
fvv_ret_t
fvv_end_of_sequence_rbsp_pack(fvv_end_of_sequence_rbsp_t *self)
{
    if(!self)
    {
        return FVV_RET_UNINITIALIZED;
    }
    return FVV_RET_SUCCESS;
}
fvv_ret_t fvv_end_of_sequence_rbsp_copy_from(
    fvv_end_of_sequence_rbsp_t *self,
    fvv_end_of_sequence_rbsp_t *other)
{
    if(!self)
    {
        return FVV_RET_UNINITIALIZED;
    }
    return FVV_RET_SUCCESS;
}
