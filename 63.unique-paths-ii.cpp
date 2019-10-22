/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
#include <vector>
using namespace std;

class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {        
        const int N = obstacleGrid.size();
        if (N == 0)return 0;
        const int M = obstacleGrid[0].size();
        if (M == 0)return 0;
        if (obstacleGrid[0][0] == 1)return 0;

        long long ans[N][M];
        ans[0][0] = 1;

        for (int i = 0;i < N; i++)
        for (int j = 0;j < M; j++)
        {
            if (i == 0 && j == 0)
                continue;
            ans[i][j] = 0;
            if (obstacleGrid[i][j] == 1)
                continue;
            if (i > 0)
                ans[i][j] += ans[i-1][j];
            if (j > 0)
                ans[i][j] += ans[i][j-1];
        }
        return ans[N-1][M-1];
    }
};

