/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
// #define LEETCODE_DEBUG
#ifdef LEETCODE_DEBUG
#include "helper.h"
#endif

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double probability[n+1];
        double slideWindowSum = 0.0;
        int leftPointer = 0;
        for (int i = 0; i <= n; i++) {
            int startPoint = max(0, i - maxPts);
            while (leftPointer < startPoint) {
                if (leftPointer < k) {
                    slideWindowSum -= probability[leftPointer];
                }
                leftPointer++;
            }
            probability[i] = (i == 0) ? 1.0 : slideWindowSum / maxPts;
            if (i < k) {
                slideWindowSum += probability[i];
            }
            // printf("i=%d, prob[i]=%f, slideSum=%f\n", i, probability[i], slideWindowSum);
        }

        return accumulate(probability+k, probability+(n+1), 0.0);
    }
};
// @lc code=end

