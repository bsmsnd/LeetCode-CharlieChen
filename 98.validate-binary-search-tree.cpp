/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool checkBST(TreeNode* t, long long lower_bound, long long upper_bound)
    {
        if (t->val <= lower_bound || t->val >= upper_bound)
            return false;
        if (t->left)
            if (checkBST(t->left, lower_bound, t->val) == false)
            {
                // cout<<t->val;
                return false;
            }
                
        if (t->right)
            if (checkBST(t->right, t->val, upper_bound) == false)
            {
                // cout<<t->val;
                return false;
            }

        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (root)
            return checkBST(root, LLONG_MIN, LLONG_MAX);
        else
            return true;
    }
};

