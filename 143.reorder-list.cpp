/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (!head)return;
        int n = 0;
        ListNode* cur = head, *prev, *tmp, *mid;
        while(cur){n++; cur = cur->next;}
        cur = head;
        for (int i = 0;i < (1 + n)/2 - 1; i++)cur=cur->next;
        
        // one more step: process mid node
        tmp = cur->next;
        cur->next = nullptr;
        cur = tmp;


        prev = nullptr;
        for (int i = (1 + n)/2; i < n; i++){
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;            
        }
        ListNode *p1 = head, *p2 = prev, *tmp1, *tmp2;
        while(p2){
            tmp1 = p1->next;
            tmp2 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1=tmp1;
            p2=tmp2;
        }
    }
};
// @lc code=end

