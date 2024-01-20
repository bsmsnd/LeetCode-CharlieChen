/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
// #include "helper.h"
// #include <string>
// #include <utility>
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // vector<pair<int, int>> ranges;
        vector<string> ranges;
        int i = 0;
        const int N = nums.size();
        while (i < N) {
            int j = i;
            while (j < N - 1 && nums[j + 1] == nums[j] + 1) {
                ++j;
            }
            if (i != j) {
                string s = to_string(nums[i]) + "->" + to_string(nums[j]);
                ranges.push_back(s);
            } else {
                ranges.push_back(to_string(nums[i]));
            }
            i = j + 1;
        }
        return ranges;
    }
};
// @lc code=end

