/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
class Solution {
public:
    // 1. 位运算性质，x^0=x，x^x=0，x^y=y^x得到x^y^x=y^x^x=y^0=y
    // 2. 因此若data累计xor运算结果为z，则z=x*y且x!=y，其中*num1=x，*num2=y
    // x!=y意味着x和y必有一位分别为1和0，找到这一位后可以根据这一位是1还是0
    // 把整个数组分成2个序列，x和y分别分布在2个序列中，相同的元素肯定分布在同一个
    // 子序列中，因此x和y为两个子序列的xor累计和
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int xor_sum = accumulate(data.cbegin(), data.cend(), 0, bit_xor<int>());
        int k = FindFirstBitsIs1(xor_sum);
        *num1 = 0;
        *num2 = 0;
        for (int x : data) {
            if (BitsIs1(x, k))
                *num1 ^= x;
            else
                *num2 ^= x;
        }
    }
    
    // 若x的二进制表示中从低位开始第idx(>=0)位为1则返回true
    bool BitsIs1(int x, int idx) {
        return (x & (1 << idx)) != 0;
    }
    
    // 找到x的二进制表示中从低位开始为1的位的下标，下标从最低位为0
    int FindFirstBitsIs1(int x) {
        for (int i = 0; i < 8 * (int)sizeof(int); ++i) {
            if ((x & (1 << i)) != 0)
                return i;
        }
        return -1;  // 若x不为0则不可能到达这一步
    }
};