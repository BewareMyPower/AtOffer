/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
class Solution {
public:  // 动态规划 f(n) = f(n-1) + f(n-2)
    int jumpFloor(int n) {  // 测试用例中n>0
        if (n == 1) return 1;
        int a[2] = {1, 2};  // 不同于斐波拉契数列初始值
        for (int i = 3; i <= n; ++i) {
            int temp = a[0] + a[1];
            a[0] = a[1];
            a[1] = temp;
        }
        return a[1];
    }
};