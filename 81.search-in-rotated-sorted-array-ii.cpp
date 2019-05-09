/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Stage 1: find pivot
        int size = (int)nums.size();
        if (size == 0)
            return false;
        int end_left, start_right;
        int l = 0, r = size - 1;
        int mid;
        if (nums[0] >= nums[size - 1])
        {
            while(r - l > 1)
            {
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
                mid = (r + l) / 2;
                if (nums[mid] > nums[l])
                    l = mid;
                else
                    r = mid;
                
            }
            end_left = l; start_right = r;
        }
        else
        {
            end_left = size - 1;
            start_right = size;
        }
        
        if (target >= nums[0]) // should search first set
        {
            l = 0; r = end_left;
        }
        else
        {
            l = start_right; r = size - 1;
            if (l >= size)
                return false;
        }
        if (nums[l] == target)
            return true;
        if (nums[r] == target)
            return true;
        while(r - l > 1)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        return false;
    }
};

