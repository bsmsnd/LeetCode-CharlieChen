/*
 * @lc app=leetcode.cn id=999 lang=cpp
 * @lcpr version=20004
 *
 * [999] 可以被一步捕获的棋子数
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
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rx;
        int ry;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                    break;
                }
            }
        }
        int capture = 0;
        for (int i = rx - 1; i >= 0; i--) {
            if (board[i][ry] == 'B') {
                break;
            }
            if (board[i][ry] == 'p') {
                capture++;
                break;
            }
        }

        for (int i = rx + 1; i < 8; i++) {
            if (board[i][ry] == 'B') {
                break;
            }
            if (board[i][ry] == 'p') {
                capture++;
                break;
            }
        }

        for (int j = ry - 1; j >= 0; j--) {
            if (board[rx][j] == 'B') {
                break;
            }
            if (board[rx][j] == 'p') {
                capture++;
                break;
            }
        }

        for (int j = ry + 1; j < 8; j++) {
            if (board[rx][j] == 'B') {
                break;
            }
            if (board[rx][j] == 'p') {
                capture++;
                break;
            }
        }
        return capture;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]\n
// @lcpr case=end

// @lcpr case=start
// [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]\n
// @lcpr case=end

 */

