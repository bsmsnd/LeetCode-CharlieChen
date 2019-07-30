/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */
class Solution {
public:
    double dp[500][500];
    double f(int a, int b)
    {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0 && b > 0) return 1;
        if (a > 0 && b <= 0) return 0;
        if (dp[a][b] > 0) return dp[a][b];
        else
            return dp[a][b] = 0.25 * (f(a-4, b) + f(a-3, b-1) + f(a-2, b-2) + f(a-1, b-3));
        
    }
    double soupServings(int N) {
        if (N > 5000) return 1.0;
        N = (N + 24) / 25;        
        return f(N, N);
    }
};

