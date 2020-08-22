/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
struct state{
    int x,y;
    int removed;
    state(int _x, int _y, int _removed) : x(_x), y(_y), removed(_removed) {};
    state(int _x, int _y) : x(_x), y(_y), removed(0) {};
    state(): x(0), y(0), removed(0) {};
};

const int mx[4] = {0,1,0,-1};
const int my[4] = {-1,0,1,0};

class Solution {
public:
    int N, M;
    int shortestPath(vector<vector<int>>& grid, int k) {
        N = grid.size();
        M = grid[0].size();
        if (N == 1 && M == 1)return 0;
        int steps[N][M][k+1];
        bool in_queue[N][M][k+1];
        memset(steps, -1, sizeof(steps));
        memset(in_queue, 0, sizeof(in_queue));

        steps[0][0][0] = 0;
        queue<state> q;
        q.push(state(0,0,0));
        int x, y, r, tx, ty;
        state cur;
        while(!q.empty()){            
            cur = q.front();
            q.pop();
            x = cur.x; y = cur.y; r = cur.removed;
            in_queue[x][y][r] = false;
            for (int t = 0; t < 4; t++){
                tx = x + mx[t];
                ty = y + my[t];
                if (tx >= 0 && tx < N && ty >= 0 && ty < M){
                    if (grid[tx][ty] == 0){
                        if (steps[tx][ty][r] == -1 || steps[tx][ty][r] > steps[x][y][r] + 1){
                            steps[tx][ty][r] = steps[x][y][r] + 1;
                            if (!in_queue[tx][ty][r]){
                                q.push(state(tx,ty,r));
                                in_queue[tx][ty][r] = 1;
                            }
                        }
                    }
                    else if (r+1 <= k){
                        if (steps[tx][ty][r+1] == -1 || steps[tx][ty][r+1] > steps[x][y][r] + 1){
                            steps[tx][ty][r+1] = steps[x][y][r] + 1;
                            if (!in_queue[tx][ty][r+1]){
                                q.push(state(tx,ty,r+1));
                                in_queue[tx][ty][r+1] = 1;
                            }
                        }
                    }
                    if (tx == N-1 && ty == M-1)
                        return steps[x][y][r] + 1;
                }
            }
        }
        return -1;      
    }
};
// @lc code=end

