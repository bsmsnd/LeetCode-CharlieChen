/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            if (slow->next != nullptr) {
                slow = slow->next;
            } else {
                return nullptr;
            }

            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;
            } else {
                return nullptr;
            }
        } while (slow != fast);
        ListNode *loopEntrance = head;
        while (loopEntrance != slow) {
            loopEntrance = loopEntrance->next;
            slow = slow->next;
        }
        return loopEntrance;
    }
};
// @lc code=end

