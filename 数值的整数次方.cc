/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent < 0)
            return 1.0 / Power(base, -exponent);
        
        bool is_odd = exponent % 2 != 0;
        // 使用二分法计算
        double half_res = Power(base, exponent / 2);
        return half_res * half_res * (is_odd ? base : 1);
    }
};