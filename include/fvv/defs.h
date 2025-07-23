#ifndef FVV_DEFS_H
#define FVV_DEFS_H

#include <stdint.h>
#include <stdlib.h>

typedef uint16_t fvv_ret_t;

#define FVV_RET_SUCCESS               0x0000
#define FVV_RET_FAIL                  0x0001
#define FVV_RET_UNINITIALIZED         0x0002
#define FVV_RET_UNSUPPORT             0x0003
#define FVV_RET_ILLEGAL_MEMORY_ACCESS 0x0004

#define FVV_FAILED(x)                 ((x) != FVV_RET_SUCCESS)
#define FVV_SUCCEEDED(x)              ((x) == FVV_RET_SUCCESS)

typedef uint8_t fvv_bool_t;

#define FVV_FALSE         0x00
#define FVV_TRUE          0x01

#define FVV_NULL          ((void *)0)

#define FVV_BITS_PER_BYTE 0x08

#endif
