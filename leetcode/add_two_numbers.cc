/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* pHead;
    ListNode** ppCurr;
    int carry;  // 若不进位则为0，若进位则为1
    
    void addNode(int x) {
        if (x < 10) {
            carry = 0;
        } else {  // 注: 输入保证了x<20
            carry = 1;
            x -= 10;
        }
        *ppCurr = new ListNode(x);
        ppCurr = &((*ppCurr)->next);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        pHead = NULL;
        ppCurr = &pHead;
        while (l1 && l2) {
            addNode(l1->val + l2->val + carry);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL)
            l1 = l2;
        while (l1) {
            addNode(l1->val + carry);
            l1 = l1->next;
        }
        if (carry == 1)
            addNode(1);
        return pHead;
    }
};