/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum = 0;
        const int N = nums.size();
        int ans = 0;
        for (int i = 0;i < N; ++i)
        {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                ans += m[sum - k];            
            if (m.find(sum) == m.end())
                m[sum] = 0;
            m[sum]++;
        }
        return ans;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        int presum[N][M] = {};    
        for (int i = 0;i < N; ++i)
        {
            presum[i][0] = matrix[i][0];
            for (int j = 1;j < M; ++j)
                presum[i][j] = presum[i][j-1] + matrix[i][j];
        }
        int ans = 0;
        vector<int> cur;
        for (int j = 0;j < M; ++j)
        {
            cur.clear();
            for (int i = 0;i < N; ++i)
                cur.push_back(presum[i][j]);
            ans += subarraySum(cur, target);
        }
        for (int i = 0;i < M-1; ++i)
        for (int j = i+1; j < M;++j)
        {
            cur.clear();
            for (int k = 0;k < N; ++k)
                cur.push_back(presum[k][j] - presum[k][i]);
            ans += subarraySum(cur, target);
        }
        return ans;
    }
};

