#ifndef FVV_MATH_H
#define FVV_MATH_H

#include <stddef.h>
#include <fvv/defs.h>

// Abs
#define fvv_abs(x)             \
  _Generic((x),                \
      int8_t: fvv_abs_int8,    \
      int16_t: fvv_abs_int16,  \
      int32_t: fvv_abs_int32,  \
      int64_t: fvv_abs_int64,  \
      float: fvv_abs_float32,  \
      double: fvv_abs_float64, \
      default: fvv_abs_default)(x)

int8_t  fvv_abs_int8(int8_t x);
int16_t fvv_abs_int16(int16_t x);
int32_t fvv_abs_int32(int32_t x);
int64_t fvv_abs_int64(int64_t x);
float   fvv_abs_float32(float x);
double  fvv_abs_float64(double x);
double  fvv_abs_default(double x);

// Ceil
#define fvv_ceil(x)             \
  _Generic((x),                 \
      float: fvv_ceil_float32,  \
      double: fvv_ceil_float64, \
      default: fvv_ceil_default)(x)

float  fvv_ceil_float32(float x);
double fvv_ceil_float64(double x);
double fvv_ceil_default(double x);

// Clip3
#define fvv_clip3(x, y, z)       \
  _Generic((z),                  \
      int8_t: fvv_clip3_int8,    \
      int16_t: fvv_clip3_int16,  \
      int32_t: fvv_clip3_int32,  \
      int64_t: fvv_clip3_int64,  \
      float: fvv_clip3_float32,  \
      double: fvv_clip3_float64, \
      default: fvv_clip3_float64)(x, y, z)

int8_t  fvv_clip3_int8(int8_t min, int8_t max, int8_t x);
int16_t fvv_clip3_int16(int16_t min, int16_t max, int16_t x);
int32_t fvv_clip3_int32(int32_t min, int32_t max, int32_t x);
int64_t fvv_clip3_int64(int64_t min, int64_t max, int64_t x);
float   fvv_clip3_float32(float min, float max, float x);
double  fvv_clip3_float64(double min, double max, double x);

// Floor
#define fvv_floor(x)             \
  _Generic((x),                  \
      float: fvv_floor_float32,  \
      double: fvv_floor_float64, \
      default: fvv_floor_float64)(x)

float  fvv_floor_float32(float x);
double fvv_floor_float64(double x);

// Log2
#define fvv_log2(x)             \
  _Generic((x),                 \
      float: fvv_log2_float32,  \
      double: fvv_log2_float64, \
      default: fvv_log2_float64)(x)

float  fvv_log2_float32(float x);
double fvv_log2_float64(double x);

// Log10
#define fvv_log10(x)             \
  _Generic((x),                  \
      float: fvv_log10_float32,  \
      double: fvv_log10_float64, \
      default: fvv_log10_float64)(x)

float  fvv_log10_float32(float x);
double fvv_log10_float64(double x);

// Max/Min
#define fvv_max(x, y) ((x) > (y) ? (x) : (y))
#define fvv_min(x, y) ((x) < (y) ? (x) : (y))

// Mean / Median / Sort
float  fvv_mean_float(const float *a, size_t n);
double fvv_mean_double(const double *a, size_t n);
float  fvv_median_float(float *a, size_t n);
double fvv_median_double(double *a, size_t n);
void   fvv_sort_float(float *a, size_t n);
void   fvv_sort_double(double *a, size_t n);

// Round
#define fvv_round(x)             \
  _Generic((x),                  \
      float: fvv_round_float32,  \
      double: fvv_round_float64, \
      default: fvv_round_float64)(x)

float  fvv_round_float32(float x);
double fvv_round_float64(double x);

// Sign
#define fvv_sign(x)             \
  _Generic((x),                 \
      int: fvv_sign_int,        \
      float: fvv_sign_float32,  \
      double: fvv_sign_float64, \
      default: fvv_sign_float64)(x)

int fvv_sign_int(int x);
int fvv_sign_float32(float x);
int fvv_sign_float64(double x);

// Sqrt
#define fvv_sqrt(x)             \
  _Generic((x),                 \
      float: fvv_sqrt_float32,  \
      double: fvv_sqrt_float64, \
      default: fvv_sqrt_float64)(x)

float  fvv_sqrt_float32(float x);
double fvv_sqrt_float64(double x);

#endif // FVV_MATH_H
