/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int* pre;
    int* in;

    TreeNode* build(int l_pre, int r_pre, int l_in, int r_in)
    {
        if (l_pre == r_pre)
            return nullptr;
        TreeNode* t = new TreeNode(*(pre+l_pre));
        
        if (r_pre - l_pre == 1)
            return t;
        int root_loc;  // root location in inorder. In preorder, it is l_pre.
        for (int i = l_in; i < r_in;i++)
            if (*(in+i) == *(pre+l_pre))
            {
                root_loc = i;
                break;
            }
        int left_tree_size = root_loc - l_in;
        if (left_tree_size > 0)  // left subtree exists
            t->left = build(l_pre + 1, l_pre + 1 + left_tree_size, l_in, root_loc);
        
        int right_tree_size = r_in - root_loc - 1;
        if (right_tree_size > 0)
            t->right = build(l_pre + left_tree_size + 1, r_pre, root_loc + 1, r_in);
        return t;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder.data();
        in = inorder.data();
        if (preorder.size() == 0)
            return nullptr;
        return build(0, preorder.size(), 0, inorder.size());
    }
};

