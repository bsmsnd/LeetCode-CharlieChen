/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> numMap;
        for (int n : nums) {
            numMap[n] = false;
        }
        int best = 0;
        for (int n : nums) {
            if (!numMap[n]) {
                int startNumber = n;
                while (numMap.find(startNumber) != numMap.end()) {
                    --startNumber;
                }
                ++startNumber; // recover
                int endNumber = startNumber;
                while (numMap.find(endNumber) != numMap.end()) {
                    numMap[endNumber] = true;
                    endNumber++;
                }
                best = max(best, endNumber - startNumber);
            }
        }
        return best;
    }
};
// @lc code=end

