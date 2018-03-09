/**
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
class Solution {
public:
    // 若树不平衡则返回false，否则返回true，并记录树到叶子节点的深度depth
    bool IsBalanced(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        int left_depth;
        int right_depth;
        if (IsBalanced(root->left, left_depth)
           && IsBalanced(root->right, right_depth)) {
            // 比较左右子树深度，差距小于1则为平衡树
            int diff = left_depth - right_depth;
            if (diff <= 1 && diff >= -1) {
                depth = std::max(left_depth, right_depth) + 1;
                return true;
            }
        }
        return false;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, depth);
    }
};