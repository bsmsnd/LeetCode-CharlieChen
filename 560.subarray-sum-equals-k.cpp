/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum = 0;
        const int N = nums.size();
        int ans = 0;
        for (int i = 0;i < N; ++i)
        {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                ans += m[sum - k];            
            if (m.find(sum) == m.end())
                m[sum] = 0;
            m[sum]++;
        }
        return ans;
    }
};

