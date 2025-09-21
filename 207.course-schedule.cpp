/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> numOfPrerequisites(numCourses);
        vector<list<int>> prerequisiteGraph(numCourses);
        for (const vector<int>& prerequisite : prerequisites) {
            prerequisiteGraph[prerequisite[1]].push_back(prerequisite[0]);
            numOfPrerequisites[prerequisite[0]]++;
        }
        queue<int> courses;
        for (int i = 0; i < numCourses; i++) {
            if (numOfPrerequisites[i] == 0) {
                courses.push(i);
            }
        }

        while (!courses.empty()) {
            int course = courses.front();
            courses.pop();
            numCourses--;
            for (int nextCourse : prerequisiteGraph[course]) {
                numOfPrerequisites[nextCourse]--;
                if (numOfPrerequisites[nextCourse] == 0) {
                    courses.push(nextCourse);
                }
            }
        }
        return (numCourses == 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

