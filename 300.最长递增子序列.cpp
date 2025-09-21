/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30203
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longestSequence(nums.size(), 1);
        size_t len = nums.size();
        for (size_t i = 1; i < len; i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    longestSequence[i] = std::max(longestSequence[i], longestSequence[j] + 1);
                }
            }
        }
        int best = 0;
        for (int v : longestSequence) {
            best = std::max(v, best);
        }
        return best;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

