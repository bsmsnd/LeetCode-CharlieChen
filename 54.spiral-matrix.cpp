/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int numFilled = 0;
        int numToFill = matrix.size() * matrix[0].size();
        int i = 0;
        int j = 0;
        int lowerBound = 0;
        int upperBound = matrix.size();
        int leftMost = 0;
        int rightMost = matrix[0].size();
        int direction = 0;
        vector<int> elements;
        while (numFilled < numToFill) {
            switch (direction) {
            case 0:
                for (; j < rightMost - 1; j++) {
                    elements.push_back(matrix[i][j]);
                    numFilled++;
                }
                rightMost--;
                direction = 1;
                break;
            case 1:
                for (; i < upperBound - 1; i++) {
                    elements.push_back(matrix[i][j]);
                    numFilled++;
                }
                upperBound--;
                direction = 2;
                break;
            case 2:
                for (; j > leftMost; j--) {
                    elements.push_back(matrix[i][j]);
                    numFilled++;
                }
                leftMost++;
                direction = 3;
            case 3:
                for (; i > lowerBound; i--) {
                    elements.push_back(matrix[i][j]);
                    numFilled++;
                }
                lowerBound++;
                direction = 0;
            default:
                break;
            }
        }
        return elements;
    }
};
// @lc code=end

