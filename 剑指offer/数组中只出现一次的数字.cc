#include <vector>
using std::vector;

/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
class Solution {
public:
    // 1. 位运算性质，x^0=x，x^x=0，x^y=y^x得到x^y^x=y^x^x=y^0=y
    // 2. 因此若data累计xor运算结果为z，则z=x*y且x!=y，其中*num1=x，*num2=y
    // x!=y意味着x和y必有一位分别为1和0，找到这一位后可以根据这一位是1还是0
    // 把整个数组分成2个序列，x和y分别分布在2个序列中，相同的元素肯定分布在同一个
    // 子序列中，因此x和y为所在的子序列的异或累积和
    void FindNumsAppearOnce(vector<int> data, int* num1,int *num2) {
        int sum = 0;
        for (int x : data)
            sum ^= x;
        int mask = 1;
        while (!(sum & mask))
            mask <<= 1;
        *num1 = *num2 = 0;
        for (int x : data) {
            if (x & mask)
                *num1 ^= x;
            else
                *num2 ^= x;
        }
    }
};
