/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        int through[N][N];
        memset(through, 0, sizeof(through));

        const int E = edges.size();
        // vector<vector<int>> adj;
        vector<vector<int>> edge_idx;
        // adj.resize(N);
        edge_idx.resize(N);
        
        int steps[N];
        memset(steps, -1, sizeof(steps));
        steps[0] = M;

        bool in_queue[N];
        memset(in_queue, 0, sizeof(in_queue));

        for (int i = 0;i < E; i++){
            // adj[edges[i][0]].push_back(edges[i][1]);
            // adj[edges[i][1]].push_back(edges[i][0]);            
            edge_idx[edges[i][0]].push_back(i);
            edge_idx[edges[i][1]].push_back(i);

        }

        queue<int> q; // node, remaining steps
        // q.push(make_pair(0, M));
        q.push(0);
        in_queue[0] = true;

        while(!q.empty()){
            int curNode = q.front();
            int remainingSteps = steps[curNode];            
            q.pop();
            in_queue[curNode] = false;
            for (auto e : edge_idx[curNode]){
                int neighbor = edges[e][0] == curNode ? edges[e][1] : edges[e][0];
                int weights = edges[e][2];
                if (weights >= remainingSteps){
                    through[curNode][neighbor] = remainingSteps;
                }
                else{
                    through[curNode][neighbor] = weights;
                    if (steps[neighbor] < remainingSteps - weights - 1 ){ // -1 because it takes one more step to reach the regular node
                        steps[neighbor] = remainingSteps - weights - 1;
                        if (!in_queue[neighbor] && steps[neighbor] > 0){
                            q.push(neighbor);
                            in_queue[neighbor] = true;
                        }
                    }
                }                        
            }
        }

        int ans = 0;
        for (int i = 0;i < E; i++){
            int x = edges[i][0], y = edges[i][1], w = edges[i][2];
            if (through[x][y] + through[y][x] >= w)
                ans += w;            
            else
                ans += through[x][y] + through[y][x];            
        }
        for (int i = 0; i < N; i++)
            if (steps[i] > -1)
                ans++;

        return ans;

    }
};

