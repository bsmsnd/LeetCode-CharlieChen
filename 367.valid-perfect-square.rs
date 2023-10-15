/*
 * @lc app=leetcode id=367 lang=rust
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
static UPPER_BOUND : i32 = 46341;

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let mut l = 0;
        let mut r = UPPER_BOUND;
        while r > l {
            let mid = (l + (r - l) / 2).floor() as i32;
            if mid * mid == num {
                return true;
            } else if mid * mid < num {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return false;
    }
}
// @lc code=end

