class Solution {
public:
    // 直接利用STL算法实现
    int GetNumberOfK(vector<int> data ,int k) {
        auto l = lower_bound(data.cbegin(), data.cend(), k);
        auto h = upper_bound(data.cbegin(), data.cend(), k);
        return distance(l, h);
    }
/*	// 手动实现二分法查找上下界
    // returns index which meets following conditions:
    // 1. data[index]>=k or index==data.size()
    // 2. data[i]<k for i<index
    int findLowerBound(const vector<int>& data, int k) {
        int l = 0;
        int h = data.size();
        while (l < h) {  // [l,h)
            int m = (l + h) / 2;
            if (data[m] < k) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }

    // returns index which meets following conditions:
    // 1. data[index]>k or index==data.size()
    // 2. data[i]<=k for i<index
    int findUpperBound(const vector<int>& data, int k) {
        int l = 0;
        int h = data.size();
        while (l < h) {  // [l,h)
            int m = (l + h) / 2;
            if (data[m] <= k) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }
    
    int GetNumberOfK(vector<int> data ,int k) {
        return findUpperBound(data, k) - findLowerBound(data, k);
    }*/
};