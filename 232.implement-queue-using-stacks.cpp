/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
        if (s.size() == 1)
            front = x;        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s.empty()){
            re.push(s.top());
            s.pop();
        }
        int x = re.top();
        
        // remove front
        re.pop();
        
        // fix front
        if (re.size() > 0)
            front = re.top();

        while(!re.empty()){
            s.push(re.top());
            re.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }

private:
    stack<int> s;
    stack<int> re;
    int front;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

