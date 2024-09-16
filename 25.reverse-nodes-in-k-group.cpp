/*
 * @lc app=leetcode id=25 lang=cpp
 * @lcpr version=30116
 *
 * [25] Reverse Nodes in k-Group
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
    void reverseK(ListNode* head, int k) {
        ListNode *prev = nullptr;
        ListNode *node = head;
        for (int i = 0; i < k; i++) {
            ListNode *tempNext = node->next;
            node->next = prev;
            prev = node;
            node = tempNext;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        ListNode *node = head;
        ListNode *newHead = nullptr;
        ListNode *prevTail = nullptr;
        while (node != nullptr) {
            int count = 0;
            ListNode *currentHead = node;
            ListNode *currentTail = nullptr;
            for (; count < k && node != nullptr; count++) {
                currentTail = node;
                node = node->next;
            }
            if (count != k) {
                prevTail->next = currentHead;
                break;
            }
            reverseK(currentHead, k);

            if (newHead == nullptr) {
                newHead = currentTail;
            } else {
                prevTail->next = currentTail;
            }

            prevTail = currentHead;
        }
        return newHead == nullptr ? head : newHead;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

