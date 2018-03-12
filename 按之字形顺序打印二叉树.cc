/**
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
    void push_node(const vector<TreeNode*> v, vector<vector<int>>& res) {
        vector<int> temp(v.size());
        for (size_t i = 0; i < v.size(); ++i) {
            temp[i] = v[i]->val;
        }
        res.push_back(temp);
    }
    
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot)
            return vector<vector<int>>();
        vector<vector<int>> res;
        vector<TreeNode*> prev = {pRoot};  // 上层结点
        push_node(prev, res);
        
        while (true) {
            vector<TreeNode*> next;  // 下层结点
            for (int i = 0; i < prev.size(); ++i) {
                if (prev[i]->left)
                    next.push_back(prev[i]->left);
                if (prev[i]->right)
                    next.push_back(prev[i]->right);
            }
            if (next.empty())
                break;
            
            prev.swap(next);
            push_node(prev, res);
        }
        for (size_t i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};