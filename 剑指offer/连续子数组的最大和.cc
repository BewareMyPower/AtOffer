class Solution {
public:
    // 记f(i)为以第i个数字结尾的子序列的最大和，则有下列递推式
    // 1. f(i-1)>=0  f(i)=f(i-1)+a[i]
    // 2. f(i-1)<0   f(i)=a[i]
    // 其中f(0)=a[0]，则最大子序列和为max(f[i])
    int FindGreatestSumOfSubArray(vector<int> array) {
        auto& a = array;
        int n = a.size();
        if (n == 0)
            return 0;
        vector<int> f(n);
        f[0] = a[0];
        for (int i = 1; i < n; ++i) {
            if (f[i - 1] > 0)
                f[i] = f[i - 1] + a[i];
            else
                f[i] = a[i];
        }
        return *std::max_element(f.begin(), f.end());
    }
};