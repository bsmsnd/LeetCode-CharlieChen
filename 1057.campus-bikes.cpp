/*
 * @lc app=leetcode id=1057 lang=cpp
 *
 * [1057] Campus Bikes
 */

// @lc code=start

class Cmp{
public: 
    bool operator()(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
    {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    }
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        const int N = workers.size();
        const int M = bikes.size();
        bool used_bike[M];
        memset(used_bike,0,sizeof(used_bike));

        priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > q[N];
        priority_queue<pair<int, pair<int, int> >,  vector<pair<int, pair<int, int> > >, Cmp> choose;   
                
        vector<int> ans(N, 0);

        for (int i = 0;i < N; i++)
        {
            for (int j = 0;j < M;j++)
            {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                q[i].push(make_pair(dist, j));
            }
            choose.push(make_pair(q[i].top().first, make_pair(i, q[i].top().second)));
            q[i].pop();
        }
        
        int n = N;
        int worker;
        cout << choose.size() << endl;

        while(n--)
        {
            while(!choose.empty() && used_bike[choose.top().second.second])
            {
                // choose.push()
                worker = choose.top().second.first;
                choose.pop();
                choose.push(make_pair(q[worker].top().first, make_pair(worker, q[worker].top().second)));
                q[worker].pop();
            }
            // if (choose.empty())
            //     cout << "Error!" << endl;
            // assign!
            worker = choose.top().second.first;
            ans[worker] = choose.top().second.second;
            // cout << worker << " " << choose.top().second.second << endl;
            used_bike[choose.top().second.second] = 1;
            choose.pop();
        }
        return ans;
    }
};
// @lc code=end

