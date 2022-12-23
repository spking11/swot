#include <cstdint>
#include <deque>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (k == 1) {
            return nums;
        }
        deque<int> que;
        vector<int> result;
        int max = INT_MIN;
        for (int i = 0; i < k; i++) {
            if (nums[i] > max) {
                max = nums[i];
                que.clear();
            } else {
                while (nums[i] > que.back()) {
                    que.pop_back();
                }
            }
            que.push_back(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            if (nums[i - k] == que.front()) {
                que.pop_front();
                max = que.front();
            }
            if (nums[i] > max) {
                max = nums[i];
                que.clear();
            } else {
                while (nums[i] > que.back()) {
                    que.pop_back();
                }
            }
            que.push_back(nums[i]);
            result.push_back(max);
        }
        return result;
    }
};

int main() {
    vector<int> nums({1, 3, -1, -3, 5, 3, 6, 7});
    Solution().maxSlidingWindow(nums, 3);
    return 0;
}