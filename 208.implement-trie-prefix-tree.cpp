/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct node{
    bool isWord;
    node* next[26];    
    node(){
        memset(next, 0, sizeof(next));
        isWord = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node;
        root->isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // cout << word << endl;
        node* cur = root;
        for (int i = 0;i < word.size(); i++){
            if (!cur->next[word[i] - 'a'])
                cur->next[word[i] - 'a'] = new node();            
            cur = cur->next[word[i] - 'a'];            
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // cout << word << endl;
        node* cur = root;
        for (int i = 0;i < word.size(); i++){
            if (cur->next[word[i] - 'a'])
                cur = cur->next[word[i] - 'a'];
            else
                return false;
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // cout << prefix << endl;
        node *cur = root;
        for (int i = 0;i < prefix.size(); i++){
            if (cur->next[prefix[i] - 'a'])
                cur = cur->next[prefix[i] - 'a'];
            else
                return false;
        }
        return true;
    }

private:
    node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

