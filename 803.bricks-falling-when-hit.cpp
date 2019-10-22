/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
const int MX[4] = {0,-1,0,1};
const int MY[4] = {1,0,-1,0};

class Solution {
public:
    int color[200][200];
    int N, M, W;
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        N = grid.size();
        M = grid[0].size();
        W = hits.size();
        memset(color, -1, sizeof(color));
        for (int i = 0;i < W; i++)
            if (grid[hits[i][0]][hits[i][1]] == 0)
                grid[hits[i][0]][hits[i][1]] = -1;
            else // should be 1 previously
                grid[hits[i][0]][hits[i][1]] = 0;
        queue<pair<int, int>> q;
        
        int x, y, nx, ny;

        for (int j = 0; j < M; j++)
        if (grid[0][j] == 1)
        {
            q.push({0,j});
            color[0][j] = 0;
            
            while(!q.empty())
            {                
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for (int k = 0;k < 4; k++)
                {
                    nx = x + MX[k];
                    ny = y + MY[k];
                    if (nx >= 0 && nx < N && ny >=0 && ny < M && grid[nx][ny] == 1 && color[nx][ny] < 0)
                    {
                        color[nx][ny] = 0;
                        q.push({nx,ny});
                    }                        
                }
            }
        }
        
        // all remaining grids are connected
        vector<int> ans;
        ans.resize(W, 0);
        for (int i = W-1; i>=0; i--)
        {
            // cout<<i<<endl;
            int id = i + 2;
            x = hits[i][0]; y = hits[i][1];
            if (grid[x][y] == -1)
                continue;
            else
                grid[x][y] = 1;
            // check if it is connected
            bool attached = (x == 0);
            if (!attached)
            for (int k = 0;k < 4; k++)
            {
                nx = x + MX[k];
                ny = y + MY[k];
                if (nx >= 0 && nx < N && ny >=0 && ny < M && grid[nx][ny] == 1 && color[nx][ny] >= 0)
                {
                    attached = true;
                    break;
                }                        
            }
            // cout<<attached<<endl;
            if (!attached)continue;

            q.push({x,y});
            color[x][y] = id;
            int cnt = 0;            
            while(!q.empty())
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for (int k = 0;k < 4; k++)
                {
                    nx = x + MX[k];
                    ny = y + MY[k];
                    if (nx >= 0 && nx < N && ny >=0 && ny < M && grid[nx][ny] == 1 && color[nx][ny] < 0)
                    {
                        cnt++;
                        color[nx][ny] = id;
                        q.push({nx, ny});
                    }
                }

            }
            ans[i] = cnt;            
        }
        return ans;
    }
};
// @lc code=end

