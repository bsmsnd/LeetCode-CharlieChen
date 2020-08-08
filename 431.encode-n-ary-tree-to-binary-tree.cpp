/*
 * @lc app=leetcode id=431 lang=cpp
 *
 * [431] Encode N-ary Tree to Binary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root)return nullptr;

        TreeNode* bRoot = new TreeNode(root->val);
        queue<pair<Node*, TreeNode*>> q;
        q.push(make_pair(root, bRoot));

        while(!q.empty()){
            Node* curNode = q.front().first;
            TreeNode* curBNode = q.front().second;
            q.pop();

            TreeNode* previousBNode = nullptr, *newBNode;
            for (Node* child : curNode->children){
                newBNode = new TreeNode(child->val);
                
                if (previousBNode)
                    previousBNode->right = newBNode;                                    
                else                    
                    curBNode->left = newBNode;                                    

                q.push(make_pair(child, newBNode));
                previousBNode = newBNode;
            }

        }

        return bRoot;

    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root)return nullptr;

        Node* nRoot = new Node(root->val);
        queue<pair<Node*, TreeNode*>> q;
        q.push(make_pair(nRoot, root));

        while(!q.empty()){
            Node* curNNode = q.front().first;
            TreeNode* curBNode = q.front().second;
            q.pop();

            if (curBNode->left){
                TreeNode *childNode = curBNode->left;
                Node *childNNode;
                while(childNode){
                    childNNode = new Node(childNode->val);
                    curNNode->children.push_back(childNNode);
                    q.push(make_pair(childNNode, childNode));
                    childNode = childNode->right;
                }                
            }
        }

        return nRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
// @lc code=end

