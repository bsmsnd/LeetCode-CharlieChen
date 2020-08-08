/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
#define LEFT 1
#define RIGHT 2

class Solution {
public:
    int longestZigZag(TreeNode* root, int direction=0) {
        if (!root)return -1;

        if (direction == 0){
            if (root->left)
                ans = max(ans, longestZigZag(root->left, LEFT) + 1);
            if (root->right)
                ans = max(ans, longestZigZag(root->right, RIGHT) + 1);
            return ans;
        }
        else if (direction == LEFT){
            if (root->left)
                ans = max(ans, longestZigZag(root->left, LEFT) + 1);
            if (root->right)
                return longestZigZag(root->right, RIGHT) + 1;
            else
                return 0;          
        }
        else{ // direction == RIGHT
            if (root->right)
                ans = max(ans, longestZigZag(root->right, RIGHT) + 1);
            if (root->left)
                return longestZigZag(root->left, LEFT) + 1;
            else
                return 0; 
        }
    }
private: 
    int ans = 0;
};
// @lc code=end

