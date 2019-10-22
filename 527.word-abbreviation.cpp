/*
 * @lc app=leetcode id=527 lang=cpp
 *
 * [527] Word Abbreviation
 */

// @lc code=start

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<int>> m;
        vector<string> ans;
        
        set<int>s;
        const int N = dict.size();
        ans.resize(N);
        // init
        for (int i = 0;i < N; i++)
        {
            if (dict[i].size() <= 3)
            {
                ans[i] = dict[i];
                continue;
            }

            ans[i] = dict[i][0] + to_string(dict[i].size()-2) + dict[i].back();
            if (m.find(ans[i]) == m.end())
                m[ans[i]] = vector<int>();
            m[ans[i]].push_back(i);
            s.insert(i);
        }

        int keep = 1;
        while(s.size() > 0)
        {
            // verify
            for (auto it = m.begin(); it!=m.end(); it++)
            {
                if (it->second.size() == 1)
                {
                    s.erase(it->second[0]);
                }                                
            }
            m.clear();            
            if (s.size() == 0)break;            
            keep++;            
            for (auto it = s.begin(); it != s.end();)
            {
                int i = *it;
                if (dict[i].size() <= keep + 2)
                {
                    ans[i] = dict[i];
                    it++;
                    s.erase(i);
                }
                else
                {
                    ans[i] = dict[i].substr(0, keep) + to_string(dict[i].size() - keep - 1) + dict[i].back();
                    if (m.find(ans[i]) == m.end())
                        m[ans[i]] = vector<int>();
                    m[ans[i]].push_back(i);
                    it++;
                }
            }
        }
        return ans;        
    }
};
// @lc code=end

