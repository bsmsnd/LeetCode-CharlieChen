/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
#include <cmath>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int best_sum = 0;
        int best_diff = 1e9;
        int left,right,cur_sum;

        for (int i = 2; i < size; i++)
        {
            if(i < nums.size() - 1 && nums[i] == nums[i+1]) continue;
            left = 0;
            right = i - 1;
            while(right > left){                            
                cur_sum = nums[left] + nums[right] + nums[i];
                if (cur_sum == target){
                    return target;                    
                }
                if (abs(cur_sum - target) < best_diff)
                {
                    best_sum = cur_sum;
                    best_diff = abs(cur_sum - target);
                }                          
                if (cur_sum > target)
                    right--;
                else
                    left++;
            }
        }
        return best_sum;
        
    }
};

