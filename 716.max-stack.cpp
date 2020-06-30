/*
 * @lc app=leetcode id=716 lang=cpp
 *
 * [716] Max Stack
 */

// @lc code=start
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        elem.push(x);
        if (maxs.empty() || x >= maxs.top())
            maxs.push(x);
        else
            maxs.push(maxs.top());
    }
    
    int pop() {
        int x = elem.top();
        elem.pop();
        maxs.pop();
        return x;        
    }
    
    int top() {
        return elem.top();
    }
    
    int peekMax() {
        return maxs.top();
    }
    
    int popMax() {
        while(elem.top()!=maxs.top()){
            re.push(elem.top());
            elem.pop();
            maxs.pop();
        }

        int x = maxs.top();
        elem.pop();
        maxs.pop();

        while(!re.empty()){
            this->push(re.top());
            re.pop();
        }

        return x;
    }

private:
    stack<int> elem;
    stack<int> maxs;
    stack<int> re;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
// @lc code=end

