/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30202
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* newHead;
        if (list1->val <= list2->val) {
            newHead = list1;
            list1 = list1->next;
        } else {
            newHead = list2;
            list2 = list2->next;
        }

        ListNode* current = newHead;
        while (list1 != nullptr && list2 != nullptr) {
           if (list1->val <= list2->val) {
                current->next = list1;
                current = current->next;
                list1 = list1->next;
            } else {
                current->next = list2;
                current = current->next;
                list2 = list2->next;
            }
        }

        if (list1 != nullptr) {
            current->next = list1;
        } else if (list2 != nullptr) {
            current->next = list2;
        }

        return newHead;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

