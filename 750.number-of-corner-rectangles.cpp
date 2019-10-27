/*
 * @lc app=leetcode id=750 lang=cpp
 *
 * [750] Number Of Corner Rectangles
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        const int N = grid.size();
        if (N <= 1)return 0;
        const int M = grid[0].size();
        if (M <= 1)return 0;
        
        int cnt[M][M];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0;i < N; i++)
        {
            vector<int> s;
            s.reserve(M);
            for (int j = 0; j < M; j++)
            if (grid[i][j] == 1)
                s.push_back(j);
            int n = s.size();
            
            for (int k = 0;k < n-1; k++)
            for (int l = k+1; l < n; l++)
                cnt[s[k]][s[l]]++;
        }
        int ans = 0;
        for (int k = 0;k < M-1; k++)
        for (int l = k;l < M; l++)
            if (cnt[k][l] > 1)
                ans += cnt[k][l] * (cnt[k][l]-1) / 2;

        return ans;
    }
};
// @lc code=end

