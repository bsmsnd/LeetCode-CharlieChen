/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;    
        int size = nums.size();    
        if (nums.size() == 0)
            return 0;
        else            
            length = 1;
        for(int i = 1;i<size;i++)
        {
            while (i < size && nums[length - 1] == nums[i]) i++;
            if (i == size)
                break;
            nums[length++] = nums[i];
        }
        return length;
    }
};

