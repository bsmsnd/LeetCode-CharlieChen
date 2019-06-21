/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
// Solution 1: from solution 2 on the website
    // string make_label(string wd)
    // {
    //     int cnt[26] = {};
    //     for (int i = 0;i < wd.length(); ++i)
    //         cnt[wd[i]-'a']++;                
    //     string rt = "";
    //     for (int i = 0;i < 25;++i)
    //     {
    //         rt += to_string(cnt[i]);
    //         rt += "_";
    //     }
    //     rt += to_string(cnt[25]);
    //     return rt;
    // }

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     map<string, vector<string>> m;
    //     string label;
    //     vector<vector<string>> ans;
    //     for (int i = 0;i < strs.size(); ++i)
    //     {
    //         label = make_label(strs[i]);
    //         auto it = m.find(label);
    //         if (it==m.end())                            
    //             m[label] = vector<string>();           
    //         m[label].push_back(strs[i]);
    //     }
    //     for (auto it=m.begin();it!=m.end();++it)
    //     ans.push_back(it->second);
    //     return ans;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size() == 0)return ans;
        unordered_map<string, int> key;
        string s_copy;
        int cnt = 0;
        for (int i = 0;i < strs.size();++i)
        {
            s_copy = strs[i];
            sort(s_copy.begin(), s_copy.end());
            // cout<<s_copy<<endl;
            auto it = key.find(s_copy);
            if (it!=key.end())
                ans[it->second].push_back(strs[i]);
            else
            {
                // cout<<cnt<<endl;
                key[s_copy] = cnt++;
                ans.push_back(vector<string>());
                ans.back().push_back(strs[i]);
            }            
        }   
        return ans;
    }
};

