/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num;
        uint32_t occurances = 0;
        for (int i : nums) {
            if (occurances == 0) {
                num = i;
                occurances = 1;
            } else {
                occurances = (num == i) ? occurances + 1 : occurances - 1;
            }
        }
        return num;
    }
};

