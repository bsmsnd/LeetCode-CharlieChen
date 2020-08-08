/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
#include <tuple>
using namespace std;

#define LOWER_BOUND -40005
#define UPPER_BOUND 40005
#define INVALID_FLAG -50000

#define ROOT 0
#define LEFT 1
#define RIGHT 2

const pair<int, int> INVALID_PAIR = {INVALID_FLAG, -1};
const tuple<int, int, int> INVALID_TUPLE = {INVALID_FLAG, INVALID_FLAG, -1};
class Solution {
public:
    tuple<int, int, int> BSTRange(TreeNode* root, int direction = ROOT){
        // RESULT: MIN, MAX, SUM
        if (!root)
            return {UPPER_BOUND, LOWER_BOUND, 0};
        if (!root->left && !root->right){
            ans = max(ans, root->val);
            return {root->val, root->val, root->val};        
        }
            
        
        tuple<int,int,int> l = BSTRange(root->left, LEFT);
        tuple<int,int,int> r = BSTRange(root->right, RIGHT);
        if (get<0>(l) != INVALID_FLAG && get<0>(r) != INVALID_FLAG)
            if (root->val > get<1>(l) && root->val < get<0>(r)){
                int curSum = root->val + get<2>(l) + get<2>(r);
                ans = max(curSum, ans);
                if (direction == ROOT)
                    return {root->val, root->val, curSum};
                else
                    return {min(root->val, get<0>(l)), max(root->val, get<1>(r)), curSum};                
            }
        return INVALID_TUPLE;
    }

    int maxSumBST(TreeNode* root) {
        BSTRange(root);
        return ans;
    }

private: 
    int ans = 0;

};
// @lc code=end

