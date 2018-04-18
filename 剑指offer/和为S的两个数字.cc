/**
 * 输入一个递增排序的数组和一个数字S，
 * 在数组中查找两个数，是的他们的和正好是S，
 * 如果有多对数字的和等于S，输出两个数的乘积最小的。
 * PS: 若不存在则返回空序列，否则从小到大输出2个数。
 */
class Solution {
public:
    // 二分法，判断a[l]+a[h]是否为sum，若等于则l=l+1 h=h-1
    // 若小于sum，则判断l是变为(l+h)/2还是l+1
    // 若大于sum，则判断h是变为(l+h)/2还是h-1
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int n = array.size();
        vector<int> res(2);
        int prod = INT_MAX;
        int l = 0;
        int h = n - 1;
        auto assign_res = [&](int i, int j) {
            if (array[i] * array[j] < prod) {
                prod = array[i] * array[j];
                res[0] = array[i];
                res[1] = array[j];
            }
        };
        while (l + 1 < h) {
            int cur = array[l] + array[h];
            int m = (l + h) / 2;
            if (cur == sum) {
                assign_res(l++, h--);
            } else if (cur < sum) {
                l = (array[m] + array[h] <= sum) ? m : (l + 1);
            } else {
                h = (array[l] + array[m] >= sum) ? m : (h - 1);
            }
        }  // h == l + 1或者h == l
        if ((l + 1 == h) && (array[l] + array[h] == sum)) {
            assign_res(l, h);
        }
        return (prod != INT_MAX) ? res : vector<int>();  // 注意不存在时返回空序列
    }
};