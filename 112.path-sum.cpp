/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        stack<pair<TreeNode*, int>> s;
        TreeNode* cur;
        int curSum;

        if (!root)return false;
        s.push(make_pair(root, root->val));
        while(!s.empty()){        
            cur = s.top().first;
            curSum = s.top().second;
            s.pop();
            // if (curSum > sum)
                // continue;

            if (cur->left){
                s.push(make_pair(cur->left, curSum + cur->left->val));
            }            
            if (cur->right){
                s.push(make_pair(cur->right, curSum + cur->right->val));
            }
            if (!cur->left && !cur->right)
                if (curSum == sum)
                    return true;
        }

        return false;
    }
};
/* Recursion
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {                
        if (!root) return false;
        return DFS(root, 0, sum);
    }

    bool DFS(TreeNode* root, int cur, const int sum){
        if (root)
            if (root->left || root->right){
                return (root->left && cur+root->val <= sum ? DFS(root->left, cur+root->val, sum): false) || (root->right ? DFS(root->right, cur+root->val, sum): false);
            }
            else{
                return cur + root->val == sum;
            }        
        return false;
    }
};
*/
// @lc code=end