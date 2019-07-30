/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
class MyCompare{
public:
    bool operator()(const vector<int>&a, const vector<int>&b) const
    {
        return a[2] > b[2];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, MyCompare> q;
        const int N = matrix[0].size();
        for (int i = 0;i < matrix.size();++i)
        {
            vector<int> new_vec = {i, 0, matrix[i][0]};
            q.push(new_vec);
        }
        for (int i = 0;i < k - 1;i++)
        {
            vector<int> cur_vec = q.top();
            // cout<<cur_vec[2]<<endl;
            q.pop();            
            if (cur_vec[1] < N - 1)
            {
                cur_vec[2] = matrix[cur_vec[0]][++cur_vec[1]];                
                q.push(cur_vec);
            }                
        }
        return q.top()[2];        
    }
};

