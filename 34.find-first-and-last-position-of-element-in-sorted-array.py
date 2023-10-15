#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#

# @lc code=start
class Solution:
    def binarySearch(self, nums: List[int], target: int):
        l = 0;
        r = nums.__len__()
        while r > l:
            mid = int(l + (r - l) / 2)
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l


    def searchRange(self, nums: List[int], target: int) -> List[int]:
        p1 = self.binarySearch(nums, target)
        if (p1 < 0 or p1 >= nums.__len__() or nums[p1] != target):
            return [-1, -1];
        p2 = self.binarySearch(nums, target + 1) - 1;
        return [p1, p2]


# @lc code=end

