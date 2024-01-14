/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        uint32_t N = s.size();
        uint32_t offset = 0;
        while (N - offset >= 2 * k) {
            reverse(s.begin()+offset, s.begin()+(offset + (k)));
            offset += (2 * k);            
        }
        if (N - offset == 0) {
            return s;
        }
        if (N - offset < k) {
            reverse(s.begin()+offset, s.end());
        } else {
            reverse(s.begin()+offset, s.begin()+(offset + k));
        }
        return s;
    }
};
// @lc code=end

