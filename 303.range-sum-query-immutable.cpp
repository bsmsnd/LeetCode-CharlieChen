/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */
class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {    
        int size = nums.size();
        int curSum = 0;
        for(int i = 0 ; i < size;++i)
        {
            curSum += nums[i];
            sums.push_back(curSum);
        }            
    }
    
    int sumRange(int i, int j) {
        if (i==0)
            return sums[j];
        else
            return sums[j] - sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

