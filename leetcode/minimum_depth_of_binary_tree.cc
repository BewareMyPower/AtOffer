#include "common.h"

/**
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 */
class Solution {
public:
    // 输入必须保证root不为null
    void dfs(TreeNode* root, int depth, int& min_depth) {
        if (!root->left && !root->right) {
            if (min_depth > depth)
                min_depth = depth;
            return;
        }
        if (depth < min_depth) {
            if (root->left)
                dfs(root->left, depth + 1, min_depth);
            if (root->right)
                dfs(root->right, depth + 1, min_depth);
        }
    }
    
    int run(TreeNode *root) {
        if (!root) return 0;
        int min_depth = INT_MAX;
        dfs(root, 1, min_depth);
        return min_depth;  // 因为NULL算上了一个节点
    }
};