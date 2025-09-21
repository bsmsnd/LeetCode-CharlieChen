/*
 * @lc app=leetcode id=79 lang=cpp
 * @lcpr version=30117
 *
 * [79] Word Search
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
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        visited.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i].resize(m, false);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    Dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool Dfs(const vector<vector<char>> &board, int x, int y, string word, int pos)
    {
        // printf("%d, %d\n", x, y);
        if (!IsValid(x, y) ||
            board[x][y] != word[pos] ||
            visited[x][y]) {
            return false;
        }
        if (pos == word.length() - 1) {
            return true;
        }
        visited[x][y] = true;
        if (Dfs(board, x + 1, y, word, pos + 1) ||
            Dfs(board, x, y + 1, word, pos + 1) ||
            Dfs(board, x - 1, y, word, pos + 1) ||
            Dfs(board, x, y - 1, word, pos + 1)) {
            return true;
        }
        visited[x][y] = false;
        return false;
    }
    bool IsValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
private:
    vector<vector<bool>> visited;
    int n;
    int m;
};
// @lc code=end



/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

