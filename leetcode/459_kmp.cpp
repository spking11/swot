#include <string>
using namespace std;

class Solution {
  public:
    static bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        next[0] = 0;
        for (int i = 0, j = 1; j < s.size(); j++) {
            while (i > 0 && s[i] != s[j]) {
                i = next[i - 1];
            }
            if (s[i] == s[j]) {
                i++;
            }
            next[j] = i;
        }
        return next[s.size() - 1] != 0 && (s.size() % (s.size() - next[s.size() - 1])) == 0;
    }
};

int main() {
    Solution::repeatedSubstringPattern("abac");
    return 0;
}
