/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
// INT_MAX = 2^31 - 1
// HALF_INT_MAX = 2^30 = 1073741824
#define HALF_INT 1073741824
class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((dividend == INT_MIN && divisor == -1) || divisor == 0)
            return INT_MAX;
        if (dividend == 0)
            return 0;
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        
        int result_flag = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? -1 : 1;
        int dividend_flag = dividend > 0 ? 1 : -1;
        int left = dividend;
    //    int abs_divisor = divisor > 0 ? divisor : -divisor;
        int step_divisor = result_flag == 1 ? divisor : -divisor;
        int ans = 0;
        int tmpAns = 0;
        int tmpSum = 0;
        while ((dividend_flag == -1 && left <= step_divisor) || (dividend_flag == 1 && left >= step_divisor))
        {
            tmpAns = result_flag;
            tmpSum = step_divisor;
            while((dividend_flag == -1 && tmpSum > -HALF_INT && tmpSum + tmpSum > left) || (dividend_flag == 1 && tmpSum < HALF_INT && tmpSum + tmpSum < left))
            {
                tmpAns += tmpAns;
                tmpSum += tmpSum;
            }
            ans += tmpAns;
            left -= tmpSum;
        }
        return ans;
    }
};

