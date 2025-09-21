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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *solutionList = nullptr;
        ListNode *solutionHead = nullptr;
        ListNode *a = l1;
        ListNode *b = l2;
        int addToNextDigit = 0;
        while (a != nullptr || b != nullptr || addToNextDigit != 0) {
            int nextDigit = addToNextDigit;
            addToNextDigit = 0;
            if (a != nullptr) {
                nextDigit += a->val;
                a = a->next;
            }
            if (b != nullptr) {
                nextDigit += b->val;
                b = b->next;
            }
            if (nextDigit >= 10) {
                addToNextDigit = nextDigit / 10;
                nextDigit %= 10;
            }
            if (solutionList == nullptr) {
                solutionList = new ListNode(nextDigit);
                solutionHead = solutionList;
            } else {
                solutionList->next = new ListNode(nextDigit);
                solutionList = solutionList->next;
            }
        }
        return solutionHead;
    }
};
