/*
 * @lc app=leetcode id=499 lang=cpp
 *
 * [499] The Maze III
 */

// @lc code=start
const int MX[4] = {0,1,0,-1};
const int MY[4] = {1,0,-1,0};

class Solution {
public:
    set<pair<int, int>> points;
    int dist[105][105];

    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        points.insert({start[0], start[1]});
        memset(dist, -1, sizeof(dist));
        dist[start[0]][start[1]] = 0;    
        int N = maze.size(), M = maze[0].size();
        
        while(!points.empty())
        {
            pair<int, int> to_extend;
            to_extend = *(points.begin());
            for (auto it = points.begin(); it != points.end(); it++)
                if (dist[to_extend.first][to_extend.second] > dist[it->first][it->second])
                    to_extend = *it;
            points.erase(to_extend);

            if (dist[hole[0]][hole[1]] != -1 && dist[to_extend.first][to_extend.second] > dist[hole[0]][hole[1]])          
            
            for (int k = 0;k < 4; k++)
            {                
                int x = to_extend.first, y = to_extend.second;
                int cnt = 0;
                while(x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0)
                {
                    x += MX[k];
                    y += MY[k];
                    cnt++;
                    if (x >= 0 && x < N && y >= 0 && y < M)
                        if (x == hole[0] && y == hole[1])
                        {
                            if (dist[hole[0]][hole[1]] == -1)
                                dist[hole[0]][hole[1]] = cnt + dist[to_extend.first][to_extend.second];
                            else
                                dist[hole[0]][hole[1]] = min(dist[hole[0]][hole[1]],cnt + dist[to_extend.first][to_extend.second]);
                        }                    
                }
                // go back one step
                x -= MX[k]; y-=MY[k];cnt--;
                
                if (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0)
                    if(dist[x][y] == -1)
                    {                    
                        dist[x][y] = dist[to_extend.first][to_extend.second] + cnt;
                        points.insert({x,y});
                    }
                    else if (dist[x][y] > dist[to_extend.first][to_extend.second] + cnt)
                        dist[x][y] = dist[to_extend.first][to_extend.second] + cnt;
            }            
        }
        return dist[destination[0]][destination[1]];
    }
};
// @lc code=end

