
#include <unordered_set>
using namespace std;

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
        unordered_set<ListNode *> visited;
        for (auto iter = head; iter != nullptr; iter = iter->next) {
            if (visited.find(iter) != visited.end()) {
                return iter;
            }
            visited.insert(iter);
        }
        return nullptr;
    }
};