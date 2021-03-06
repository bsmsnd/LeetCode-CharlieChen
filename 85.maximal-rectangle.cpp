/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
class Solution {
public:
    int size;   
    int largestRectangleArea(int heights[]) {
        stack<int> s;  // save indices        
        int best_ans = 0;        
        int last;
        int cur_ans;
        if (size == 0)
            return 0;
        for (int i = 0;i < size;i++)
        {
            if (s.empty())
                s.push(i);
            else
            {
                if (heights[s.top()] <= heights[i])
                    s.push(i);
                else
                {                    
                    while(!s.empty() && heights[s.top()] > heights[i])
                    {
                        last = s.top();
                        s.pop();
                        cur_ans = heights[last] * (s.empty()? i : (i - s.top() - 1));
                        best_ans = max(best_ans, cur_ans);                                                
                    }                    
                    s.push(i);                    
                }
            }            
        }

        while(!s.empty())
        {
            last = s.top();
            s.pop();
            cur_ans = heights[last] * (s.empty()? size : (size - s.top() - 1));
            best_ans = max(best_ans, cur_ans);                        
        }
        return best_ans;          
    }  
       
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int n_rows = matrix.size();
        if (n_rows == 0)
            return 0;
        const int n_cols = matrix[0].size();
        if (n_cols == 0)
            return 0;
        int hist[n_cols];
        size = n_cols;
        for(int i = 0;i<n_cols;i++)
            hist[i] = 0;
        int best_ans = 0; 
        for (int i = 0 ; i < n_rows; i ++)
        {
            for (int j = 0 ; j < n_cols;j++)
                if (matrix[i][j] == '1')
                    hist[j]++;
                else
                    hist[j] = 0;
            int cur = largestRectangleArea(hist);
            // printf("%d %d %d %d %d\n", hist[0], hist[1], hist[2], hist[3], hist[4]);
            best_ans = max(best_ans, cur);            
        }
        return best_ans;
        
    }
};

