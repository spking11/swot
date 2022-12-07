#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> sortedSquares(vector<int> &nums) {
        auto left_iter = nums.cbegin();
        auto right_iter = nums.cend() - 1;

        vector<int> new_nums(nums.size());
        for (auto iter = new_nums.rbegin(); iter != new_nums.rend();) {
            if (*left_iter >= 0) {
                while (iter != new_nums.rend()) {
                    *iter++ = (*right_iter) * (*right_iter--);
                }
            } else if (*right_iter < 0) {
                while (iter != new_nums.rend()) {
                    *iter++ = (*left_iter) * (*left_iter++);
                }
            } else if ((*right_iter) * (*right_iter) >
                       (*left_iter) * (*left_iter)) {
                *iter++ = (*right_iter) * (*right_iter--);
            } else {
                *iter++ = (*left_iter) * (*left_iter++);
            }
        }
        return new_nums;
    }
};