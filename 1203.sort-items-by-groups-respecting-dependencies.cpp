/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 */
#include <vector>

using namespace std;
class Solution {
public:
// group_as_node id = group + n
    vector<int> group_order;
    vector<vector<int>> G;
    // vector<vector<int>> G_g;
    vector<vector<int>> item_group;
    vector<int> visited;
    vector<int> parent;

    bool DFS_visit(int vertex, vector<int>& place_order)
    {
        visited[vertex] = 1;
        int n = G[vertex].size();
        for (int i = 0;i < n; i++)
            if (!visited[G[vertex][i]])
            {
                parent[G[vertex][i]] = vertex;
                if (DFS_visit(G[vertex][i], place_order) == false)
                    return false;
            }
            else // check loop
            {
                int p = parent[vertex];
                while(p!=-1)
                {
                    if (p == G[vertex][i])
                        return false;
                    p = parent[p];
                }
            }
        place_order.push_back(vertex);
        return true;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        G.resize(n+m+1);
        // G.resize(m);
        item_group.resize(m);

        for (int i = 0;i < n; i++)
        {
            int my_id = i;
            if (group[i] != -1)
            {
                my_id = group[i] + n;
            }
                
            for (int j = 0;j < beforeItems[i].size(); j++)
            {
                int item_id = beforeItems[i][j];
                if (group[item_id] == -1)
                {
                    G[my_id].push_back(item_id);
                }
                else if (group[item_id] == group[i])
                {
                    G[i].push_back(item_id);
                }
                else // group[item_id] != -1 && in different group
                {
                    G[my_id].push_back(group[item_id] + n);
                }
            }
        }

        visited.resize(n, false);

        parent.resize(n, -1);
        // level 1: in-group order
        for (int i = 0;i < n;i++)
            if (group[i] != -1 && !visited[i])
            {
                if (DFS_visit(i, item_group[group[i]]) == false)
                    return vector<int>(0);
            }
        
        // level 2: among-group order
        visited.resize(n+m, false);
        parent.resize(n+m, -1);
        for (int i = 0;i < n+m;i++)
        if ((i < n && group[i] == -1) || i >= n)
        if (!visited[i])
        {
            if (DFS_visit(i, group_order) == false)
                return vector<int>(0);
        }

        vector<int> ans;
        for (int i = 0;i < group_order.size(); i++)
        if (group_order[i] >= n)
        {
            for (int j = 0;j < item_group[group_order[i] - n].size(); j++)
                ans.push_back(item_group[group_order[i] - n][j]);
        }
        else
            ans.push_back(group_order[i]);

        return ans;
    }
};

