/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int s = q.size(), tmp;
        for (int i = 0;i < s-1; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int s = q.size(), tmp;
        for (int i = 0;i < s-1; i++){
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        tmp = q.front();
        q.pop();
        q.push(tmp);
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

