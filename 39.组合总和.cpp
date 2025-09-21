/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30202
 *
 * [39] 组合总和
 */

// @lc code=start
// #include "helper.h"
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // initialization
        candidateSize = candidates.size();
        solutions.clear();

        // abnormal cases
        if (candidateSize == 0) {
            return solutions;
        }

        // search
        vector<int> currentList;
        dfs(candidates, currentList, target, 0, 0);
        return solutions;
    }

    void dfs(const vector<int>& candidates, vector<int> currentList, int target, int currentPosition, int currentSum)
    {
        if (currentSum > target) {
            return;
        }

        for (size_t i = currentPosition; i < candidateSize; i++) {
            if (currentSum + candidates[i] < target) {
                currentList.push_back(candidates[i]);
                dfs(candidates, currentList, target, i, currentSum + candidates[i]);
                currentList.pop_back();
            } else if (currentSum + candidates[i] == target) {
                currentList.push_back(candidates[i]);
                solutions.push_back(currentList);
                currentList.pop_back();
            }
        }
    }
private:
    vector<vector<int>> solutions;
    size_t candidateSize;
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

