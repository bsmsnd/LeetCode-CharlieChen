/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <vector>   
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_ans = nums[0];
        int prev_sum = nums[0];
        vector<int> sums;
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            if (prev_sum < 0)
                prev_sum = nums[i];
            else
                prev_sum += nums[i];
            
            best_ans = max(best_ans, prev_sum);
        }
        return best_ans;
    }
};

