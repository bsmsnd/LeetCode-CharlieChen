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
        ListNode* cur = head;
        ListNode* new_head;
        while(cur)
        {
            ListNode* tmp = cur->next;
            if (tmp)
            {                
                cur->next = cur->next->next;
                cur->next = cur;            
            }
            else
                break;
            if (cur == head)
                new_head = tmp;
            cur = cur->next;
        }
        return new_head;
        INT_MIN
    }
};

