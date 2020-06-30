/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // graph
        bool in_queue[n][K+1];
        int dist[n][K+2];
        vector<vector<int>> edges;
        edges.resize(n);
        for(int i = 0;i < flights.size(); i++)
            edges[flights[i][0]].push_back(i);        
        
        memset(dist, -1, sizeof(dist));
        memset(in_queue,0,sizeof(in_queue));
        queue<int> q;

        dist[src][0] = 0;
        q.push(src);
        // in_queue[src] = true;        

        for (int i = 0; i < K+1; i++){
            int S = q.size();
            while(S--){
                int x = q.front();
                q.pop();
                // in_queue[x] = false;

                for (auto e: edges[x]){
                    int neighbor = flights[e][1];
                    if (dist[neighbor][i+1] == -1 || dist[x][i] + flights[e][2] < dist[neighbor][i+1]){
                        dist[neighbor][i+1] = dist[x][i] + flights[e][2];
                        if (!in_queue[neighbor][i]){
                            q.push(neighbor);
                            in_queue[neighbor][i] = true;
                        }
                    } // in_queue                    
                } // loop of edges
            } // loop of queue elements
        } // loop of K stops

        int ans = -1;
        for (int i = 0; i <= K+1; i++)
            if (dist[dst][i] != -1 && (ans == -1 || dist[dst][i] < ans))
                ans = dist[dst][i];
        return ans;
    }
};

// Bellman-Ford Algorithm
/*class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        K++;
        int dist[n][K+1];
        bool in_queue[n];

        memset(dist, -1, sizeof(dist));
        memset(in_queue, 0, sizeof(in_queue));

        dist[src][0] = 0;

        // graph
        vector<vector<int>> edges;
        edges.resize(n);
        for(int i = 0;i < flights.size(); i++)
            edges[flights[i][0]].push_back(i);
        
        // build the tree
        queue<int> q;
        q.push(src);
        in_queue[src] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            in_queue[x] = false;
            for (auto e: edges[x]){
                int neighbor = flights[e][1];
                bool update_flag = false;
                for (int i = 1; i <= K; i++)
                    if (dist[x][i-1] != -1)
                        if (dist[neighbor][i] == -1 || dist[x][i-1] + flights[e][2] < dist[neighbor][i]){
                            dist[neighbor][i] = dist[x][i-1] + flights[e][2];
                            update_flag = true;
                    }
                if (update_flag && !in_queue[neighbor]){
                    in_queue[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        int ans = -1;
        for (int i = 0;i <= K; i++)
            if (dist[dst][i] != -1)
                if (ans == -1 || ans > dist[dst][i])
                    ans = dist[dst][i];                            
        return ans;
    }
};*/
// @lc code=end

