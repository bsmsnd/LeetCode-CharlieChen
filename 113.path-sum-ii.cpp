/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
struct node{
    TreeNode* t;
    int curSum;
    int level;    
    node(TreeNode* p1, int p2, int p3){
        t = p1;
        curSum = p2;
        level = p3;
    }
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        stack<node> s;
        vector<vector<int>> ans;
        vector<int> curAnswer;
        if (!root) return ans;

        s.push(node(root, root->val, 0));
        curAnswer.push_back(root->val);

        TreeNode* curNode;
        int curSum, curLv;        
        while(!s.empty()){
            curNode = s.top().t;
            curSum = s.top().curSum;
            curLv = s.top().level;
            s.pop();            
            // cout << curSum << endl;
            

            while(curAnswer.size() > curLv){
                curAnswer.pop_back();
            }
            curAnswer.push_back(curNode->val);            

            if (curNode->right){
                s.push(node(curNode->right, curNode->right->val + curSum, curLv+1));                
            }
            if (curNode->left){
                s.push(node(curNode->left, curNode->left->val + curSum, curLv+1));
            }
            if (!curNode->left && !curNode->right){
                if (curSum == sum){
                    // curAnswer.push_back(curNode->val);
                    ans.push_back(curAnswer);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

