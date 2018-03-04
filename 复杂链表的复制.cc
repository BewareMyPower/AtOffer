/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    // 空间复杂度为O(1)，本质上用原链表的next指针替代hashmap的映射关系
    RandomListNode* Clone(RandomListNode* pHead)
    {
        typedef RandomListNode Node;
        if (!pHead)
            return nullptr;
        for (auto p = pHead; p; ) {
            auto next = p->next;
            p->next = new Node(p->label);  // 新链表的结点
            p->next->next = next;
            p = next;
        }
        for (auto p = pHead; p; p = p->next->next) {
            // 注意空指针的判断!
            p->next->random = p->random ? p->random->next : nullptr;
        }
        // 分离新旧链表
        auto res = pHead->next;
        for (auto p = pHead; p; p = p->next) {
            auto pNew = p->next;
            auto pOldNext = p->next->next;
            p->next = pOldNext;
            // 注意空指针的判断!
            pNew->next = pOldNext ? pOldNext->next : nullptr;
        }
        return res;
    }
	/*
    RandomListNode* Clone(RandomListNode* pHead)
    {
        typedef RandomListNode Node;
        if (!pHead)
            return nullptr;
        
        unordered_map<Node*, Node*> um;  // 旧结点->新结点
        Node* newHead = nullptr;
        Node** ppNew = &newHead;
        for (auto p = pHead; p; p = p->next) {
            *ppNew = new Node(p->label);
            um[p] = *ppNew;
            
            ppNew = &(*ppNew)->next;
        }
        auto newNode = newHead;
        for (auto p = pHead; p; p = p->next) {
            newNode->random = (p->random) ? um[p->random] : nullptr;
            
            newNode = newNode->next;
        }
        return newHead;
    }*/
};