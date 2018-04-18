/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
 */
class Solution {
public:
    int Fibonacci(int n) {
        int a[2] = {0,1};
        if (n < 2)
            return a[n];
        for (int i = 2; i <= n; i++)
            a[i % 2] = a[0] + a[1];
        return a[n % 2];
    }
};