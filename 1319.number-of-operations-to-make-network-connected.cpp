/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
public:
    // int p[MAX_N];
    int find(int x, int *p){return x == p[x] ? x : p[x]=find(p[x], p); }
    int makeConnected(int n, vector<vector<int>>& connections) {
        const int E = connections.size();
        if (E < n-1)return -1;
        
        int p[n];
        // vector<int> p(n);
        for (int i = 0; i < n; i++)
            p[i]=i;
        // int find = [](int x){return x == p[x] ? x : p[x]=find(p[x]); };
        
        int redundent = 0;
        int blocks = n;

        
        int p1, p2;
        for (int i = 0;i < E;i++){
            p1 = find(connections[i][0], p);
            p2 = find(connections[i][1], p);
            if (p1 == p2)
                redundent++;
            else{
                p[p1] = p2;
                blocks--;
            }
        }        
        
        if (blocks > 1){
            if (blocks - 1 > redundent)
                return -1;
            else
                return blocks - 1;
        }
        else
            return 0;
    }
};
// @lc code=end

