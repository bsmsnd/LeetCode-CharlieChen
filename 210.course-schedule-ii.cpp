/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<vector<int>> G;
    vector<bool> visited;
    vector<int> ans;
    bool DFS(int vertex)
    {
        visited[vertex] = true;
        int n = G[vertex].size();
        for (int i = 0;i < n; i++)
        {
            int pre = G[vertex][i];
            if (!visited[pre])
            {
                parent[pre] = vertex;
                if (!DFS(pre))
                    return false;                
            }
            else
            {
                int p = parent[vertex];
                while (p != -1)
                {
                    if (p == pre)
                        return false;
                    p = parent[p];
                }
            }
        }
        ans.push_back(vertex);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {     
        G.resize(numCourses);
        int n = prerequisites.size();
        for (int i = 0;i < n; i++)
            G[prerequisites[i][0]].push_back(prerequisites[i][1]);
        visited.resize(numCourses);
        parent.resize(numCourses, -1);
        ans.reserve(numCourses);

        for (int i = 0;i < numCourses; i++)
            if (!visited[i])
                if (!DFS(i))
                    return vector<int>();
        return ans;   
    }
};

