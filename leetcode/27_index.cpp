#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[slow++] = nums[i];
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums({3, 2, 2, 3});
    cout << Solution().removeElement(nums, 3) << endl;
    return 0;
}