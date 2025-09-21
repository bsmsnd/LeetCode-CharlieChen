/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30202
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = nullptr;
        ListNode* smallTail = nullptr;
        ListNode* greatHead = nullptr;
        ListNode* greatTail = nullptr;
        ListNode* current = head;
        for (; current != nullptr; current = current->next) {
            if (current->val < x) {
                if (smallHead == nullptr) {
                    smallHead = current;
                    smallTail = smallHead;
                } else {
                    smallTail->next = current;
                    smallTail = smallTail->next;
                }
            } else {
                if (greatHead == nullptr) {
                    greatHead = current;
                    greatTail = greatHead;
                } else {
                    greatTail->next = current;
                    greatTail = greatTail->next;
                }
            }
        }
        if (smallHead != nullptr && greatHead != nullptr) {
            smallTail->next = greatHead;
            greatTail->next = nullptr;
            return smallHead;
        } else if (smallHead != nullptr) {
            return smallHead;
        } else if (greatHead != nullptr) {
            return greatHead;
        } else {
            return nullptr;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */

