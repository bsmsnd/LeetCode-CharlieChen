/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    multiset<int, greater<int>> q;    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0)
            return ans;
        for (int i = 0; i < k;++i)
            q.insert(nums[i]);
        ans.push_back(*q.begin());
        for (int i =k; i < nums.size();++i)
        {            
            auto it = q.find(nums[i-k]);
            q.erase(it);
            q.insert(nums[i]);
            ans.push_back(*q.begin());            
        }
        return ans;        
    }
};

