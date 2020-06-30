/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
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
    int countNodes(TreeNode* root) {
        // find level
        TreeNode* cur = root;
        int level = 0;
        while(cur){
            level++;
            cur = cur->left;
        }

        // binary search
        int l = 0, r = pow(2, level - 1), m;
        while(r - l > 1){
            m = (r + l) /2;
            cur = root;
            for (int i = 0;i < level - 1; i++){
                if (m & (1 << (level - 2 - i)))
                    cur = cur->right;
                else
                    cur = cur->left;                
            }
            if (cur) l = m; else r = m;
        }
        return l + pow(2, level-1);

    }
};
// @lc code=end

