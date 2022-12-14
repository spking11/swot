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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy = ListNode(0, head);
        ListNode *slow = &dummy;
        for (ListNode *iter = &dummy; iter != nullptr; iter = iter->next) {
            if (n >= 0) {
                n--;
            } else {
                slow = slow->next;
            }
        }
        auto temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy.next;
    }
};