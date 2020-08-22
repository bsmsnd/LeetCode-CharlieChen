/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

// @lc code=start
class Solution {
public:
    string generateTheString(int n) {
        if(n%2 == 0)
            return string(n-1, 'a') + "b";
        else
            return string(n, 'a');
    }
};
// @lc code=end

