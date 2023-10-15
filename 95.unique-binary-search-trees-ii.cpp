/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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

// #include "helper.h"

class Solution {
public:
    void BuildTree(int lowerBound, int upperBound, vector<TreeNode*> &trees) {
        if (lowerBound <= upperBound) {
            for (int root = lowerBound; root <= upperBound; root++) {
                vector<TreeNode*> leftSubTreeSet;
                vector<TreeNode*> rightSubTreeSet;
                BuildTree(lowerBound, root - 1, leftSubTreeSet);
                BuildTree(root + 1, upperBound, rightSubTreeSet);
                for (TreeNode* leftSubTree : leftSubTreeSet) {
                    for (TreeNode* rightSubTree : rightSubTreeSet) {
                        TreeNode *treeNode = new TreeNode(root, leftSubTree, rightSubTree);
                        trees.push_back(treeNode);
                    }
                }
            }
        } else {
            trees.push_back(nullptr);
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> trees;
        BuildTree(1, n, trees);
        return trees;
    }
};
// @lc code=end

