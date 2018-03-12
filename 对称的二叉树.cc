/**
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	// 若二叉树对称，则首先左孩子和右孩子都为NULL或者val相等。
	// 其次左孩子的左/右子树和右孩子的右/左子树必须对称。
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot)
            return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }
    
    bool isSymmetrical(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        if (!isSymmetrical(left->left, right->right))
            return false;
        if (!isSymmetrical(left->right, right->left))
            return false;
        return true;
    }
	
    // 二叉树对称意味着根->左->右遍历和根->右->左遍历的结果一致，对于非叶子节点，
    // 若孩子存在空指针，也要保存进遍历结果中。
/*    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot)
            return true;
        vector<TreeNode*> v1;
        root_left_right(pRoot, v1);
        vector<TreeNode*> v2;
        root_right_left(pRoot, v2);
        if (v1.size() != v2.size()) {
            return false;
        } else {
            for (size_t i = 0; i < v1.size(); ++i) {
                if ((v1[i] && v2[i]) && (v1[i]->val != v2[i]->val))
                    return false;
                else if ((!v1[i] && v2[i]) || (v1[i] && !v2[i]))
                    return false;
            }
            return true;
        }
    }
    
    void root_left_right(TreeNode* pRoot, vector<TreeNode*>& v) {
        if (pRoot) {
            if (!pRoot->left && !pRoot->right)
                return;
            v.push_back(pRoot->left);
            root_left_right(pRoot->left, v);
            v.push_back(pRoot->right);
            root_left_right(pRoot->right, v);
        }
    }
    
    void root_right_left(TreeNode* pRoot, vector<TreeNode*>& v) {
        if (pRoot) {
            if (!pRoot->left && !pRoot->right)
                return;
            v.push_back(pRoot->right);
            root_right_left(pRoot->right, v);
            v.push_back(pRoot->left);
            root_right_left(pRoot->left, v);
        }
    }*/
};