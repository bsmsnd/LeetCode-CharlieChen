/*
 * @lc app=leetcode id=138 lang=cpp
 * @lcpr version=30116
 *
 * [138] Copy List with Random Pointer
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old2New;
        Node* copyHead = nullptr;
        Node* copyNode = nullptr;
        Node* node = head;
        while (node != nullptr) {
            if (copyNode == nullptr) {
                copyNode = new Node(node->val);
                copyHead = copyNode;
            } else {
                copyNode->next = new Node(node->val);
                copyNode = copyNode->next;
            }
            old2New[node] = copyNode;
            node = node->next;
        }
        copyNode = copyHead;
        node = head;
        old2New[nullptr] = nullptr;
        while (copyNode != nullptr) {
            copyNode->random = old2New[node->random];
            copyNode = copyNode->next;
            node = node->next;
        }
        return copyHead;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */

