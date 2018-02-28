/**
 * 输入一个链表，输出该链表中倒数第k个结点。
 */
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k == 0)
            return nullptr;
        ListNode* pFirst = pListHead;
        ListNode* pLast = pFirst;
        for (unsigned int i = 1; i < k && pLast; ++i)
            pLast = pLast->next;
        // 无论是pListHead为NULL或者k大于链表大小都会导致pLast为NULL
        if (!pLast)
            return nullptr;
        // pFirst即从pLast开始倒数第k个节点，当pLast到末尾时pFirst即结果
        while (pLast->next) {
            pLast = pLast->next;
            pFirst = pFirst->next;
        }
        return pFirst;
    }
};