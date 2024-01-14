/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int currentNumber = 0;
        int offset = 0;
        vector<vector<int>> result(n, vector<int>(n, 0));
        int loops = n / 2;
        while (loops--) {
            int upperBound = n - 1 - offset;
            int i = offset;
            int j = offset;            
            while (j < upperBound) {
                result[i][j++] = ++currentNumber;
            }
            while (i < upperBound) {
                result[i++][j] = ++currentNumber;
            }
            while (j > offset) {
                result[i][j--] = ++currentNumber;
            }
            while (i > offset) {
                result[i--][j] = ++currentNumber;
            }
            offset++;
        }
        if (n % 2 != 0) {
            result[n/2][n/2] = n * n;
        }
        return result;
    }
};
// @lc code=end

