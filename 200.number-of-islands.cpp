/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
// #include "helper.h"
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (IsLand(grid[i][j]) && !IsVisited(grid[i][j])) {
                    numOfIslands++;
                    traverse(grid, i, j);
                }
            }
        }
        return numOfIslands;
    }

    void traverse(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int, int>> q;
        constexpr int dx[] = {0, 1, 0, -1};
        constexpr int dy[] = {1, 0, -1, 0};
        q.push({i, j});
        grid[i][j] = SetVisited(grid[i][j]);
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = p.first + dx[k];
                int y = p.second + dy[k];
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
                    continue;
                }
                if (IsLand(grid[x][y]) && !IsVisited(grid[x][y])) {
                    q.push({x, y});
                    grid[x][y] = SetVisited(grid[x][y]);
                }
            }
        }
    }
private:
    bool IsLand(int v)
    {
        return (v & 1) == 1;
    }
    bool IsVisited(int v)
    {
        return (v & 2) == 2;
    }
    int SetVisited(int v)
    {
        return v | 2;
    }
};
// @lc code=end

