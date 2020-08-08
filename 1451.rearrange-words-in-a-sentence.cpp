/*
 * @lc app=leetcode id=1451 lang=cpp
 *
 * [1451] Rearrange Words in a Sentence
 */

// @lc code=start
class Solution {
public:
    string arrangeWords(string text) {
        map<int, list<string>> s;
        char cText[text.length() + 1];
        strcpy(cText, text.c_str());
        char *pch = strtok(cText," ");
        while(pch){
            string curString = string(pch);
            if(curString[0] >= 'A' && curString[0] <= 'Z')
                curString[0] += ('a' - 'A');
            int len = curString.size();
            if (s.find(len) == s.end()){
                s[len] = list<string>();
                s[len].push_back(curString);
            }
            else
                s[len].push_back(curString);
            pch = strtok(NULL," ");
        }

        bool firstWord = false;
        string ans;
        for (auto it = s.begin(); it != s.end(); it++)
            for (auto& word : it->second)
                if (!firstWord){
                    string w = word;
                    w[0] += ('A' - 'a');
                    ans = w;
                    firstWord = true;
                }
                else
                    ans += " " + word;

        return ans;
    }
};
// @lc code=end

