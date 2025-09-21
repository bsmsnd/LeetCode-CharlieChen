// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
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
struct Node {
    Node *subtree[26];
    Node() {
        memset(subtree, 0, sizeof(subtree));
    }
};

constexpr int DELTA_X[] = {0, 1, 0, -1};
constexpr int DELTA_Y[] = {1, 0, -1, 0};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Build(board);
        vector<string> boardWords;
        for (const string &word: words) {
            if (Search(word)) {
                boardWords.push_back(word);
            }
        }
        return boardWords;
    }
private:
    void Build(const vector<vector<char>>& board)
    {
        root = new Node();
        n = board.size();
        m = board[0].size();
        visited.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i].resize(m, false);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                BuildTrie(board, i, j, 0, root);
            }
        }
    }

    void BuildTrie(const vector<vector<char>>& board, int x, int y,
        int chars, Node *node)
    {
        if (node->subtree[board[x][y] - 'a'] == nullptr) {
            node->subtree[board[x][y] - 'a'] = new Node();
        }
        node = node->subtree[board[x][y] - 'a'] ;
        visited[x][y] = true;
        for (int t = 0; t < 4; t++) {
            int newX = x + DELTA_X[t];
            int newY = y + DELTA_Y[t];
            if (IsValid(newX, newY) && chars + 1 < 10 && !visited[newX][newY]) {
                BuildTrie(board, newX, newY, chars + 1, node);
            }
        }
        visited[x][y] = false;
    }

    bool IsValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    bool Search(const string &word)
    {
        Node *node = root;
        for (char ch : word) {
            if (node->subtree[ch - 'a'] == nullptr) {
                return false;
            }
            node = node->subtree[ch - 'a'];
        }
        return (node != nullptr);
    }
private:
    Node *root;
    vector<vector<bool>> visited;
    int n;
    int m;
};
// @lc code=end

