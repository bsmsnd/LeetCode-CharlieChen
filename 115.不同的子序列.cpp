/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=30203
 *
 * [115] 不同的子序列
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        uint32_t answer[1000] = {};
        uint32_t newAnswer[1000] = {};

        for (size_t i = 0; i < s.size(); i++) {
            swap(answer, newAnswer);
            memset(newAnswer, 0, sizeof(newAnswer));

            // j == 0
            newAnswer[0] = answer[0] + (s[i] == t[0]);
            // printf("s = %d, answer = %d", i, newAnswer[0]);
            // j = 1 .. n
            for (size_t j = 1; j < t.size(); j++) {
                newAnswer[j] = answer[j] + ((s[i] == t[j]) ? answer[j - 1] : 0);
                // printf(", %d", newAnswer[j]);
            }
            // printf("\n");
        }
        return newAnswer[t.size() - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */

