/*
 * @lc app=leetcode id=428 lang=cpp
 *
 * [428] Serialize and Deserialize N-ary Tree
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        // determine height
        if (!root)return "[]";
        int level = 0;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            level++;
            int S = q.size();
            while(S--){
                Node* cur = q.front();
                q.pop();
                for (Node* child : cur->children)
                    q.push(child);
            }
        }

        // print
        string ans = "[";
        q.push(root);
        q.push(nullptr);
        int curLevel = 0;
        int nullCnt = 0;
        while(!q.empty()){
            curLevel++;
            int S = q.size();            
            while(S--){
                Node* cur = q.front();
                q.pop();
                if (cur){
                    if (curLevel < level){ // not a leave
                        for (Node* child : cur->children)
                            q.push(child);
                        q.push(nullptr);
                    }                    
                    while(nullCnt > 0){// lazy update
                        ans += "null,";
                        nullCnt--;
                    } 
                            
                    ans += to_string(cur->val) + ",";                    
                }
                else{ // nullptr
                    nullCnt++;
                }
            }
        }

        ans.back() = ']';
        return ans;
        
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.size() <= 2) return nullptr;
        const int L = data.size();
        char cstr_data[L];
        strcpy(cstr_data, data.c_str()+1);

        char *tok = strtok(cstr_data, ",]");
        queue<Node*> q;
        int x = atoi(tok);
        Node* root = new Node(x);
        q.push(root);
        
        tok = strtok(NULL, ",]"); // null
        if (tok)
            tok = strtok(NULL, ",]");
        else 
            return root;
        if (!tok)
            return root;
        
        const string nullStr = "null";
        while(!q.empty() && tok){
            Node* cur = q.front();
            q.pop();
            while(tok && string(tok) != nullStr){
                Node *newNode = new Node(atoi(tok));
                q.push(newNode);
                cur->children.push_back(newNode);
                tok = strtok(NULL, ",]");
            }
            if (tok)
                tok = strtok(NULL, ",]");
            else
                return root;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
