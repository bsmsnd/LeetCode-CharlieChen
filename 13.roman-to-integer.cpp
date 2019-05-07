/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (51.47%)
 * Total Accepted:    390.1K
 * Total Submissions: 751.1K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
#include <string>
using namespace std;
const int VALUES[7] = {1,5,10,50,100,500,1000}; // I0 V1 X2 L3 C4 D5 M6
const int I_CHANGE[2] = {4,9};  // V or X
const int X_CHANGE[2] = {40,90};  // L or C
const int C_CHANGE[2] = {400,900};  // D or M
class Solution {
public:
    int romanToInt(string s) {
        bool hold_flag = false;
        char hold_symbol = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (hold_flag)
            {
                hold_flag = false;
                switch (hold_symbol) {
                    case 'I':
                        if (s[i] == 'V'){
                            sum += I_CHANGE[0];
                            continue;
                        }
                        else if (s[i] == 'X')
                        {
                            sum += I_CHANGE[1];
                            continue;
                        }
                        else
                            sum += VALUES[0];
                        
                        break;
                    case 'X':
                        if (s[i] == 'L'){
                            sum += X_CHANGE[0];                            
                            continue;
                        }
                        else if (s[i] == 'C')
                        {
                            sum += X_CHANGE[1];
                            continue;
                        }
                        else
                            sum += VALUES[2];
                        break;
                    case 'C':
                        if (s[i] == 'D'){
                            sum += C_CHANGE[0];                            
                            continue;
                        }
                        else if (s[i] == 'M')
                        {
                            sum += C_CHANGE[1];
                            continue;
                        }
                        else
                            sum += VALUES[4];
                        break;
                }
            }
            if (i == s.length() - 1){
                switch (s[i]){
                    case 'I': sum += VALUES[0];break;
                    case 'V': sum += VALUES[1];break;
                    case 'X': sum += VALUES[2];break;
                    case 'L': sum += VALUES[3];break;
                    case 'C': sum += VALUES[4];break;
                    case 'D': sum += VALUES[5];break;
                    case 'M': sum += VALUES[6];break;
                }
            }
            else
            {
                switch (s[i]){
                    case 'V': sum += VALUES[1];break;
                    case 'L': sum += VALUES[3];break;
                    case 'D': sum += VALUES[5];break;
                    case 'M': sum += VALUES[6];break;
                    default: hold_flag = true; hold_symbol = s[i];
                }
            } 
        }
        return sum;
    }
};

