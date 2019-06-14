/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int K = prices.size();
        int dp[K][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < K ; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        return dp[K-1][1];
    }
};

