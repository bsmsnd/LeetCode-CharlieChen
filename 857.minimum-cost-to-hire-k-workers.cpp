/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */
vector<double> unitCost;
bool cmp(int a, int b)
{
    return unitCost[a]  <= unitCost[b];
}

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        const int N = quality.size();        
        unitCost.resize(N);
        int order[N];
        for (int i = 0;i < N ; i++)
        {
            unitCost[i] = (double)(wage[i]) / quality[i];
            order[i] = i;
        }
                            
        sort(order, order+N, cmp);
        
        priority_queue<int> qu;
        double ans;
        int acc_quality = 0;
        for (int i = 0;i < K;i++)
        {
            qu.push(quality[order[i]]);
            acc_quality += quality[order[i]];
        }
        // cout<<unitCost[order[K-1]]<<" "<<acc_quality<<endl;
        ans = unitCost[order[K-1]] * acc_quality;
        
        for (int i = K; i<N;i++)
        if (quality[order[i]] < qu.top())
        {
            acc_quality -= qu.top();            
            qu.pop();
            acc_quality += quality[order[i]];
            qu.push(quality[order[i]]);
            // cout<<unitCost[order[i]]<<" "<<acc_quality<<endl;
            ans = min(ans, unitCost[order[i]] * acc_quality);
        }
        return ans;
    }
};

