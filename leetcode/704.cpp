#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            auto mid = end + ((start - end) >> 1); // prevent overflow (start + end) / 2
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};
