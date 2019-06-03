/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;  // save indices        
        int best_ans = 0;
        int size = heights.size();
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
};

