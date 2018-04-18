class Solution {
public:
    // 计算10的n次方
    unsigned int power10(unsigned int n) {
        if (n == 0)
            return 1;
        int x = power10(n / 2);
        if (n % 2)
            return 10 * x * x;
        else
            return x * x;
    }
    
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        if (n < 10)
            return 1;
        int nBits = 1;  // 十进制位数
        int highBit = n;
        for (; highBit >= 10; highBit /= 10) {
            nBits++;
        }
        // 若n=3234，则0~999,1000~1999,2000~2999的后三位中
        // 1出现的次数均为10^3 * (1/10) * 3次
        // 而在最高位1出现的次数为1000，如果最高位为1，比如n=1234
        // 则在最高位1出现的次数为235
        int sum = highBit * power10(nBits - 2) * (nBits - 1);
        int temp = power10(nBits - 1);
        if (highBit > 1)
            sum += temp;
        else
            sum += (n % temp + 1);
        return sum + NumberOf1Between1AndN_Solution(n % temp);
    }
};