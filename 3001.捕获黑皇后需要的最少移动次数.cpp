/*
 * @lc app=leetcode.cn id=3001 lang=cpp
 * @lcpr version=20004
 *
 * [3001] 捕获黑皇后需要的最少移动次数
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
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int x1 = c - e;
        int y1 = d - f;
        int x2 = a - e;
        int y2 = b - f;
        if (x1 == y1) {
            if (x2 == y2 && a >= min(c, e) && a <= max(c, e)) {
                return 2;
            }
            return 1;
        }

        if (x1 == -y1) {
            if (x2 == -y2 && a >= min(c, e) && a <= max(c, e)) {
                return 2;
            }
            return 1;
        }

        if (a == e) {
            if (c == a) {
                return (d >= min(b, f) && d <= max(b, f)) ? 2 : 1;
            }
            return 1;
        }
        if (b == f) {
            if (d == b) {
                return (c >= min(a, e) && c <= max(a, e)) ? 2 : 1;
            }
            return 1;
        }
        return 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n8\n8\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n3\n3\n4\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// 4\n3\n3\n4\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// 6\n5\n3\n5\n5\n5\n
// @lcpr case=end

 */

