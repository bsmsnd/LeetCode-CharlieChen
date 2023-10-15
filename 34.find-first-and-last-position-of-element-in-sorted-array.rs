/*
 * @lc app=leetcode id=34 lang=rust
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let p1 = Solution::binary_search(&nums, target);
        if p1 < 0 || p1 as usize >= nums.len() || nums[p1 as usize] != target {
            return vec![-1, -1];
        }
        let p2 = Solution::binary_search(&nums, target + 1) - 1;
        return vec![p1, p2];
    }

    pub fn binary_search(nums: &Vec<i32>, target: i32) -> i32 {
        let mut l = 0;
        let mut r = nums.len();
        while r > l {
            let mid = l + (r - l) / 2;
            if nums[mid as usize] >= target {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l as i32;
    }
}

// @lc code=end

