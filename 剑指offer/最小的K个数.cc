/**
 * 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */
class Solution {
public:
	// 直接用优先队列来做，注意默认std::less是最大堆
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        auto& v = input;
        int n = v.size();
        if (k > n || k <= 0 || n == 0)
            return {};
        std::priority_queue<int, vector<int>, std::greater<int>> q;
        for (int i : input)
            q.push(i);
        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
	
	// 用堆算法，根据k的大小选择构造最小堆还是最大堆
/*    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        auto& v = input;
        int n = v.size();
        if (k > n || k <= 0 || n == 0)
            return {};
        if (k > n / 2) {  // 最大堆，将最大的n-k个元素剔除
            make_heap(v.begin(), v.end());
            for (int i = 0; i < n - k; ++i)
                pop_heap(v.begin(), v.end() - i);
            v.resize(k);
            return v;
        } else {  // 最小堆，将最小的k个元素加入新的vector中
            vector<int> res;
            res.reserve(k);
            auto pred = std::greater<int>();
            make_heap(v.begin(), v.end(), pred);
            for (int i = 0; i < k; i++) {
                res.push_back(v[0]);
                pop_heap(v.begin(), v.end() - i, pred);
            }
            return res;
        }
    }*/

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