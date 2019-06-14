/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {    
        int furthest_point = 0;
        const int K = nums.size();
        for (int i = 0;i < K;++i)
        {
            if (i > furthest_point)
                return false;
            else
            {
                furthest_point = max(i + nums[i], furthest_point);
            }
        }
        return true;
    }
};

