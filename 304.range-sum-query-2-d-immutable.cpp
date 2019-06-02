/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();

        // first row
        int first_row_sum = 0;
        vector<int> first_row(n_cols);
        for (int j = 0;j<n_cols;j++)
        {
            first_row_sum += matrix[0][j];
            first_row[j] = first_row_sum;
        }
        sums.push_back(first_row);

        for (int i=1;i<n_rows;i++)
        {
            vector<int> row_vector(n_cols);
            for (int j = 0; j < n_cols; j++)
            {                
                if (j == 0)
                    row_vector[j] = sums[i-1][j] + matrix[i][j];
                else
                    row_vector[j] = sums[i-1][j] + row_vector[j-1] - sums[i-1][j-1] + matrix[i][j];
            }
            sums.push_back(row_vector);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<" "<<sums[row2][col2]<<" " << (col1 == 0? 0 : sums[row2][col1 - 1]) << " "<< (row1==0 ? 0 : sums[row1 - 1][col2])  << " "<< (row1==0 || col1 == 0? 0 : sums[row1][col1])<<endl;
        return sums[row2][col2] - (col1 == 0? 0 : sums[row2][col1 - 1]) - (row1==0 ? 0 : sums[row1 - 1][col2]) + (row1==0 || col1 == 0? 0 : sums[row1 - 1][col1 - 1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

