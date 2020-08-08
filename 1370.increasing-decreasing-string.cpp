/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 */

// @lc code=start
class Solution {
public:
    string sortString(string s) {
        set<char> chars;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        int tot = 0;
        for (char ch : s){
            cnt[ch - 'a']++;
            chars.insert(ch);
            tot++;
        }

        string ans;
        while(tot){
            string to_remove;
            for (auto it = chars.begin(); it != chars.end(); it++){
                char cur = *it;                
                ans+=cur;
                tot--;
                if (--cnt[cur - 'a'] == 0)
                    to_remove += cur;
            }         
            if (tot == 0)break;
            for (char ch : to_remove)
                chars.erase(ch);

            to_remove = "";
            for (auto it = chars.rbegin(); it != chars.rend(); it++){
                char cur = *it;                
                ans+=cur;
                tot--;
                if (--cnt[cur - 'a'] == 0)
                    to_remove += cur;
            }    
            if (tot == 0)break;
            for (char ch : to_remove)
                chars.erase(ch);                  
        }
        return ans;
    }
};
// @lc code=end

