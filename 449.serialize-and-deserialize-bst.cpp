/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";

        string ans = "[";
        TreeNode *cur;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            // level++;
        }
        
        int nullCnt = 0;
        ans += to_string(root->val);
        q.push(root);
        while(!q.empty()){
            // level--;
            int t = q.size();
            while(t--){
                cur = q.front();
                q.pop();

                if (cur->left){
                    while(nullCnt > 0){
                        ans+=",null";
                        nullCnt--;
                    }

                    q.push(cur->left);
                    ans += "," + to_string(cur->left->val);
                }
                else{
                    nullCnt++;
                }

                if (cur->right){
                    while(nullCnt > 0){
                        ans+=",null";
                        nullCnt--;
                    }

                    q.push(cur->right);
                    ans += "," + to_string(cur->right->val);
                }
                else{
                    nullCnt++;
                }
            }
        }
        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // data = remove_if(data.begin(), data.end(), isspace);
        if (data.size() <= 2)return nullptr;

        queue<TreeNode*> q;
        vector<string> sep;

        size_t p = 1, comma_pos;
        string addStr;
        while(p < data.size()){
            comma_pos = data.find(',', p);
            if (comma_pos == data.npos){
                addStr = data.substr(p, data.size()-1 -p);
                // remove_if(addStr.begin(), addStr.end(), isspace);
                sep.push_back(addStr);
                break;
            }
            else{
                addStr = data.substr(p, comma_pos-p);
                // remove_if(addStr.begin(), addStr.end(), isspace);
                sep.push_back(addStr);
                p = comma_pos+1;
            }
        }
        
        // build the tree
        
        // pick the root
        int x = stoi(sep[0]);
        TreeNode* root = new TreeNode(x);
        // q.push(root);
        bool flag = 0;        

        TreeNode *parentNode = root, *curNode;
        for (int i = 1;i < sep.size(); i++){
            if (sep[i][0] >= '0' && sep[i][0] <= '9')
                curNode = new TreeNode(stoi(sep[i]));            
            else
                curNode = nullptr;

            if (flag){ // right
                parentNode->right = curNode;
                if(curNode) q.push(curNode);
                parentNode = q.front();
                q.pop();
                flag = 0;
            }
            else{
                flag = 1;
                parentNode->left = curNode;
                if(curNode) q.push(curNode);                    
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

