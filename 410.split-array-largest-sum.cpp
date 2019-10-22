/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// #include <vector>
// #include <numeric>
// using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {        
        long long l = 0, r = 0;
        const int N = nums.size();        
        for (int i = 0;i < N; i++)
        {
            r+=nums[i];
            l = max(l, (long long)nums[i]);
        }
            
        
        while (l < r)
        {
            // cout<<l<<" "<<r<<endl;
            long long mid = (l + r) / 2;
            long long sum = 0;
            int cnt = 1;
            for (int i = 0;i < N; i++)            
                if (sum + nums[i] <= mid)
                    sum += nums[i];
                else
                {
                    sum = nums[i];
                    cnt++;
                    if (cnt > m)
                        break;
                }
            if (cnt > m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }            
        }
        return l;
    }
};

