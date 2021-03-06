/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root, Node* RightNode = nullptr) {
        if (!root)return nullptr;
        if (root->left)
        {
            root->left->next = root->right;
            if (RightNode)            
                root->right->next = RightNode->left;                
            else
                root->right->next = nullptr;            
            connect(root->left, root->right);
            connect(root->right, RightNode ? RightNode->left : nullptr);            
        }
        return root;
    }
};

