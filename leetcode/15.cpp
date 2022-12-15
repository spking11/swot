#include <algorithm>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                auto sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k - 1 && nums[j] == nums[j + 1])
                        j++;
                    j++;
                    while (k > j + 1 && nums[k] == nums[k - 1])
                        k--;
                    k--;
                } else if (sum < 0) {
                    while (j < k - 1 && nums[j] == nums[j + 1])
                        j++;
                    j++;
                } else {
                    while (k > j + 1 && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
            }
        }
        return result;
    }
};