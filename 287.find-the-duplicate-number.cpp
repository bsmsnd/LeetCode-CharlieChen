/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int leftCount, rightCount, mid, leftLowerBound, leftUpperBound, rightLowerBound, rightUpperBound, upperBound, lowerBound, midCount;
        const int S = nums.size();            
        lowerBound = 1;
        upperBound = S - 1;
        while(lowerBound < upperBound)
        {
            mid = (lowerBound+upperBound)/2;
            // traverse the vector
            
            leftLowerBound = mid;
            leftUpperBound = lowerBound - 1;
            rightLowerBound = upperBound + 1;
            rightUpperBound = mid;
            leftCount = rightCount = midCount = 0;
            
            for (int i =0;i < S; ++i)
            if (nums[i] >= lowerBound && nums[i] <= upperBound)
                if (nums[i] < mid)
                {
                    leftLowerBound = min(leftLowerBound, nums[i]);
                    leftUpperBound = max(leftUpperBound, nums[i]);
                    leftCount++;
                }
                else if (nums[i] == mid)
                    midCount++;
                else
                {
                    rightLowerBound = min(rightLowerBound, nums[i]);
                    rightUpperBound = max(rightUpperBound, nums[i]);
                    rightCount++;
                }
            if (midCount > 1)
                return mid;
            if (rightCount > leftCount)
            {
                lowerBound = rightLowerBound;
                upperBound = rightUpperBound;
            }
            else
            {
                lowerBound = leftLowerBound;
                upperBound = leftUpperBound;
            }            
        }
        return lowerBound;
    }
};

