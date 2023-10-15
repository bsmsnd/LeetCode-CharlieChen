/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
// #include "helper.h"

class Solution {
public:
    void StepCombine(int level) 
    {
        // Cases to skip immediately: not enough numbers to fill in the blank
        if (!currentSolution_.empty() && k_ - level > n_ - currentSolution_.back()) {
            return;
        }
        if (level == k_) {
            solutionSet_.push_back(currentSolution_);
        } else {
            int lowerBound = currentSolution_.empty() ? 1 : currentSolution_.back() + 1;
            int upperBound = n_;
            for (int nextNumToInsert = lowerBound; nextNumToInsert <= upperBound; nextNumToInsert++) {
                currentSolution_.push_back(nextNumToInsert);
                StepCombine(level+1);
                currentSolution_.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        StepCombine(0);
        return solutionSet_;
    }
private:
    vector<vector<int>> solutionSet_;
    vector<int> currentSolution_;
    int n_;
    int k_;
};
// @lc code=end

