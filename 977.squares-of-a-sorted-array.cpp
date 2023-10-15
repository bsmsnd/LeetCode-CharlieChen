/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int32_t negative = 0;
        int32_t positive = nums.size() - 1;
        vector<int> answer;
        answer.reserve(nums.size());
        while (positive >= negative) {
            // both numbers are valid
            if (nums[positive] >= 0 && nums[negative] < 0) {
                if (nums[positive] >= -nums[negative]) {
                    answer.push_back(nums[positive] * nums[positive]);
                    positive--;
                } else {
                    answer.push_back(nums[negative] * nums[negative]);
                    negative++;
                }
            } else if (nums[positive] >= 0) { // only positive is valid
                answer.push_back(nums[positive] * nums[positive]);
                positive--;
            } else { // only negative is valid
                answer.push_back(nums[negative] * nums[negative]);
                negative++;
            }
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
// @lc code=end

