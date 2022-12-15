#include <vector>
using namespace std;

class Solution {
  public:
    void reverseString(vector<char> &s) {
        for (auto left = s.begin(), right = s.end() - 1; left < right; left++, right--) {
            swap(*left, *right);
        }
    }
};