/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)return root;

        if (root->val == key){
            if (root->left && root->right){
                TreeNode* new_root = root->right;
                TreeNode* new_left = root->left;
                TreeNode* far_left = new_root;

                while(far_left->left)
                    far_left = far_left->left;
                far_left->left = new_left;
                return new_root;
            }   
            else if (root->left){
                return root->left;
            }
            else if (root->right){
                return root->right;
            }
            else{
                return nullptr;
            }
        }
        else{
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};
// @lc code=end

