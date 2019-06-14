/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int K = s.length();
        int cnt[26] = {0};        
        for (int i = 0 ; i < K;++i)
            cnt[s[i] - 'a']++;
        bool visited[26] = {false};
        string ans = "";
        char cur;
        for (int i = 0; i < K; i++)
        {
            cur = s[i];
            cnt[cur - 'a']--;
            if (visited[cur - 'a'])
                continue;
            while(ans.length() > 0 && cur < ans.back() && cnt[ans.back() - 'a'] > 0)
            {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(cur);
            visited[cur - 'a'] = true;
        }
        return ans;
    }
};

