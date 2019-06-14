/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {        
        const int M = obstacleGrid.size();
        if (M == 0)
            return 0;
        const int N = obstacleGrid[0].size();
        long long sol[M][N];
        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            sol[0][0] = 1;
        for (int i = 0;i < M; i++)
            for (int j = 0; j < N ; j++)
                if (!(i==0 && j==0))
                {
                    if (obstacleGrid[i][j] == 0)                    
                        sol[i][j] = (i>0 ? sol[i-1][j] : 0)  +  (j>0?sol[i][j-1] : 0);
                    else
                        sol[i][j] = 0;
                }                    
        return sol[M-1][N-1];    
    }
};

