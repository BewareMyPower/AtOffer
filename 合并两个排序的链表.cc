/**
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
	/*
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		// 非递归版本，可以发现代码量冗余
        if (!pHead1)
            return pHead2;
        if (!pHead2)
            return pHead1;
        
        // 判断合并链表的头节点
        ListNode* pNewHead;
        if (pHead1->val <= pHead2->val) {
            pNewHead = pHead1;
            pHead1 = pHead1->next;
        } else {
            pNewHead = pHead2;
            pHead2 = pHead2->next;
        }
        
        ListNode* pNewTail = pNewHead;
        while (pHead1 && pHead2) {
            // 找到小的节点接入到尾部
            if (pHead1->val <= pHead2->val) {
                pNewTail->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                pNewTail->next = pHead2;
                pHead2 = pHead2->next;
            }

            pNewTail = pNewTail->next;
        }
        
        if (pHead1)
            pNewTail->next = pHead1;
        if (pHead2)
            pNewTail->next = pHead2;
        
        return pNewHead;
    }
	*/
};