/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        stack<pair<TreeNode*, int>> s;
        if (!root)return 0;

        s.push(make_pair(root, root->val));
        TreeNode* curNode;
        int curVal;
        while(!s.empty()){
            curNode = s.top().first;
            curVal = s.top().second;
            s.pop();

            if (!curNode->left && !curNode->right){
                sum += curVal;
                continue;
            }

            if (curNode->left){
                s.push(make_pair(curNode->left, curVal * 10 + curNode->left->val));
            }
            if (curNode->right){
                s.push(make_pair(curNode->right, curVal * 10 + curNode->right->val));
            }
        }
        return sum;
    }
};
// @lc code=end

