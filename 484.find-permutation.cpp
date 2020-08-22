/*
 * @lc app=leetcode id=484 lang=cpp
 *
 * [484] Find Permutation
 */

// @lc code=start
class Solution {
public:    
    int N;
    int countD(string& s, int pos){
        for(int i = pos; i < N; i++)
            if (s[i] == 'I')return i - pos;
        return N - pos;
    }
    vector<int> findPermutation(string s) {        
        N = s.size();
        vector<int> ans(N+1);
        for (int i = 0; i < N+1; i++)ans[i] = i+1;
        int i = 0;
        while(i < N){
            while(s[i] == 'I')i++;
            int t = countD(s, i);
            reverse(ans.begin() + i, ans.begin() + (i+t+1));
            i = i + t;
        }        
        return ans;
    }
};
// @lc code=end

