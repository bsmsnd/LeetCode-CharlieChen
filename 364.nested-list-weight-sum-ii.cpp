/*
 * @lc app=leetcode id=364 lang=cpp
 *
 * [364] Nested List Weight Sum II
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public: 
    int getLevel(vector<NestedInteger>& nestedList){
        int level = 1;
        for (NestedInteger& n: nestedList)
            if (!n.isInteger())
                level = max(level, 1 + getLevel(n.getList()));
        return level;
    }
    int sumResults(vector<NestedInteger>& nestedList, int level){
        int sum = 0;
        int ans = 0;
        for (NestedInteger& n: nestedList)
            if (n.isInteger())
                sum += n.getInteger();                
            else
                ans += sumResults(n.getList(), level-1);
        return sum * level + ans;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int level = 1;
        int sum = 0;
        int ans = 0;
        for (NestedInteger& n: nestedList)
            if (n.isInteger())
                sum += n.getInteger();                
            else
                level = max(level, 1 + getLevel(n.getList()));
        for (NestedInteger& n: nestedList)
            if (!n.isInteger())
                ans += sumResults(n.getList(), level-1);
        return sum * level + ans;
    }
};
// @lc code=end

