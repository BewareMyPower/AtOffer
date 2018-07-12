#include "common.h"

// 31ms 40.26%
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;  // x为INT_MIN时，-x溢出，仍然为负数，所以需要单独判断
        if (x < 0) return -reverse(-x);
        while (x > 0 && x % 10 == 0)
            x /= 10;
        int res = 0;
        while (x > 0) {
            // 溢出，这里不用判断res == INT_MAX / 10 && x % 10 > INT_MAX % 10的情况
            // 因为满足上述条件的x在int范围内是不存在的
            if (res > INT_MAX / 10)
                return 0;       
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};