/*
 * @lc app=leetcode.cn id=3186 lang=cpp
 * @lcpr version=30203
 *
 * [3186] 施咒的最大总伤害
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> damages;
        for (int p : power) {
            if (damages.find(p) == damages.end()) {
                damages[p] = 1;
            } else {
                ++damages[p];
            }
        }
        list<pair<int, long long>> previousDamages; // 至多保留3个
        long long grandMaxDamage = 0;
        for (const auto &item : damages) {
            long long thisDamage = (long long)item.first * (long long)item.second;
            long long maxDamage = thisDamage;
            for (const auto &previous: previousDamages) {
                if (item.first - previous.first > 2) {
                    maxDamage = max(maxDamage, thisDamage + previous.second);
                } else {
                    maxDamage = max(maxDamage, previous.second);
                }
            }
            previousDamages.push_front(make_pair(item.first, maxDamage));
            while (previousDamages.size() > 3) {
                previousDamages.pop_back();
            }
            grandMaxDamage = max(grandMaxDamage, maxDamage);
        }
        return grandMaxDamage;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,1,6,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,4,3,1,1,1,5]\n
// @lcpr case=end

 */

