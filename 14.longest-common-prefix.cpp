/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.95%)
 * Total Accepted:    437.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.empty()){
            return ans;
        }
        int n = 0;
        while(1){
            if ((*strs.begin()).length() < n)
                break;
            char this_char = (*strs.begin())[n];
            bool same_flag = true;
            for (auto & element : strs) {
                if (element.length() < n || element[n] != this_char)
                {
                    same_flag = false;
                    break;
                }
            }
            if (same_flag){
                ans = ans + this_char;
                n = n + 1;
            }
            else
                break;   
        }
        return ans;
    }
};

