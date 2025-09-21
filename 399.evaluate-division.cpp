/*
 * @lc app=leetcode.cn id=399 lang=cpp
 * @lcpr version=30204
 *
 * [399] 除法求值
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    pair<string, double> Find(const string& var)
    {
        if (parents[var].first != var) {
            pair<string, double> parentInfo = Find(parents[var].first);
            parents[var] = {parentInfo.first, parentInfo.second * parents[var].second};
        }
        return parents[var];
    }

    void Union(const string& leftVar, const string& rightVar, double value)
    {
        pair<string, double> parentLeftInfo = Find(parents[leftVar].first);
        pair<string, double> parentRightInfo = Find(parents[rightVar].first);
        parents[parentLeftInfo.first] = {parentRightInfo.first, parentRightInfo.second * value / parentLeftInfo.second};
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nEquations = equations.size();
        for (int i = 0; i < nEquations; i++) {
            if (parents.find(equations[i][0]) == parents.end()) {
                parents[equations[i][0]] = {equations[i][0], 1.0};
            }
            if (parents.find(equations[i][1]) == parents.end()) {
                parents[equations[i][1]] = {equations[i][1], 1.0};
            }
            Union(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> answer;
        for (const vector<std::string> &query: queries) {
            string leftVar = query[0];
            string rightVar = query[1];
            if (parents.find(leftVar) == parents.end()) {
                answer.push_back(leftVar == rightVar ? 1.0 : -1.0);
            }
            pair<string, double> parentLeftInfo = Find(parents[leftVar].first);
            pair<string, double> parentRightInfo = Find(parents[rightVar].first);
            answer.push_back(parentLeftInfo.first == parentRightInfo.first ?
                parentLeftInfo.second / parentRightInfo.second : -1.0);
        }
        return answer;
    }
    unordered_map<string, pair<string, double>> parents;
};
// @lc code=end



/*
// @lcpr case=start
// [["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
// @lcpr case=end

 */

