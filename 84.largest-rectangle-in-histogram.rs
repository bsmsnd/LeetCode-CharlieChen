/*
 * @lc app=leetcode id=84 lang=rust
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let n = heights.len();        
        let mut left_boundaries : Vec<usize> = Vec::new();
        let mut right_boundaries : Vec<usize> = Vec::new();
        let mut mono_stack : Vec<usize> = Vec::new();
        left_boundaries.resize(n, 0);
        right_boundaries.resize(n, 0);
        
        for i in 0..n {
            while !mono_stack.is_empty() && heights[*mono_stack.last().unwrap() as usize] > heights[i] {
                let p = mono_stack.pop().unwrap();
                right_boundaries[p] = i as usize;
            }
            mono_stack.push(i as usize);
        }
        while !mono_stack.is_empty() {
            let p = mono_stack.pop().unwrap();
            right_boundaries[p] = n;
        }
    
        for i in (0..n).rev() {
            while !mono_stack.is_empty() && heights[*mono_stack.last().unwrap()] > heights[i] {
                let p = mono_stack.pop().unwrap();
                left_boundaries[p] = i as usize + 1;
            }
            mono_stack.push(i as usize);
        }
        while !mono_stack.is_empty() {
            let p = mono_stack.pop().unwrap();
            left_boundaries[p] = 0;
        }
        let mut max_area = 0;
        for i in 0..n {
            let area = heights[i] * (right_boundaries[i] as i32 - left_boundaries[i] as i32);
            if area > max_area {
                max_area = area;
            }
        }
        return max_area;
    }
}
// @lc code=end

