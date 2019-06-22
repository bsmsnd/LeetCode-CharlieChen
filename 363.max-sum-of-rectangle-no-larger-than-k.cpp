/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int ans = INT_MIN;
        const int R = matrix.size();
        const int C = matrix[0].size();
        for (int l = 0;l < C; ++l)
        {
            vector<int> sums(R);
            for (int r = l;r < C; ++r)
            {
                set<int> s;
                s.insert(0);
                int curSum = 0;
                for (int m = 0;m < R;++m)
                {
                    sums[m] += matrix[m][r];
                    curSum += sums[m];
                    auto it = s.lower_bound(curSum - k);
                    if (it!=s.end())
                    {
                        ans = max(ans, curSum - *it);
                        if (ans == k)
                            return ans;
                    }
                    s.insert(curSum);                    
                }
            }
        }
        return ans;                
    }
};

