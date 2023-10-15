/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
// #include "helper.h"

class Solution {
public:
    static constexpr uint32_t MAX_NUMS_LENGTH = 10000;
    int jump(vector<int>& nums) {
        const uint32_t n = nums.size();
        for (uint32_t i = 0; i < n; i++) {
            dist[i] = INT32_MAX;
        }

        dist[0] = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if ((i + j < n) && (dist[i + j] > dist[i] + 1)) {
                    dist[i + j] = dist[i] + 1;
                }
            }
        }
        return dist[n-1];
    }
private:
    int dist[MAX_NUMS_LENGTH];
};

// int main()
// {
//     Solution sol;
//     vector<int> s = {2, 3, 1, 1, 4};
//     cout << sol.jump(s) << endl;
//     return 0;
// }


