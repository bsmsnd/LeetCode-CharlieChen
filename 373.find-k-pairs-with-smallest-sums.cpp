/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

class Compare{
public:
    bool operator() (pair<int, int> a, pair<int, int> b) const
    {
        return a.first + a.second > b.first + b.second;
    }
};


class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> q;
        for (int i = 0;i < nums1.size();++i)
        for (int j = 0;j < nums2.size(); ++j)
            q.push(make_pair(nums1[i], nums2[j]));
        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i)
        {
            if (q.empty())
                return ans;
            ans.push_back({q.top().first, q.top().second});
            q.pop();
        }
        return ans;
    }
};

