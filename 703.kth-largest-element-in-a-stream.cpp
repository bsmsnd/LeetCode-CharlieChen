/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : K(k){
        for (int elem : nums){
            q.push(elem);
            while(q.size() > K)
                q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size() > K)
            q.pop();
        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

