/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        // BFS
        int N = routes.size();
        unordered_map<int, vector<pair<int, int> > > m;

        for (int i = 0; i < N; i++)
        {
            int n = routes[i].size();
            for (int j = 0;j < n; j++)
            {
                if (m.find(routes[i][j]) == m.end())
                    m[routes[i][j]] = vector<pair<int, vector<int>::iterator> >();
                m[routes[i][j]].push_back({i, j});
            }
        }

    }
};
// @lc code=end

