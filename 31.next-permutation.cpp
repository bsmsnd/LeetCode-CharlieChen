/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first = -1, second = -1;
        int n = nums.size();
        for (int i = 0;i < n-1; ++i)
            if (nums[i] < nums[i+1])
            {
                first = i; second = i + 1;
                for (int j = i+1; j < n; ++j)
                {
                    if (nums[j] <= nums[i])
                    {
                        i = j - 1;
                        break;
                    }                        
                    if ((j == n-1 && nums[j] > nums[i]) || nums[j-1] > nums[j])
                        second = j;
                    if (j < n-1 && nums[j] <  nums[j+1])
                    {
                        i = j - 1;
                        break;
                    }                        
                }
            }
        cout<<first<<" "<<second<<endl;
        if (first == -1)
            sort(nums.begin(), nums.end());
        else
        {
            swap(nums[first], nums[second]);    
            // cout<<nums[0]<<nums[1]<<nums[2]<<endl;
            sort(nums.begin()+(first+1), nums.end());
        }
            
    }
};
