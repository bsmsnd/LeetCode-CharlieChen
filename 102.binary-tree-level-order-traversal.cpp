/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;        
        if (!root)
            return ans;
        int cnt = 1;            
        q.push(root);
        TreeNode* cur;
        int new_cnt = 0;
        while(!q.empty())
        {
            new_cnt = 0;
            vector<int> cur_degree;
            while(cnt > 0)
            {
                cnt--;
                cur = q.front();
                cur_degree.push_back(cur->val);
                if (cur->left)
                {
                    q.push(cur->left);
                    new_cnt++;
                }            
                if (cur->right)
                {
                    q.push(cur->right);
                    new_cnt++;
                }
                q.pop();
            }
            ans.push_back(cur_degree);
            cnt = new_cnt;
        }
        return ans;
    }
};

