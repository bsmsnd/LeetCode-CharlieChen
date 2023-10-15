/*
 * @lc app=leetcode id=1647 lang=rust
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
impl Solution {
    pub fn min_deletions(s: String) -> i32 {
        let mut freq : Vec<i32> = Vec::new();
        freq.resize(26, 0);
        for ch in s.chars() {
            freq[(ch as i32 - 'a' as i32) as usize] += 1;
        }
        freq.sort_by(|a, b| b.cmp(a));
        let mut prev_value = 100001;
        let mut current_sum = 0;
        let mut good_sum = 0;

        for &value in &freq {
            if (value == 0) {
                break;
            }
            current_sum += value;
            if value < prev_value {
                good_sum += value;
                prev_value = value;
            } else if prev_value > 0 {
                prev_value = prev_value - 1;
                good_sum += prev_value;
            }
            // println!("good_sum = {good_sum}, current_sum = {current_sum}, prev_value = {prev_value}")
        }
        return current_sum - good_sum;
    }
}
// @lc code=end

