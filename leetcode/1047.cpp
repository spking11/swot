#include <stack>
#include <string>
using namespace std;
class Solution {
  public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty() || stk.top() != c) {
                stk.push(c);
            } else {
                stk.pop();
            }
        }
        auto size = stk.size();
        if (s.size() != size) {
            s.resize(size);
            while (size--) {
                s[size] = stk.top();
                stk.pop();
            }
        }
        return s;
    }
};

int main() {
    Solution().removeDuplicates("abbaca");
    return 0;
}