/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0;i < m; i++)
        for (int j = 0;j < n; j++)
        if (i == 0 && j == 0)
            continue;
        else
        {
            if (i > 0)
                dp[i][j] += dp[i-1][j];
            if (j > 0)
                dp[i][j] += dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};

