/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    map<string,vector<string>> G;  // TODO: should choose a different data struct to obtain keys
    map<string, vector<double>> G_values;
    vector<double> ans;
    map<string, bool> visited;

    double DFS_visit(string a, string b)
    {
        double rec;
        for (int i = 0;i < G[a].size();i++)
        if (!visited[G[a][i]])
        {
            visited[G[a][i]] = true;
            if (G[a][i] == b)
                return G_values[a][i];
            else
                {
                    rec = DFS_visit(G[a][i], b);
                    if (rec > 0)
                        return rec * G_values[a][i];
                }                  
            // using DFS so will not go backward if not found          
        }
        return -1; // indicate not found
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int E =  equations.size();
        for (int i = 0; i < E; ++i)
        {
            if (G.find(equations[i][0]) == G.end()) // not found
            {
                G[equations[i][0]] = vector<string>();
                G_values[equations[i][0]] = vector<double>();
                
                visited[equations[i][0]] = false;
            }
            G[equations[i][0]].push_back(equations[i][1]);
            G_values[equations[i][0]].push_back(values[i]);

            if (G.find(equations[i][1]) == G.end()) // not found
            {
                G[equations[i][1]] = vector<string>();
                G_values[equations[i][1]] = vector<double>();
                
                visited[equations[i][1]] = false;
            }
            G[equations[i][1]].push_back(equations[i][0]);
            G_values[equations[i][1]].push_back(1/values[i]);
        }

        const int Q = queries.size();
        for (int i = 0; i < Q; ++i)
        {
            if (G.find(queries[i][0]) == G.end() || G.find(queries[i][1]) == G.end()) // one of the vars. is not found
                ans.push_back(-1.0);
            else
            {
                for (auto it = visited.begin(); it != visited.end(); ++it)
                    it->second = false;
                if (queries[i][0] == queries[i][1])
                    ans.push_back(1.0);
                else
                    ans.push_back(DFS_visit(queries[i][0], queries[i][1]));
            }
                
        }
        return ans;
    }
};

