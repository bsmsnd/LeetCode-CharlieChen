/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* Head;
    int size;
    Solution(ListNode* head) {
        size = 0;
        ListNode* cur = head;
        while(cur)
        {
            size++;
            cur = cur->next;
        }
        Head = head;        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int random_number = rand() % size;
        ListNode* cur = Head;
        for (int i = 0;i < random_number;++i)
            cur = cur->next;
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

