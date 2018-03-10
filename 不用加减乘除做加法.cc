/**
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */
class Solution {
public:
    int Add(int num1, int num2)
    {
        while (true) {
            // x + y == num1 + num2
            int x = num1 ^ num2;  // 忽略0和0/1和1的运算
            int y = (num1 & num2) << 1;  // 1和1运算进位
            if (y == 0)
                return x;
            
            num1 = x;
            num2 = y;
        }
    }
};