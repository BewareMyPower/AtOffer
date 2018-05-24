/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */
// 二分查找，在a[l..h]范围内满足a[k]<=...<=a[h]<=a[l]<=...<=a[k-1]
// 则对任意中间点m有a[m]<=a[h] or a[m] >= a[l]
// 若a[m] <= a[l]则m在[k,h]区间内，可以缩小右边界h
// 否则m在[l,k]区间内，可以缩小左边界l
// 特殊情况: a[l] == a[m] == a[k]，无法判断，只能顺序查找
class Solution {
public:
    int minNumberInRotateArray(vector<int> a) {
        int n = a.size();
        if (n == 0) return 0;
        
        int low = 0, high = n - 1;  // a[low] >= a[high] >= x
        while (low < high) {
            if (high - low == 1)  // 注意没有此判断可能无限循环!
                return min(a[low], a[high]);

            int mid = (low + high) / 2;
            if (a[mid] == a[low] && a[mid] == a[high])
                return *min_element(a.begin(), a.end()); // 只能顺序查找
            
            if (a[mid] <= a[high])
                high = mid;
            else  // a[low] <= a[mid]
                low = mid;
        }
        return a[low];
    }
};