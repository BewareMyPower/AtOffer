/**
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    // 就是BFS，注意保证队列q中的节点不为NULL
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr)
            return {};
        std::vector<int> v;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            
            v.push_back(x->val);
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        return v;
    }
};