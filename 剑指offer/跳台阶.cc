/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
class Solution {
public:  // 动态规划 f(n) = f(n-1) + f(n-2)
    int jumpFloor(int number) {
        if (number <= 0)
            return 0;
        int a[2] = {1, 2};
        int n = number;
        if (n <= 2)
            return a[n - 1];
        for (int i = 3; i <= n; i++)
            a[(i+1) % 2] = a[0] + a[1];
        return a[(n + 1) % 2];
    }
};