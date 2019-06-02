/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> sums;
        int size = nums.size();
        sums.insert(0);
        int ans = 0;
        long long sum = 0;
        for (int i = 0;i<size;i++)
        {
            sum += nums[i];
            // Note that lower_bound(v) gives the value that is less or equal to v, while upper_bound(v) gives the value that is greater than v
            ans += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return ans;
    }
};

