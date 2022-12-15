#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        auto len = nums1.size();
        unordered_map<int, int> record_1plus2;
        for (auto n1 : nums1) {
            for (auto n2 : nums2) {
                record_1plus2[n1 + n2]++;
            }
        }
        int count = 0;
        for (auto n3 : nums3) {
            for (auto n4 : nums4) {
                auto p = record_1plus2.find(0 - n3 - n4);
                if (p != record_1plus2.end()) {
                    count += p->second;
                }
            }
        }
        return count;
    }
};