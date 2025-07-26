#include <fvv/bitstream.h>

int main()
{
  fvv_bitstream_t bits = {0};

  uint64_t        foo  = 0x000000FA; // u(8)
  uint64_t        bar  = 0x00001357; // u(13)
  uint64_t        baz  = 0x00000004; // u(3)

  fvv_bitstream_init(&bits);
  
  bits.alloc(&bits, 3);
  bits.pad(&bits, foo, 8);
  bits.pad(&bits, bar, 13);
  bits.pad(&bits, baz, 3);

  fvv_bitstream_destroy(&bits);
}
