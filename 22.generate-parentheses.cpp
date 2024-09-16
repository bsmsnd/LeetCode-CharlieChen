/*
 * @lc app=leetcode id=22 lang=cpp
 * @lcpr version=30117
 *
 * [22] Generate Parentheses
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
    vector<string> generateParenthesis(int n) {
        dfs(n, 0);
        return solutions;
    }
private:
    void dfs(int remainingLeft, int remainingRight)
    {
        if (remainingRight == 0) {
            current.push_back('(');
            dfs(remainingLeft - 1, 1);
            current.pop_back();
        } else if (remainingLeft == 0) {
            for (int i = 0; i < remainingRight; i++) {
                current.push_back(')');
            }
            solutions.push_back(current);
            for (int i = 0; i < remainingRight; i++) {
                current.pop_back();
            }
        } else {
            // try left
            current.push_back('(');
            dfs(remainingLeft - 1, remainingRight + 1);
            current.pop_back();

            // try right
            current.push_back(')');
            dfs(remainingLeft, remainingRight - 1);
            current.pop_back();
        }
    }
private:
    vector<string> solutions;
    string current;
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

