/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <vector>
#include <string> 
using namespace std;

vector<string> numberMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<int> len = {0,0,3,3,3,3,3,4,3,4};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)return ans;
        int tot = 1;
        for (char digit: digits)
            tot *= len[digit-'0'];
        for (int i = 0;i < tot; i++){
            int tmp = i; string thisString = "";
            for (char digit: digits){
                int base = len[digit-'0'];
                char t = numberMap[digit-'0'][tmp % base];
                thisString += t;
                tmp /= base;
            }
            ans.push_back(thisString);
        }
        return ans;
        
    }
};
// @lc code=end

