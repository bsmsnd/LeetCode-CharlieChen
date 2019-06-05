/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool symmetryTest(TreeNode* leftTree, TreeNode* rightTree)
    {
        if (!leftTree && !rightTree)
            return true;
        if ((!leftTree && rightTree) || (!rightTree && leftTree))
            return false;
        if (leftTree->val != rightTree->val)
            return false;
        return (symmetryTest(leftTree->left, rightTree->right) && symmetryTest(leftTree->right, rightTree->left));            
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else
            return symmetryTest(root->left, root->right);
    }
};

