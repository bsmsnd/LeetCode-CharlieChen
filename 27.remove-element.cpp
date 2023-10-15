/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <cstdint>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        uint32_t fast = 0;
        uint32_t slow = 0;
        const uint32_t t = nums.size();
        while (fast < t) {
            while (fast < t && nums[fast] == val) {
                fast++;
            }
            if (fast < t) {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};
// @lc code=end

