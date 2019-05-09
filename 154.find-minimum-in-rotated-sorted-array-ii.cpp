/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        // Stage 1: find pivot        
        int l = 0, r = nums.size() - 1;
        int mid;
        if (nums[0] >= nums[nums.size() - 1])
        {
            while(r - l > 1)
            {
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
                mid = (r + l) / 2;
                if (nums[mid] >= nums[l])
                    l = mid;
                else
                    r = mid;
                
            }   
            return nums[r];         
        }
        else
            return nums[0];
        
    }
};

