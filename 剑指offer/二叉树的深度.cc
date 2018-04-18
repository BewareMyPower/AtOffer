/**
 * 输入一棵二叉树，求该树的深度。
 * 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
 * 最长路径的长度为树的深度。（PS: 一个结点的树深度为1）
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
	/*
	运行时间：4ms
	占用内存：508k
	*/
	// 递归求得左右子树的深度，结果为较大者+1
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;
        int left_depth = TreeDepth(pRoot->left);
        int right_depth = TreeDepth(pRoot->right);
        return std::max(left_depth, right_depth) + 1;
    }
	/*
	运行时间：4ms
	占用内存：512k
	*/
    // 带记忆的DFS取得路径，并传递当前最长路径的长度
	// 同习题《二叉树中和为某一值的路径》
/*    void TreeDepth(vector<TreeNode*>& path, int& max_depth) {
        auto node = path.back();
        if (!node->left && !node->right) {
            int depth = (int)path.size();
            if (depth > max_depth)
                max_depth = depth;
        }
        else {
            if (node->left) {
                path.push_back(node->left);
                TreeDepth(path, max_depth);
            }
            if (node->right) {
                path.push_back(node->right);
                TreeDepth(path, max_depth);
            }
        }
        // 无论是形成完整路径还是加入了新结点都要弹出回到原来的状态
        path.pop_back();
    }

    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;
        vector<TreeNode*> path = {pRoot};
        int max_depth = 1;
        TreeDepth(path, max_depth);
        return max_depth;
    }*/
};