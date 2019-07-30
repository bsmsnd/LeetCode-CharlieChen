/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 */
#define MOD 1000000007
class Solution {
public:
    // int sumSubseqWidths(vector<int>& A) {
    //     const int N = A.size();
    //     long long ans[N] = {};
    //     long long sums[N] = {};
    //     long long power_2 = 0;
    //     sort(A.begin(), A.end());
    //     ans[0] = 0; sums[0] = A[0] % MOD; power_2 = 1;

    //     for (int i = 1;i < N;++i)
    //     {
    //         ans[i] = (ans[i-1] + (ans[i-1] + ((2 * power_2 - 1) % MOD) * (long long)A[i] - sums[i-1])%MOD)%MOD;
    //         sums[i] = (sums[i-1] + (((2 * power_2) % MOD) * (long long)A[i])) % MOD;
    //         power_2 = (power_2 * 2) % MOD;
    //         // cout<<ans[i]<<" "<<sums[i]<<endl;
    //     }
    //     return ans[N-1];
    // }
    int sumSubseqWidths(vector<int>& A) {
        const int N = A.size();        
        long long power_2[N] = {};
        sort(A.begin(), A.end());
        power_2[0] = 1;

        for (int i = 1;i < N;++i)                
            power_2[i] = (power_2[i-1] * 2) % MOD;
            // cout<<ans[i]<<" "<<sums[i]<<endl;
        long long ans = 0;
        for (int i = 0;i < N;++i)
            ans = (ans + (power_2[i] - power_2[N-i-1]) * A[i]) % MOD;
        return ans;
    }
};

