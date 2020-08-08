/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        memset(dist, -1, sizeof(dist));

        const int E = edges.size();
        for (int i = 0; i < E; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            dist[x][y] = dist[y][x] = w;
        }
        for (int i = 0;i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][k] != -1 && dist[j][k] != -1)
                if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

        int ans[n];
        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i] += (dist[i][j] != -1 && dist[i][j] <= distanceThreshold);
        
        int bestIdx = 0;
        int bestCnt = INT_MAX;
        for (int i = 0; i < n; i++)
            if (bestCnt >= ans[i]){
                bestCnt = ans[i];
                bestIdx = i;
            }

        return bestIdx;    
    }
};
// @lc code=end

