/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        while(p0 < nums.size() && nums[p0] == 0)p0++;
        while(p2 >=0 && nums[p2] == 2)p2--;
        if (p0 == nums.size() || p2 < 0 || p0 > p2)return;
        int cur = p0;

        while (cur <= p2){            
            if (nums[cur] == 0){
                swap(nums[p0], nums[cur]);                
                while(nums[p0] == 0)p0++;
                cur = max(cur, p0);
                
            }
            else if (nums[cur] == 2){
                swap(nums[p2], nums[cur]);
                while(nums[p2] == 2)p2--;
            }
            else
                cur++;
        }
    }
};
// @lc code=end

