/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int len = S.length();
        int i,j;
        i = 0;
        while(i < len)
        {
            j = i+1;
            while(S[j] == S[i] && j < len) j++;
            if (j - i >= 3)
            {
                vector<int> T = {i, j-1};
                ans.push_back(T);
            }
            i = j;            
        }
        return ans;
    }
};

