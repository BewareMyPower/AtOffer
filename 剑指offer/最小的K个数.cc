#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

/**
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */
class Solution {
public:
    // 最大堆保存最大的k个数，堆顶是最大的，每次和新元素比较，若小于堆顶则替代堆顶
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n = input.size();
        if (k == 0 || n < k)
            return {};
        priority_queue<int> q;  // 最大堆
        for (int i = 0; i < k; i++)
            q.push(input[i]);
        for (int i = k; i < n; i++) {
            if (q.top() > input[i]) {
                q.pop();
                q.push(input[i]);
            }
        }
        vector<int> v;
        while (!q.empty()) {
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }

    // 闭区间[low, high]，未检查low>high
/*    int Partition(vector<int>& v, int low, int high) {
        int mid = (low + high) / 2;
        std::swap(v[low], v[mid]);
        int pivot = v[low];
        while (low < high) {
            while (low < high && v[high] >= pivot)
                high--;
			if (low < high)
				v[low++] = v[high];
            while (low < high && v[low] < pivot)
                low++;
			if (low < high)
				v[high--] = v[low];
        }
        v[low] = pivot;
        return low;
    }

    // 即找出第k+1大的数字，input[0..k-1]即最小的k个数字
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        auto& v = input;
        int n = v.size();
        if (k > n || k <= 0 || n == 0)
            return {};
        if (k == n)
            return v;
        int low = 0;
        int high = n - 1;
        while (true) {
            int pos = Partition(input, low, high);
            if (pos == k)
                break;
            else if (pos < k)
                low = pos + 1;
            else
                high = pos - 1;
        }
        vector<int> res(k);
        res.assign(v.begin(), v.begin() + k);
        return res;
    }*/
};
