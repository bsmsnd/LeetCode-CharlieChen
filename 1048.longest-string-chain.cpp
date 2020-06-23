/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
bool comp(string& a, string& b){
    return (a.size() < b.size()) || (a.size() == b.size() && a < b);
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        const int N = words.size();
        int ans[N], cnt[17];        
                
        for (int i = 0; i < 17; i++)cnt[i] = 0;

        int best = -1;
        sort(words.begin(), words.end(), comp);                

        for (int i = 0;i < N; i++)
            cnt[words[i].size()]++;

        int l = 0, r = 0;
        for (int len = 1; len <= 16; len++){
            // cout << len << endl;
            l += (len >= 2 ? cnt[len-2] : 0);
            r += cnt[len-1];

            if (cnt[len - 1] == 0){
                for (int i = r; i < r + cnt[len]; i++)
                    ans[i] = 1;
                best = max(1, best);
            }
            else{
                for (int i = r; i < r + cnt[len]; i++){
                    ans[i] = 1;

                    for (int j = l; j < r; j++)
                        if (verify(words[j], words[i]))
                            ans[i] = max(ans[i], ans[j] + 1);
                    // cout << i << " " << ans[i] << endl;
                    best = max(best, ans[i]);
                }                            
            }            
        }

        return best;
    }

    bool verify(string& a, string& b){
        if (b.size() - a.size() != 1)return false;
        bool flag = false;
        int p1 = 0, p2 = 0;
        while(p1 < a.size()){
            if (a[p1] == b[p2]){
                p1++; p2++;
            }
            else{
                if (flag)return false;
                else{
                    flag = true;
                    p2++;
                }                
            }                         
        }
        return true;
    }
};
// @lc code=end

