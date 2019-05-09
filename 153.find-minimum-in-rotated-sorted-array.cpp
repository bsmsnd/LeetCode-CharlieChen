/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        // Stage 1: find pivot
        int size = (int)nums.size();
        int l = 0, r = size-1;
        int mid;
        if (nums[l] > nums[r])
        {
            while(r-l>1)
            {
                mid = l + (r-l)/2;
                if (nums[mid] > nums[l])
                    l = mid;
                else
                    r = mid;
                
            }
            return nums[r];
        }
        else
        {
            return nums[0];
        }
    }
};

