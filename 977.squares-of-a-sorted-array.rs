/*
 * @lc app=leetcode id=977 lang=rust
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut answer = vec![];
        let mut negative : i32 = 0;
        let mut positive : i32 = 0;
        while positive >= negative {
            // if both numbers are valid
            if nums[positive as usize] >= 0 && nums[negative as usize] < 0 {
                if (nums[positive as usize] >= -nums[negative as]) {
                    answer.push(nums[positive as usize] * nums[positive as usize]);
                    positive -= 1;
                } else {
                    answer.push(nums[negative as usize] * nums[negative as usize]);
                    negative += 1;
                }
            } else if (nums[positive as usize] >= 0) {
                answer.push(nums[positive as usize] * nums[positive as usize]);
                positive -= 1;
            } else {
                answer.push(nums[negative as usize] * nums[negative as usize]);
                negative += 1;
            }
        }
        answer.reverse();
        answer
    }
}
// @lc code=end

