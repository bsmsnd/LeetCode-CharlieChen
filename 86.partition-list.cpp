/*
 * @lc app=leetcode id=86 lang=cpp
 * @lcpr version=30116
 *
 * [86] Partition List
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
#include "helper.h"

constexpr uint32_t LESS_THAN_X = 0;
constexpr uint32_t GREATER_THAN_OR_EQUAL_TO_X = 1;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *heads[2] = {nullptr, nullptr};
        ListNode *runningNodes[2] = {nullptr, nullptr};
        auto append = [&heads, &runningNodes](ListNode* node, uint32_t position) {
            if (heads[position] == nullptr) {
                heads[position] = node;
                runningNodes[position] = node;
            } else {
                runningNodes[position]->next = node;
                runningNodes[position] = node;
            }
        };

        ListNode *node = head;
        while (node != nullptr) {
            if (node->val >= x) {
                append(node, GREATER_THAN_OR_EQUAL_TO_X);
            } else {
                append(node, LESS_THAN_X);
            }
            node = node->next;
        }

        // connect
        ListNode *newHead = nullptr;
        if (heads[LESS_THAN_X] != nullptr) {
            newHead = heads[LESS_THAN_X];
            runningNodes[LESS_THAN_X]->next = heads[GREATER_THAN_OR_EQUAL_TO_X];
        }
        if (heads[GREATER_THAN_OR_EQUAL_TO_X] != nullptr) {
            if (newHead == nullptr) {
                heads[LESS_THAN_X];
            }
            runningNodes[GREATER_THAN_OR_EQUAL_TO_X]->next = nullptr;
        }

        return newHead;
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

