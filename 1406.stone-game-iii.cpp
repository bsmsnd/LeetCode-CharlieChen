/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();
        int dp[N+1];
        dp[N] = 0;
        for (int i = N-1; i >= 0; i--){            
            dp[i] = INT_MIN;
            int take = 0;
            for (int k = 0; k < 3 && i+k < N; k++){
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }
        if (dp[0] == 0)return "Tie";
        if (dp[0] > 0)return "Alice";
        return "Bob";
    }
};
// @lc code=end

