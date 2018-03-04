/**
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
class Solution {
public:
    typedef TreeNode Node;
    
    void convert_imp(Node* root, Node*& tail) {
        if (!root)
            return;
        if (root->left)
            convert_imp(root->left, tail);  // 获得左子树转换后的尾结点
        root->left = tail;
        if (tail)  // 注意判断是否为空!
            tail->right = root;
        // 现在左子树和根节点都已转换好
        tail = root;
        if (root->right)
            convert_imp(root->right, tail);
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        Node* tail = nullptr;
        convert_imp(pRootOfTree, tail);
        if (!tail)
            return nullptr;
        while (tail->left)
            tail = tail->left;
        return tail;
    }
};