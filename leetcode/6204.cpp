#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMaxK(vector<int> &nums) {
        unsigned char bitmap_n[1000 / 8] = {0};
        unsigned char bitmap[1000 / 8] = {0};
        for (auto num : nums) {
            if (num < 0) {
                int index = -num - 1;
                bitmap_n[index / 8] |= 0x1 << (index % 8);
            } else {
                int index = (num - 1);
                bitmap[index / 8] |= 0x1 << (index % 8);
            }
        }
        for (int i = sizeof(bitmap) - 1; i >= 0; i--) {
            int temp = bitmap[i] & bitmap_n[i];
            if (temp) {
                for (int j = 7; j >= 0; j--) {
                    if (temp & (0x1 << j))
                        return i * 8 + j + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v({});
    cout << s.findMaxK(v) << endl;
}
