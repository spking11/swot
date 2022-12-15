#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
class Solution {
  public:
    string reverseWords(string s) {
        // reverse total and strip space
        auto left = s.begin(), right = s.end() - 1;
        while (*left == ' ') {
            left++;
        }
        while (*right == ' ') {
            right--;
        }
        reverse(s.begin(), right + 1);
        s.resize(s.size() - distance(s.begin(), left) - distance(right, s.end() - 1));
        // reverse every word
        auto start = s.begin(), pos = find(start, s.end(), ' ');
        while (pos != s.end()) {
            reverse(start, pos);
            start = pos + 1;
            pos = find(start, s.end(), ' ');
        }
        if (start != s.end()) {
            reverse(start, s.end());
        }
        // delete redundant space
        auto slow = s.begin() + 1, fast = s.begin() + 1;
        while (fast != s.end()) {
            while (*fast == ' ' && *(fast - 1) == ' ') {
                fast++;
            }
            *slow++ = *fast++;
        }
        s.resize(s.size() - distance(slow, fast));
        return s;
    }
};