/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    uint32_t GetLinkedListLen(ListNode *head, ListNode *&tail)
    {
        uint32_t count = 0;
        while (head != nullptr) {
            count++;
            tail = head;
            head = head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tailA;
        ListNode *tailB;
        int m = GetLinkedListLen(headA, tailA);
        int n = GetLinkedListLen(headB, tailB);
        if (tailA == tailB) {
            // Fast Forward 
            ListNode *visitA = headA;
            ListNode *visitB = headB;
            while (m > n) {
                visitA = visitA->next;
                m--;
            }
            while (n > m) {
                visitB = visitB->next;
                n--;
            }
            for (; m >= 0; m--) {
                if (visitA == visitB) {
                    return visitA;
                }
                visitA = visitA->next;
                visitB = visitB->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end

