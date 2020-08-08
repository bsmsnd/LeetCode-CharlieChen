/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 */

// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        x1 -= x_center;x2 -= x_center;y1 -= y_center;y2 -= y_center;
        int x1s = x1 * x2 <= 0 ? 0 : min(x1*x1, x2*x2);
        int y1s = y1 * y2 <= 0 ? 0 : min(y1*y1, y2*y2);
        return x1s + y1s <= radius * radius;
    }
};
// @lc code=end

