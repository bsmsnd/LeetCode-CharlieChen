// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode id=92 lang=cpp
 * @lcpr version=30116
 *
 * [92] Reverse Linked List II
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
// #include "helper.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // special case
        if (left == right) {
            return head;
        }
        ListNode *newHead = nullptr;
        ListNode *node = head;
        ListNode *enter = nullptr;

        /* Fast forward to the reverse interval */
        int count = 0;
        // change to 0-indexed
        left--;
        right--;
        for (; count < left && node != nullptr; count++) {
            enter = node;
            if (newHead == nullptr) {
                newHead = node;
            }
            node = node->next;
        }
        ListNode *rangeNewTail = node;
        ListNode *exit = nullptr;

        // Reverse List
        ListNode *prev = enter;
        for (; count <= right && node != nullptr; count++) {
            ListNode *tempNext = node->next;
            node->next = prev;
            prev = node;
            exit = prev;
            node = tempNext;
        }

        // connect
        rangeNewTail->next = node;

        if (newHead == nullptr) { // start reversing from position 0
            return exit;
        }
        enter->next = exit;
        return newHead;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n1\n5\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

