/*
 * @lc app=leetcode id=377 lang=rust
 *
 * [377] Combination Sum IV
 */

// @lc code=start

impl Solution {
    pub fn dfs(nums: &Vec<i32>, target: i32, dfs_results : &mut Vec<i32>) -> i32 {
        if (dfs_results[(target) as usize] != -1) {
            return dfs_results[(target) as usize];
        }
        let mut results : i32 = 0;
        for x in nums {
            if (target >= *x) {
                results = results + Solution::dfs(nums, target - *x, dfs_results);
            }
        }
        dfs_results[(target) as usize] = results;
        return results;
    }

    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let mut dfs_results : Vec<i32> = Vec::new();
        dfs_results.resize((target + 1) as usize, -1);
        dfs_results[0] = 1;
        return Solution::dfs(&nums, target, &mut dfs_results);
    }
}
// @lc code=end

