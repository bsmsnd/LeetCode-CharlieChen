/*
 * @lc app=leetcode id=248 lang=cpp
 *
 * [248] Strobogrammatic Number III
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool cmp(string a, string b)
    // return true if a <= b
    {
        if (a.size() < b.size())return true;
        if (a.size() > b.size())return false;
        int n = a.size();
        for (int i = 0;i < n; i++)
            if (a[i] != b[i])
                return a[i] < b[i];
        return true;
    }

    int strobogrammaticInRange(string low, string high) {
        int lower = low.size(), upper = high.size();
        
    }
};
// @lc code=end

