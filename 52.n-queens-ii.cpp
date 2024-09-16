// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode id=52 lang=cpp
 * @lcpr version=30117
 *
 * [52] N-Queens II
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
    int totalNQueens(int n) {
        targetN = n;
        solutionNum = 0;
        columnStatus.resize(n, false);
        diagStatus.resize(2 * n, false);
        backwardDiagStatus.resize(2 * n, false);
        dfs(0);
        return solutionNum;
    }
private:
    void dfs(int row)
    {
        auto isValid = [&](int x, int y) -> bool {
            return !this->columnStatus[x] &&
                !this->diagStatus[MapToDiag(y - x)] &&
                !this->backwardDiagStatus[x + y];
        };
        auto setInUse = [&](int x, int y) -> void {
            this->columnStatus[x] = true;
            this->diagStatus[MapToDiag(y - x)] = true;
            this->backwardDiagStatus[x + y] = true;
        };
        auto revertUsage = [&](int x, int y) -> void {
            this->columnStatus[x] = false;
            this->diagStatus[MapToDiag(y - x)] = false;
            this->backwardDiagStatus[x + y] = false;
        };

        int y = row;
        for (int x = 0; x < targetN; x++) {
            if (isValid(x, y)) {
                if (y == targetN - 1) {
                    solutionNum++;
                } else {
                    setInUse(x, y);
                    dfs(row+1);
                    revertUsage(x, y);
                }
            }
        }
    }
private:
    int targetN;
    int solutionNum;
    // vector<vector<bool>> board;
    vector<bool> columnStatus;
    vector<bool> diagStatus;
    vector<bool> backwardDiagStatus;
    inline int MapToDiag(int yMinusX)
    {
        return yMinusX + targetN - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

 */

