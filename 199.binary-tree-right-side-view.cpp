/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if (root == nullptr) {
            return answer;
        }
        answer.push_back(root->val);
        list<TreeNode*> currentLevel;
        list<TreeNode*> nextLevel;
        currentLevel.push_back(root);
        while (!currentLevel.empty()) {
            nextLevel.clear();
            for (const auto &node: currentLevel) {
                if (node->left) {
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    nextLevel.push_back(node->right);
                }
            }
            currentLevel.clear();
            if (!nextLevel.empty()) {
                answer.push_back(nextLevel.back()->val);
            }
            swap(currentLevel, nextLevel);
        }
        return answer;
    }
};
// @lc code=end

