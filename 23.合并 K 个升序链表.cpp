/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30202
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// #include "helper.h"

struct CompareNode {
    bool operator()(const ListNode* const a, const ListNode* const b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> q;
        for (ListNode* node: lists) {
            if (node != nullptr) {
                q.push(node);
            }
        }
        ListNode* newHead = nullptr;
        ListNode* current = nullptr;
        auto pushNext = [&q](ListNode* item) {
            if (item->next != nullptr) {
                q.push(item->next);
            }
        };

        // pick the head
        if (!q.empty()) {
            ListNode *temp = q.top();
            q.pop();
            newHead = temp;
            current = newHead;
            pushNext(current);
        }

        // iterate all nodes
        while (!q.empty()) {
            ListNode *temp = q.top();
            q.pop();
            current->next = temp;
            current = current->next;
            pushNext(current);
        }

        if (current != nullptr) {
            current->next = nullptr;
        }

        return newHead;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

