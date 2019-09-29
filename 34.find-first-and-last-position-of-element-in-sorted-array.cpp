/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int N = nums.size();
        if (N == 0)return {-1,-1};
        int l = 0, r = N - 1, m;
        
        while (l <= r)
        {
            m = (l + r)/2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }       
        int left = l;

        l = left; r = N - 1;
        while(l <= r)
        {
            m = (l + r) / 2;
            if (nums[m] <= target)
                l = m;
            else
                r = m - 1;
        }
        int right = r;
        if (l <= r)
            return {l,r};
        else
            return {-1, -1};
    }
};

