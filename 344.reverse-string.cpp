/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        uint32_t N = s.size();
        for (uint32_t i = 0; i < N/2; i++) {
            swap(s[i], s[N-1-i]);
        }
    }
};
// @lc code=end

