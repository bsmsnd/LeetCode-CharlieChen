/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30202
 *
 * [234] 回文链表
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
// #include "helper.h"
class Solution {
public:
    ListNode* ReverseListNode(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* current = head;
        ListNode* currentNext = head->next;
        while (current != nullptr && currentNext != nullptr) {
            ListNode* tempNext = currentNext->next;
            currentNext->next = current;
            current = currentNext;
            currentNext = tempNext;
        }
        head->next = nullptr;
        return current;
    }

    bool isPalindrome(ListNode* head) {
        // find the midpoint
        ListNode* fast = head;
        ListNode* slow = head;
        if (fast == nullptr) {
            return true;
        }

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast != nullptr) {
            if (fast->next != nullptr) { // even # of items
                 slow = slow->next;
            }
        }

        // reverse from midpoint to tail
        fast = ReverseListNode(slow);

        // visit
        slow = head;
        while (slow != nullptr && fast != nullptr) {
            if (slow->val != fast->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5,6,1,6,5,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

