#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <fvv/math.h>

#define FLOAT_EQ(a, b)  (fabsf((a) - (b)) < FLT_EPSILON)
#define DOUBLE_EQ(a, b) (fabs((a) - (b)) < DBL_EPSILON)

void test_fvv_abs();
void test_fvv_ceil();
void test_fvv_clip3();
void test_fvv_floor();
void test_fvv_log();
void test_fvv_max_min();
void test_fvv_mean_median_sort();
void test_fvv_round();
void test_fvv_sign();
void test_fvv_sqrt();

int main() {
  test_fvv_abs();
  test_fvv_ceil();
  test_fvv_clip3();
  test_fvv_floor();
  test_fvv_log();
  test_fvv_max_min();
  test_fvv_mean_median_sort();
  test_fvv_round();
  test_fvv_sign();
  test_fvv_sqrt();
  puts("All fvv math tests passed.");
  return 0;
}

void test_fvv_abs() {
  assert(fvv_abs((int8_t)-127) == 127);
  assert(fvv_abs((int16_t)-32000) == 32000);
  assert(fvv_abs((int32_t)-1) == 1);
  assert(fvv_abs((int64_t)-123456789012345) == 123456789012345);
  assert(FLOAT_EQ(fvv_abs(-1.5f), 1.5f));
  assert(DOUBLE_EQ(fvv_abs(-2.718), 2.718));
}

void test_fvv_ceil() {
  assert(FLOAT_EQ(fvv_ceil(1.2f), ceilf(1.2f)));
  assert(DOUBLE_EQ(fvv_ceil(-2.8), ceil(-2.8)));
}

void test_fvv_clip3() {
  assert(fvv_clip3(1, 5, 0) == 1);
  assert(fvv_clip3(1, 5, 6) == 5);
  assert(fvv_clip3(1, 5, 3) == 3);
  assert(FLOAT_EQ(fvv_clip3(0.0f, 1.0f, -0.5f), 0.0f));
  assert(DOUBLE_EQ(fvv_clip3(0.0, 1.0, 1.5), 1.0));
}

void test_fvv_floor() {
  assert(FLOAT_EQ(fvv_floor(1.9f), floorf(1.9f)));
  assert(DOUBLE_EQ(fvv_floor(-2.1), floor(-2.1)));
}

void test_fvv_log() {
  assert(FLOAT_EQ(fvv_log2(8.0f), 3.0f));
  assert(DOUBLE_EQ(fvv_log2(16.0), 4.0));
  assert(FLOAT_EQ(fvv_log10(1000.0f), 3.0f));
  assert(DOUBLE_EQ(fvv_log10(1.0), 0.0));
}

void test_fvv_max_min() {
  assert(fvv_max(5, 10) == 10);
  assert(fvv_min(5, 10) == 5);
  assert(fvv_max(3.2, 1.1) == 3.2);
  assert(fvv_min(-1.0, 0.0) == -1.0);
}

void test_fvv_mean_median_sort() {
  float fa[] = {3.0f, 1.0f, 2.0f};
  double da[] = {6.0, 4.0, 2.0, 8.0};
  assert(FLOAT_EQ(fvv_mean_float(fa, 3), 2.0f));
  assert(DOUBLE_EQ(fvv_mean_double(da, 4), 5.0));
  assert(FLOAT_EQ(fvv_median_float(fa, 3), 2.0f));
  assert(DOUBLE_EQ(fvv_median_double(da, 4), 5.0));
}

void test_fvv_round() {
  assert(FLOAT_EQ(fvv_round(2.3f), 2.0f));
  assert(DOUBLE_EQ(fvv_round(2.7), 3.0));
}

void test_fvv_sign() {
  assert(fvv_sign(-5) == -1);
  assert(fvv_sign(0) == 0);
  assert(fvv_sign(5) == 1);
  assert(fvv_sign(-1.0f) == -1);
  assert(fvv_sign(0.0) == 0);
  assert(fvv_sign(2.3) == 1);
}

void test_fvv_sqrt() {
  assert(FLOAT_EQ(fvv_sqrt(9.0f), 3.0f));
  assert(DOUBLE_EQ(fvv_sqrt(16.0), 4.0));
}

