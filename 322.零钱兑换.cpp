/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30203
 *
 * [322] 零钱兑换
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> solution(amount + 1, -1);
        solution[0] = 0;
        size_t nCoins = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < nCoins; j++) {
                if (i >= coins[j] && solution[i - coins[j]] != -1) {
                    solution[i] = (solution[i] == -1) ? (solution[i - coins[j]] + 1) :
                        std::min(solution[i - coins[j]] + 1, solution[i]);
                    // printf("solution(%d) = %d\n", i, solution[i]);
                }
            }
        }
        return solution[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

