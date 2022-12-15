/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto ptr_a = headA, ptr_b = headB;
        if (!ptr_a || !ptr_b) {
            return nullptr;
        }
        while (ptr_a->next && ptr_b->next) {
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }
        auto cmp_a = headA, cmp_b = headB;
        if (ptr_a->next && !ptr_b->next) {
            while (ptr_a->next) {
                ptr_a = ptr_a->next;
                cmp_a = cmp_a->next;
            }
        } else if (!ptr_a->next && ptr_b->next) {
            while (ptr_b->next) {
                ptr_b = ptr_b->next;
                cmp_b = cmp_b->next;
            }
        }
        while (cmp_a) {
            if (cmp_a == cmp_b) {
                return cmp_a;
            }
            cmp_a = cmp_a->next;
            cmp_b = cmp_b->next;
        }
        return nullptr;
    }
};