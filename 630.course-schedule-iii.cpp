/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
bool cmp(vector<int>& a, vector<int>& b){
    return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);

        priority_queue<int> selectedCourses;
        const int N = courses.size();
        int allTime = 0;
        for (int i = 0;i < N; i++){
            if (allTime + courses[i][0] <= courses[i][1]){
                selectedCourses.push(courses[i][0]);
                allTime += courses[i][0];
            }
            else if (!selectedCourses.empty() && selectedCourses.top() > courses[i][0] && allTime - selectedCourses.top() + courses[i][0] <= courses[i][1]){
                allTime = allTime - selectedCourses.top() + courses[i][0];
                selectedCourses.pop();
                selectedCourses.push(courses[i][0]);                
            }
        }
        return selectedCourses.size();
    }
};
// @lc code=end

