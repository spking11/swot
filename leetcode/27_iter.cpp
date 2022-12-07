#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        auto slow = nums.begin();
        for (auto iter = nums.begin(); iter < nums.end(); iter++) {
            if (*iter != val) {
                *slow++ = move(*iter);
            }
        }
        return distance(nums.begin(), slow);
    }
};

int main() {
    vector<int> nums({3, 2, 2, 3});
    cout << Solution().removeElement(nums, 3) << endl;
    return 0;
}