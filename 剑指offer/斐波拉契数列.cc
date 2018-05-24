/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
 */
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) return 0;
        if (n <= 1) return 1;
        int a[2] = {1, 1};
        for (int i = 3; i <= n; ++i) {
            int temp = a[0] + a[1];
            a[0] = a[1];
            a[1] = temp;
        }
        return a[1];
    }
};