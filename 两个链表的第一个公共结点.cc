/**
 * 输入两个链表，找出它们的第一个公共结点。
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
    // 若两个链表有公共结点，则第一个公共结点之后所有结点均为公共结点
    // 比如1->2->5->6和3->5->6，第一个公共结点是5，公共链表是5->6
    // 因此只需要从后往前找到第一个不同的值即可。
    // 可以用尺度法，让长的链表先走若干步，再开始对比，参考习题《链表中倒数第k个结点》
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2)
            return nullptr;
        auto len = [](ListNode* p) {
            int cnt = 0;
            for (; p; p = p->next)
                cnt++;
            return cnt;
        };
        int n1 = len(pHead1);
        int n2 = len(pHead2);
        if (n1 < n2)
            swap(pHead1, pHead2);  // 令pHead1为更长的链表
        for (int i = 0; i < (n1 - n2); i++)  // 长链表先走若干步
            pHead1 = pHead1->next;
        while (pHead1 && pHead2 && pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
}