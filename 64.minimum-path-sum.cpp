/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        if (M == 0)
            return 0;
        const int N = grid[0].size();
        int sol[M][N];
        sol[0][0] = grid[0][0];
        for (int i = 0; i < M;i++)
            for (int j = 0 ;j < N ; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                        continue;
                    else
                        sol[i][j] = sol[i][j-1] + grid[i][j];
                    continue;
                }

                if (j == 0)
                {
                    sol[i][j] = sol[i-1][j] + grid[i][j];
                    continue;
                }                    
                sol[i][j] = min(sol[i-1][j], sol[i][j-1]) + grid[i][j];                
            }
        return sol[M-1][N-1];
    }
};

