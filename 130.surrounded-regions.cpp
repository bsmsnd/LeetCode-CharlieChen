/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

class Solution {
public:
    int MOVE_X[4] = {-1,0,1,0};
    int MOVE_Y[4] = {0,-1,0,1};
    int rows, cols;    

    void solve(vector<vector<char>>& board) {
        const int R = board.size();
        if (R == 0)
            return;
        const int C = board[0].size();
        if (C == 0)
            return;
        rows = R;
        cols = C;
        vector<bool> colors;  //true = on the edge = not surrounded

        int board_int[R][C];
        for (int i = 0;i<R;i++)
            for (int j = 0;j<C;j++)
                board_int[i][j] = -1;
        int cnt = 0;
        for (int i = 0;i < R; i++)
        for (int j = 0;j < C; j++)
        {
            if (board[i][j] == 'O' && board_int[i][j] == -1)
            {               
                bool on_edge = false; 
                queue<vector<int>> q;
                q.push({i,j});
                vector<int> cur;
                board_int[i][j] = cnt;
                int new_X, new_Y;                
                while(!q.empty())
                {
                    cur = q.front();                    
                    q.pop();
                    if (cur[0] == 0 || cur[0] == R-1 || cur[1] == 0 || cur[1] == C-1)
                        on_edge = true;
                    for(int k = 0;k < 4;k++)
                    {
                        new_X = cur[0] + MOVE_X[k];
                        new_Y = cur[1] + MOVE_Y[k];
                        if (new_X >= 0 && new_X < rows && new_Y >= 0 && new_Y < cols && board[new_X][new_Y] == 'O' && board_int[new_X][new_Y] == -1)
                        {
                            board_int[new_X][new_Y] = cnt;
                            q.push({new_X, new_Y});
                        }
                    }

                }
                colors.push_back(on_edge);
                cnt++;
            }                    
        }        

        for (int i = 0;i < R; i++)
        for (int j = 0;j < C; j++)
            if (board[i][j] == 'O' && !colors[board_int[i][j]])
                board[i][j] = 'X';        

    }
};

