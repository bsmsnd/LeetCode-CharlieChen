/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
bool cmp(vector<int>&a, vector<int>& b){
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)return 0;
        
        sort(points.begin(), points.end(), cmp);

        int left = points[0][0], right = points[0][1];
        // bool newShot = true;
        int ans = 1;

        const int N = points.size();
        for (int i = 1;i < N; i++){
            if (right < points[i][0] || points[i][1] < left){ // no intersection
                left = points[i][0];
                right = points[i][1];
                ans++;
            }
            else{
                left = max(left, points[i][0]);
                right = min(right, points[i][1]);
            }
        }
        return ans;
    }
};
// @lc code=end

