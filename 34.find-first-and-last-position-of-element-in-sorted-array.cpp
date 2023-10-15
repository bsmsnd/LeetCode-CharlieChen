/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int p1 = BinarySearch(nums, target);
        if (!(p1 >= 0 && p1 < nums.size() && nums[p1] == target)) {
            return vector<int>{-1, -1};
        }
        int p2 = BinarySearch(nums, target + 1) - 1;
        return vector<int>{p1, p2};
    }

    int BinarySearch(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (r > l) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] >= target) {
                r = mid;
            }
        }
        return l;
    }
};

