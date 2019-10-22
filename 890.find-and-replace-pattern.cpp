/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        char toPattern[26], toWord[26];        
        // int usedCharInPattern = 0;
        const int N = words.size();
        const int K = pattern.length();
        vector<string> ans;
        for(int i = 0;i < N; i++)
        if (words[i].length() == K)
        {
            // usedCharInPattern = 0;
            memset(toPattern, 0, sizeof(toPattern));
            memset(toWord, 0, sizeof(toWord));
            bool fail_flag = false;
            for (int j = 0;j < K; j++)
            {
                if (toPattern[words[i][j] - 'a'] == 0 && toWord[pattern[j] - 'a'] == 0)
                {
                    toPattern[words[i][j] - 'a'] = pattern[j];
                    toWord[pattern[j] - 'a'] = words[i][j];
                    // usedCharInPattern++;
                }
                else if (toPattern[words[i][j] - 'a'] != 0 && toWord[pattern[j] - 'a'] != 0)
                {
                    if (toPattern[words[i][j] - 'a'] == pattern[j] && toWord[pattern[j] - 'a'] == words[i][j])
                        continue;
                    else
                    {
                        fail_flag = true;
                        break;
                    }                    
                }
                else
                {
                    fail_flag = true;
                    break;
                }                
            }
            if (!fail_flag)
                ans.push_back(words[i]);
        }
        return ans;
    }
};
// @lc code=end

