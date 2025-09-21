/*
 * @lc app=leetcode.cn id=LCR 104 lang=cpp
 * @lcpr version=30202
 *
 * [LCR 104] 组合总和 Ⅳ
 */
#include "helper.h"
// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> additionsMap(target + 1);
        additionsMap[0][0] = 0;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */

