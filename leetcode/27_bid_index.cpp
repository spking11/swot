#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            while (left < right && nums[left] != val) {
                left++;
            }
            while (left < right && nums[right - 1] == val) {
                right--;
            }
            if (left < right) {
                nums[left++] = nums[(right--) - 1];
            }
        }
        return right;
    }
};

int main() {
    vector<int> nums({3, 2, 2, 3});
    cout << Solution().removeElement(nums, 3) << endl;
    return 0;
}