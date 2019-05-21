/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> bst;
        for (int i = 0; i < nums.size(); ++i )
        {
            if (bst.size() == k + 1)bst.erase(bst.find(nums[i - k - 1]));
            auto lb = bst.lower_bound(nums[i] - (long long)t);
            if (lb != bst.end() && *lb - nums[i] <= t) return true;
            bst.insert(nums[i]);
        }
        return false;
    }
};

