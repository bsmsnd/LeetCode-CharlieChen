/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

class Solution {
public:
    vector<string> ans;
    map<string,set<string>> G;    
    map<string,map<string, int>> remain_visits;
    int N;
    bool DFS_visit(string from, int stop_cnt)
    {
        for (auto cur_level: G[from])
        if (remain_visits[from][cur_level] > 0)
        {
            // forward 
            remain_visits[from][cur_level]--;
            ans.push_back(cur_level);
            if (stop_cnt == N - 1)
                return true;
            else
                if (DFS_visit(cur_level, stop_cnt+1))
                    return true;
                else
                {
                    // backward
                    remain_visits[from][cur_level]++;
                    ans.pop_back();
                }                
        }
        // did not find a solution
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const int E = tickets.size();        
        N = E + 1; // number of stops
        for (int i = 0; i < E;i++)
            if ( G.find(tickets[i][0]) == G.end() )
            {
                // not  found
                G[tickets[i][0]] = set<string> {};
                G[tickets[i][0]].insert(tickets[i][1]);

                remain_visits[tickets[i][0]] = map<string, int>{};
                remain_visits[tickets[i][0]][tickets[i][1]] = 1;
            }
            else
            {
                auto it = G[tickets[i][0]].find(tickets[i][1]);
                if (it != G[tickets[i][0]].end())  // duplicate element!
                    remain_visits[tickets[i][0]][tickets[i][1]]++;
                else
                {
                    G[tickets[i][0]].insert(tickets[i][1]);
                    remain_visits[tickets[i][0]][tickets[i][1]] = 1;
                }
                
            }
        ans.push_back("JFK");
        DFS_visit("JFK", 1);
        return ans; 
    }
};

