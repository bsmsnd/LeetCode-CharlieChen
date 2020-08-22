/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    vector<int> ans;
    int N;

    int func(int p, vector<int>& ratings){
        if (p == N-1)
            return ans[p] = 1;
        if (ratings[p] <= ratings[p+1])
            return ans[p] = 1;
        return ans[p] = func(p+1, ratings) + 1;
    }

    int candy(vector<int>& ratings) {
        N = ratings.size();
        ans.resize(N, 0);
        if (N == 1){
            return 1;            
        }
        if (ratings[0] <= ratings[1])
            ans[0] = 1;
        else
            ans[0] = func(1, ratings) + 1;
        
        for (int i = 1;i < N-1; i++)
            if(ans[i] == 0){
                if (ratings[i] <= ratings[i+1])
                    ans[i] = (ratings[i-1] >= ratings[i] ? 1 : ans[i-1] + 1); 
                else{
                    if (ratings[i] > ratings[i-1])
                        ans[i] = max(ans[i-1] + 1, func(i+1, ratings) + 1);
                    else
                        ans[i] = func(i+1, ratings) + 1;
                }
                    
            }
        
        
        if(ans.back() == 0)
            ans[N-1] = (ratings[N-1] > ratings[N-2]) ? ans[N-2] + 1 : 1;
        
        return accumulate(ans.begin(), ans.end(), 0);        
    }
};
// @lc code=end

