#include <fvv/bitstream.h>
#include <fvv/semantic.h>

int main()
{
  fvv_bitstream_t bits = {0};

  uint64_t        foo  = 0x000000FA; // u(8)
  uint64_t        bar  = 0x00001357; // u(13)
  uint64_t        baz  = 0x00000004; // u(3)

  fvv_bitstream_init(&bits);

  bits.alloc(&bits, 3);
  bits.write_bits(&bits, foo, 8, FVV_DESCRIPTOR_U);
  bits.write_bits(&bits, bar, 13, FVV_DESCRIPTOR_U);
  bits.write_bits(&bits, baz, 3, FVV_DESCRIPTOR_U);

  fvv_bitstream_destroy(&bits);
}
