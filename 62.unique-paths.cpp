/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int sol[100][100];
        sol[0][0] = 1;
        for (int i = 0;i < m; i++)
            for (int j = 0; j < n ; j++)
                if (!(i==0 && j==0))
                    sol[i][j] = (i>0 ? sol[i-1][j] : 0)  +  (j>0?sol[i][j-1] : 0);
        return sol[m-1][n-1];
    }
};

