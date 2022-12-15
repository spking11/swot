#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    string reverseStr(string s, int k) {
        auto start = s.begin();
        auto end = start + 2 * k;
        while (end <= s.end()) {
            reverse(start, start + k);
            start = end;
            end += 2 * k;
        }
        if (start != s.end()) {
            reverse(start, min(start + k, s.end()));
        }
        return s;
    }
};