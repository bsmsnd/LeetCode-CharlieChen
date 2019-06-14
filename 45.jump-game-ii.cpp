/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        const int K = nums.size();
        int min_steps[K];
        int furthest = 0;        
        min_steps[0] = 0;
        for (int i = 0;i<K;i++)
        if (nums[i] >= 0 && i + nums[i] > furthest)
        {            
            for (int j = furthest + 1; j < min(i + nums[i] + 1, K); ++j)
                min_steps[j] = min_steps[i] + 1;
            furthest = i + nums[i];
            if (furthest >= K)
                return min_steps[K - 1];

        }
        return min_steps[K-1];

    }
};


