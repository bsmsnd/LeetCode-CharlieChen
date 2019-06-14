/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */
#include <string>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int skip = 0;        
        const int K = nums.size();
        const int maintain = K - k;        
        for (int i = 0 ; i < K-1; i++)
        {
            if (ans.length() < maintain)  // need more to be pushed
            {
                while(skip < k && ans.back() > num[i])
                {
                    ans.pop_back();
                    skip++;
                }
                ans.push_back(num[i]);                    
            }
            else
            {

            }
            
        }
    }
};

