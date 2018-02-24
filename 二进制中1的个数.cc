/**
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 */
class Solution {
public:
    // 注意-k(k>0)的二进制表示是最高位1，剩余部分为k-1的补码
    int NumberOf1(int n) {
        bool is_neg = n < 0;
        n = (n < 0) ? (-n - 1) : n; 
        int res = 0;
        if (n < 0)
            res = 1;
        while (n > 0) {
            res += (n & 1);
            n >>= 1;
        }
        int nbits = sizeof(int) * 8;
        return is_neg ? (nbits - res) : res;
    }
};