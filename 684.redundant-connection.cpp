/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

class Solution {
public:
    vector<int> p;  // Disjoint-set

    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int V = edges.size();
        const int E = V;
        for (int i = 0; i < V+1; ++i)
            p.push_back(i);            
        for (int i = 0; i < E; ++i)
        {
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if (x!=y)
                p[x] = y;
            else
                return edges[i];
        }
        return edges.back();
    }
};

