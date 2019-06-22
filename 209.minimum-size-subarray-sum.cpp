/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int ans = 0;
        int left = 0; int right = 0; int cur = 0;
        while(left <= right && right < nums.size())
        {
            // move right
            while(cur < s && right < nums.size())
            {
                cur += nums[right++];                
            }
            while(cur >= s && left <= right)
            {
                cur -= nums[left];
                if (cur < s)
                {
                    if (ans == 0)
                        ans = (right-left);
                    else
                        ans = min(ans, right-left);
                }
                left++;
            }
        }
        return ans;
    }
};

