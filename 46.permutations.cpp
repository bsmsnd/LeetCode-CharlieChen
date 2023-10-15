/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    // static constexpr int NUMBER_MAX_LENGTH = 6;
    bool IsMasked(int mask, int t) {
        return ((mask >> t) & 0b01) == 0b01;
    }
    int SetMask(int mask, int t) {
        return (mask | (0b01 << t));
    }

    void NextPermute(const vector<int>& nums, int mask, int remainingNumbers) {
        if (remainingNumbers == 0) {
            permutations.push_back(currentPermutation);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (!IsMasked(mask, i)) {
                    currentPermutation.push_back(nums[i]);
                    NextPermute(nums, SetMask(mask, i), remainingNumbers - 1);
                    currentPermutation.pop_back();
                }
            }
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        NextPermute(nums, 0, nums.size());
        return permutations;
    }
private:
    vector<vector<int>> permutations;
    vector<int> currentPermutation;
};
// @lc code=end

