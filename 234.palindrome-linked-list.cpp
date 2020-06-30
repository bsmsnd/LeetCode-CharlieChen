/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* cur;
        int cnt = 0;
        cur = head;
        while(cur){
            cur = cur->next;
            cnt++;
        }

        // revert first half
        cur = head;
        ListNode *prev = nullptr, *next;        
        for (int i = 0;i < cnt/2 ; i++){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;            
        }
        
        if (cnt%2 == 1)
            cur = cur->next;

        for (int i = 0; i < cnt/2; i++){
            if (cur->val != prev->val)
                return false;
            else{
                cur = cur->next;
                prev = prev->next;
            }
        }
        return true;
    }
};
// @lc code=end

