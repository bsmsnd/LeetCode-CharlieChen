/*
 * @lc app=leetcode.cn id=688 lang=cpp
 * @lcpr version=20004
 *
 * [688] 骑士在棋盘上的概率
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
const int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dy[] = {2, 2, 1, -1, -2, -2, -1, 1};
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) {
            return 1.;
        }
        vector<vector<vector<double>>> gridWithProb(k, vector<vector<double>>(n, vector<double>(n))); // (k, x, y)
        for (int step = 0; step < k; step++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    double prob = 0;
                    for (int d = 0; d < 8; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }
                        if (step == 0) {
                            prob += 0.125;
                        } else {
                            prob += 0.125 * gridWithProb[step - 1][nx][ny];
                        }
                    }
                    gridWithProb[step][x][y] = prob;
                }
            }
        }
        return gridWithProb[k - 1][row][column];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n0\n0\n0\n
// @lcpr case=end

 */

