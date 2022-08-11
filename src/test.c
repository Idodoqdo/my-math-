#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_test) {
    long int org_result, s21_result;
    int a = -2147483648;
    org_result = abs(a);
    s21_result = s21_abs(a);
    ck_assert_msg(org_result == s21_result, "s21_abs test-1 failed");
    a = -456;
    org_result = abs(a);
    s21_result = s21_abs(a);
    ck_assert_msg(org_result == s21_result, "s21_abs test-2 failed");
    a = 0;
    org_result = abs(a);
    s21_result = s21_abs(a);
    ck_assert_msg(org_result == s21_result, "s21_abs test-3 failed");
}
END_TEST

START_TEST(fabs_test) {
    double org_result;
    long double s21_result;
    double a = 123.456;
    org_result = fabs(a);
    s21_result = s21_fabs(a);
    ck_assert_msg(org_result == s21_result, "s21_fabs test-1 failed");
    a = 456;
    org_result = fabs(a);
    s21_result = s21_fabs(a);
    ck_assert_msg(org_result == s21_result, "s21_fabs test-3 failed");
    a = 0.1;
    org_result = fabs(a);
    s21_result = s21_fabs(a);
    ck_assert_msg(org_result == s21_result, "s21_fabs test-4 failed");
    a = NAN;
    org_result = fabs(a);
    s21_result = s21_fabs(a);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_fabs test-5 failed");
    a = INFINITY;
    org_result = fabs(a);
    s21_result = s21_fabs(a);
    ck_assert_msg(org_result == s21_result, "s21_fabs test-5 failed");
    a = -INFINITY;
    org_result = fabs(a);
    s21_result = s21_fabs(a);
    ck_assert_msg(org_result == s21_result, "s21_fabs test-6 failed");
}
END_TEST

START_TEST(fmod_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    double d = 0.345;
    org_result = fmod(-c, d);
    s21_result = s21_fmod(-c, d);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_fmod test-1 failed");
    org_result = fmod(-c, -d);
    s21_result = s21_fmod(-c, -d);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_fmod test-2 failed");
    org_result = fmod(c, -d);
    s21_result = s21_fmod(c, -d);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_fmod test-3 failed");
    org_result = fmod(c, d);
    s21_result = s21_fmod(c, d);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_fmod test-4 failed");
    c = NAN;
    d = 0.345;
    org_result = fmod(c, d);
    s21_result = s21_fmod(c, d);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_fmod test-5 failed");
    c = 23;
    d = NAN;
    org_result = fmod(c, d);
    s21_result = s21_fmod(c, d);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_fmod test-6 failed");
    c = 23;
    d = INFINITY;
    org_result = fmod(c, d);
    s21_result = s21_fmod(c, d);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_fmod test-7 failed");
    c = INFINITY;
    d = 123;
    org_result = fmod(c, d);
    s21_result = s21_fmod(c, d);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_fmod test-8 failed");
}
END_TEST

