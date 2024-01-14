/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // move to N-th element
        ListNode *nodeToVisit = head;
        for (int i = 0; i < n - 1; i++) {
            nodeToVisit = nodeToVisit->next;
        }
        ListNode *nodeToRemove = head;
        ListNode *nodeBeforeToRemove = nullptr;
        while (nodeToVisit->next != nullptr) {
            nodeBeforeToRemove = nodeToRemove;
            nodeToRemove = nodeToRemove->next;
            nodeToVisit = nodeToVisit->next;
        }
        if (nodeBeforeToRemove == nullptr) {
            return nodeToRemove->next;            
        }
        nodeBeforeToRemove->next = nodeToRemove->next;
        return head;
    }
};
// @lc code=end

