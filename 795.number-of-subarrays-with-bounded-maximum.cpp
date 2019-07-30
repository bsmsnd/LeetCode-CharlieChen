/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        int premature = 0;
        int mature = 0;
        const int N = A.size();
        for (int i = 0;i < N;++i)
        {
            if (A[i] < L)
            {
                premature++;
                ans += mature;
            }
                
            else if (A[i] <= R)
            {
                mature+= 1 + premature;
                premature = 0;
                ans += mature;
            }
            else
            {
                premature = mature = 0;
            }            
        }
        return ans;
    }
};

