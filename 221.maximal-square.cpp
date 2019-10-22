/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int N = matrix.size();
        if (N == 0)return 0;
        const int M = matrix[0].size();
        if (M == 0)return 0;

        int dp[M];
        memset(dp, 0, sizeof(dp));
        int best_ans = 0,tmp;
        for (int i = 0;i < N; i++)
        {
            int prev = dp[0];
            dp[0] = (matrix[i][0] == '1');   
            best_ans = max(best_ans, dp[0]);         
            // cout<<dp[0]<<" ";
            for (int j = 1;j < M; j++)
            {   
                tmp = dp[j];       
                // prev = dp[j];
                if (matrix[i][j] == '0')
                    dp[j] = 0;
                else
                    dp[j] = min(min(dp[j],dp[j-1]),prev) + 1;                
                best_ans = max(best_ans, dp[j]);
                prev = tmp;
                // cout<<dp[j]<<" ";                
            }            
            // cout<<endl;
        }
        return best_ans * best_ans;
    }
};

