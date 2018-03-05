/**
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
 * 如果不存在则输出0。
 */
class Solution {
public:
    // 闭区间[low, high]
    int Partition(vector<int>& v, int low, int high) {
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
/*        int pivot = v[low];
        auto it = std::partition(v.begin() + low + 1, v.begin() + high + 1,
            [&](int x) { return x < pivot; });
		std::swap(*(--it), v[low]);
        return std::distance(v.begin(), it);*/
    }
    
    // 出现次数超过一半，那么肯定是第n/2大的数字，问题变成了k-选择问题
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        auto& v = numbers;
        int n = v.size();
        if (n == 0)
            return 0;
        int mid = n / 2;
        int low = 0;
        int high = n - 1;
        while (true) {
            int idx = Partition(v, low, high);
            if (idx == mid)
                break;
            else if (idx < mid)
                low = idx + 1;
            else
                high = idx - 1;
        }
        if (count(v.cbegin(), v.cend(), v[mid]) > mid)
            return v[mid];
        return 0;
    }

	
/*    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        int x = numbers[0];
        int cnt = 1;
        for (size_t i = 1; i < numbers.size(); ++i) {
            if (numbers[i] != x) {
                if (cnt > 0) {
                    cnt--;
                } else {
                    cnt = 1;
                    x = numbers[i];
                }
            } else {
                cnt++;
            }
        }
        // 如果数字在数组中出现一半次数以上，则肯定是x
        if (count(numbers.cbegin(), numbers.cend(), x) > numbers.size() / 2)
            return x;
        return 0;
    }*/
	// 无脑方法，hashmap统计出现次数
/*    int MoreThanHalfNum_Solution(vector<int> numbers) {
        size_t n = numbers.size();
        unordered_map<int, size_t> um;
        for (int i : numbers) {
            if (um.count(i) == 0)
                um[i] = 1;
            else
                um[i]++;
            if (um[i] > (n / 2))
                return i;
        }
        return 0;
    }*/
};