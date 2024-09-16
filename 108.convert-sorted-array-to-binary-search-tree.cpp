/*
 * @lc app=leetcode id=108 lang=cpp
 * @lcpr version=30117
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
#include "helper.h"
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l = -1, int r = -1) {
        if (l == -1) {
            l = 0;
            r = nums.size();
        }
        // printf("l = %d, r = %d\n", l, r);
        if (l >= r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, l, mid);
        node->right = sortedArrayToBST(nums, mid + 1, r);
        return node;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

