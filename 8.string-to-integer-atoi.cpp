/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.47%)
 * Total Accepted:    345.9K
 * Total Submissions: 2.4M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */
#include <string>

#define INT_MIN  -2147483648
#define INT_MAX  2147483647

const string STR_MIN = "2147483648";
const string STR_MAX = "2147483647";
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        string get_num = "";
        int sign = 0;
        bool number_start_flag = false;
        for (int i = 0;i < str.length(); i++)
        {
            bool out_loop_flag = false;
            if (str[i] == ' ')
                if (number_start_flag)
                    break;
                else
                    continue;
            switch (isDigitOrSign(str[i])) {
                case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
                    if (!number_start_flag){                        
                        number_start_flag = true;
                        sign = 1;                        
                    }
                    get_num = get_num + str[i];
                    break;
                case 10: 
                    if (!number_start_flag){
                        number_start_flag = true;
                        sign = 1;
                    }
                    else
                        out_loop_flag = true; // has numbers already. end reading.
                    break;
                case 11:
                    if (!number_start_flag){
                        number_start_flag = true;
                        sign = -1;
                    }
                    else
                        out_loop_flag = true; // has numbers already. end reading.
                    break;
                default: 
                    out_loop_flag = true;    
            }
            if (out_loop_flag)
                break;
        }
        if (get_num.length() == 0) return 0;
        else
        {
            int compare = compareString(get_num, (sign == 1 ? STR_MAX : STR_MIN));
            if (compare == 1 or compare == 2)
                return sign == 1 ? INT_MAX : INT_MIN; 
            else
                return sign * convertStringToInt(get_num);
        }
        
    }

    int isDigitOrSign(char ch){
        if (ch >= '0' and ch <= '9') return ch - '0';
        if (ch == '+') return 10;
        if (ch == '-') return 11;
        return -1;
    }

    int compareString(string a, string b){
        // a: the number received; b: the maximum value
        // return values: 0 = OK; 1 = exceed; 2 = ON_BOUNDARY
        int count_zero = 0;
        while (a.length() > count_zero && a[count_zero] == '0'){
            count_zero++;
        }
        a.erase(0,count_zero);
        if (a.length() < b.length())
            return 0;
        if (a.length() > b.length())
            return 1;
        // Left case: same length
        for (int i = 0; i<a.length();i++){
            if (a[i] > b[i])
                return 1;
            else if (a[i] < b[i])
                return 0;
        }
        return 2;
        
    }

    int convertStringToInt(string s){
        // s should not be on the bound of exceed the bound
        int n = 0;
        for (int i = 0;i<s.length();i++)
        {
            n = n * 10 + (s[i] - '0');
        }
        return n;
    }

    
};

