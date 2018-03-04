/**
 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
	// 递归解法，带记忆的DFS
	vector<int> path;
    vector<vector<int>> res;
public:
    void dfs(TreeNode* root, int s) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (s == root->val)
                res.push_back(path);
        }
        if (root->left)
            dfs(root->left, s - root->val);
        if (root->right)
            dfs(root->right, s - root->val);
        path.pop_back();  // 关键代码!!! 回溯至未加入根节点的状态!!!
    }
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        res.clear();
        path.clear();
        dfs(root, expectNumber);
        return res;
    }
	
	// 迭代解法
/*
    typedef TreeNode Node;
    vector<Node*> path;
    int sum = 0;
    unordered_set<Node*> vis_set;
    
    bool visited(Node* node) const { return vis_set.count(node) > 0; }
    
    void push_node(Node* node) {  // node != nullptr
        path.emplace_back(node);
        sum += node->val;
        vis_set.emplace(node);
    }
    
    void pop_node() {  // !path.empty()
        sum -= path.back()->val;
        path.pop_back();
    }
    
    void fall_back() {
        while (!path.empty()) {
            Node* right = path.back()->right;
            if (right && !visited(right)) {
                push_node(right);
                break;
            } else {
                pop_node();
            }
        }
    }
    
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (!root)
            return res;
        
        push_node(root);
        while (!path.empty()) {
            auto node = path.back();
            if (!node->left && !node->right) {
                if (sum == expectNumber) {
                    vector<int> temp(path.size());
                    std::transform(path.cbegin(), path.cend(), temp.begin(),
                             [](const TreeNode* node) { return node->val; });
                    res.emplace_back(std::move(temp));
                }
                fall_back();
            } else if (node->left) {
                push_node(node->left);
            } else {
                push_node(node->right);
            }
        }
        
        return res;
    }
*/
};