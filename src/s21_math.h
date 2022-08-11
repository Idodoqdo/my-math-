#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

/* тут нужно использовать 0.0/0.0L чтоб это работало с long double */

/* not a number */
#define S21_NAN 0.0/0.0L

/* infinity number */
#define S21_INF 1.0/0.0L

/* infinity number */
#define S21_NINF -1.0/0.0L

/* precision */
#define S21_EPS 1e-6

#define S21_EPS_7 1e-7

/* natural logarithm 2 log(2) */
#define S21_LN2 0.69314718055994530942

/* pi number */
#define S21_M_PI 3.141592653589793238462643383279502884L

/* pi/2 number */
#define S21_M_PI_2 1.570796326794896619231321691639751442L


long int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double x, double y);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_fact(long double x);
long double s21_acos(double x);


long double s21_fact(long double x);

#endif  // SRC_S21_MATH_H_
