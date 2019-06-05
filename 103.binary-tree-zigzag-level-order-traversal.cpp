/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> ans;        
        if (!root)
            return ans;
        int cnt = 1;            
        s1.push(root);
        TreeNode* cur;
        int new_cnt = 0;
        int direction = 0; // 0 ==>, 1 <==
        while(!s1.empty() || !s2.empty())
        {
            vector<int> cur_degree;
            if (direction == 0)
            {
                while(!s1.empty())
                {
                    cur = s1.top();
                    cur_degree.push_back(cur->val);
                    s1.pop();
                    if (cur->left)
                        s2.push(cur->left);
                    if (cur->right)
                        s2.push(cur->right);
                }
            }
            else
            {
                while(!s2.empty())
                {
                    cur = s2.top();
                    cur_degree.push_back(cur->val);
                    s2.pop();
                    if (cur->right)
                        s1.push(cur->right);
                    if (cur->left)
                        s1.push(cur->left);
                    
                }
            }
            ans.push_back(cur_degree);
            direction = 1 - direction;            
        }
        return ans;        
    }
};

