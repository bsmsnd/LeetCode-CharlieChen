/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int ans;
    int goal;
    int traverse(TreeNode* node, int cur_rank)
    {
        if (cur_rank >= goal)
            return cur_rank;  // no need to continue
        if (node->left)
            cur_rank = traverse(node->left, cur_rank);
        if (cur_rank == -1)
            cur_rank = 0;
        else
            cur_rank = cur_rank + 1;
        if (cur_rank == goal - 1)
        {
            ans = node->val;
            return cur_rank;
        }
        if (node->right)
            cur_rank = traverse(node->right, cur_rank);
        return cur_rank;
    }



    int kthSmallest(TreeNode* root, int k) {
        goal = k;
        traverse(root, -1);
        return ans;
    }
};

