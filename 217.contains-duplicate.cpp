/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /* version 1: set
        set<int> S;
        int size = nums.size();
        for (int i = 0;i<size;i++)
        {
            if (S.count(nums[i]) == 0)
                S.insert(nums[i]);
            else
                return true;
        }
        return false;
        */
       // Version 2: Sort
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for (int i = 0;i < size - 1;++i)
            if (nums[i] == nums[i+1])
                return true;
        return false;
        
    
    }
};

