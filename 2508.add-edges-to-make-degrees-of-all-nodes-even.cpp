/*
 * @lc app=leetcode id=2508 lang=cpp
 *
 * [2508] Add Edges to Make Degrees of All Nodes Even
 */

// @lc code=start
// #define DEBUG_ON_LOCAL_MACHINE
#ifdef DEBUG_ON_LOCAL_MACHINE
#include "helper.h"
#endif

class Solution {
public:
    // O(N) search!
    bool IsDirectlyConnected(uint32_t i, uint32_t j, vector<vector<int>>& edges)
    {
        for (auto& edge : edges) {
            if ((edge[0] == i && edge[1] == j) || (edge[0] == j && edge[1] == i)) {
                return true;
            }
        }
        return false;
    }

    bool IsRelayNodeExist(uint32_t i, uint32_t j, int n, vector<vector<int>>& edges)
    {
        vector<bool> connectedToI(n, false);
        vector<bool> connectedToJ(n, false);
        for (auto& edge : edges) {
            if (edge[0] == i) {
                connectedToI[edge[1]] = true;
            }
            if (edge[1] == i) {
                connectedToI[edge[0]] = true;
            }
            if (edge[0] == j) {
                connectedToJ[edge[1]] = true;
            }
            if (edge[1] == j) {
                connectedToJ[edge[0]] = true;
            }
        }
        for (uint32_t k = 0; k < n; k++) {
            if (k != i && k != j && !connectedToI[k] && !connectedToJ[k]) {
                return true;
            }
        }
        return false;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        int degrees[n];
        memset(degrees, 0, sizeof(degrees));
        for (auto& edge : edges) {
            // make the graph 0-indexed
            edge[0]--;
            edge[1]--;
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        vector<uint32_t> oddDegreeNodes;
        for (uint32_t i = 0; i < n; i++) {
            if (degrees[i] % 2 != 0) {
                oddDegreeNodes.push_back(i);
            }
        }

        switch (oddDegreeNodes.size()) {
            case 0:
                return true;
            case 2:
                // Scenario #1: node[0] & node[1] are not directly connected, simply add a edge between them.
                if (!IsDirectlyConnected(oddDegreeNodes[0], oddDegreeNodes[1], edges)) {
                    return true;
                }
                // Scenario #2: node[0] & node[1] are directly connected, in this case we will have to find a relay node that is not connected to either of node[0] or node[1].
                return IsRelayNodeExist(oddDegreeNodes[0], oddDegreeNodes[1], n, edges);
            case 4:
                /** We will have to find two pairs of nodes that are not directly connected.
                 * There are 3 choices:
                 * 1) (0,1), (2,3)
                 * 2) (0,2), (1,3)
                 * 3) (0,3), (1,2)
                **/
                return ((!IsDirectlyConnected(oddDegreeNodes[0], oddDegreeNodes[1], edges) && !IsDirectlyConnected(oddDegreeNodes[2], oddDegreeNodes[3], edges)) || (!IsDirectlyConnected(oddDegreeNodes[0], oddDegreeNodes[2], edges) && !IsDirectlyConnected(oddDegreeNodes[1], oddDegreeNodes[3], edges)) || (!IsDirectlyConnected(oddDegreeNodes[0], oddDegreeNodes[3], edges) && !IsDirectlyConnected(oddDegreeNodes[1], oddDegreeNodes[2], edges)));
            default:
                return false;
        }
    }
};
// @lc code=end

