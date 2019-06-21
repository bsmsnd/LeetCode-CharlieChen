/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool filled[3][9][9] = {};
        
        int cur_number;
        for (int row = 0;row < 9;++row)
            for (int col = 0; col < 9;++col)
            if (board[row][col]!='.')
            {
                cur_number = board[row][col] - '1';
                if (!filled[0][row][cur_number])
                    filled[0][row][cur_number] = true;
                else
                    return false;

                if (!filled[1][col][cur_number])
                    filled[1][col][cur_number] = true;
                else
                    return false;
                
                if (!filled[2][(row/3) * 3 +  (col/3)][cur_number])
                    filled[2][(row/3) * 3 +  (col/3)][cur_number] = true;
                else
                    return false;
            }
        return true;
    }
};

