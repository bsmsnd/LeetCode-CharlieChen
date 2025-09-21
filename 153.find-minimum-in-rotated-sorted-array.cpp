/*
 * @lc app=leetcode id=153 lang=cpp
 * @lcpr version=30118
 *
 * [153] Find Minimum in Rotated Sorted Array
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int pivot = nums[0];
        int searchTimes = log2(right - left) + 1;
        while (left <= right && searchTimes--) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > pivot) {
                left = mid;
            } else if (nums[mid] < pivot) {
                right = mid;
            }
        }
        return nums[right];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */

