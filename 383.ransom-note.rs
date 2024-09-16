/*
 * @lc app=leetcode id=383 lang=rust
 *
 * [383] Ransom Note
 */

// @lc code=start
impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut magazine_chars : Vec<u32> = Vec::new();
        magazine_chars.resize(26, 0);
        for c in magazine.chars() {
            magazine_chars[c as usize - 'a' as usize] += 1;
        }
        for c in ransom_note.chars() {
            if (magazine_chars[c as usize - 'a' as usize] == 0) {
                return false;                
            }
            magazine_chars[c as usize - 'a' as usize] -= 1;
        }
        return true;
    }
}
// @lc code=end

