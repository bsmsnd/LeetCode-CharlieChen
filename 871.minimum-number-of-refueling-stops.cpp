/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // map<int, long long> m;
        
        const int N = stations.size();
        int prev_pos = 0;

        long long m[502];                
        long long new_map[502];
        for (int i = 0;i <= N;++i)
            m[i] = new_map[i] = -1;
        m[0] = startFuel;

        for (int i = 0;i < N;++i)
        {            
            long long dist = stations[i][0] - prev_pos;
            prev_pos = stations[i][0];

            for (int j = 0;j <= i;++j)
                if (m[j] >= dist)
                {
                    //use this station
                    if (new_map[j+1] < m[j] - dist + stations[i][1])
                        new_map[j+1] = m[j] - dist + stations[i][1];
                    if (new_map[j] < m[j] - dist)
                        new_map[j] = m[j] - dist;
                }
            for (int j = 0;j <= i+1;++j)
            {
                m[j] = new_map[j];
                new_map[j] = -1;
            }

        }
        // target        
        int dist = target - prev_pos;
        for (int j = 0;j <= N;++j)
            if (m[j] >= dist)
            {
                // cout<<m[j];
                return j;
            }
                
        return -1;
    }
};

