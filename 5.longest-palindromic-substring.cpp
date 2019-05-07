/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.49%)
 * Total Accepted:    518.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
int save_table[1005][1005]; // -1 --> Not verified. 0 --> false.  1 --> true
string str;
class Solution {
public:
    string longestPalindrome(string s) {
        str = s;
        if (s.length() <= 1)
            return s;
        memset(save_table,-1,sizeof(save_table));
        for (int i = 0;i<s.length();i++) save_table[i][i] = 1;
        int best_length = 1;
        int best_answer_loc = 0;
        for (int i = 0;i<s.length() - 1;i++)
            for (int j = i+1;j<s.length();j++)
            {
                if (save_table[i][j] == -1)
                    save_table[i][j] = check(i,j);
                if (save_table[i][j] == 1 && j-i+1 > best_length){
                    best_length = j - i + 1;
                    best_answer_loc = i;
                }
            }
        // cout<<best_answer_loc<<endl;
        return s.substr(best_answer_loc, best_length);
    }

    int check(int left, int right){
        if (save_table[left][right] != -1)
            return save_table[left][right];
        if (str[left] == str[right])
            if (right - left == 1 || right - left == 2){
                save_table[left][right] = 1;
                return true;
            }
            else{
                save_table[left][right] = check(left + 1, right - 1);
                return save_table[left][right];
            }
        else
        {
            save_table[left][right] = 0;
            return 0;
        }
        
            

    }
};

