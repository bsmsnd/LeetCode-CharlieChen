/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;

        for (long i = 31;i >= 0;--i)
        {
            if ((m & ((long)1 << i))  == (n & ((long)1 << i)))
                ans += m & ((long)1 << i);
            else
                break;
        }
        return ans;


    }
};

