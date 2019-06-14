/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N =prices.size();
        bool hold_stock = false;
        int profit = 0;
        for (int i = 0; i < N - 1;i++)
            if (hold_stock)
            {
                if (prices[i+1] < prices[i])  // sell the stock since its price will decrease
                {
                    hold_stock = false;
                    profit+=prices[i];
                }
            }
            else  // hold_stock = false
            {
                if (prices[i+1] > prices[i])
                {
                    hold_stock = true;
                    profit-=prices[i];
                }
            }
        // on the last day
        if (hold_stock)
        {
            profit += prices[N-1];
            hold_stock = false;
        }
        return profit;
    }
};

