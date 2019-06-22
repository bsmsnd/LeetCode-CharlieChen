/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        // row search
        const int R = matrix.size();
        const int C = matrix[0].size();
        int leftRow = 0;
        int rightRow = R - 1;
        while(rightRow - leftRow > 1)
        {
            int mid = (leftRow + rightRow)/2;
            if (target >= matrix[mid][0])
                leftRow = mid;
            else
                rightRow = mid - 1;  // ensures no infinite loop            
        }
        if (rightRow != leftRow)
            if (target >= matrix[rightRow][0])
                leftRow = rightRow;
            else
                rightRow = leftRow;


        int left = 0; int right = C - 1;
        while(left<right)
        {
            int mid = (left + right) / 2;
            if (target == matrix[leftRow][mid])
                return true;
            if (target > matrix[leftRow][mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return matrix[leftRow][left] == target;
    }
};

