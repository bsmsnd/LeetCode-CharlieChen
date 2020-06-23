/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    int sum[4];
    int sum_of_elems;
    bool makesquare(vector<int>& nums, int t=0) {
        if (t == 0){
            memset(sum, sizeof(sum), 0);
            sum_of_elems = accumulate(nums.begin(), nums.end(), 0);
            if (sum_of_elems % 4 != 0)return false;
            sum_of_elems /= 4;
            sort(nums.begin(), nums.end(), greater<int>());
        }
        if (t == nums.size()) return (sum[0] != 0 && sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3]);

        for (int i = 0; i < 4; i++){
            sum[i] += nums[t];
            if (sum[i] <= sum_of_elems && makesquare(nums, t+1))
                return true;
            sum[i] -= nums[t];
        }
        return false;
    }
};
// @lc code=end

