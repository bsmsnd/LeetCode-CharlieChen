/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
// #include <vector>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    int* in;
    int* post;

    TreeNode* build(int l_in, int r_in, int l_post, int r_post)
    {
        if (l_in == r_in)
            return nullptr;
        TreeNode* t = new TreeNode(*(post+r_post-1));
        
        if (r_in - l_in == 1)
            return t;
        int root_loc;  // root location in inorder. In preorder, it is l_pre.
        for (int i = l_in; i < r_in;i++)
            if (*(in+i) == t->val)
            {
                root_loc = i;
                break;
            }
        int left_tree_size = root_loc - l_in;
        if (left_tree_size > 0)  // left subtree exists
            t->left = build(l_in, root_loc, l_post, l_post + left_tree_size);
        
        int right_tree_size = r_in - root_loc - 1;
        if (right_tree_size > 0)
            t->right = build(root_loc + 1, r_in, l_post + left_tree_size, r_post - 1);
        return t;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder.data();
        in = inorder.data();
        if (postorder.size() == 0)
            return nullptr;
        return build(0, inorder.size(), 0, postorder.size());
    }
};

