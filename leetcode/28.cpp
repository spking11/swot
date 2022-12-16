#include <string>
using namespace std;

class Solution {
  public:
    static int strStr(string haystack, string needle) {
        int next[needle.size()];
        next[0] = 0;
        for (int j = 0, i = 1; i < needle.size(); i++) {
            while (j > 0 && needle[j] != needle[i]) {
                j = next[j - 1];
            }
            if (needle[j] == needle[i]) {
                j++;
            }
            next[i] = j;
        }
        for (int i = 0, j = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i - j + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution::strStr("leetcode", "leeto");
    return 0;
}