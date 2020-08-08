/*
 * @lc app=leetcode id=1494 lang=cpp
 *
 * [1494] Parallel Courses II
 */

// @lc code=start
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        int requirements[n];
        fill_n(requirements, n, 0);        

        for (int i = 0;i < dependencies.size(); i++)
            requirements[dependencies[i][1] - 1] |= (1 << (dependencies[i][0] - 1));
        
        // init
        int nStates = pow(2, n);
        int dp[nStates];
        fill_n(dp, nStates, n);
        dp[0] = 0;

        // loop: for all states
        for (int curState = 0; curState < nStates; curState++){
            // cout << curState << " ";
            int availableNextMoves = 0;
            for (int i = 0; i < n; i++)
                if ((curState & requirements[i]) == requirements[i])
                    availableNextMoves |= (1 << i);
            availableNextMoves &= (~curState);
            // cout << availableNextMoves << endl;
            for (int s = availableNextMoves; s; s = (s-1) & availableNextMoves)
                if (__builtin_popcount(s) <= k){
                    int newState = curState | s;
                    dp[newState] = min(dp[newState], dp[curState] + 1);
                    // printf("%d : %d\n", newState, dp[newState]);
                }
        }
        return dp[nStates-1];
    }
};
// @lc code=end

