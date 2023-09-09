/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start

// #define LEETCODE_DEBUG
#ifdef LEETCODE_DEBUG
#include "helper.h"
#endif

class Solution {
public:
    int dfs(vector<int>& nums, int target)
    {
        if (dfsResults[target] != -1) {
            return dfsResults[target];
        }
        int result = 0;
        for (int t : nums) {
            if (target >= t) {
                result += dfs(nums, target - t);
            }
        }
        return dfsResults[target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dfsResults.resize(target + 1, -1);
        dfsResults[0] = 1;
        return dfs(nums, target);
    }
private:
    vector<int> dfsResults;
};
// @lc code=end

