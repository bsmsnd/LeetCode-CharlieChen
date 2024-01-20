/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                sums[n1+n2]++;
            }
        }
        int zeroResult = 0;
        for (int n3 : nums3) {
            for (int n4: nums4) {
                if (sums.find(-n3-n4) != sums.end()) {
                    zeroResult += sums[-n3-n4];
                }
            }
        }
        return zeroResult;
    }
};
// @lc code=end

