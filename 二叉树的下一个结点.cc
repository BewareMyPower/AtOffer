/**
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 */
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode)
            return nullptr;
        if (pNode->right) {  // 含有右子树，下个结点即右子树最左边的结点
            pNode = pNode->right;
            while (pNode->left)
                pNode = pNode->left;
            return pNode;
        } else {
            // 若pNode为父节点的右子树，则下个结点为所在子树的根节点
            while (pNode->next && pNode->next->right == pNode)
                pNode = pNode->next;
            return pNode->next;
        }
    }
};