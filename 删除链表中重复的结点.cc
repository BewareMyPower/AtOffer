/**
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    void deleteList(ListNode* pHead) {
        while (pHead) {
            auto temp = pHead;
            pHead = pHead->next;
            delete temp;
        }
    }
    
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (!pHead)
            return nullptr;
        if (!pHead->next)
            return pHead;
        // 若头结点就是重复结点，则清除这一系列结点
        if (pHead->val == pHead->next->val) {
            auto pPrev = pHead;
            while (pPrev->next && pPrev->next->val == pHead->val)
                pPrev = pPrev->next;
            auto nextHead = pPrev->next;
            pPrev->next = nullptr;
            deleteList(pHead);
            return deleteDuplication(nextHead);
        }
        // 头结点不是重复结点，则清除next为首的链表
        pHead->next = deleteDuplication(pHead->next);
        return pHead;
    }
};