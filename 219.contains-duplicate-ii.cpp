/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
// #include "helper.h"
// #include <unordered_set>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        uint32_t N = nums.size();
        unordered_set<int> values;
        for (uint32_t i = 0; i < min((uint32_t)k, N); i++) {
            if (values.find(nums[i]) == values.end()) {
                values.insert(nums[i]);
            } else {
                return true;
            }
        }
        for (uint32_t i = k; i < N; i++) {
            if (values.find(nums[i]) == values.end()) {
                values.insert(nums[i]);
            } else {
                return true;
            }
            values.erase(nums[i - k]);
        }
        return false;
    }
};

