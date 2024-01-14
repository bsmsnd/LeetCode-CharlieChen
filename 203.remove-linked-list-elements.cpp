/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
// #include <__config>

class Solution {
public:
    ListNode* FindNextAvailableNode(ListNode *curHead, int val) {
        while (curHead != nullptr) {
            if (curHead->val != val) {
                break;
            } else {
                curHead = curHead->next;
            }
        }
        return curHead;
    }
     ListNode* removeElements(ListNode* head, int val) {
        ListNode *front = FindNextAvailableNode(head, val);
        ListNode *realHead = front;
        while(front != nullptr && front->next != nullptr) {
            if (front->next->val == val) {
                front->next = FindNextAvailableNode(front->next, val);
            }
            front = front->next;
        }
        return realHead;
    }
};
// @lc code=end

