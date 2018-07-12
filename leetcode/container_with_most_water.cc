#include "common.h"

// 19ms 96.59%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int max_val = 0;
        while (lo < hi) {
            max_val = max(max_val, min(height[lo], height[hi]) * (hi - lo));
            /**
             * 设x为height，由于水的容量是min(x[lo], x[hi]) * (hi - lo)
             * 初始时使得hi - lo最大，之后若要使容量增大则必须增大min(x[lo], x[hi])
             * 因为hi - lo会越来越小。
             */
            if (height[lo] < height[hi]) {
                ++lo;
            } else {
                --hi;
            }
        }
        return max_val;
    }
};