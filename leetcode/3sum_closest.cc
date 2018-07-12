#include "common.h"

// 4ms 100%
class Solution {
public:
    using LL = long long;

    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int diff = (res > target) ? res - target : target - res;
        if (diff == 0) return res;

        sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 2 < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // 跳过重复元素
                size_t lo = i + 1, hi = nums.size() - 1;
                // 依旧采用threeSum()的向内逼近法
                while (lo < hi) {
                    LL sum = nums[i] + nums[lo] + nums[hi];
                    printf("sum: %lld; %zd,%zd,%zd\n", sum, i, lo, hi);
                    int cur_diff = abs(sum - target);
                    if (cur_diff < diff) {  // 找到更近的值
                        diff = cur_diff;
                        res = sum;
                        if (diff == 0) return res;
                    }
                    // 使sum更逼近target
                    if (sum < target) {
                        ++lo;
                    } else {
                        --hi;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> v{-3, -2, -5, 3, -4};
    cout << Solution().threeSumClosest(v, -1) << endl;
}
