/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=30203
 *
 * [931] 下降路径最小和
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    int GetMinValue(uint32_t x, uint32_t y)
    {
        if (x < 0 || x >= n_ || y < 0 || y >= n_) {
            return 1e6;
        }
        return minPath_[x][y];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n_ = matrix.size();
        minPath_.resize(n_, vector<int>(n_, 1e7));
        // 1st row
        for (uint32_t j = 0; j < n_; j++) {
            minPath_[0][j] = matrix[0][j];
        }
        for (uint32_t i = 1; i < n_; i++) {
            for (uint32_t j = 0; j < n_; j++) {
                minPath_[i][j] = min(min(GetMinValue(i - 1, j - 1), GetMinValue(i - 1, j)), GetMinValue(i - 1, j + 1)) + matrix[i][j];
            }
        }
        int best = 1e7;
        for (int j = 0; j < n_; j++) {
            best = min(best, minPath_[n_ - 1][j]);
        }
        return best;
    }
private:
    vector<vector<int>> minPath_;
    uint32_t n_;
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */

