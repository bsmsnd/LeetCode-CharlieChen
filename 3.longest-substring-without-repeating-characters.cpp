/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (27.17%)
 * Total Accepted:    867.1K
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        bool all_symbols[500];  // Should not need that much!
        memset(all_symbols, 0, sizeof(all_symbols));  // Set all to false
        int best[2] = {0,0};
        int best_length = 1;
        int left = 0;
        int right = 0;
        all_symbols[s[0]] = true;
        while (right < s.length() - 1){
            right++;
            if (all_symbols[s[right]])  // already in the sequence
            {
                while(s[left] != s[right]){
                    all_symbols[s[left]] = false;
                    left++;
                }
                left++;  // skip the same symbol
                all_symbols[s[right]] = true;
            }
            else
            {
                all_symbols[s[right]] = true;
                if (right - left + 1 > best_length)
                {
                    best[0] = left;
                    best[1] = right;
                    best_length = right - left + 1;
                }
            }
        }
        return best_length;
    }
    
};

