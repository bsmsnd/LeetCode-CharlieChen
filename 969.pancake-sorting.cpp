/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */
#include <vector>
using namespace std;

class Solution {
public:
    int pos[101];
    void flip(int k, vector<int>& A)
    {
        vector<int> tmp = A;
        for(int i = 0;i < k;++i)
        {
            A[i] = tmp[k - i - 1];
            pos[A[i]] = i;
        }
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        const int N = A.size();
        for (int i = 0;i < N;++i)
            pos[A[i]] = i;
        for (int i = N;i>0;--i)
        if (pos[i] != i-1)        
        {
            if (pos[i] != 0)
            {
                ans.push_back(pos[i]);
                flip(pos[i], A);                
            }
            ans.push_back(i);
            flip(i, A);                            
        }
        return ans;
    }
};

