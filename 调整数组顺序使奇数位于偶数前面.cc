/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 * 所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
class Solution {
public:
	/*
	void reOrderArray(vector<int> &array) {
		// O(1)空间复杂度 O(Nlog(N))时间复杂度
		auto is_odd = [](int x) { return (x & 1) == 1; };
        auto is_even = std::not1(std::function<bool (int)>(is_odd));
        std::stable_sort(array.begin(), array.end(), [&](int x, int y) {
            return is_odd(x) && is_even(y);  // 左边为奇数右边为偶数
        });
	}
	*/
	void reOrderArray(vector<int> &array) {
		// 空间足够则时间复杂度是线性的，否则有N*log(N)次交换
		std::stable_partition(array.begin(), array.end(), [](int x) { return (x&1) == 1; });
	}
	/*
    void reOrderArray(vector<int> &array) {
		// O(N)空间复杂度 O(N)时间复杂度
        auto is_odd = [](int x) { return (x & 1) == 1; };
        const vector<int> array_copy = array;
         
        // 是count_if而非count!!!
        size_t nOdd = count_if(array_copy.cbegin(), array_copy.cend(), is_odd);
        size_t idx_odd = 0;
        size_t idx_even = nOdd;
         
        for (int i : array_copy) {
            if (is_odd(i))
                array[idx_odd++] = i;
            else
                array[idx_even++] = i;
        }
    }
	*/
};

