/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
class MyCompare{
public:
    bool operator()(const pair<int, int> a, const pair<int, int> b) const
    {
        // pair: key, freq
        return a.second < b.second;
    }
};

class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, MyCompare> q;
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = m.find(nums[i]);
            if (it != m.end())
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
        }
        for (auto it=m.begin();it!=m.end();++it)
        {
            q.push(make_pair(it->first, it->second));
        }
        for (int i = 0 ; i < k;i++)
        {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};

