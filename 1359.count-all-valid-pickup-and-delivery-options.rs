/*
 * @lc app=leetcode id=1359 lang=rust
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
impl Solution {
    pub fn modulo_multiply(a : i32, b : i32) -> i32 {
        let p : i64 = 1e9 as i64 + 7;
        return ((a as i64 % p) * (b as i64 % p) % p) as i32;
    }
    pub fn count_orders(n: i32) -> i32 {
        let mut prev = 1;
        let mut current = 1;
        for i in 2..=n {
            current = Solution::modulo_multiply(Solution::modulo_multiply(prev, i), (2 * i - 1));
            prev = current;
        }
        return current;
    }
}
// @lc code=end

