#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int sum = 0;
        int minLen = 0;
        for (auto begin = nums.cbegin(), end = nums.cbegin();
             end != nums.cend();) {
            if (sum + *end >= target) {
                if (minLen == 0 || distance(begin, end + 1) < minLen) {
                    minLen = distance(begin, end + 1);
                }
                sum -= *begin++;
            } else {
                sum += *end++;
            }
        }
        return minLen;
    }
};

int main() {
    vector<int> nums({2, 3, 1, 2, 4, 3});
    cout << Solution().minSubArrayLen(7, nums) << endl;
    return 0;
}