/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
 */

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
    int cnt = 0;
    bool unival(TreeNode* root){
        bool leftCond = root->left ? (unival(root->left) && (root->val == root->left->val)) : true;
        bool rightCond = root->right ? (unival(root->right) && (root->val == root->right->val)) : true;

        if (leftCond && rightCond){
            cnt++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (!root)return 0;
        unival(root);
        return cnt;
    }
};
// @lc code=end

