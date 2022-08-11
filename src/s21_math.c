#include "s21_math.h"

#include <math.h>
#include <stdio.h>

long double s21_fabs(double x) {
    if (x <= 0) {
        x = -x;
    }
    return x;
}

long int s21_abs(int x) {
    if (x <= 0) {
        x = -x;
    }
    return x;
}

long double s21_fmod(double x, double y) {
    return x == S21_INF   ? S21_NAN
           : y == S21_INF ? x
                          : (x - (__int128_t)(x / y) * y);
}

/* Вспомогательная для s21_log */
long double s21_log_taylor(long double x, int mode) {
    long double result = 0;
    long double temp = -1;
    if (mode) {
        result = S21_LN2;
    }
    for (int i = 1; i < 50; i++) {
        if (mode) {
            temp *= (-x / 2);
        } else {
            temp *= -x;
        }
        result += temp / i;
    }
    return result;
}

long double s21_log(double x) {
    int i = 0;
    long double result;
    if (x == S21_INF) {
        result = S21_INF;
    } else if (x == 0) {
        result = S21_NINF;
    } else if (x < 0) {
        result = S21_NAN;
    } else {
        if (x > 2) {
            for (; x > 2; i++) x /= 2;
        } else if (x < 1) {
            for (; x < 1; i--) x *= 2;
        }
        if (x <= 1.5) {
            result = s21_log_taylor(x - 1, 0) + i * S21_LN2;
        } else {
            result = s21_log_taylor(x - 2, 1) + i * S21_LN2;
        }
    }
    return result;
}

/* Вспомогательная для s21_exp */
long double s21_int_pow(long double x, int y) {
    long double result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

/* Вспомогательная для exp при x > 645 */
long double s21_powered_exp(long double x) {
    long double result = x;
    int count = 0, flag = 0;
    if (x > 2 || x < -2) {
        flag = 1;
        while (result > 2) {
            result /= 2;
            count++;
        }
    }
    if (flag) {
        result = s21_exp(result);
        for (int i = 0; i < count; i++) {
            result = s21_int_pow(result, 2);
        }
    }
    return result;
}

long double s21_exp(double x) {
    long double result;
    if (x == S21_INF) {
        result = S21_INF;
    } else if (x == S21_NINF) {
        result = 0;
    } else {
        result = 1;
        int sign = 0;
        if (x < 0) {
            x = fabs(x);
            sign = 1;
        }
        if (x > 645) {
            result = s21_powered_exp(x);
        } else {
            long double fact = 1;
            long double j = 1;
            int i = 1;
            do {
                fact = fact * i;
                j = s21_int_pow(x, i) / fact;
                result = result + j;
                i++;
            } while (j >= S21_EPS_7 * S21_EPS_7);
        }
        if (sign) {
            result = 1.0 / result;
        }
    }
    return result;
}

long double s21_ceil(double x) {
    long double result;
    if (x == S21_INF || x == S21_NINF) {
        result = x;
    } else if (s21_fmod(x, 1.0) == 0.0) {
        result = x;
    } else if (x > 0) {
        result = x + 1 - s21_fmod(x, 1.0);
    } else if (x == 0) {
        result = 0;
    } else {
        result = x - s21_fmod(x, 1.0);
    }
    return result;
}

long double s21_pow(double x, double y) {
    long double result = 1;
    int sign;
    if (y != y) {
        result = S21_NAN;
    } else if ((x == S21_NINF || x == S21_INF) && y != S21_NAN) {
        result = x;
    } else if (x != x) {
        result = S21_NAN;
    } else if ((y == S21_INF || y == S21_NINF) && x != S21_NAN) {
        result = y == S21_INF ? y : 0;
    } else {
        sign = y > 0 ? 0 : 1;
        y = sign ? -y : y;
        if (s21_fmod(y, 1.0) == 0.0) {
            for (int i = 1; i <= y; i++) result *= x;
        } else {
            result = s21_exp(y * s21_log(x));
        }
        result = sign ? 1.0 / result : result;
    }
    return result;
}

long double s21_sqrt(double x) {
    return x == S21_NINF ? S21_NAN : s21_pow(x, 0.5);
}

long double s21_sin(double x) {
    long double s;
    if (x == S21_NINF) {
        s = S21_NAN;
    } else {
        x = s21_fmod(x, S21_M_PI * 2);
        s = 0.0;
        long double y = x;
        int i = 1;
        do {
            s += y;
            y *= (-1 * s21_pow(x, 2)) / (2 * i * (2 * i + 1));
            i++;
        } while ((y > 0.0 ? y : -y) > S21_EPS_7 * S21_EPS_7);
    }
    return s;
}

long double s21_cos(double x) { return s21_sin(x + S21_M_PI_2); }

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_floor(double x) {
    long double result;
    if (x == 0) {
        result = 0;
    } else if (x == S21_INF || x == S21_NINF) {
        result = x;
    } else if (s21_fmod(x, 1.0) == 0.0) {
        result = x;
    } else if (x > 0) {
        result = x - s21_fmod(x, 1.0);
    } else {
        result = x + (s21_fmod(x, 1.0) * (-1)) - 1;
    }
    return result;
}

long double s21_fact(long double x) {
    return (x < 2) ? 1 : x * s21_fact(x - 1);
}
long double s21_asin(double x) {
    long double sum;
    if (x != x) {
        sum = S21_NAN;
    } else if (s21_fabs(x) > 1) {
        sum = S21_NAN;
    } else {
        double last;
        long long int i = 1;
        last = x;
        sum = 0;
        if (x >= 0 && x <= 0.5) {
            while (s21_fabs(last) > S21_EPS_7) {
                sum += last;
                last = (s21_fact(2 * i) / (s21_pow(4, i) * s21_pow(s21_fact(i), 2) * (2 * i + 1)))
                 * s21_pow(x, 2 * i + 1);
                i++;
            }
        } else {
            sum = S21_M_PI_2 - (2 * s21_asin(s21_sqrt((1 - x) / 2)));
        }
    }
    return sum;
}

long double s21_acos(double x) {
    return s21_fabs(x) > 1 ? S21_NAN : S21_M_PI_2 - s21_asin(x);
}

long double s21_atan(double x) {
    long double sum = 0;
    if (x == S21_INF) {
        sum = 1.570796;
    } else if (x == S21_NINF) {
        sum = -1.570796;
    } else {
        if (x != x) {
            sum = S21_NAN;
        } else {
            sum = x / s21_sqrt(s21_pow(x, 2) + 1);
            sum = s21_asin(sum);
        }
    }
    return sum;
}
