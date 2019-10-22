/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        set<int> s1, s2;
        int n = stones.size();
        s1.insert(0);
        for (int i = 0;i < n; i++)
        {
            for (auto it = s1.begin(); it != s1.end(); it++)
            {
                s2.insert(abs(*it + stones[i]));
                s2.insert(abs(*it - stones[i]));
            }
            s1 = s2;
            s2.clear();
        }
        return *s1.begin();
    }
};
// @lc code=end