START_TEST(log_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    org_result = log(c);
    s21_result = s21_log(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_log test-1 failed");
    c = 0.345;
    org_result = log(c);
    s21_result = s21_log(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_log test-2 failed");
    c = NAN;
    org_result = log(c);
    s21_result = s21_log(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_log test-3 failed");
    c = INFINITY;
    org_result = log(c);
    s21_result = s21_log(c);
    ck_assert_msg(org_result == s21_result, "s21_log test-4 failed");
    c = -INFINITY;
    org_result = log(c);
    s21_result = s21_log(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_log test-5 failed");
}
END_TEST

START_TEST(ceil_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_ceil test-1 failed");
    c = 0.345;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_ceil test-2 failed");
    c = 11;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_ceil test-3 failed");
    c = -11;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_ceil test-4 failed");
    c = -11.23;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_ceil test-5 failed");
    c = -INFINITY;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    ck_assert_msg(org_result == s21_result, "s21_ceil test-6 failed");
    c = INFINITY;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    ck_assert_msg(org_result == s21_result, "s21_ceil test-7 failed");
    c = NAN;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_ceil test-8 failed");
    c = 0;
    org_result = ceil(c);
    s21_result = s21_ceil(c);
    ck_assert_msg(org_result == s21_result, "s21_ceil test-8 failed");
}
END_TEST

START_TEST(pow_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    double b = 2;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_pow test-1 failed");
    c = 0.345;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_pow test-2 failed");
    c = 11;
    b = -12;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_pow test-3 failed");
    c = -11;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_pow test-4 failed");
    c = -11.23;
    b = 0.23;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-5 failed");
    c = NAN;
    b = 0.23;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-6 failed");
    c = NAN;
    b = NAN;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-7 failed");
    c = 0.23;
    b = NAN;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-8 failed");
    c = INFINITY;
    b = NAN;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-9 failed");
    c = NAN;
    b = INFINITY;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-10 failed");
    c = INFINITY;
    b = INFINITY;
    org_result = pow(c, b);
    s21_result = s21_pow(c, b);
    ck_assert_msg(org_result == s21_result, "s21_pow test-11 failed");
}
END_TEST

START_TEST(sqrt_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sqrt test-1 failed");
    c = 0.345;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sqrt test-2 failed");
    c = 11;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sqrt test-3 failed");
    c = -11;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_pow test-4 failed");
    c = -11.23;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_sqrt test-5 failed");
    c = NAN;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_sqrt test-6 failed");
    c = INFINITY;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    ck_assert_msg(org_result == s21_result, "s21_sqrt test-7 failed");
    c = -INFINITY;
    org_result = sqrt(c);
    s21_result = s21_sqrt(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_sqrt test-8 failed");
}
END_TEST

START_TEST(sin_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    org_result = sin(c);
    s21_result = s21_sin(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sin test-1 failed");
    c = 0.345;
    org_result = sin(c);
    s21_result = s21_sin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sin test-2 failed");
    c = 11;
    org_result = sin(c);
    s21_result = s21_sin(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sin test-3 failed");
    c = -11;
    org_result = sin(c);
    s21_result = s21_sin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_sin test-4 failed");

    c = -11.23;
    org_result = sin(c);
    s21_result = s21_sin(c);
    ck_assert_msg(dif == 0, "s21_sin test-5 failed");

    c = NAN;
    org_result = sin(c);
    s21_result = s21_sin(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_sin test-6 failed");
    c = INFINITY;
    org_result = sin(c);
    s21_result = s21_sin(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_sin test-7 failed");
    c = -INFINITY;
    org_result = sin(c);
    s21_result = s21_sin(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_sin test-8 failed");
}
END_TEST

START_TEST(cos_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    org_result = cos(c);
    s21_result = s21_cos(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_cos test-1 failed");
    c = 0.345;
    org_result = cos(c);
    s21_result = s21_cos(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_cos test-2 failed");
    c = 11;
    org_result = cos(c);
    s21_result = s21_cos(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_cos test-3 failed");
    c = -11;
    org_result = cos(c);
    s21_result = s21_cos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_cos test-4 failed");

    c = -11.23;
    org_result = cos(c);
    s21_result = s21_cos(c);
    ck_assert_msg(dif == 0, "s21_cos test-5 failed");

    c = NAN;
    org_result = cos(c);
    s21_result = s21_cos(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_cos test-6 failed");
    c = INFINITY;
    org_result = cos(c);
    s21_result = s21_cos(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_cos test-7 failed");
    c = -INFINITY;
    org_result = cos(c);
    s21_result = s21_cos(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_cos test-8 failed");
}
END_TEST

START_TEST(tan_test) {
    long double org_result, s21_result;
    int dif;
    double c = 123.456;
    org_result = tan(c);
    s21_result = s21_tan(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_tan test-1 failed");
    c = 0.345;
    org_result = tan(c);
    s21_result = s21_tan(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_tan test-2 failed");
    c = 11;
    org_result = tan(c);
    s21_result = s21_tan(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_tan test-3 failed");
    c = -11;
    org_result = tan(c);
    s21_result = s21_tan(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_tan test-4 failed");

    c = -11.23;
    org_result = tan(c);
    s21_result = s21_tan(c);
    ck_assert_msg(dif == 0, "s21_tan test-5 failed");

    c = NAN;
    org_result = tan(c);
    s21_result = s21_tan(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_tan test-6 failed");
    c = INFINITY;
    org_result = tan(c);
    s21_result = s21_tan(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_tan test-7 failed");
    c = -INFINITY;
    org_result = tan(c);
    s21_result = s21_tan(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_tan test-8 failed");
}
END_TEST

START_TEST(exp_test) {
    long double org_result, s21_result;
    int dif;
    double c = 1.2;
    org_result = exp(c);
    s21_result = s21_exp(c);
    long double a = fmod(fabsl(org_result), S21_EPS);
    long double b = fmod(fabsl(s21_result), S21_EPS);
    ck_assert_msg(a == b, "s21_exp test-1 failed");
    c = 0.345;
    org_result = exp(c);
    s21_result = s21_exp(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_exp test-2 failed");
    c = 11;
    org_result = exp(c);
    s21_result = s21_exp(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_exp test-3 failed");
    c = -11;
    org_result = exp(c);
    s21_result = s21_exp(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_exp test-4 failed");
    c = -11.23;
    org_result = exp(c);
    s21_result = s21_exp(c);
    dif = fabsl(org_result - s21_result) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_exp test-5 failed");
    c = NAN;
    org_result = exp(c);
    s21_result = s21_exp(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result,
                  "s21_exp test-6 failed");
    c = INFINITY;
    org_result = exp(c);
    s21_result = s21_exp(c);
    ck_assert_msg(org_result == s21_result, "s21_exp test-7 failed");
    c = -INFINITY;
    org_result = exp(c);
    s21_result = s21_exp(c);
    ck_assert_msg(org_result == s21_result, "s21_exp test-8 failed");
    c = 655;
    org_result = exp(c);
    s21_result = s21_exp(c);
    a = fmod(fabsl(org_result), S21_EPS);
    b = fmod(fabsl(s21_result), S21_EPS);
    dif = fabsl(a - b) <= S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_exp test-9 failed");
}
END_TEST

START_TEST(floor_test) {
    long double org_result, s21_result;
    int dif;
    double c = -123.456;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-1 failed");
    c = 0.345;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-2 failed");
    c = 11;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-3 failed");
    c = -11;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-4 failed");
    c = -11.234456;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-5 failed");
    c = S21_NAN;
    org_result = floor(NAN);
    s21_result = s21_floor(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result , "s21_floor test-6 failed");
    c = 11434444.234456;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-7 failed");
    c = 0.0;
    org_result = floor(c);
    s21_result = s21_floor(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_floor test-8 failed");
    c = S21_INF;
    org_result = floor(INFINITY);
    s21_result = s21_floor(c);
    ck_assert_msg(org_result == s21_result, "s21_floor test-9 failed");
}
END_TEST

START_TEST(asin_test) {
    long double org_result, s21_result;
    int dif;
    double c = 0.832;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-1 failed");
    c = 0.645645;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-2 failed");
    c = -0.645645;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-3 failed");
    c = 212234545.645645;
    org_result = asin(c);
    s21_result = s21_asin(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result, "s21_asin test-4 failed");
    c = -0.234456;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-5 failed");
    c = -1;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-6 failed");
    c = 1;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-7 failed");
    c = S21_NAN;
    org_result = asin(NAN);
    s21_result = s21_asin(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result, "s21_asin test-8 failed");
    c = S21_INF;
    org_result = asin(INFINITY);
    s21_result = s21_asin(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result, "s21_asin test-9 failed");
    c = 0.0;
    org_result = asin(c);
    s21_result = s21_asin(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_asin test-10 failed");
}
END_TEST

START_TEST(acos_test) {
    long double org_result, s21_result;
    int dif;
    double c = 1;
    org_result = acos(c);
    s21_result = s21_acos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_acos test-1 failed");
    c = -1;
    org_result = acos(c);
    s21_result = s21_acos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_acos test-2 failed");
    c = 0.56;
    org_result = acos(c);
    s21_result = s21_acos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_acos test-3 failed");
    c = -0.73;
    org_result = acos(c);
    s21_result = s21_acos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_acos test-4 failed");
    c = -0.234456;
    org_result = acos(c);
    s21_result = s21_acos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_acos test-5 failed");
    c = S21_NAN;
    org_result = acos(NAN);
    s21_result = s21_acos(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result , "s21_acos test-6 failed");
    c = 21434444.234456;
    org_result = acos(c);
    s21_result = s21_acos(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result , "s21_acos test-7 failed");
    c = 0.0;
    org_result = acos(c);
    s21_result = s21_acos(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_acos test-8 failed");
    c = S21_INF;
    org_result = acos(INFINITY);
    s21_result = s21_acos(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result , "s21_acos test-9 failed");
}
END_TEST

START_TEST(atan_test) {
    long double org_result, s21_result;
    int dif;
    double c = 1;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-1 failed");
    c = -1;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-2 failed");
    c = 0.56;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-3 failed");
    c = -0.73;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-4 failed");
    c = -0.234456;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-5 failed");
    c = S21_NAN;
    org_result = atan(NAN);
    s21_result = s21_atan(c);
    ck_assert_msg(org_result != org_result && s21_result != s21_result , "s21_atan test-6 failed");
    c = 21434444.234456;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-7 failed");
    c = 0.0;
    org_result = atan(c);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-8 failed");
    c = S21_INF;
    org_result = atan(INFINITY);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-9 failed");
    c = S21_NINF;
    org_result = atan(-INFINITY);
    s21_result = s21_atan(c);
    dif = fabsl(org_result - s21_result) < S21_EPS ? 0 : 1;
    ck_assert_msg(dif == 0, "s21_atan test-10 failed");
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, abs_test);
    tcase_add_test(tc1_1, fabs_test);
    tcase_add_test(tc1_1, fmod_test);
    tcase_add_test(tc1_1, log_test);
    tcase_add_test(tc1_1, ceil_test);
    tcase_add_test(tc1_1, pow_test);
    tcase_add_test(tc1_1, sqrt_test);
    tcase_add_test(tc1_1, sin_test);
    tcase_add_test(tc1_1, cos_test);
    tcase_add_test(tc1_1, tan_test);
    tcase_add_test(tc1_1, exp_test);
    tcase_add_test(tc1_1, floor_test);
    tcase_add_test(tc1_1, asin_test);
    tcase_add_test(tc1_1, acos_test);
    tcase_add_test(tc1_1, atan_test);


    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
