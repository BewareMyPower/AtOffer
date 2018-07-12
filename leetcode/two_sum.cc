#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;  // 记录已遍历过的元素的值与其在nums中的下标
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (um.find(other) != um.end())
                return {um[other], i};
            else
                um[nums[i]] = i;
        }
        return {};
    }
};