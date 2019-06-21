/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
#include <string>
using namespace std;
class Solution {
public:
    const string single_digit[10]={"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    const string digit_on_tens[10]={"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    const string below_twenty[10]={"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        int digits = 0;
        int num_cp = num;
        int all_digits[10] = {};
        string ans;
        while(num_cp > 0)
        {
            all_digits[digits++] = num_cp % 10;
            num_cp /= 10;
        }
        if (digits>=10)
        {
            ans += single_digit[all_digits[9]] + "Billion ";
        }
        bool flag;

        flag = false;
        if (digits >= 7)
        {
            if (all_digits[8] > 0) //hundred
            {
                flag = true;
                ans += single_digit[all_digits[8]] + "Hundred ";                
            }
            if (all_digits[7] > 0) //tens
            {                
                if (all_digits[7] == 1)
                {
                    ans += below_twenty[all_digits[6]];
                    flag = true;
                }                    
                else if (all_digits[7] != 0)
                {
                    flag = true;
                    ans += digit_on_tens[all_digits[7]];
                    ans += single_digit[all_digits[6]];
                }
                else if (all_digits[6] != 0)
                {
                    flag = true;
                    ans += single_digit[all_digits[6]];
                }
            }
            else if (all_digits[6] != 0)// no tens
            {
                flag = true;
                ans += single_digit[all_digits[6]];
            }
            if (flag)
                ans += "Million ";                            
        }

        flag = false;
        if (digits >= 4)
        {
            if (all_digits[5] > 0) //hundred
            {
                flag = true;
                ans += single_digit[all_digits[5]] + "Hundred ";                
            }
            if (all_digits[4] > 0) //tens
            {                
                if (all_digits[4] == 1)
                {
                    ans += below_twenty[all_digits[3]];
                    flag = true;
                }                    
                else if (all_digits[4] != 0)
                {
                    flag = true;
                    ans += digit_on_tens[all_digits[4]];
                    ans += single_digit[all_digits[3]];
                }
                else if (all_digits[3] != 0)
                {
                    flag = true;
                    ans += single_digit[all_digits[3]];
                }
            }
            else if (all_digits[3] != 0)// no tens
            {
                flag = true;
                ans += single_digit[all_digits[3]];
            }
            if (flag)
                ans += "Thousand ";                            
        }
        
        if (all_digits[2] > 0)
        {
            ans += single_digit[all_digits[2]] + "Hundred ";                
        }
        if (all_digits[1] > 0)
        {
            if (all_digits[1]==1)
                ans += below_twenty[all_digits[0]];
            else
            {
                ans += digit_on_tens[all_digits[1]];
                ans += single_digit[all_digits[0]];
            }
        }
        else if (all_digits[0] != 0)
            ans += single_digit[all_digits[0]];
        ans.pop_back();
        return ans;
    }
};

