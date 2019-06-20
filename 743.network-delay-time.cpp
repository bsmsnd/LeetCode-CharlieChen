/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    queue<int> q;
    vector<vector<int>> G;
    vector<vector<int>> G_time;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int E = times.size();
        G.resize(N);
        G_time.resize(N);
        int ans[N];        
        for (int i = 0;i < N;i++)ans[i] = -1;
        // for (int i = 0; i < N;i++)cout<<ans[i]<<endl;
        for (int i = 0; i < E;++i)
        {
            G[times[i][0] - 1].push_back(times[i][1] - 1);
            G_time[times[i][0] - 1].push_back(times[i][2]);
        }
        ans[K-1] = 0;
        q.push(K-1);
        int cur_node;
        while(!q.empty())
        {
            cur_node = q.front();
            q.pop();
            for (int i = 0;i < G[cur_node].size();++i)
            {
                if (ans[G[cur_node][i]] == -1 || ans[G[cur_node][i]] > ans[cur_node] + G_time[cur_node][i])
                {
                    ans[G[cur_node][i]] = ans[cur_node] + G_time[cur_node][i];
                    q.push(G[cur_node][i]);
                }
            }
        }
        int sol = 0;
        for (int i = 0; i < N;i++)
        {
            if (ans[i] == -1)        
                return -1;
            else
            {
                sol = sol < ans[i] ? ans[i] : sol;
                // cout<<ans[i]<<endl;
            }
                
        }
        return sol;
    }
};

