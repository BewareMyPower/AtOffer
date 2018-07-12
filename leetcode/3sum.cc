#include "common.h"

// 72ms 98.69%
class Solution {
public:
    // 对于nums[i]==INT_MIN的特殊情况，-nums[i]会溢出，仍然是INT_MIN
    // 这里简单地用long long来处理，因为后面的twoSum()仍然会出现溢出的问题
    using LL = long long;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序后对于-1,-1,0,0,0,1,1这样的情况，就可以仅在{-1,0,1}中查找，防止添加重复结果
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (size_t i = 0; i + 2 < nums.size(); ++i) {
            // 找到重复连续子序列中的第1个元素下标
            if (i == 0 || nums[i] != nums[i - 1]) {
                // 求解有序数组的twoSum()问题，由于要求解所有解，所以二分法反而会更慢，复杂度是O(nlogn)
                // 而直接从左右两侧向内逼近的方法，复杂度是O(n)
                int lo = i + 1, hi = nums.size() - 1;
                LL target = -static_cast<LL>(nums[i]);
                while (lo < hi) {
                    LL sum = nums[lo] + nums[hi];
                    if (sum == target) {
                        res.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1])
                            ++lo;
                        while (lo < hi && nums[hi] == nums[hi - 1])
                            --hi;
                        ++lo;
                        --hi;
                    } else if (sum < target) {
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