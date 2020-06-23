 /*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        bool newNodeFlag = true;
        TreeNode* curNode = root;
        stack<TreeNode*> s;

        TreeNode *swap1, *swap2, *prev;
        swap1 = nullptr;
        swap2 = nullptr;
        prev = nullptr;

        // in-order traversal
        while(true){
            if (newNodeFlag){
                if (curNode->left){
                    s.push(curNode);
                    curNode = curNode->left;
                    newNodeFlag = true;
                    continue;
                }                
            }
            
            // visit the node
            if (prev){                
                if (prev->val >= curNode->val){ // Not OK
                    if (!swap1){
                        swap1 = prev;
                        swap2 = curNode;
                    }
                    else{
                        swap2 = curNode;
                        break;
                    }
                }
            }
            prev = curNode;
            if (curNode->right){
                curNode = curNode->right;
                newNodeFlag = true;
            }
            else{
                if (s.empty())break;
                curNode = s.top();
                s.pop();
                newNodeFlag = false;
            }
        }

        int tmp = swap1->val;
        swap1->val = swap2->val;
        swap2->val = tmp;                 
    }
};
// @lc code=end

