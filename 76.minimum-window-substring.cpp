/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        unordered_map<char,int> constraint;
        unordered_map<char,int> cnt;
        for (int i=0;i<t.length();++i)
        {
            auto it = constraint.find(t[i]);
            if (it!=constraint.end())
                constraint[t[i]]++;
            else
                constraint[t[i]] = 1;
        }
        int reqs = 0;
        for (auto it = constraint.begin(); it!=constraint.end(); ++it)
        {
            cnt[it->first] = 0;
            reqs++;
        }
        
        int left = 0;
        int right = 0;
        int sats = 0;
        char cur;
        while(left <= right && right <= s.size())
        {
            // first move right pointer until a valid answer
            while(sats < reqs && right <= s.size())
            {
                cur = s[right++];
                auto it = cnt.find(cur);
                if (it!=cnt.end())
                {
                    cnt[cur]++;
                    if (cnt[cur] == constraint[cur])
                        sats++;
                }
            }
            
            // then move left pointer for best answer (right pointer fixed)
            while(sats == reqs && left < right)
            {
                cur = s[left];
                auto it = cnt.find(cur);
                if (it!=cnt.end())
                {
                    cnt[cur]--;
                    if (cnt[cur] < constraint[cur])  // need save answer now
                    {
                        if (sats == reqs && (ans.length() > right-left || ans == ""))
                            ans = s.substr(left, right-left);
                        sats--;
                    }
                }
                left++;
            }
        }
        return ans;
    }
};

