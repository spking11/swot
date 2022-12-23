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
        class MyQueue {
        public:
            void push(int n){
                while (!_deque.empty() && n > _deque.back()) {
                    _deque.pop_back();
                }
                _deque.push_back(n);
            }
            void pop(int n){
                if (n == _deque.front()) {
                    _deque.pop_front();
                }
            }
            int front(){
                return _deque.front();
            }
          private:
            deque<int> _deque;
        } que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

int main() {
    vector<int> nums({1, 3, -1, -3, 5, 3, 6, 7});
    Solution().maxSlidingWindow(nums, 3);
    return 0;
}