/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> G;
    vector<int> parent;

    bool DFS_visit(int vertex)
    {
        visited[vertex] = true;
        if (G[vertex].size() > 0)
            for (int j = 0; j < G[vertex].size(); j++)
            if (!visited[G[vertex][j]])
                {
                    parent[G[vertex][j]] = vertex;
                    if (DFS_visit(G[vertex][j]) == false)
                        return false;
                }
            else  // has visited G[vertex][j]: check if there is a back 
            {
                // enumerate all parents of vertex to see if G[vertex][j] is the ancestor
                int p = parent[vertex];                
                while(p!=-1)
                {
                    if (p == G[vertex][j])
                        return false;
                    p = parent[p];
                }          
            }
            
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int V = numCourses;
        const int E = prerequisites.size();        
        // init graph 
        visited.resize(V,false);
        G.resize(V, vector<int>(0));
        parent.resize(numCourses, -1);

        // need to build the graph first
        for (int i = 0; i < E;i++)
        {
            G[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // DFS
        for (int i = 0; i < V;i++)
        if (!visited[i])
        {
            if (DFS_visit(i) == false)
                return false;
        }
        return true;
    }
};

