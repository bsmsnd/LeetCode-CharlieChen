/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (41.25%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */

// Hash table version
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_map;
        vector<int> result;
        int tmp;
        /* TWO ITERATIONS
        for (int i = 0;i < nums.size();i++)
            num_map[nums[i]] = i;
        for (int i = 0;i < nums.size();i++)
        {
            tmp = target - nums[i];
            if (num_map.find(tmp) != num_map.end() && num_map[tmp] != i){
                result.push_back(i);
                result.push_back(num_map[tmp]);
                break;
            }
        }
        */
        //TWO ITERATIONS
        int beg,end;
        for (int i = 0;i < nums.size();i++)
        {
            tmp = target - nums[i];
            if (num_map.find(tmp) != num_map.end() && num_map[tmp] != i)
            {
                beg = i > num_map[tmp] ? num_map[tmp] : i;
                end = i > num_map[tmp] ? i : num_map[tmp];
                result.push_back(beg);
                result.push_back(end);
                break;
            }
            num_map[nums[i]] = i;
        }
        return result;
    }
};
