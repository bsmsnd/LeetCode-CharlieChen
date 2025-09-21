/*
 * @lc app=leetcode.cn id=3264 lang=cpp
 * @lcpr version=20004
 *
 * [3264] K 次乘运算后的最终数组 I
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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [&nums](int a, int b) -> bool  {
            return (nums[a] > nums[b]) || (nums[a] == nums[b] && a > b);
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums.size(); i++) {
            pq.push(i);
        }
        for (int i = 0; i < k; i++) {
            int t = pq.top();
            pq.pop();
            nums[t] *= multiplier;
            pq.push(t);
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,5,6]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n3\n4\n
// @lcpr case=end

 */

