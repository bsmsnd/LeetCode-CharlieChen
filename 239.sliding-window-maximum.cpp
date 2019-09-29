/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <set>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // O(n lg n) solution
    // multiset<int, greater<int>> q;    
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     if (nums.size() == 0)
    //         return ans;
    //     for (int i = 0; i < k;++i)
    //         q.insert(nums[i]);
    //     ans.push_back(*q.begin());
    //     for (int i =k; i < nums.size();++i)
    //     {            
    //         auto it = q.find(nums[i-k]);
    //         q.erase(it);
    //         q.insert(nums[i]);
    //         ans.push_back(*q.begin());            
    //     }
    //     return ans;        
    // }
    // O(n) solution
    deque<int> q;
    void addValue(int x)
    {
        while(!q.empty() && q.back() < x)
        {
            q.pop_back();
        }
        q.push_back(x);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0)return vector<int>(0);
        int n = nums.size();
        for (int i = 0;i < k;i++)
            addValue(nums[i]);
        vector<int> ans;
        ans.push_back(q.front());
        for (int i = k;i < n; i++)
        {
            if (!q.empty() && q.front() == nums[i - k])q.pop_front();
            addValue(nums[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
};

