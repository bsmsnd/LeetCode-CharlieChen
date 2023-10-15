/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1, 0);
        uint32_t MAX_BINARY_BITS = 18;
        for (uint32_t i = 0; i < MAX_BINARY_BITS; i++) {
            static uint32_t mask;
            mask = (1 << i);
            for (uint32_t j = 0; j <= n; j++) {
                if ((j & mask) > 0) {
                    answer[j]++;
                }
            }
        }
        return answer;
    }
};
// @lc code=end

