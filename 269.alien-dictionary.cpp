/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */
#include <iostream>
#include <string> 
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_map<char, unordered_set<char>> m;
    unordered_map<char, char> parent;
    unordered_map<char, bool> visited;
    string ans;
    bool failure = false;
    void addRule(string a, string b) // a < b
    {
        int k = min(a.length(), b.length());
        for (int i = 0;i < k;i++)
        if (a[i] != b[i])
        {
            // add rule: b[i] --> a[i]
            
            // first check if not a[i] --> b[i]
            if (m.find(a[i]) != m.end() && m[a[i]].find(b[i]) != m[a[i]].end())
            {
                cout<<"conflict!"<<endl;
                failure = true;
                return;
            }

            if (m.find(b[i]) == m.end())
                m[b[i]] = unordered_set<char>();
            if(m[b[i]].find(a[i]) == m[b[i]].end())
                m[b[i]].insert(a[i]);
            return;
        }            
    }

    bool DFS_visit(char vertex)
    {
        visited[vertex] = true;
        if(m.find(vertex) != m.end())
        {
            for (auto& m : m[vertex])
            {
                if (!visited[m])
                {
                    parent[m] = vertex;
                    if (!DFS_visit(m))
                        return false;
                }
                else
                {
                    char p = parent[vertex];
                    while(p!=-1)
                    {
                        if (p == m)
                            return false;
                        p = parent[p];
                    }               
                }                
            }
        }    
        ans+=vertex;
        return true;
    }


    string alienOrder(vector<string>& words) {
        m.clear();                
        // step 1: build graph
        int N = words.size();
        for (int i = 0;i < N-1;i++)
            for (int j = i+1; j < N; j++)
            {
                addRule(words[i], words[j]);
                if(failure)
                    return "";
            }
        
        for (int i = 0;i < N; i++)
            for (int j = 0;j < words[i].size(); j++)
                if (parent.find(words[i][j]) == parent.end())
                {
                    parent[words[i][j]] = -1;
                    visited[words[i][j]] = false;
                }
                    
        
        // step 2: topological sort
        for (auto it = parent.begin(); it != parent.end(); it++)
        {
            char cur = it->first;
            if (!visited[cur])
            {
                if (!DFS_visit(cur))return "";                
            }
        }
        return ans;                                
    }
};

