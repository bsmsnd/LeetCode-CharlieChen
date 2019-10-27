/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int N = position.size();
        int group_cnt = 0;
        // stack<double> s; 
        priority_queue<pair<int, double> > q;
        for (int i = 0;i < N; i++)
        {
            double t = (target - position[i]) / (double)(speed[i]);
            q.push({position[i], t});
        }

        stack<double > s;

        while(!q.empty()) 
        {
            // cout << q.top().first << " " << q.top().second << endl;
            double arrival_time = q.top().second;
            if (s.empty() || s.top() < arrival_time)
                s.push(arrival_time);    
            q.pop();                    
        }
        return s.size();

    }
};
// @lc code=end

