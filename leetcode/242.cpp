#include <string>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        constexpr int alphabet_count = 26;
        int counting[alphabet_count] = {0};
        for (auto iter = s.cbegin(); iter != s.cend(); iter++) {
            counting[*iter - 'a']++;
        }
        for (auto iter = t.cbegin(); iter != t.cend(); iter++) {
            counting[*iter - 'a']--;
        }
        for (int i = 0; i < alphabet_count; i++) {
            if (counting[i] != 0) {
                return false;
            }
        }
        return true;
    }
};