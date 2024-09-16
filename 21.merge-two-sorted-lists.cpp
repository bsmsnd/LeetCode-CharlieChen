// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode id=21 lang=cpp
 * @lcpr version=30116
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeList = nullptr;
        ListNode* mergeListHead = nullptr;
        while (list1 != nullptr || list2 != nullptr) {
            int nextValue;
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    nextValue = list1->val;
                    list1 = list1->next;
                } else {
                    nextValue = list2->val;
                    list2 = list2->next;
                }
            } else if (list1 != nullptr) {
                nextValue = list1->val;
                list1 = list1->next;
            } else {
                nextValue = list2->val;
                list2 = list2->next;
            }

            if (mergeList == nullptr) {
                mergeList = new ListNode(nextValue);
                mergeListHead = mergeList;
            } else {
                mergeList->next = new ListNode(nextValue);
                mergeList = mergeList->next;
            }
        }
        return mergeListHead;
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

