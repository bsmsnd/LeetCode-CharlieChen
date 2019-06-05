/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        unsigned long size = nums.size();
        unsigned long long power_it = (unsigned long long)pow(2, size);
        for (int i = 0;i<power_it;i++)
        {
            int m = i;
            vector<int> cur_set;
            int cnt = 0;
            int bit;
            while(m > 0)
            {
                bit = m & 1;
                if (bit)
                    cur_set.push_back(nums[cnt]);                
                cnt++;
                m>>=1;
            }
            sol.push_back(cur_set);
        }
        return sol;
    }
};

