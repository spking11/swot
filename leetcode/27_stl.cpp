#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};

int main() {
    vector<int> nums({3, 2, 2, 3});
    cout << Solution().removeElement(nums, 3) << endl;
    return 0;
}