/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

double perQualityWage[10001];
bool cmp(int a, int b)
{
    return perQualityWage[a] < perQualityWage[b];
}


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        const int N = quality.size();
        
        int idx[N];
        for (int i = 0;i < N; i++)
        {
            perQualityWage[i] = (double)(wage[i]) / quality[i];
            idx[i] = i;
        }

        sort(idx, idx+N, cmp);
        priority_queue<int> q;
        int tot_quality = 0;
        for (int i = 0;i < K; i++) // get first K
        {
            q.push(quality[idx[i]]);
            tot_quality += quality[idx[i]];
        }        
        double best_ans = tot_quality * perQualityWage[idx[K-1]];

        for (int i = K; i < N; i++) // see others with higher per quality wage, min. quality
        if (q.top() > quality[idx[i]])
        {            
            tot_quality -= q.top();
            tot_quality += quality[idx[i]];
            q.pop();
            q.push(quality[idx[i]]);
            best_ans = min(best_ans, tot_quality * perQualityWage[idx[i]]);
        }
        return best_ans;        
    }
};

