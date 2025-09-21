/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 * @lcpr version=20004
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
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
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a';
        int b = coordinates[1] - '0';
        return (a + b) % 2 == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a1"\n
// @lcpr case=end

// @lcpr case=start
// "h3"\n
// @lcpr case=end

// @lcpr case=start
// "c7"\n
// @lcpr case=end

 */

