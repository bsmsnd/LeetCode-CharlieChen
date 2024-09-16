#include "helper.h"

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        valueStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        int v = valueStack.top();
        valueStack.pop();
        if (v == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return valueStack.top();
    }

    int getMin() {
        return minStack.top();
    }
private:
    stack<int> valueStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */