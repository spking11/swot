/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        while (head != nullptr && head->val == val) {
            auto next = head->next;
            delete head;
            head = next;
        }

        for (auto iter = head; iter != nullptr; iter = iter->next) {
            while (iter->next != nullptr && iter->next->val == val) {
                auto next = iter->next->next;
                delete iter->next;
                iter->next = next;
            }
        };
        return head;
    }
};