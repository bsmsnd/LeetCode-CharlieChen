/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        if (s3.size() == 0)return s1.size() == 0 && s2.size() == 0;
        const int SIZE[3] = {(int)s1.size(), (int)s2.size(), (int)s3.size()};
        set<pair<int, int>> states[SIZE[2]];
        
        // 0-th char
        if (s1.size() > 0 && s3[0] == s1[0])
            states[0].insert(make_pair(1,0));
        if (s2.size() > 0 && s3[0] == s2[0])
            states[0].insert(make_pair(0,1));
                       
        for (int i = 1; i < SIZE[2]; i++)
            if(states[i-1].size() > 0) 
                for (auto p : states[i-1]){                    
                    if (p.first < SIZE[0] && s3[i] == s1[p.first])
                        states[i].insert(make_pair(p.first + 1, p.second));
                    if (p.second < SIZE[1] && s3[i] == s2[p.second])
                        states[i].insert(make_pair(p.first, p.second + 1));
                }
        return states[SIZE[2] - 1].size() > 0;
    }
};
// @lc code=end

