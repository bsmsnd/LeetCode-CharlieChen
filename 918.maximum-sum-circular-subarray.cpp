/*
 * @lc app=leetcode id=918 lang=cpp
 * @lcpr version=30117
 *
 * [918] Maximum Sum Circular Subarray
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int prefixSum = 0;
        vector<int> prefixSumMax(nums.size());
        int previous = -1e5;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            prefixSumMax[i] = max(prefixSum, previous);
            previous = prefixSumMax[i];
        }


        int maxValue = -1e5;
        int suffixSum = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            suffixSum += nums[i];
            maxValue = max(maxValue, prefixSumMax[i - 1] + suffixSum);
        }

        return max(maxValue, maxSubArray(nums));
    }

private:
    int maxSubArray(vector<int>& nums) {
         int maxValue = -1e5;
         int previousBestSum = 0;
         for (int t : nums) {
             previousBestSum = t + max(previousBestSum, 0);
             maxValue = max(maxValue, previousBestSum);
         }
         return maxValue;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-3]\n
// @lcpr case=end

 */

