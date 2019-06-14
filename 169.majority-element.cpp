/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curValue;
        int occurance = 0;
        for (int i = 0;i < nums.size();++i)
        {
            if (occurance == 0)
            {
                curValue = nums[i];
                occurance++;
            }
            else
            {
                if (curValue == nums[i])
                    occurance++;
                else
                    occurance--;
            }            
        }
        return curValue;
    }
};

