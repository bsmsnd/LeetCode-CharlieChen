/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#define REGION(row,col) ((row/3) * 3 + (col/3))

class Solution {
public:
    int board_array[9][9];
    bool row[9][9];
    bool col[9][9];
    bool region[9][9];
    bool findSolution(int r, int c)
    {
        if (board_array[r][c] != -1)  // board is pre-determined
        {
            if (r == 8 && c == 8)  // end of search
                return true;
            else
            {
                if (c<8)
                    return findSolution(r,c+1);
                else
                    return findSolution(r+1, 0);
            }
        }

        else
        {
            for(int i = 0;i<9;i++)
            {
                if (row[r][i] || col[c][i] || region[REGION(r,c)][i])
                    continue;
                else
                {
                    row[r][i] = col[c][i] = region[REGION(r,c)][i] = true;
                    board_array[r][c] = i;
                    if (r == 8 && c == 8)
                        return true;
                    else
                    {
                        bool result = (c < 8) ? findSolution(r, c+1) : findSolution(r+1, 0);
                        if (result)
                            return result;
                        else
                        {
                            row[r][i] = col[c][i] = region[REGION(r,c)][i] = false;
                            board_array[r][c] = -1;
                        }
                    }                    
                }                
            }
            return false;
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        // fill_n(row,sizeof(row), false); fill_n(col, sizeof(col), false); fill_n(region, sizeof(region), false);
        for(int i = 0;i < 9;i++)
            for (int j = 0;j<9;j++)
            {
                if (board[i][j] == '.')
                    board_array[i][j] = -1;
                else
                {
                    board_array[i][j] = board[i][j] - '0' - 1;                    
                    row[i][board_array[i][j]] = true;
                    col[j][board_array[i][j]] = true;
                    region[REGION(i,j)][board_array[i][j]] = true;
                }                
            }                    
        findSolution(0,0);
        for(int i = 0;i < 9;i++)
            for (int j = 0;j<9;j++)
                if (board[i][j] == '.')
                    board[i][j] = '1' + board_array[i][j];        
    }
};

