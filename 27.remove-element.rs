/*
 * @lc app=leetcode id=27 lang=rust
 *
 * [27] Remove Element
 */

// @lc code=start
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut fast : usize = 0;
        let mut slow : usize = 0;
        while fast < nums.len() {
            while fast < nums.len() && nums[fast] == val {
                fast += 1;
            }
            if fast < nums.len() {
                nums[slow] = nums[fast];
                slow += 1;
                fast += 1;
            }
        }
        slow as i32
    }
}
// @lc code=end

