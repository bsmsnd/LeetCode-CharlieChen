/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30202
 *
 * [142] 环形链表 II
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

// #include "helper.h"
// #include <cassert>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // step 1: fast/slow pointer
        ListNode *fast = head;
        ListNode *slow = head;
        if (head == nullptr) {
            return nullptr;
        }
        uint32_t k = 0;
        do {
            // printf("(%d, %d)\n", slow->val, fast->val);
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            slow = slow->next;
            k++;
        } while (fast != nullptr && slow != nullptr && fast != slow);

        // no cycle case
        if (fast == nullptr) {
            return nullptr;
        }
        // cycle exists
        fast = head;
        while (fast != slow) {
            assert(fast != nullptr);
            assert(slow != nullptr);
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

