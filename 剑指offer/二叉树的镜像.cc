/**
 * 操作给定的二叉树，将其变换为源二叉树的镜像
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
    void Mirror(TreeNode *pRoot) {
        if (pRoot) {
            auto& left = pRoot->left;
            auto& right = pRoot->right;
            std::swap(left, right);
            
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
	
	/*
	void Mirror(TreeNode *pRoot) {
        // 使用循环而非递归的方法，实质上是BFS
        std::queue<TreeNode*> q;
        q.push(pRoot);
        
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (x) {
                std::swap(x->left, x->right);
                q.push(x->left);
                q.push(x->right);
            }
        }
    }
	*/
};