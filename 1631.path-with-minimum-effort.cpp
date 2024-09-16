/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
#define LEETCODE_DEBUG
#ifdef LEETCODE_DEBUG
#include "helper.h"
#include <_types/_uint32_t.h>
#endif

struct Point {
    int x;
    int y;
    Point(int ix = 0, int iy = 0) : x(ix), y(iy) {};
};
inline bool operator<(const Point &lhs, const Point &rhs) 
{
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

inline bool operator==(const Point &lhs, const Point &rhs) 
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

inline bool operator!=(const Point &lhs, const Point &rhs) 
{
    return !(lhs == rhs);
}

struct Edge {
    Point a;
    Point b;
    int heightDiff;
    Edge(int x1, int y1, int x2, int y2, int inputHeightDiff) : a(x1, y1), b(x2, y2), heightDiff(inputHeightDiff) {};
};

inline bool operator<(const Edge &lhs, const Edge &rhs) 
{
    return (lhs.heightDiff < rhs.heightDiff) || 
        (lhs.heightDiff == rhs.heightDiff && lhs.a < rhs.a) ||
        (lhs.heightDiff == rhs.heightDiff && lhs.a == rhs.a && lhs.b < rhs.b);
}

class Solution {
public:
    void ReadMap(const vector<vector<int> > &heights, vector<Edge> edges, uint32_t N, uint32_t M) {
        for (uint32_t i = 0; i < N; i++) {
            for (uint32_t j = 0; j < M; j++) {
                if (i + 1 < N) {
                    edges.push_back(Edge(i, j, i+1, j, 
                        heights[i][j] > heights[i+1][j] ? heights[i][j] - heights[i+1][j] : heights[i+1][j] - heights[i][j]));
                }
                if (j + 1 < M) {
                    edges.push_back(Edge(i, j, i, j+1, heights[i][j] > heights[i][j+1] ? heights[i][j] - heights[i][j+1] : heights[i][j+1] - heights[i][j]));
                }
            }
        }
    }

    Point find(const Point &x, vector<vector<Point> > parents) 
    {
        return parents[x.x][x.y] == x ? x : (parents[x.x][x.y] = find(parents[x.x][x.y], parents));
    }

    int minimumEffortPath(vector<vector<int> > &heights) {
        vector<Edge> edges;
        const uint32_t N = heights.size();
        if (N == 0) {
            return 0;
        }
        const uint32_t M = heights[0].size();
        if (M == 0) {
            return 0;
        }
        ReadMap(heights, edges, N, M);
        sort(edges.begin(), edges.end());
        vector<vector<Point> > parents(N, vector<Point>(M));
        for (uint32_t i = 0; i < N; i ++) {
            for (uint32_t j = 0; j < M; j++) {
                parents[i][j] = Point(i, j);
            }
        }
        auto findInScope = [&parents, this](const Point &x) -> Point {
            return this->find(x, parents);
        };

        auto stopCondition = [&parents, &N, &M, this]() -> bool {
            Point parentA = this->find(Point(N-1, M-1), parents); 
            Point parentB = this->find(Point(0, 0), parents); 
            return parentA == parentB;
        };

        for (const Edge &edge: edges) {
            Point parentA = findInScope(edge.a);
            Point parentB = findInScope(edge.b);
            if (parentA != parentB) {
                parents[parentB.x][parentB.y] = parentB;
            }
            if (stopCondition()) {
                return edge.heightDiff;
            }
        }
        return -1;
    }
};

#ifdef LEETCODE_DEBUG
int main()
{
    vector<vector<int> > matrix = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    Solution sol;
    cout << sol.minimumEffortPath(matrix) << endl;
}
#endif
// @lc code=end

