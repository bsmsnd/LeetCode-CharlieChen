/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
// #include <unordered_set>
// #include <vector>
// using namespace std;

class Solution {
public:
    unordered_multiset<int> s;
    vector<int> ans;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0;i < nums1.size();++i)
            s.insert(nums1[i]);
        for (int i = 0;i < nums2.size();++i)        
        {
            auto it = s.find(nums2[i]);
            if (it != s.end())
            {
                ans.push_back(nums2[i]);
                s.erase(it);
            }            
        }
        return ans;
    }
};

