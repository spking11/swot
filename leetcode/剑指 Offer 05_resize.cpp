#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string replaceSpace(string s) {
        int count = 0;
        for (auto c : s) {
            if (c == ' ') {
                count++;
            }
        }
        auto original_size = s.size();
        s.resize(original_size + count * 2);
        for (int fast = original_size - 1, slow = s.size() - 1; fast >= 0; fast--) {
            if (s[fast] == ' ') {
                s[slow--] = '0';
                s[slow--] = '2';
                s[slow--] = '%';
            } else {
                s[slow--] = s[fast];
            }
        }
        return s;
    }
};