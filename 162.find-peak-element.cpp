/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0; int right = nums.size() - 1;
        int mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if (mid == 0)
                return nums[0] > nums[1] ? 0 : 1;
            if (nums[mid-1] < nums[mid])
            {
                if (nums[mid] > nums[mid+1])
                    return mid;
                else
                    left = mid + 1;
            }
            else
                right = mid-1;
        }
        return left;
    }
};

