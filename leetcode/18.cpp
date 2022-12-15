#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    static vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (nums[i] > 0 && nums[i] >= target) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (nums[j] > 0 && nums[i] + nums[j] >= target) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    auto sum = (long)(nums[i]) + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l - 1 && nums[k] == nums[k + 1])
                            k++;
                        k++;
                        while (l > k + 1 && nums[l] == nums[l - 1])
                            l--;
                        l--;
                    } else if (sum < target) {
                        while (k < l - 1 && nums[k] == nums[k + 1])
                            k++;
                        k++;
                    } else {
                        while (l > k + 1 && nums[l] == nums[l - 1])
                            l--;
                        l--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> v{0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000};
    Solution::fourSum(v, 1000000000);
    return 0;
}