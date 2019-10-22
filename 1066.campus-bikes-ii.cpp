/*
 * @lc app=leetcode id=1066 lang=cpp
 *
 * [1066] Campus Bikes II
 */

// @lc code=start

// class Solution {
// public:
//     int dist[12][12];
//     int dp[1024][1024];
//     // int N, M;
//     int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
//         const int N = workers.size(); 
//         const int M = bikes.size();
//         queue<pair<int, int> > q;
//         memset(dp, -1, sizeof(dp));
//         for (int i = 0;i < N; i++)
//         for (int j = 0;j < M; j++)
//         {
//             dist[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
//             dp[1 << i][1 << j] = dist[i][j];
//             q.push(make_pair( (1 << i), (1 << j) ));
//         }
        
//         int n = N - 1;        
//         while(n--)
//         {
//             int m = q.size();
//             for (int k = 0;k < m; k++)
//             {
//                 int worker_state = q.front().first, bike_state = q.front().second;
//                 q.pop();                
//                 for (int i = 0; i < N; i++)
//                 for (int j = 0;j < M; j++)
//                 if (((worker_state & (1 << i)) == 0) && ((bike_state & (1 << j)) == 0))
//                 {
//                     // cout << (worker_state & (1 << i)) << " " << (bike_state & (1 << j)) << endl;
                                          
//                     int new_worker_state = worker_state | (1 << i);
//                     int new_bike_state = bike_state | (1 << j);
//                     if (dp[new_worker_state][new_bike_state] == -1)
//                     {
//                         dp[new_worker_state][new_bike_state] = dp[worker_state][bike_state] + dist[i][j];
//                         q.push(make_pair(new_worker_state, new_bike_state));          
//                     }
//                     else
//                     {
//                         dp[new_worker_state][new_bike_state] = min(dp[new_worker_state][new_bike_state], dp[worker_state][bike_state] + dist[i][j]);                            
//                     }                                                             
//                 }
//             }
//         }
//         int best_ans = INT_MAX;
//         int full_worker = (1 << N) - 1;
//         for (int j = (1 << N)-1; j < (1 << M); j++)
//             if (dp[full_worker][j] != -1)                                      
//                 best_ans = min(best_ans, dp[full_worker][j]);
              
                
//         return best_ans;      
//     }
// };

class Solution {
public:
    int dist[12][12];
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        unordered_map<int, int> ans;
        const int N = workers.size(); 
        const int M = bikes.size();                

        for (int i = 0;i < N; i++)
            for (int j = 0;j < M; j++)
                dist[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        
        for (int j = 0;j < M; j++)
            ans[1 << j] = dist[0][j];
        
        for (int i = 1; i < N; i++)
        {
            unordered_map<int, int> tmp;
            // tmp.clear();
            for (auto it = ans.begin(); it != ans.end(); it++)
                for (int j = 0; j < M; j++)
                if ((it->first & (1 << j)) == 0)
                {
                    int new_state = it->first | (1 << j);
                    if (tmp.find(new_state) == tmp.end())
                        tmp[new_state] = it->second + dist[i][j];
                    else
                        tmp[new_state] = min(tmp[new_state], it->second + dist[i][j]);
                }
            swap(ans, tmp);
        }        
        int best_ans = INT_MAX;
        for (auto it = ans.begin(); it != ans.end(); it++)
            best_ans = min(best_ans, it->second);
        return best_ans;
    }
};
// @lc code=end

