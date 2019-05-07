/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.52%)
 * Total Accepted:    822.5K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a, *b;
        a = l1;
        b = l2;
        int add_to_next = 0;
        ListNode* last_node = NULL;
        bool a_end_flag = (l1 == NULL);
        bool b_end_flag = (l2 == NULL);
        ListNode* start_node = NULL;
        while(!a_end_flag || !b_end_flag){
            ListNode* new_node = new ListNode(((a_end_flag?0:a->val) + (b_end_flag?0:b->val) + add_to_next) % 10);
            add_to_next = ((a_end_flag?0:a->val) + (b_end_flag?0:b->val) + add_to_next) / 10;
            
            a = a_end_flag ? NULL : a->next;
            if (a == NULL) a_end_flag = true;
            b = b_end_flag ? NULL : b->next;
            if (b == NULL) b_end_flag = true;
            if (last_node == NULL)
            {
                start_node = new_node;
                last_node = new_node;
            }
            else
            {
                last_node->next = new_node;
                last_node = new_node;
            }
        }
        if (add_to_next > 0){
            ListNode* new_node = new ListNode(add_to_next);
            last_node->next = new_node;
            last_node = new_node;
        }
        if (last_node != NULL) last_node->next = NULL;
        return start_node;
    }
};

