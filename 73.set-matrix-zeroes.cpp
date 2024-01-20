/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include "helper.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero = false;
        bool isFirstColumnZero = false;
        uint32_t N = matrix.size();
        uint32_t M = matrix[0].size();
        for (uint32_t i = 0; i < N; i++) {
            if (matrix[i][0] == 0) {
                isFirstColumnZero = true;
                break;
            }
        }
        for (uint32_t j = 0; j < M; j++) {
            if (matrix[0][j] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        for (uint32_t i = 1; i < N; i++) {
            for (uint32_t j = 0; j < M; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        for (uint32_t j = 1; j < M; j++) {
            for (uint32_t i = 0; i < N; i++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        auto setRowZero = [&N, &M, &matrix](uint32_t row) {
            for (uint32_t j = 0; j < M; j++) {
                matrix[row][j] = 0;
            }
        };

        auto setColumnZero = [&N, &M, &matrix](uint32_t column) {
            for (uint32_t i = 0; i < N; i++) {
                matrix[i][column] = 0;
            }
        };
        for (uint32_t i = 1; i < N; i++) {
            if (matrix[i][0] == 0) {
                setRowZero(i);
            }
        }
        for (uint32_t j = 1; j < M; j++) {
            if (matrix[0][j] == 0) {
                setColumnZero(j);
            }
        }
        if (isFirstRowZero) {
            setRowZero(0);
        }
        if (isFirstColumnZero) {
            setColumnZero(0);
        }
    }
};
// @lc code=end

