#include <stack>
#include <string>
using namespace std;
class Solution {
  public:
    bool isValid(string s) {
        if (s.size() % 2)
            return false;
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty() || (c - stk.top() != 2 && c - stk.top() != 1)) {
                stk.push(c);
            } else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution().isValid("()");
    return 0;
}