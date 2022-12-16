#include <stack>
using namespace std;

class MyQueue {
  public:
    MyQueue() {
    }

    void push(int x) {
        if (_stack.empty()) {
            _stack.push(x);
        } else {
            stack<int> __stack;
            while (!_stack.empty()) {
                __stack.push(_stack.top());
                _stack.pop();
            }
            _stack.push(x);
            while (!__stack.empty()) {
                _stack.push(__stack.top());
                __stack.pop();
            }
        }
    }

    int pop() {
        int item = _stack.top();
        _stack.pop();
        return item;
    }

    int peek() {
        return _stack.top();
    }

    bool empty() {
        return _stack.empty();
    }

  private:
    stack<int> _stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */