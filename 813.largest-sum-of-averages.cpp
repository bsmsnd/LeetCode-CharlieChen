/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */
#include <vector>
using namespace std;
class Solution {
public:
    int sums[100];
    double largestSumOfAverages(vector<int>& A, int K) {
        sums[0] = A[0];
        const int S = A.size();
        for (int i = 1;i < S;++i)
            sums[i] = sums[i-1] + A[i];
        
        double dp[S];
        for (int i = 0;i < S;++i)
            dp[i] = (double)(sums[S-1] - (i == 0 ? 0 : sums[i-1]) ) / (S-i);
        
        for (int k = 2; k <= K; ++k)
            for (int i = 0;i < S-1;++i)
            {
                double best = (double)(sums[S-1] - (i == 0 ? 0 : sums[i-1]) ) / (S-i);
                for (int j = i; j < S-1;++j)
                    best = max(best, (double)(sums[j] - (i == 0 ? 0 : sums[i-1])) / (j-i+1) + dp[j+1]);
                dp[i] = best;
            }
        return dp[0];
    }


};

