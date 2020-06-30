/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
public:
    CustomStack(int maxSize): mSize(maxSize) {
        inc.resize(maxSize + 1, 0);
    }
    
    void push(int x) {
        if(s.size() < mSize){
            s.push(x);
        }
    }
    
    int pop() {
        if (s.empty())return -1;        
        int val = s.top() + inc[s.size()];        
        inc[s.size() - 1] += inc[s.size()];
        inc[s.size()] = 0;
        s.pop();
        return val;
    }
    
    void increment(int k, int val) {
        inc[min(k, (int)s.size())] += val;
        // cout << min(k, int(s.size())) << " " << inc[min(k, (int)s.size())] << endl;
    }

private:
    vector<int> inc;
    stack<int> s;
    int mSize;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

