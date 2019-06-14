/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int M = dungeon.size();
        if (M == 0)
            return 0;
        const int N = dungeon[0].size();
        int sol[M][N];
        sol[0][0] = dungeon[0][0];
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

