/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<unordered_set<int>> G;
    // vector<int> parent;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        const int V = n;
        const int E = edges.size();        
        // init graph 
        visited.resize(V,false);
        G.resize(V, unordered_set<int>{} );
        // parent.resize(V, -1);

        // build the graph (undirected)
        for (int i = 0; i < E;i++)
        {
            G[edges[i][0]].insert(edges[i][1]);
            G[edges[i][1]].insert(edges[i][0]);
        }

        int left_nodes = n;

        if (n > 2)
        {
            queue<int> q;
            int  cur_node;
            for (int i = 0;i < V;i++)
                if (G[i].size() == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                    left_nodes--;
                }
            // travse the graph to locate all leaves
            while(left_nodes > 2)
            {
                int S = q.size();
                for (int i = 0 ; i < S;i++)
                {
                    cur_node = q.front();
                    q.pop();
                    for (auto j: G[cur_node])
                    {
                        G[j].erase(cur_node);
                        if (G[j].size() == 1)
                        {
                            visited[j] = true;
                            q.push(j);
                            left_nodes--;
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0;i < V;i++)
            if (!visited[i])
                ans.push_back(i);
        return ans;
    }
};

