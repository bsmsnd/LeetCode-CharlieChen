/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        curNode = root;
        while(curNode){
            if (curNode->left){
                s.push(curNode);
                curNode = curNode->left;
            }
            else{
                // curNode = curNode;
                // newNodeFlag = true;
                return;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        if (!curNode)return -1;

        int x = curNode->val;
        
        if (curNode->right){
            curNode =  curNode->right;
            while(curNode->left){
                s.push(curNode);
                curNode = curNode->left;
            }
        }
        else{
            if (!s.empty()){
                curNode = s.top();
                s.pop();
            }
            else{
                curNode = nullptr;
            }
        }

        return x;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (curNode)
            return true;
        return false;
    }

private:
    stack<TreeNode*> s;
    // bool newNodeFlag;
    TreeNode* curNode;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

