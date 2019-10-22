/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // unordered_map<int, int> parent;
    int parent[1001];
    int find(int x)
    {
        return parent[x] == -1 ? x : parent[x] = find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {   
        memset(parent, -1, sizeof(parent));     
        int E = edges.size();
        for (int i = 0;i < E; i++)
        {
            if (edges[i][0] > edges[i][1]) swap(edges[i][0], edges[i][1]);
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if (x == y)
                return edges[i];
            else
            parent[y] = x;
        }
        return edges.back();
    }
};

