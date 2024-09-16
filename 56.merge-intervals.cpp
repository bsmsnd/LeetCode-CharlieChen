/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
// #include "helper.h"
bool Compare(vector<int> &lhs, vector<int> &rhs)
{
    return (lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]));
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Compare);
        vector<vector<int>> mergedIntervals;
        vector<int> current = intervals[0];
        for (const vector<int> &p : intervals) {
            if (p[0] < current[0] && p[1] < current[1]) {
                mergedIntervals.push_back(current);
                current = p;
            } else if (current[1] < p[1]) {
                current[1] = p[1];
            }
        }
        mergedIntervals.push_back(current);
        return mergedIntervals;
    }
};
// @lc code=end

