/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
#include <vector>
using namespace std;

struct dp_cell
    {
        int top;  // -1 indicates unavailable
        int left;  // -1 indicates unavailable
        int topleft[2];  // (i,j)
        int n_cells;  
    };

class Solution {
public:    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<dp_cell>> dp;
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        int best_ans = 0;

        // first row
        vector<dp_cell> first_row;
        for (int j = 0 ; j < n_cols; j++)
        {            
            dp_cell cur_cell;
            if (matrix[0][j] == '0')
            {
                cur_cell.top = cur_cell.left = cur_cell.topleft[0] = cur_cell.topleft[1] = -1;
                cur_cell.n_cells = 0;
            }
            else // 1
            {
                if (j == 0 || first_row[j-1].left != -1)
                {
                    cur_cell.top = 0;
                    cur_cell.left = first_row[j-1].left;
                    cur_cell.topleft[0] = first_row[j-1].topleft[0];
                    cur_cell.topleft[1] = first_row[j-1].topleft[1];
                    cur_cell.n_cells = first_row[j-1].n_cells + 1;                    
                }
                else
                {
                    cur_cell.top = 0;
                    cur_cell.left = j;
                    cur_cell.topleft[0] = 0;
                    cur_cell.topleft[1] = j;
                    cur_cell.n_cells = 1;        
                }     
                best_ans = max(best_ans, cur_cell.n_cells);           
            }
            first_row.push_back(cur_cell);            
        }
        dp.push_back(first_row);

        // for other rows
        for (int i = 1;i < n_rows; i++)
        {
            // start with j = 0
            vector<dp_cell> cur_row;
            dp_cell first_col;
            if (matrix[i][0] == '0')
            {
                first_col.top = first_col.left = first_col.topleft[0] = first_col.topleft[1] = -1;
                first_col.n_cells = 0;
            }
            else
            {
                if (dp[i-1][0].n_cells > 0)
                {
                    first_col.left = 0;
                    first_col.top = dp[i-1][0].top;
                    first_col.topleft[0] = dp[i-1][0].topleft[0];
                    first_col.topleft[1] = dp[i-1][0].topleft[1];
                    first_col.n_cells = dp[i-1][0].n_cells + 1;
                }
                else
                {
                    first_col.left = 0;
                    first_col.top = i;
                    first_col.topleft[0] = i;
                    first_col.topleft[1] = 0;
                    first_col.n_cells = 1;
                }
                best_ans = max(best_ans, first_col.n_cells);
                            
            }            
            cur_row.push_back(first_col);
            
            // other cells 
            for (int j = 1;j < n_cols; j++)
            {
                dp_cell cur_cell;
                
                if (matrix[i][j] == '0')
                {
                    first_col.top = first_col.left = first_col.topleft[0] = first_col.topleft[1] = -1;
                    first_col.n_cells = 0;
                }
                else
                {
                    // top
                    if (matrix[i-1][j] == '1')
                        cur_cell.top = dp[i-1][j].top;
                    else
                        cur_cell.top = i;

                    // left
                    if (matrix[i][j-1] == '1')
                        cur_cell.left = cur_row[j-1].left;
                    else
                        cur_cell.left = j;

                    //topleft
                    cur_cell.topleft[0] = max(cur_cell.top, dp[i-1][j-1].topleft[0]);
                    cur_cell.topleft[1] = max(cur_cell.left, dp[i-1][j-1].topleft[1]);

                    //n_cells
                    cur_cell.n_cells = max(max((i - cur_cell.topleft[0] + 1) * (j - cur_cell.topleft[1] + 1), i - cur_cell.top + 1), j - cur_cell.left + 1);
                    best_ans = max(best_ans, cur_cell.n_cells);
                }
                cur_row.push_back(cur_cell);                
            }
            dp.push_back(cur_row);
        }

        return best_ans;
    }
};

