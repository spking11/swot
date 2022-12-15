#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            auto n = nums[i];
            auto p = record.find(target - n);
            if (p != record.end()) {
                return {p->second, i};
            }
            record.emplace(n, i);
        }
        return {};
    }
};