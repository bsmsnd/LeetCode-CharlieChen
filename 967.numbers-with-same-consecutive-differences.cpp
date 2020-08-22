/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
public:
    vector<int> ans;
    int cur;
    int n,k;
    void search(int t, int p){        
        if (t == n)
            ans.push_back(cur);
        else{
            if (p >= k){
                cur = cur * 10 + (p - k);
                search(t+1, p-k);
                cur /= 10;
            }
            if (p+k <= 9 && k!=0){
                cur = cur * 10 + (p+k);
                search(t+1, p+k);
                cur /= 10;
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 0)return ans;
        n = N;
        k = K;
        cur = 0;
        for (int i = (n == 1) ? 0 : 1;i <= 9; i++){
            cur = i;
            search(1, i);
        }     
        return ans;   
    }
};
// @lc code=end

