/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
    int addStop(int state, int newStop){
        return state | (1<<newStop);
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        // curStop, state
        queue<pair<int,int>> q;
        const int N = graph.size();
        if (N < 2)return 0;

        const int completeState = pow(2, N) - 1;
        bool allStates[N][completeState];
        memset(allStates, 0, sizeof(allStates));

        for (int i = 0;i < N; i++){
            q.push(make_pair(i, addStop(0, i)));
            // cout << i << " " << addStop(0,i) << endl;
        }
        
        int steps = 1;
        while(!q.empty()){
            int S = q.size();
            while(S--){
                int curStop = q.front().first;
                int state = q.front().second;
                q.pop();
                for (auto nextStop : graph[curStop]){
                    int newState = addStop(state, nextStop);
                    if (newState == completeState)
                        return steps;
                    else if (!allStates[nextStop][newState]){                        
                        allStates[nextStop][newState] = true;
                        q.push(make_pair(nextStop, newState));
                        // printf("%d %d\n", nextStop, newState);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
// @lc code=end

