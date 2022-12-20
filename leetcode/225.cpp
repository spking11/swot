#include <queue>
using namespace std;

class MyStack {
  public:
    MyStack() {
    }

    void push(int x) {
        int size = _queue.size();
        _queue.push(x);
        while (size--) {
            _queue.push(_queue.front());
            _queue.pop();
        }
    }

    int pop() {
        auto i = _queue.front();
        _queue.pop();
        return i;
    }

    int top() {
        return _queue.front();
    }

    bool empty() {
        return _queue.empty();
    }

  private:
    queue<int> _queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */