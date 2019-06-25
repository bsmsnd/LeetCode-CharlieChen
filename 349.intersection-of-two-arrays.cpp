/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */
// #include <unordered_set>
// #include <vector>
// using namespace std;

class Solution {
public:
    unordered_set<int> s1, s2;
    vector<int> ans;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size();++i)
            s1.insert(nums1[i]);
        for (int i = 0;i < nums2.size(); ++i)
        {
            if (s1.find(nums2[i]) != s1.end() && s2.find(nums2[i]) == s2.end())
            {
                ans.push_back(nums2[i]);
                s2.insert(nums2[i]);
            }
        }
        return ans;                
    }
};

