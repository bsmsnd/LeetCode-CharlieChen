/*
 * @lc app=leetcode id=35 lang=rust
 *
 * [35] Search Insert Position
 */

// @lc code=start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0;
        let mut r = nums.len();
        while r > l {
            let mid = l + (r - l) / 2;
            if nums[mid as usize] == target {
                return mid as i32;
            } else if nums[mid as usize] > target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l as i32;
    }
}
// @lc code=end

