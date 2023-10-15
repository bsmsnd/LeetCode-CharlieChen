/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr) {
            // fast moves two steps, if possible
            fast = fast->next;
            if (fast->next != nullptr) {
                fast = fast->next;
            } else {
                return false;
            }
            // slow moves one step
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

