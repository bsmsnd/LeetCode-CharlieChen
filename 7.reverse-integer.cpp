/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.10%)
 * Total Accepted:    637.6K
 * Total Submissions: 2.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */



class Solution {
const int BOUND = 214748364;
const int NEG = 8;
const int POS = 7;

public:
    int reverse(int x) {
        if (x == 0)
            return 0;
        int ans = 0;
        int sign = x>0 ? 1 : -1;
        if (sign == 1 && x == INT_MAX)
            return 0;
        if (sign == -1 && x == INT_MIN)
            return 0;
        int tmp = x * sign;
        int bound_for_this = sign == 1 ? POS : NEG;
        while(tmp != 0){
            int digit = tmp % 10;
            tmp /= 10;
            if (ans > BOUND) return 0;
            else if (ans == BOUND && digit > bound_for_this) return 0;
            ans = ans * 10 + digit;
        }
        return sign*ans;
        

    }
};

