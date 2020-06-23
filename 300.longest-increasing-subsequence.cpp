/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<pair<int, int>> v;
        const int s = nums.size();
        int ans = 0;
        for (int i = 0; i < s; i++){
            int cur = findBestBefore(v, nums[i]);
            ans = max(ans, cur+1);
            addPair(v, nums[i], cur+1);
        }
        return ans;
    }

    int findBestBefore(vector<pair<int, int>>& v, int key){
        int s = v.size();
        int l = 0, r = s, m;
        while(l < r){
            m = (l+r) / 2;
            if (v[m].first == key){
                return (m == 0) ? 0 : v[m-1].second;
            }
            if (v[m].first > key){
                r = m;
            }
            else{
                l = m;
            }

            if (r-l == 1)
                return v[l].first < key ? v[l].second : 0;
        }
        return 0;

    }

    void addPair(vector<pair<int, int>>& v, int key, int value){
        if (v.size() < value)
            v.push_back(make_pair(key, value));            
        else
            v[value-1].first = min(v[value-1].first, key);
    }
};
// @lc code=end

