#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<long> stk;
        for (auto token : tokens) {
            if (token == "+") {
                auto r = stk.top();
                stk.pop();
                auto l = stk.top();
                stk.pop();
                stk.push(l + r);
            } else if (token == "-") {
                auto r = stk.top();
                stk.pop();
                auto l = stk.top();
                stk.pop();
                stk.push(l - r);
            } else if (token == "*") {
                auto r = stk.top();
                stk.pop();
                auto l = stk.top();
                stk.pop();
                stk.push(l * r);
            } else if (token == "/") {
                auto r = stk.top();
                stk.pop();
                auto l = stk.top();
                stk.pop();
                stk.push(l / r);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

int main() {
    vector<string> tokens({"-128","-128","*","-128","*","-128","*","8","*","-1","*"});
    Solution().evalRPN(tokens);
    return 0;
}