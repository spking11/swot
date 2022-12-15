#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        bool stats[1001] = {false};
        for (auto num : nums1) {
            stats[num] = true;
        }
        vector<int> result;
        for (auto num : nums2) {
            if (stats[num]) {
                result.push_back(num);
                stats[num] = !stats[num];
            }
        }
        return result;
    }
};