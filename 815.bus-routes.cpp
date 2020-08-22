/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool connect(vector<int>&a, vector<int>&b){
        int n1 = a.size(), n2 = b.size();
        int p1 = 0, p2 = 0;
        while(p1 < n1 && p2 < n2){
            if (a[p1] < b[p2])p1++;
            else if (a[p1] > b[p2])p2++;
            else return true;
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)return 0;
        for (vector<int>& r: routes)
            sort(r.begin(), r.end());
        const int N = routes.size();
        // int distance[N][N];
        vector<vector<int>> conn(N, vector<int>(0));        

        for (int i = 0;i < N-1; i++)
            for (int j = i+1; j < N; j++)
                if (connect(routes[i], routes[j])){
                    conn[i].push_back(j);
                    conn[j].push_back(i);
                }
                    
        queue<int> q;
        int steps[N];
        vector<int> finishingBuses;
        
        for (int i = 0;i < N; i++){
            if (find(routes[i].begin(), routes[i].end(), S) != routes[i].end()){
                q.push(i);
                steps[i] = 1;
            }
            else
                steps[i] = -1;

            if (find(routes[i].begin(), routes[i].end(), T) != routes[i].end())
                finishingBuses.push_back(i);
        }
        
        for (int& f: finishingBuses)
            if (steps[f] != -1)return steps[f];

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int s = q.front();
                q.pop();
                for (int& nextBus : conn[s])
                    if (steps[nextBus] == -1){
                        steps[nextBus] = steps[s] + 1;
                        q.push(nextBus);
                    }
            }    

            for (int& f: finishingBuses)
                if (steps[f] != -1)return steps[f];        
        }

        return -1;
    }
};
// @lc code=end

