/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int lower = 0;
        const int  N = S.size();
        int upper = N;
        vector<int> ans;
        // ans.push_back(S[0] == 'I' ? lower++ : upper--);
        for (int i = 0;i < N;++i)
        {
            if (S[i] == 'I')
                ans.push_back(lower++);
            else
                ans.push_back(upper--);
        }
        ans.push_back(lower);
        return ans;

    }
};

