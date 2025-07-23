#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <fvv/math.h>

int8_t fvv_abs_int8(int8_t x)
{
  return (x == INT8_MIN) ? INT8_MAX : ((x < 0) ? -x : x);
}
int16_t fvv_abs_int16(int16_t x)
{
  return (x == INT16_MIN) ? INT16_MAX : ((x < 0) ? -x : x);
}
int32_t fvv_abs_int32(int32_t x)
{
  return (x == INT32_MIN) ? INT32_MAX : ((x < 0) ? -x : x);
}
int64_t fvv_abs_int64(int64_t x)
{
  return (x == INT64_MIN) ? INT64_MAX : ((x < 0) ? -x : x);
}
float fvv_abs_float32(float x)
{
  return fabsf(x);
}
double fvv_abs_float64(double x)
{
  return fabs(x);
}
double fvv_abs_default(double x)
{
  return fvv_abs_float64(x);
}

float fvv_ceil_float32(float x)
{
  return ceilf(x);
}
double fvv_ceil_float64(double x)
{
  return ceil(x);
}
double fvv_ceil_default(double x)
{
  return fvv_ceil_float64(x);
}

int8_t fvv_clip3_int8(int8_t min, int8_t max, int8_t x)
{
  return (x < min) ? min : (x > max) ? max : x;
}
int16_t fvv_clip3_int16(int16_t min, int16_t max, int16_t x)
{
  return (x < min) ? min : (x > max) ? max : x;
}
int32_t fvv_clip3_int32(int32_t min, int32_t max, int32_t x)
{
  return (x < min) ? min : (x > max) ? max : x;
}
int64_t fvv_clip3_int64(int64_t min, int64_t max, int64_t x)
{
  return (x < min) ? min : (x > max) ? max : x;
}
float fvv_clip3_float32(float min, float max, float x)
{
  return fminf(fmaxf(x, min), max);
}
double fvv_clip3_float64(double min, double max, double x)
{
  return fmin(fmax(x, min), max);
}

float fvv_floor_float32(float x)
{
  return floorf(x);
}
double fvv_floor_float64(double x)
{
  return floor(x);
}

float fvv_log2_float32(float x)
{
  return log2f(x);
}
double fvv_log2_float64(double x)
{
  return log2(x);
}

float fvv_log10_float32(float x)
{
  return log10f(x);
}
double fvv_log10_float64(double x)
{
  return log10(x);
}

float fvv_mean_float(const float *a, size_t n)
{
  float sum = 0.0f;
  for (size_t i = 0; i < n; ++i)
    sum += a[i];
  return sum / n;
}
double fvv_mean_double(const double *a, size_t n)
{
  double sum = 0.0;
  for (size_t i = 0; i < n; ++i)
    sum += a[i];
  return sum / n;
}

static int float_cmp(const void *a, const void *b)
{
  float fa = *(const float *)a, fb = *(const float *)b;
  return (fa > fb) - (fa < fb);
}
static int double_cmp(const void *a, const void *b)
{
  double da = *(const double *)a, db = *(const double *)b;
  return (da > db) - (da < db);
}

void fvv_sort_float(float *a, size_t n)
{
  qsort(a, n, sizeof(float), float_cmp);
}
void fvv_sort_double(double *a, size_t n)
{
  qsort(a, n, sizeof(double), double_cmp);
}

float fvv_median_float(float *a, size_t n)
{
  fvv_sort_float(a, n);
  return (n % 2 == 0) ? (a[n / 2 - 1] + a[n / 2]) / 2.0f : a[n / 2];
}
double fvv_median_double(double *a, size_t n)
{
  fvv_sort_double(a, n);
  return (n % 2 == 0) ? (a[n / 2 - 1] + a[n / 2]) / 2.0 : a[n / 2];
}

float fvv_round_float32(float x)
{
  return roundf(x);
}
double fvv_round_float64(double x)
{
  return round(x);
}

int fvv_sign_int(int x)
{
  return (x > 0) - (x < 0);
}
int fvv_sign_float32(float x)
{
  return (x > 0.0f) - (x < 0.0f);
}
int fvv_sign_float64(double x)
{
  return (x > 0.0) - (x < 0.0);
}

float fvv_sqrt_float32(float x)
{
  return sqrtf(x);
}
double fvv_sqrt_float64(double x)
{
  return sqrt(x);
}
