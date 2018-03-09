class Solution {
public:
    // 二分查找，增加当a[low]==a[high]时的判断
    int GetNumberOfK(vector<int> data ,int k) {
        auto l = lower_bound(data.cbegin(), data.cend(), k);
        auto h = upper_bound(data.cbegin(), data.cend(), k);
        return distance(l, h);
    }
};