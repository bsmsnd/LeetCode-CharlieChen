/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30202
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftPos = 0, rightPos = numbers.size() - 1;
        if (numbers.size() == 0) {
            // unlikely
            return {-1};
        }

        int sum = numbers[leftPos] + numbers[rightPos];
        while (leftPos < rightPos) {
            if (numbers[leftPos] + numbers[rightPos] > target) {
                rightPos--;
            } else if (numbers[leftPos] + numbers[rightPos] < target) {
                leftPos++;
            } else {
                return {leftPos + 1, rightPos + 1};
            }
        }
        return {-1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

