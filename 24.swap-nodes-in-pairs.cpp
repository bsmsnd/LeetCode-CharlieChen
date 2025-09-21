/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(nullptr) {}
//  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *visit = head;
        ListNode *prev = nullptr;
        while (visit != nullptr) {
            ListNode *p1 = visit;
            ListNode *p2 = visit->next;
            if (p1 == nullptr || p2 == nullptr) {
                break;
            }
            ListNode *pNext = p2->next;
            if (prev != nullptr) {
                prev->next = p2;
            }
            p2->next = p1;
            p1->next = pNext;
            if (head == p1) {
                head = p2;
            }
            prev = p1;
            visit = pNext;
        }
        return head;
    }
};

