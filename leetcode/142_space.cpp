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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (1) {
            if ((!slow || !slow->next) ||
                (!fast || !fast->next || !fast->next->next)) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};