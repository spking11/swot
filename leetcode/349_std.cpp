#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> stats(nums1.begin(), nums1.end());
        vector<int> result;
        for (auto num : nums2) {
            if (stats.erase(num) != 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};