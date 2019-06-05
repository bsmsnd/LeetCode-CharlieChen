/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(nullptr) {}
//  };
 
// #include <vector>
// #include <queue>
// using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        const int K = lists.size();
        if (K==0)
            return nullptr;
        int cnt_completed_lists = 0;        
        // first build the heap with K pointers
        for (int i = 0;i < K; i++)
        {
            if (lists[i] != nullptr)            
                q.push(lists[i]);
            else
            {
                cnt_completed_lists++;                
            }            
        }
        // start to roll over all lists
        if (cnt_completed_lists == K)
            return nullptr;
        ListNode* root = q.top();        
        ListNode* prev = nullptr;
        while(cnt_completed_lists < K)
        {
            ListNode* cur = q.top();
            if (prev)
                prev->next =  cur;
            q.pop();
            if (cur->next)
            {
                q.push(cur->next);                
            }
            else
            {
                cnt_completed_lists++;
            }       
            prev = cur;     
        }
        return root;
    }
};

