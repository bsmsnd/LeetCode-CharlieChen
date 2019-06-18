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
        const int K = num.size();
        const int maintain = K - k;      
        if (maintain <= 0)
        {
            ans = "0";
            return ans;
        }  
        for (int i = 0 ; i < K; i++)
        {
            while(skip < k && ans.length() > 0 && ans.back() > num[i])
            {
                ans.pop_back();
                skip++;
            }
            if (ans.length() < maintain)
                ans.push_back(num[i]);  
            else
                skip++;          
        }
        // strip all zeros
        while(ans.length() > 0 && ans[0] == '0')
        {
            // cout<<ans[0]<<endl;
            ans.erase(0, 1);
            // cout<<ans<<endl;
        }
            
        if (ans.length() == 0)
            ans = "0";

        return ans;
    }
};

