/**
 * 输入一个链表，从尾到头打印链表每个节点的值
 */
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    // 递归打印
    void saveListFromTailToHead(ListNode* head, vector<int>& v) {
        if (!head) return;
        saveListFromTailToHead(head->next, v);
        v.push_back(head->val);
    }

    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        saveListFromTailToHead(head, v);
        return v;
    }
	
/*    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        std::reverse(v.begin(), v.end());
        return v;
    }*/
};