/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */
// 前序: 根->左->右；中序：左->根->右
// 因此需要找到中序中根的位置，左边的即根的左子树，右边的即根的右子树
// 比如对根节点1，左子树的前序为{2,4,7}，中序为{4,7,2}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(int* pre, int* vin, int len) {
        // 递归终止条件
        if (len == 0)
            return nullptr;
        
        TreeNode* head = new TreeNode(pre[0]);
        // 找到左子树的数量
        auto it = std::find(vin, vin + len, pre[0]);
        int nLeft = std::distance(vin, it);
        // 构建子树
        head->left = reConstructBinaryTree(pre + 1, vin, nLeft);
        head->right = reConstructBinaryTree(pre + 1 + nLeft, vin + 1 + nLeft, len - nLeft - 1);
        
        return head;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (0 == pre.size() || pre.size() != vin.size())
            return nullptr;
        int len = vin.size();
        return reConstructBinaryTree(&pre[0], &vin[0], len);
    }
};