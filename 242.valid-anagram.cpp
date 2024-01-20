/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        int charCount[26];
        memset(charCount, 0, sizeof(charCount));
        if (s.length() != t.length()) {
            return false;
        }
        for (char ch : s) {
            ++charCount[ch - 'a'];
        }
        for (char ch : t) {
            if (charCount[ch - 'a'] <= 0) {
                return false;
            }
            --charCount[ch - 'a'];
        }
        return true;
    }
};
// @lc code=end

