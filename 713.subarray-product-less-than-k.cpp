/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /* Solution 1
        int left = 0;
        int right = 0;
        long long ans = 0;
        int product = nums[left];
        int size = (int)nums.size();
        long long indices = 0;
        long long overlap = 0;
        while(right < size)
        {
            while(product < k)
            {
                if (right < size - 1)
                    product *= nums[++right];
                else
                {
                    right++;
                    break;
                }
            }
            // count combinations from left to right - 1
            indices = right - left;
            ans += (indices + 1) * indices / 2 - (overlap + 1) * overlap / 2;
            overlap = indices;
            while(product >= k && left < right)
            {
                product /= nums[left++];
                overlap--;
            }
            if (nums[left] >= k)
            {
                left = ++right;
                overlap = 0;
                if (right < size)
                    product = nums[right];
                else
                    break;
            }
        }
        */
        if (k == 0) 
            return 0; 
        
        int ans = 0;
        int product = 1;
        int size = nums.size();
        int left = 0, right = 0;
        for (right = 0; right < size; right++){
            product *= nums[right];
            while(left <= right && product >= k){
                product /=nums[left++];                
            }
            ans += right - left + 1; 
        }
        return ans;
    }
};

