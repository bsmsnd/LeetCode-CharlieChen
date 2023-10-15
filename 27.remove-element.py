#
# @lc app=leetcode id=27 lang=python3
#
# [27] Remove Element
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        fast = 0
        slow = 0
        while fast < len(nums):
            while fast < len(nums) and nums[fast] == val:
                fast += 1
            if fast < len(nums):
                nums[slow] = nums[fast]
                slow += 1
                fast += 1
        return slow

# @lc code=end

