/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode *swapPairs(ListNode *head) {
        auto swap = [](ListNode *ptr) -> ListNode * {
            auto next = ptr->next;
            ptr->next = next->next;
            next->next = ptr;
            return next;
        };

        if (head != nullptr && head->next != nullptr) {
            head = swap(head);
            for (auto iter = head->next->next, last = head->next;
                 iter != nullptr && iter->next != nullptr; iter = iter->next) {
                last->next = swap(iter);
                last = last->next->next;
            }
        }
        return head;
    }
};