#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        auto left = nums.begin(), right = nums.end();
        while (left != right) {
            while (left != right && *left != val) {
                left++;
            }
            while (right != left && *(right - 1) == val) {
                right--;
            }
            if (left != right) {
                *(left++) = *((right--) - 1);
            }
        }
        return distance(nums.begin(), right);
    }
};

int main() {
    vector<int> nums({3, 2, 2, 3});
    cout << Solution().removeElement(nums, 3) << endl;
    return 0;
}