/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    inline int MoveForward(vector<int> &nums, int beginPosToModify, int offset, int realSize)
    {
        for (int i = beginPosToModify; i < realSize - offset; i++) {
            nums[i] = nums[i+offset];
        }
        return realSize - offset;
    }
    int removeDuplicates(vector<int>& nums) {
        int realSize = nums.size();
        for (uint32_t i = 2; i < realSize; i++) {
            if (nums[i] == nums[i-2]) {
                uint32_t j = 0;
                while ((i + j < realSize) && (nums[i+j] == nums[i])) {
                    j++;
                }
                realSize = MoveForward(nums, i, j, realSize);
            }
        }
        return realSize;
    }
};
// @lc code=end

