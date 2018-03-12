/**
 * 给定一颗二叉搜索树，请找出其中的第k大的结点。
 * 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
    // 二叉搜索树左<根<右，因此中序遍历第k个结点(k从1开始)即所求结点
    // 若成功找到该结点，返回该结点指针(此时k应该为1)，否则返回NULL
    TreeNode* KthNodeImp(TreeNode* pRoot, int& k) {
        if (!pRoot)
            return nullptr;
        auto res = KthNodeImp(pRoot->left, k);
        if (res)
            return res;
        if (--k == 0)
            return pRoot;
        return KthNodeImp(pRoot->right, k);
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        return KthNodeImp(pRoot, k);
    }
};