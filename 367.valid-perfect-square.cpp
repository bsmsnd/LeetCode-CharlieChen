/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
constexpr int UPPER_BOUND = 46341; // 46341^2 > 2^31 - 1 > 46340^2
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = UPPER_BOUND;
        while (r > l) {
            int mid = l + (r - l) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return false;
    }
};
// @lc code=end

