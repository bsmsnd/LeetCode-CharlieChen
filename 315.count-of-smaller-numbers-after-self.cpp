/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BST binary_search_tree;
        vector<int> result;
        for (int i = nums.size() - 1;i>=0;--i)
        {
            result.push_back(binary_search_tree.findSmaller(nums[i]));
            binary_search_tree.root = binary_search_tree.insert(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }

};

