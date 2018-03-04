/**
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 *如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */
class Solution {
    bool VerifySquenceOfBST(int* a, int n) {
        if (n <= 1)
            return true;
        int mid = 0;  // [0, mid)为左子树，[mid, n-1)为右子树
        // 左子树必须小于根节点
        for (; mid < n - 1; ++mid) {
            if (a[mid] > a[n - 1])
                break;
            else if (a[mid] == a[n - 1])
                return false;
        }
        // 右子树必须大于根节点
        for (int i = mid + 1; i < n - 1; i++) {
            if (a[i] <= a[n - 1])
                return false;
        }
        // 递归判断左子树和右子树
        bool res = VerifySquenceOfBST(a, mid);
        if (res)  // 注意右边界是n-1-mid而非n-mid，n-mid会无限递归
            res = VerifySquenceOfBST(a + mid, n - 1 - mid);
        return res;
    }
public:
    // 后序: 左->右->根，二叉搜索树: 左<根<右
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)  // 空树视为false
            return false;
        return VerifySquenceOfBST(&sequence[0], (int)sequence.size());
    }
};