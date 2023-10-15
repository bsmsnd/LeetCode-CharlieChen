/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
// #include "helper.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = 0;
        int minBuyPrice = INT32_MAX;
        for (int p : prices) {
            if (p >= minBuyPrice) {
                bestProfit = max(bestProfit, p - minBuyPrice);
            } else {
                minBuyPrice = p;
            }
        }
        return bestProfit;
    }
};
// @lc code=end

