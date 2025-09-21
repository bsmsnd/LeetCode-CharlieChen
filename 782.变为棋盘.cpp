/*
 * @lc app=leetcode.cn id=782 lang=cpp
 * @lcpr version=20004
 *
 * [782] 变为棋盘
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
#include <cassert>
// @lcpr-template-end
// @lc code=start

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        vector<int> rows;
        vector<int> columns;
        int n = board.size();
        assert(n <= 30);
        for (int i = 0; i < n; i++) {
            int v = 0;
            for (int j = 0; j < n; j++) {
                v |= (board[i][j] << j);
            }
            // printf("%d,", v);
            rows.push_back(v);
        }
        // printf("\n");
        for (int j = 0; j < n; j++) {
            int v = 0;
            for (int i = 0; i < n; i++) {
                v |= (board[i][j] << i);
            }
            // printf("%d,", v);
            columns.push_back(v);
        }
        // printf("\n");

        int moves = 0;

        auto act = [&](const vector<int> values) {
            int numOfPatterns = 1;
            int patternA = values[0];
            int patternAOddCounter = 0;
            int patternAEvenCounter = 1;
            int patternB;
            for (int i = 1; i < n; i++) {
                if (values[i] == patternA) {
                    if (i % 2 == 0) {
                        patternAEvenCounter++;
                    } else {
                        patternAOddCounter++;
                    }
                } else if (numOfPatterns == 1) {
                    patternB = values[i];
                    numOfPatterns++;
                } else if (values[i] != patternB) {
                    // printf("A = %d, B = %d, C = %d\n", patternA, patternB, values[i]);
                    return -1; // 3rd pattern!
                }
            }
            // printf("patternA ^ patternB = %d, expect = %d\n", patternA ^ patternB, (int)(pow(2, n)) - 1);
            if (numOfPatterns == 1 || (patternA ^ patternB) != (int)(pow(2, n)) - 1) {
                return -1;
            }
            if (n % 2 == 0) {
                if (patternAEvenCounter + patternAOddCounter != n / 2) {
                    return -1;
                }
                return min(patternAOddCounter, patternAEvenCounter);
            }
            if (patternAEvenCounter + patternAOddCounter != n / 2 && patternAEvenCounter + patternAOddCounter != n / 2 + 1) {
                return -1;
            }
            if (patternAEvenCounter + patternAOddCounter > n / 2) {
                return patternAOddCounter;
            }
            return patternAEvenCounter;
        };

        int t1 = act(rows);
        int t2 = act(columns);
        // printf("t1 = %d, t2 = %d\n", t1, t2);
        if (t1 == -1 || t2 == -1) {
            return -1;
        }
        return t1 + t2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0, 1], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 0], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,0],[0,0,1],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,0],[1,1,1,0],[0,0,0,1],[0,0,0,1]]\n
// @lcpr case=end

 */

