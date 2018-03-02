/**
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 */
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    // 判断树pRoot1是否包含pRoot2
    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val) {
            return DoesTree1HaveTree2(pRoot1->left, pRoot2->left)
                && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
        }
        return false;
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2)
            return false;
        
        // 在pRoot1中找到所有子树可能是pRoot2的根节点
        bool res = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr) {
            // 根节点相同，判断是否包含
            if (pRoot1->val == pRoot2->val)
                res = DoesTree1HaveTree2(pRoot1, pRoot2);
            // 若不包含则递归搜索pRoot1的左/右子树是否包含pRoot2
            if (!res)
                res = HasSubtree(pRoot1->left, pRoot2);
            if (!res)
                res = HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
    }
};