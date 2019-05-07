/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#define max(a,b)(((a) > (b)) ? (a) : (b))
#define min(a,b)(((a) < (b)) ? (a) : (b))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right, small_h;
        left = 0;
        right = height.size() - 1;
        int best_sol = 0;
        do
        {
            small_h = min(height[left], height[right]);
            best_sol = max(best_sol, (right - left) * small_h);
            while(left < right && height[left] <= small_h) left++;
            while(left < right && height[right] <= small_h) right--;
        } while (left < right);
        return best_sol;   
    }
};

