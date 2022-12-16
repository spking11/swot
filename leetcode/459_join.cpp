#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return search(t.begin() + 1, t.end() - 1, s.begin(), s.end()) != t.end() - 1;
    }
};