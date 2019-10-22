/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int i = 0; i < stones.size(); i++)
            q.push(stones[i]);
        
        while(q.size() > 1)
        {
            int t1 = q.top(); q.pop();
            int t2 = q.top(); q.pop();            
            if (t1 != t2)
                q.push(abs(t1 - t2));            
        }
        return q.empty() ? 0 : q.top();
    }
};
// @lc code=end

