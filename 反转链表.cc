/**
 * 输入一个链表，反转链表后，输出链表的所有元素。
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
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead->next)  // 节点数量为0或1
            return pHead;
        auto pPrev = pHead;
        auto pNext = pPrev->next;  // 不为NULL
        pPrev->next = nullptr;
        while (pNext->next) {
            auto temp = pNext->next;  // 记录节点以便下次迭代
            pNext->next = pPrev;  // 逆转前驱和后置节点

            pPrev = pNext;  // 迭代
            pNext = temp;
        }  // end: pNext->next == NULL, pNext为逆转后的头节点
        
        pNext->next = pPrev;
        return pNext;
    }
};