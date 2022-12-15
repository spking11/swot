#include <string>
using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int dict[26] = {0};
        for (auto c : magazine) {
            dict[c - 'a']++;
        }
        for (auto c : ransomNote) {
            if (dict[c - 'a'] == 0) {
                return false;
            }
            dict[c - 'a']--;
        }
        return true;
    }
};