/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n!=0)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
};

