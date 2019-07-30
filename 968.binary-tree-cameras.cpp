/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
#define INF 10000
#define min(a,b)(((a) < (b)) ? (a) : (b))
class Solution {
public:
    int* DFS(TreeNode* cur)
    {        
        int* ret = new int[3];
        if (!cur)
        {
            ret[0] = ret[2] = 0;
            ret[1] = INF;
            return ret;
        }
        int* l = DFS(cur->left);
        int* r = DFS(cur->right);
        if (!cur->left && !cur->right)
        {
            ret[0] = INF;
            ret[1] = 1;
            ret[2] = 0;
        }
        else
        {
            ret[0] = min(l[1] + min(r[0], r[1]), r[1] + min(l[0], l[1]));
            ret[1] = 1 + min(min(l[0], l[1]),l[2]) + min(min(r[0], r[1]),r[2]);
            ret[2] = min(l[0],l[1]) + min(r[0], r[1]);
        }                
        return ret;
        
    }

    int minCameraCover(TreeNode* root) {
        int* ans = DFS(root);       
        return min(ans[0], ans[1]);
    }
};

