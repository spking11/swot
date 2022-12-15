#include <unordered_set>
using namespace std;
class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> record;
        while (n != 1) {
            if (record.find(n) != record.end()) {
                return false;
            }
            record.insert(n);
            int new_n = 0;
            for (int copy_n = n; copy_n != 0; copy_n /= 10) {
                auto num = copy_n % 10;
                new_n += num * num;
            }
            n = new_n;
        }
        return true;
    }
};