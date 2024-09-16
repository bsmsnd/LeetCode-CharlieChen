/*
 * @lc app=leetcode id=211 lang=cpp
 * @lcpr version=30117
 *
 * [211] Design Add and Search Words Data Structure
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
struct Node {
    Node *subtree[26];
    bool isWord;
    Node() : isWord(false) {
        memset(subtree, 0, sizeof(subtree));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node *node = root;
        for (char ch : word) {
            if (node->subtree[ch - 'a'] == nullptr) {
                node->subtree[ch - 'a'] = new Node();
            }
            node = node->subtree[ch - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word) {
        return Search(word, root, 0);
    }
private:
    Node *root;
    bool Search(string word, Node *node, int pos)
    {
        if (node == nullptr) {
            return false;
        }

        if (pos == word.length()) {
            return node->isWord;
        }

        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->subtree[i] != nullptr &&
                    Search(word, node->subtree[i], pos + 1)) {
                    return true;
                }
            }
        } else {
            return (node->subtree[word[pos] - 'a'] != nullptr && Search(word, node->subtree[word[pos] - 'a'], pos + 1));
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end



