/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#define min(a,b)((a) < (b) ? (a) : (b))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();

        // Empty set handler
        if (a == 0)
        {
            if (b%2 == 0)
                return (nums2[b/2 - 1] + nums2[b/2]) / 2.0;
            else
                return double(nums2[b/2]);
        }

        if (b == 0)
        {
            if (a%2 == 0)
                return (nums1[a/2 - 1] + nums1[a/2]) / 2.0;
            else
                return double(nums1[a/2]);
        }

        if ((a+b) % 2 ==0) // even
        {
            return (findKthSmallestValue(nums1,nums2, (a+b)/2) + findKthSmallestValue(nums1,nums2, (a+b)/2+1) ) / 2.0;
        }
        else  //odd
        {
            return findKthSmallestValue(nums1,nums2, (a+b)/2 + 1);
        }
        



    }

    double findKthSmallestValue(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int left1, left2, range1, range2;
        int a = nums1.size();
        int b = nums2.size();
        int cur1,cur2;

        left1 = 0;
        left2 = 0;
        while(k > 1 && left1 < a && left2 < b){
            range1 = min(k/2, (a - left1));
            range2 = k - range1;            
            
            cur1 = left1 + range1 - 1;
            cur2 = left2 + range2 - 1;

            if (cur2 >= b) // longer b!
            {
                range2 = min(k/2, (b-left2));
                range1 = k - range2;
                cur1 = left1 + range1 - 1;
                cur2 = left2 + range2 - 1;
            }
            
            if (nums1[cur1] == nums2[cur2])
                return nums1[cur1];
            if (nums1[cur1] < nums2[cur2])
            {
                left1 += range1;
                k -= range1;
            }
            if (nums1[cur1] > nums2[cur2])
            {
                left2 += range2;
                k -= range2;
            }
        }
        if (left1 >= a)
            return nums2[k-1];
        if (left2 >= b)
            return nums1[k-1];

        return min(nums1[left1], nums2[left2]);
            
        
    }
};
