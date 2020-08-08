/*
 * @lc app=leetcode id=1136 lang=cpp
 *
 * [1136] Parallel Courses
 */

// @lc code=start
class Solution {
public:
    int DFS(int node){
        // cout << node << endl;
        visited[node] = true;        

        int curOrder = 0, x;
        for (int child : G[node]){
            if (!visited[child]){
                parent[child] = node;                
                x = DFS(child);
                if (-1 == x)
                    return -1;
                else
                    curOrder = max(x + 1, curOrder);
                // order[G[node]]
            }
            else{
                int p = parent[node];
                while(p!=-1)
                    if (p == child)
                        return -1; // loop!
                    else
                        p = parent[p];
                curOrder = max(curOrder, order[child] + 1);
            }
        }
        // printf("%d : %d\n", node, curOrder);
        return order[node] = curOrder;
    }

    int minimumSemesters(int N, vector<vector<int>>& relations) {
        G.resize(N);
        visited.resize(N, false);
        parent.resize(N, -1);
        order.resize(N, 0);
        
        const int E = relations.size();
        for (int i = 0; i < E; i++)
            G[relations[i][0] - 1].push_back(relations[i][1] - 1);

        for (int i = 0; i < N; i++)
            if (!visited[i])
                if (-1 == DFS(i))
                    return -1;
        
        return *max_element(order.begin(), order.end()) + 1;
                
    }

private:
    vector<vector<int>> G;
    // vector<int> visited;
    vector<int> parent;
    vector<int> level;
    vector<int> order;
};
// @lc code=end

