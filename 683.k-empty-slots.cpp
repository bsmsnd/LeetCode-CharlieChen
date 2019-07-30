/*
 * @lc app=leetcode id=683 lang=cpp
 *
 * [683] K Empty Slots
 */
class Solution {
public:
    // O(N lg(N)) solution
    // int kEmptySlots(vector<int>& bulbs, int K) {
    //     set<int> s;        
    //     const int N = bulbs.size();        
    //     if (bulbs.size() < K+2)return -1;
        
    //     int day[N+1];
    //     for (int i = 0;i < N;++i)
    //         day[bulbs[i]] = i+1;
        
    //     int ans = 20001;
    //     if (K == 0)
    //     {
    //         for (int i = 1;i <= N - 1; ++i)
    //             ans = min(ans, max(day[i], day[i+1]));
    //         return ans;
    //     }

    //     for (int i = 2; i <= 1 + K; ++i)
    //         s.insert(day[i]);        
        
    //     for (int i = 1;i <= N - K - 1;i++)
    //     {
    //         if (*s.begin() > day[i] && *s.begin() > day[i+K+1])
    //             ans = min(ans, max(day[i], day[i+K+1]));
    //         s.erase(s.find(day[i+1]));
    //         s.insert(day[i+K+1]);            
    //     }
    //     return ans == 20001 ? -1 : ans;
    // }
    // Sliding window solution O(N)
    int kEmptySlots(vector<int>& bulbs, int K) {
        const int N = bulbs.size();
        int day[N+1];
        for (int i = 0;i < N;++i) day[bulbs[i] - 1] = i+1;
        int left = 0; int right = K + 1;
        int ans = 20001;
        for (int i = 1;right < N; ++i)
        {
            if (i == right)
            {
                ans = min(ans, max(day[left], day[right]));
                left = i;
                right = i + K + 1;
            }   
            else if (day[i] < day[left] || day[i] < day[right])
            {
                left = i;
                right = i + K + 1;
            }
        }               
        return ans == 20001 ? -1 : ans;
    }
};

