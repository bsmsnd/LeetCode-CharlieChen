/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.length() < 10)
            return ans;
        unordered_set<string> se, ans_set;        
        string sub_string;
        for (int i = 0; i < s.length() - 9; ++i)
        {
            sub_string = s.substr(i, 10);
            cout<<sub_string<<endl;
            auto it = se.find(sub_string);
            if (it != se.end())
                ans_set.insert(*it);
            else
                se.insert(sub_string);
        }
        return vector<string>(ans_set.begin(), ans_set.end());
    }
};

