/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int M = dungeon.size();
        const int N = dungeon[0].size();
        int dp[M][N];
        for (int i = 0;i < M;++i)
        for(int j = 0;j < N;++j)dp[i][j] = -1;

        for (int i = M-1;i>=0;--i)
        for (int j = N-1;j>=0;--j)
        {
            if (i == M-1)
                if(j == N-1)
                    dp[i][j] = dungeon[i][j] >=0 ? 1 : -dungeon[i][j] + 1;
                else
                    {
                        dp[i][j] = (dungeon[i][j] >= dp[i][j+1]) ? 1 : dp[i][j+1] - dungeon[i][j];
                    }
            else
                if (j == N-1)
                    dp[i][j] = (dungeon[i][j] >= dp[i+1][j]) ? 1 : dp[i+1][j] - dungeon[i][j];
                else
                    {
                        int best = min(dp[i+1][j], dp[i][j+1]);
                        dp[i][j] = (dungeon[i][j] >= best) ? 1 : best - dungeon[i][j];
                    }
        }
        return dp[0][0];
    }
};

