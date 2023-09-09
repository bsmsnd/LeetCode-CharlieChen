/*
 * @lc app=leetcode id=837 lang=rust
 *
 * [837] New 21 Game
 */

// @lc code=start
impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        let mut probability : Vec<f64> = Vec::new();
        probability.resize((n+1) as usize, 0.0);
        let mut left_point = 0;
        let mut slide_window_sum = 0.0;
        for i in 0..=n {
            let mut start_point = 0;
            if (i > max_pts) {
                start_point = i - max_pts;
            }
            while left_point < start_point {
                if (left_point < k) {
                    slide_window_sum = slide_window_sum - probability[left_point as usize];
                }
                left_point = left_point + 1;
            }
            if (i == 0) {
                probability[0] = 1.0;
            } else {
                probability[i as usize] = slide_window_sum / max_pts as f64;
            }
            if (i < k) {
                slide_window_sum = slide_window_sum + probability[i as usize];
            }
        }
        let mut result : f64 = 0.0;
        for i in k..=n {
            result = result + probability[i as usize];
        }
        return result;
    }
}
// @lc code=end

