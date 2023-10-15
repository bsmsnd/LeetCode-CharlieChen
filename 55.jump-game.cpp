/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthestPoint = 0;
        int target = nums.size() - 1;
        for (int i = 0; i <= furthestPoint; i++) {
            furthestPoint = max(furthestPoint, nums[i] + i);
            if (furthestPoint >= target) {
                return true;
            }
        }
        return false;
    }
};

