/**
 * 一个链表中包含环，请找出该链表的环的入口结点。
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
    // 假设环包含k个结点，链表有n个结点，则移动n-k步就到了环的入口
    // 再走k步又会回到环的入口，因此如果p1先走k步，然后p2以相同的速度移动，
    // 最后(经过n-k步后)会在环的入口相遇。
    // 问题变成求环路结点数量，而p1和p2同时出发，p1每次走2步，p2每次走1步。
    // p1和p2肯定会在环内相遇，之后只要记录走多少步回到原地即可得到环的结点数
    ListNode* EntryNodeOfLoop(ListNode* pHead)  // 484k 4ms
    {
        int nLoop = getLoopNodeNum(pHead);
        if (nLoop == 0)
            return nullptr;
        auto p1 = pHead;
        for (int i = 0; i < nLoop; i++)
            p1 = p1->next;
        auto p2 = pHead;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    
    // 返回链表中环的结点数，若不存在环路则返回0
    int getLoopNodeNum(ListNode* pHead) {
        auto p1 = pHead;
        auto p2 = pHead;
        while (true) {
            if (!p1)
                return 0;
            p1 = p1->next;
            if (!p1)
                return 0;
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2)
                break;
        }  // p1 == p2
        int cnt = 1;
        for (p1 = p1->next; p1 != p2; p1 = p1->next)
            cnt++;
        return cnt;
    }
	
	// 无脑hashset记录遍历过的结点地址
/*    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_set<ListNode*> us;
        for (; pHead; pHead = pHead->next) {
            if (us.count(pHead) == 0) {
                us.emplace(pHead);
            } else {
                return pHead;
            }
        }
        return nullptr;
    }*/
};