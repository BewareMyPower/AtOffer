#include "common.h"

// 20ms 48.18%
int myAtoi(char* str) {
    while (*str == ' ') ++str;  // 去除首部空格
    int sign = 1, base = 0;
    if (*str == '+' || *str == '-') {
        sign = 1 - 2 * (*str++ == '-');  // 如为正负号，则在判断正负号的同时移动到下个字符
    }
    while (isdigit(*str)) {
        int digit = *str++ - '0';
        if (base > INT_MAX / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        } else if (base == INT_MAX / 10) {  // 判断最低位
            if (sign == 1 && digit >= INT_MAX % 10)
                return INT_MAX;
            if (sign == -1 && digit >= (INT_MAX % 10 + 1))
                return INT_MIN;
        }
        base = base * 10 + digit;
    }
    return base * sign;
}